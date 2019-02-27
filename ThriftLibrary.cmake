#
# Requirements:
# Please provide the following two variables before using these macros:
#   ${THRIFT1} - path/to/bin/thrift1
#   ${THRIFT_TEMPLATES} - path/to/include/thrift/templates
#   ${THRIFTCPP2} - path/to/lib/thriftcpp2
#

#
# thrift_object
# This creates a object that will contain the source files and all the proper
# dependencies to generate and compile thrift generated files
#
# Params:
#   @file_name - The name of the thrift file
#   @services  - A list of services that are declared in the thrift file
#   @language  - The generator to use (cpp or cpp2)
#   @options   - Extra options to pass to the generator
#   @file_path - The directory where the thrift file lives
#   @output_path - The directory where the thrift objects will be built
#   @include_prefix - The last part of output_path, relative include prefix
#
# Output:
#  A object file named `${file-name}-${language}-obj` to include into your
#  project's library
#
# Notes:
# If any of the fields is empty, it is still required to provide an empty string
#
# Usage:
#   thrift_object(
#     #file_name
#     #services
#     #language
#     #options
#     #file_path
#     #output_path
#     #include_prefix
#   )
#   add_library(somelib $<TARGET_OBJECTS:${file_name}-${language}-obj> ...)
#

macro(thrift_object file_name services language options file_path output_path include_prefix)
thrift_generate(
  "${file_name}"
  "${services}"
  "${language}"
  "${options}"
  "${file_path}"
  "${output_path}"
  "${include_prefix}"
)
bypass_source_check(${${file_name}-${language}-SOURCES})
add_library(
  "${file_name}-${language}-obj"
  OBJECT
  ${${file_name}-${language}-SOURCES}
)
add_dependencies(
  "${file_name}-${language}-obj"
  "${file_name}-${language}-target"
)
message("Thrift will create the Object file : ${file_name}-${language}-obj")
endmacro()

# thrift_library
# Same as thrift object in terms of usage but creates the library instead of
# object so that you can use to link against your library instead of including
# all symbols into your library
#
# Params:
#   @file_name - The name of the thrift file
#   @services  - A list of services that are declared in the thrift file
#   @language  - The generator to use (cpp or cpp2)
#   @options   - Extra options to pass to the generator
#   @file_path - The directory where the thrift file lives
#   @output_path - The directory where the thrift objects will be built
#   @include_prefix - The last part of output_path, relative include prefix
#
# Output:
#  A library file named `${file-name}-${language}` to link against your
#  project's library
#
# Notes:
# If any of the fields is empty, it is still required to provide an empty string
#
# Usage:
#   thrift_library(
#     #file_name
#     #services
#     #language
#     #options
#     #file_path
#     #output_path
#     #include_prefix
#   )
#   add_library(somelib ...)
#   target_link_libraries(somelibe ${file_name}-${language} ...)
#

macro(thrift_library file_name services language options file_path output_path include_prefix)
thrift_object(
  "${file_name}"
  "${services}"
  "${language}"
  "${options}"
  "${file_path}"
  "${output_path}"
  "${include_prefix}"
)
add_library(
  "${file_name}-${language}"
  $<TARGET_OBJECTS:${file_name}-${language}-obj>
)
target_link_libraries("${file_name}-${language}" ${THRIFTCPP2})
message("Thrift will create the Library file : ${file_name}-${language}")
endmacro()

#
# bypass_source_check
# This tells cmake to ignore if it doesn't see the following sources in
# the library that will be installed. Thrift files are generated at compile
# time so they do not exist at source check time
#
# Params:
#   @sources - The list of files to ignore in source check
#

macro(bypass_source_check sources)
set_source_files_properties(
  ${sources}
  PROPERTIES GENERATED TRUE
)
endmacro()


# TODO: How to pass additional Cython includes to the custom command?
# filename .. depenencies

