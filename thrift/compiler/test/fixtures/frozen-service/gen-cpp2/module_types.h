/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include <thrift/lib/cpp2/GeneratedHeaderHelper.h>
#include <thrift/lib/cpp2/Thrift.h>
#include <thrift/lib/cpp2/gen/module_types_h.h>
#include <thrift/lib/cpp2/protocol/Protocol.h>


// BEGIN declare_enums

// END declare_enums
// BEGIN struct_indirection

// END struct_indirection
// BEGIN forward_declare
namespace some { namespace ns {
class ModuleA;
class ModuleB;
class ExceptionA;
class ExceptionB;
}} // some::ns
// END forward_declare
// BEGIN typedefs

// END typedefs
// BEGIN hash_and_equal_to
// END hash_and_equal_to
namespace some { namespace ns {
class ModuleA final : private apache::thrift::detail::st::ComparisonOperators<ModuleA> {
 public:

  ModuleA() :
      i32Field(0) {}
  // FragileConstructor for use in initialization lists only.
  ModuleA(apache::thrift::FragileConstructor, int32_t i32Field__arg, std::string strField__arg, std::vector<int16_t> listField__arg, std::map<std::string, int32_t> mapField__arg);
  template <typename _T>
  void __set_field(::apache::thrift::detail::argument_wrapper<1, _T> arg) {
    i32Field = arg.move();
    __isset.i32Field = true;
  }
  template <typename _T>
  void __set_field(::apache::thrift::detail::argument_wrapper<2, _T> arg) {
    strField = arg.move();
    __isset.strField = true;
  }
  template <typename _T>
  void __set_field(::apache::thrift::detail::argument_wrapper<3, _T> arg) {
    listField = arg.move();
    __isset.listField = true;
  }
  template <typename _T>
  void __set_field(::apache::thrift::detail::argument_wrapper<4, _T> arg) {
    mapField = arg.move();
    __isset.mapField = true;
  }

  ModuleA(ModuleA&&) = default;

  ModuleA(const ModuleA&) = default;

  ModuleA& operator=(ModuleA&&) = default;

  ModuleA& operator=(const ModuleA&) = default;
  void __clear();
  int32_t i32Field;
  std::string strField;
  std::vector<int16_t> listField;
  std::map<std::string, int32_t> mapField;

  struct __isset {
    bool i32Field;
    bool strField;
    bool listField;
    bool mapField;
  } __isset = {};
  bool operator==(const ModuleA& rhs) const;
  bool operator<(const ModuleA& rhs) const;

  int32_t get_i32Field() const {
    return i32Field;
  }

  int32_t& set_i32Field(int32_t i32Field_) {
    i32Field = i32Field_;
    __isset.i32Field = true;
    return i32Field;
  }

  const std::string& get_strField() const& {
    return strField;
  }

  std::string get_strField() && {
    return std::move(strField);
  }

  template <typename T_ModuleA_strField_struct_setter = std::string>
  std::string& set_strField(T_ModuleA_strField_struct_setter&& strField_) {
    strField = std::forward<T_ModuleA_strField_struct_setter>(strField_);
    __isset.strField = true;
    return strField;
  }
  const std::vector<int16_t>& get_listField() const&;
  std::vector<int16_t> get_listField() &&;

  template <typename T_ModuleA_listField_struct_setter = std::vector<int16_t>>
  std::vector<int16_t>& set_listField(T_ModuleA_listField_struct_setter&& listField_) {
    listField = std::forward<T_ModuleA_listField_struct_setter>(listField_);
    __isset.listField = true;
    return listField;
  }
  const std::map<std::string, int32_t>& get_mapField() const&;
  std::map<std::string, int32_t> get_mapField() &&;

