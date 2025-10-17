include_directories(${LLVM_MAIN_SRC_DIR}/../mlir/include)
include_directories(${CMAKE_BINARY_DIR}/tools/mlir/include)

# GCC, unlike clang, issues a warning when one virtual function is overridden
# in a derived class but one or more other virtual functions with the same
# name and different signature from a base class are not overridden. This
# leads to many warnings in the MLIR and ClangIR code when using the
# OpenConversionPattern<>::matchAndRewrite() function in the ordinary way.
# The "hiding" behavior is what we want, so we're just disabling the warning
# here.
if (LLVM_COMPILER_IS_GCC_COMPATIBLE AND (NOT "${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang"))
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-overloaded-virtual")
endif()

if(EXISTS  "${CMAKE_CURRENT_SOURCE_DIR}/Dialect")
  add_subdirectory(Dialect)
endif()
if(EXISTS  "${CMAKE_CURRENT_SOURCE_DIR}/CodeGen")
  add_subdirectory(CodeGen)
endif()
if(EXISTS  "${CMAKE_CURRENT_SOURCE_DIR}/FrontendAction")
  add_subdirectory(FrontendAction)
endif()
if(EXISTS  "${CMAKE_CURRENT_SOURCE_DIR}/Interfaces")
  add_subdirectory(Interfaces)
endif()
if(EXISTS  "${CMAKE_CURRENT_SOURCE_DIR}/Lowering")
  add_subdirectory(Lowering)
endif()