macro(thrift_cython_to_cxx filename)
  foreach(_src
    "types"
    "clients"
    "services"
  )
    # Parse the arguments
    set(_nextarg)
    set(_dependencies)
    foreach(_arg ${ARGN})
      if("${_arg}" STREQUAL "WORKING_DIRECTORY")
        set(_nextarg "WORKING_DIRECTORY")
      elseif ("${_arg}" STREQUAL "DEPENDS")
        set(_nextarg "DEPENDS")
      else()
        if("${_nextarg}" STREQUAL "WORKING_DIRECTORY")
          set(_working_directory ${_arg})
          set(_nextarg)
        elseif("${_nextarg}" STREQUAL "DEPENDS")
          list(APPEND _dependencies ${_arg})
        else()
          message(FATAL_ERROR "Unexpected parameter '${_arg}' in "
            "thrift_cython_to_cxx call")
        endif()
      endif()
    endforeach()

    set(_pyx "gen-py3/${filename}/${_src}.pyx")
    set(_cxx "gen-py3/${filename}/${_src}.cpp")
    string(REPLACE "/" "-" _module_name "${filename}/${_src}-py3")
    message(STATUS "Create Cython module ${_module_name} from ${_pyx}")

    add_custom_command(OUTPUT ${_cxx}
      COMMAND ${CYTHON_EXE} --fast-fail -3 --cplus ${_pyx} -o ${_cxx}
        -I${THRIFT_BUILD}/thrift/lib/py3/cybld/
      COMMENT "Generating ${_cxx} using Cython"
      DEPENDS ${_dependencies}
      WORKING_DIRECTORY ${_working_directory}
    )

    if(${_src} STREQUAL "types")
      python_add_module(${_module_name} "${_cxx}")
    else()
      python_add_module(${_module_name} "${_cxx}"
        "gen-py3/${filename}/${_src}_wrapper.cpp"
      )
      set_source_files_properties(
        "gen-py3/${filename}/${_src}_wrapper.cpp"
        PROPERTIES GENERATED TRUE
      )
    endif()
    set_target_properties(${_module_name}
      PROPERTIES
      LIBRARY_OUTPUT_DIRECTORY "gen-py3/${filename}"
      LIBRARY_OUTPUT_NAME ${_src})
  endforeach()
endmacro()

#
# thrift_generate
# This is used to codegen thrift files using the thrift compiler
# Params:
#   @file_name - The name of tge thrift file
#   @services  - A list of services that are declared in the thrift file
#   @language  - The generator to use (cpp, cpp2 or py3)
#   @options   - Extra options to pass to the generator
#   @output_path - The directory where the thrift file lives
#
# Output:
#  file-language-target     - A custom target to add a dependenct
#  ${file-language-HEADERS} - The generated Header Files.
#  ${file-language-SOURCES} - The generated Source Files.
#
# Notes:
# If any of the fields is empty, it is still required to provide an empty string
#
# When using file_language-SOURCES it should always call:
#   bypass_source_check(${file_language-SOURCES})
# This will prevent cmake from complaining about missing source files
#

macro(thrift_generate file_name services language options file_path output_path include_prefix)
set("${file_name}-${language}-HEADERS"
  ${output_path}/gen-${language}/${file_name}_constants.h
  ${output_path}/gen-${language}/${file_name}_data.h
  ${output_path}/gen-${language}/${file_name}_types.h
  ${output_path}/gen-${language}/${file_name}_types.tcc
)
set("${file_name}-${language}-SOURCES"
  ${output_path}/gen-${language}/${file_name}_constants.cpp
  ${output_path}/gen-${language}/${file_name}_data.cpp
  ${output_path}/gen-${language}/${file_name}_types.cpp
)
foreach(service ${services})
  set("${file_name}-${language}-HEADERS"
    ${${file_name}-${language}-HEADERS}
    ${output_path}/gen-${language}/${service}.h
    ${output_path}/gen-${language}/${service}.tcc
    ${output_path}/gen-${language}/${service}AsyncClient.h
    ${output_path}/gen-${language}/${service}_custom_protocol.h
  )
  set("${file_name}-${language}-SOURCES"
    ${${file_name}-${language}-SOURCES}
    ${output_path}/gen-${language}/${service}.cpp
    ${output_path}/gen-${language}/${service}AsyncClient.cpp
  )
endforeach()
if("${include_prefix}" STREQUAL "")
  set(include_prefix_text "")
else()
  set(include_prefix_text "include_prefix=${include_prefix}")
  if(NOT "${options}" STREQUAL "")
    set(include_prefix_text ",${include_prefix_text}")
  endif()
endif()
set(gen_language ${language})
if("${language}" STREQUAL "cpp2")
  set(gen_language "mstch_cpp2")
elseif("${language}" STREQUAL "py3")
  set(gen_language "mstch_py3")
  file(WRITE "${output_path}/gen-${language}/${file_name}/__init__.py")
endif()
add_custom_command(
  OUTPUT ${${file_name}-${language}-HEADERS} ${${file_name}-${language}-SOURCES}
  COMMAND ${THRIFT1}
    --gen "${gen_language}:${options}${include_prefix_text}"
    -o ${output_path}
    --templates ${THRIFT_TEMPLATES}
    "${file_path}/${file_name}.thrift"
  DEPENDS ${THRIFT1}
  COMMENT "Generating ${file_name} files. Output: ${output_path}"
)
add_custom_target(
  ${file_name}-${language}-target ALL
  DEPENDS ${${language}-${language}-HEADERS} ${${file_name}-${language}-SOURCES}
)
install(
  DIRECTORY gen-${language}
  DESTINATION include/${include_prefix}
  FILES_MATCHING PATTERN "*.h")
install(
  DIRECTORY gen-${language}
  DESTINATION include/${include_prefix}
  FILES_MATCHING PATTERN "*.tcc")
endmacro()