  template <typename T_ModuleA_mapField_struct_setter = std::map<std::string, int32_t>>
  std::map<std::string, int32_t>& set_mapField(T_ModuleA_mapField_struct_setter&& mapField_) {
    mapField = std::forward<T_ModuleA_mapField_struct_setter>(mapField_);
    __isset.mapField = true;
    return mapField;
  }

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t serializedSize(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t serializedSizeZC(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t write(Protocol_* prot_) const;

 private:
  template <class Protocol_>
  void readNoXfer(Protocol_* iprot);

  friend class ::apache::thrift::Cpp2Ops< ModuleA >;
};

void swap(ModuleA& a, ModuleA& b);
extern template void ModuleA::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
extern template uint32_t ModuleA::write<>(apache::thrift::BinaryProtocolWriter*) const;
extern template uint32_t ModuleA::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
extern template uint32_t ModuleA::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
extern template void ModuleA::readNoXfer<>(apache::thrift::CompactProtocolReader*);
extern template uint32_t ModuleA::write<>(apache::thrift::CompactProtocolWriter*) const;
extern template uint32_t ModuleA::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
extern template uint32_t ModuleA::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

template <class Protocol_>
uint32_t ModuleA::read(Protocol_* iprot) {
  auto _xferStart = iprot->getCurrentPosition().getCurrentPosition();
  readNoXfer(iprot);
  return iprot->getCurrentPosition().getCurrentPosition() - _xferStart;
}

}} // some::ns
namespace apache { namespace thrift {

template <> inline void Cpp2Ops< ::some::ns::ModuleA>::clear( ::some::ns::ModuleA* obj) {
  return obj->__clear();
}

template <> inline constexpr apache::thrift::protocol::TType Cpp2Ops< ::some::ns::ModuleA>::thriftType() {
  return apache::thrift::protocol::T_STRUCT;
}

template <> template <class Protocol> uint32_t Cpp2Ops< ::some::ns::ModuleA>::write(Protocol* proto,  ::some::ns::ModuleA const* obj) {
  return obj->write(proto);
}

template <> template <class Protocol> void Cpp2Ops< ::some::ns::ModuleA>::read(Protocol* proto,  ::some::ns::ModuleA* obj) {
  return obj->readNoXfer(proto);
}

template <> template <class Protocol> uint32_t Cpp2Ops< ::some::ns::ModuleA>::serializedSize(Protocol const* proto,  ::some::ns::ModuleA const* obj) {
  return obj->serializedSize(proto);
}

template <> template <class Protocol> uint32_t Cpp2Ops< ::some::ns::ModuleA>::serializedSizeZC(Protocol const* proto,  ::some::ns::ModuleA const* obj) {
  return obj->serializedSizeZC(proto);
}

}} // apache::thrift
namespace some { namespace ns {
class ModuleB final : private apache::thrift::detail::st::ComparisonOperators<ModuleB> {
 public:

  ModuleB() :
      i32Field(0) {}
  // FragileConstructor for use in initialization lists only.
  ModuleB(apache::thrift::FragileConstructor, int32_t i32Field__arg);
  template <typename _T>
  void __set_field(::apache::thrift::detail::argument_wrapper<1, _T> arg) {
    i32Field = arg.move();
    __isset.i32Field = true;
  }

  ModuleB(ModuleB&&) = default;

  ModuleB(const ModuleB&) = default;

  ModuleB& operator=(ModuleB&&) = default;

  ModuleB& operator=(const ModuleB&) = default;
  void __clear();
  int32_t i32Field;

  struct __isset {
    bool i32Field;
  } __isset = {};
  bool operator==(const ModuleB& rhs) const;
  bool operator<(const ModuleB& rhs) const;

  int32_t get_i32Field() const {
    return i32Field;
  }

  int32_t& set_i32Field(int32_t i32Field_) {
    i32Field = i32Field_;
    __isset.i32Field = true;
    return i32Field;
  }

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t serializedSize(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t serializedSizeZC(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t write(Protocol_* prot_) const;

 private:
  template <class Protocol_>
  void readNoXfer(Protocol_* iprot);

  friend class ::apache::thrift::Cpp2Ops< ModuleB >;
};

void swap(ModuleB& a, ModuleB& b);
extern template void ModuleB::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
extern template uint32_t ModuleB::write<>(apache::thrift::BinaryProtocolWriter*) const;
extern template uint32_t ModuleB::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
extern template uint32_t ModuleB::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
extern template void ModuleB::readNoXfer<>(apache::thrift::CompactProtocolReader*);
extern template uint32_t ModuleB::write<>(apache::thrift::CompactProtocolWriter*) const;
extern template uint32_t ModuleB::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
extern template uint32_t ModuleB::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

template <class Protocol_>
uint32_t ModuleB::read(Protocol_* iprot) {
  auto _xferStart = iprot->getCurrentPosition().getCurrentPosition();
  readNoXfer(iprot);
  return iprot->getCurrentPosition().getCurrentPosition() - _xferStart;
}

}} // some::ns
namespace apache { namespace thrift {

template <> inline void Cpp2Ops< ::some::ns::ModuleB>::clear( ::some::ns::ModuleB* obj) {
  return obj->__clear();
}

template <> inline constexpr apache::thrift::protocol::TType Cpp2Ops< ::some::ns::ModuleB>::thriftType() {
  return apache::thrift::protocol::T_STRUCT;
}

template <> template <class Protocol> uint32_t Cpp2Ops< ::some::ns::ModuleB>::write(Protocol* proto,  ::some::ns::ModuleB const* obj) {
  return obj->write(proto);
}

template <> template <class Protocol> void Cpp2Ops< ::some::ns::ModuleB>::read(Protocol* proto,  ::some::ns::ModuleB* obj) {
  return obj->readNoXfer(proto);
}

template <> template <class Protocol> uint32_t Cpp2Ops< ::some::ns::ModuleB>::serializedSize(Protocol const* proto,  ::some::ns::ModuleB const* obj) {
  return obj->serializedSize(proto);
}

template <> template <class Protocol> uint32_t Cpp2Ops< ::some::ns::ModuleB>::serializedSizeZC(Protocol const* proto,  ::some::ns::ModuleB const* obj) {
  return obj->serializedSizeZC(proto);
}

}} // apache::thrift
namespace some { namespace ns {
class ExceptionA final : private apache::thrift::detail::st::ComparisonOperators<ExceptionA>, public apache::thrift::TException {
 public:

