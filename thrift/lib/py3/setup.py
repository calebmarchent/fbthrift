#!/usr/bin/env python3

# Do not call directly, use cmake
#
# Cython requires source files in a specific structure, the structure is
# created as tree of links to the real source files.

from setuptools import setup, Extension
import os
from setuptools.command.build_ext import build_ext as _build_ext
from distutils.file_util import copy_file

class heresoneimadeearlier(_build_ext):

    def build_extension(self, ext):
        copy_file(
            ext.sources[0],
            self.get_ext_fullpath(ext.name),
            verbose=self.verbose,
            dry_run=self.dry_run
        )

# Extension: filename created by cmake
extensions = [
    Extension("folly.iobuf", sources=["folly/iobuf.so"]),
    Extension("thrift.py3.common", sources=["thrift/py3/common.so"]),
    Extension("thrift.py3.types", sources=["thrift/py3/types.so"]),
    Extension("thrift.py3.exceptions", sources=["thrift/py3/exceptions.so"]),
    Extension("thrift.py3.serializer", sources=["thrift/py3/serializer.so"]),
    Extension("thrift.py3.client", sources=["thrift/py3/client.so"]),
    Extension("thrift.py3.server", sources=["thrift/py3/server.so"]),
]
setup(name="thrift",
      cmdclass={'build_ext': heresoneimadeearlier},
      version='0.0.1',
      packages=['folly', 'thrift', 'thrift.py3'],
      package_data={"": ['*.pxd', '*.h', '__init__.pyx']},
      zip_safe=False,
      ext_modules=extensions
)
