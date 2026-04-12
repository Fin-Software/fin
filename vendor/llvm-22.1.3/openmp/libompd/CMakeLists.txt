#
#//===----------------------------------------------------------------------===//
#//
#// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
#// See https://llvm.org/LICENSE.txt for license information.
#// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#//
#//===----------------------------------------------------------------------===//
#

find_package (Python3 COMPONENTS Interpreter Development)
option(LIBOMP_OMPD_GDB_SUPPORT "Build gdb-plugin code that enables OMPD support in GDB." ${Python3_FOUND})
find_program (GDB_FOUND NAMES "gdb")


if(LIBOMP_OMPD_SUPPORT)
    set(OMPD_INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/src/)
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/src")
  add_subdirectory(src)
endif()
    if(LIBOMP_OMPD_GDB_SUPPORT)
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/gdb-plugin")
  add_subdirectory(gdb-plugin)
endif()
		# GDB is required to run the tests
		if (GDB_FOUND)
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/test")
  add_subdirectory(test)
endif()
		endif()
    endif()
endif()