  ExceptionA() :
      code(0) {}
  // FragileConstructor for use in initialization lists only.
  ExceptionA(apache::thrift::FragileConstructor, int32_t code__arg, std::string msg__arg);
  template <typename _T>
  void __set_field(::apache::thrift::detail::argument_wrapper<1, _T> arg) {
    code = arg.move();
    __isset.code = true;
  }
  template <typename _T>
  void __set_field(::apache::thrift::detail::argument_wrapper<2, _T> arg) {
    msg = arg.move();
    __isset.msg = true;
  }

  ExceptionA(ExceptionA&&) = default;

  ExceptionA(const ExceptionA&) = default;

  ExceptionA& operator=(ExceptionA&&) = default;

  ExceptionA& operator=(const ExceptionA&) = default;
  void __clear();
  int32_t code;
  std::string msg;

  struct __isset {
    bool code;
    bool msg;
  } __isset = {};
  bool operator==(const ExceptionA& rhs) const;
  bool operator<(const ExceptionA& rhs) const;

  int32_t get_code() const {
    return code;
  }

  int32_t& set_code(int32_t code_) {
    code = code_;
    __isset.code = true;
    return code;
  }

  const std::string& get_msg() const& {
    return msg;
  }

  std::string get_msg() && {
    return std::move(msg);
  }

  template <typename T_ExceptionA_msg_struct_setter = std::string>
  std::string& set_msg(T_ExceptionA_msg_struct_setter&& msg_) {
    msg = std::forward<T_ExceptionA_msg_struct_setter>(msg_);
    __isset.msg = true;
    return msg;
  }

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t serializedSize(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t serializedSizeZC(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t write(Protocol_* prot_) const;

  const char* what() const noexcept override {
    return " ::some::ns::ExceptionA";
  }

 private:
  template <class Protocol_>
  void readNoXfer(Protocol_* iprot);

  friend class ::apache::thrift::Cpp2Ops< ExceptionA >;
};

void swap(ExceptionA& a, ExceptionA& b);
extern template void ExceptionA::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
extern template uint32_t ExceptionA::write<>(apache::thrift::BinaryProtocolWriter*) const;
extern template uint32_t ExceptionA::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
extern template uint32_t ExceptionA::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
extern template void ExceptionA::readNoXfer<>(apache::thrift::CompactProtocolReader*);
extern template uint32_t ExceptionA::write<>(apache::thrift::CompactProtocolWriter*) const;
extern template uint32_t ExceptionA::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
extern template uint32_t ExceptionA::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

template <class Protocol_>
uint32_t ExceptionA::read(Protocol_* iprot) {
  auto _xferStart = iprot->getCurrentPosition().getCurrentPosition();
  readNoXfer(iprot);
  return iprot->getCurrentPosition().getCurrentPosition() - _xferStart;
}

}} // some::ns
namespace apache { namespace thrift {

template <> inline void Cpp2Ops< ::some::ns::ExceptionA>::clear( ::some::ns::ExceptionA* obj) {
  return obj->__clear();
}

template <> inline constexpr apache::thrift::protocol::TType Cpp2Ops< ::some::ns::ExceptionA>::thriftType() {
  return apache::thrift::protocol::T_STRUCT;
}

template <> template <class Protocol> uint32_t Cpp2Ops< ::some::ns::ExceptionA>::write(Protocol* proto,  ::some::ns::ExceptionA const* obj) {
  return obj->write(proto);
}

template <> template <class Protocol> void Cpp2Ops< ::some::ns::ExceptionA>::read(Protocol* proto,  ::some::ns::ExceptionA* obj) {
  return obj->readNoXfer(proto);
}

template <> template <class Protocol> uint32_t Cpp2Ops< ::some::ns::ExceptionA>::serializedSize(Protocol const* proto,  ::some::ns::ExceptionA const* obj) {
  return obj->serializedSize(proto);
}

template <> template <class Protocol> uint32_t Cpp2Ops< ::some::ns::ExceptionA>::serializedSizeZC(Protocol const* proto,  ::some::ns::ExceptionA const* obj) {
  return obj->serializedSizeZC(proto);
}

}} // apache::thrift
namespace some { namespace ns {
class ExceptionB final : private apache::thrift::detail::st::ComparisonOperators<ExceptionB>, public apache::thrift::TException {
 public:

  ExceptionB() :
      code(0) {}
  // FragileConstructor for use in initialization lists only.
  ExceptionB(apache::thrift::FragileConstructor, int32_t code__arg, std::string msg__arg);
  template <typename _T>
  void __set_field(::apache::thrift::detail::argument_wrapper<1, _T> arg) {
    code = arg.move();
    __isset.code = true;
  }
  template <typename _T>
  void __set_field(::apache::thrift::detail::argument_wrapper<2, _T> arg) {
    msg = arg.move();
    __isset.msg = true;
  }

  ExceptionB(ExceptionB&&) = default;

  ExceptionB(const ExceptionB&) = default;

  ExceptionB& operator=(ExceptionB&&) = default;

  ExceptionB& operator=(const ExceptionB&) = default;
  void __clear();
  int32_t code;
  std::string msg;

  struct __isset {
    bool code;
    bool msg;
  } __isset = {};
  bool operator==(const ExceptionB& rhs) const;
  bool operator<(const ExceptionB& rhs) const;

  int32_t get_code() const {
    return code;
  }

  int32_t& set_code(int32_t code_) {
    code = code_;
    __isset.code = true;
    return code;
  }

  const std::string& get_msg() const& {
    return msg;
  }

  std::string get_msg() && {
    return std::move(msg);
  }

  template <typename T_ExceptionB_msg_struct_setter = std::string>
  std::string& set_msg(T_ExceptionB_msg_struct_setter&& msg_) {
    msg = std::forward<T_ExceptionB_msg_struct_setter>(msg_);
    __isset.msg = true;
    return msg;
  }

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t serializedSize(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t serializedSizeZC(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t write(Protocol_* prot_) const;

  const char* what() const noexcept override {
    return " ::some::ns::ExceptionB";
  }

 private:
  template <class Protocol_>
  void readNoXfer(Protocol_* iprot);

  friend class ::apache::thrift::Cpp2Ops< ExceptionB >;
};

void swap(ExceptionB& a, ExceptionB& b);
extern template void ExceptionB::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
extern template uint32_t ExceptionB::write<>(apache::thrift::BinaryProtocolWriter*) const;
extern template uint32_t ExceptionB::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
extern template uint32_t ExceptionB::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
extern template void ExceptionB::readNoXfer<>(apache::thrift::CompactProtocolReader*);
extern template uint32_t ExceptionB::write<>(apache::thrift::CompactProtocolWriter*) const;
extern template uint32_t ExceptionB::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
extern template uint32_t ExceptionB::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

template <class Protocol_>
uint32_t ExceptionB::read(Protocol_* iprot) {
  auto _xferStart = iprot->getCurrentPosition().getCurrentPosition();
  readNoXfer(iprot);
  return iprot->getCurrentPosition().getCurrentPosition() - _xferStart;
}

}} // some::ns
namespace apache { namespace thrift {

template <> inline void Cpp2Ops< ::some::ns::ExceptionB>::clear( ::some::ns::ExceptionB* obj) {
  return obj->__clear();
}

template <> inline constexpr apache::thrift::protocol::TType Cpp2Ops< ::some::ns::ExceptionB>::thriftType() {
  return apache::thrift::protocol::T_STRUCT;
}

template <> template <class Protocol> uint32_t Cpp2Ops< ::some::ns::ExceptionB>::write(Protocol* proto,  ::some::ns::ExceptionB const* obj) {
  return obj->write(proto);
}

template <> template <class Protocol> void Cpp2Ops< ::some::ns::ExceptionB>::read(Protocol* proto,  ::some::ns::ExceptionB* obj) {
  return obj->readNoXfer(proto);
}

template <> template <class Protocol> uint32_t Cpp2Ops< ::some::ns::ExceptionB>::serializedSize(Protocol const* proto,  ::some::ns::ExceptionB const* obj) {
  return obj->serializedSize(proto);
}

template <> template <class Protocol> uint32_t Cpp2Ops< ::some::ns::ExceptionB>::serializedSizeZC(Protocol const* proto,  ::some::ns::ExceptionB const* obj) {
  return obj->serializedSizeZC(proto);
}

}} // apache::thrift
