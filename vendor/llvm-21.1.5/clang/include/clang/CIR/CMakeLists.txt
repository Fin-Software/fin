set(MLIR_INCLUDE_DIR ${LLVM_MAIN_SRC_DIR}/../mlir/include ) # --includedir
set(MLIR_TABLEGEN_OUTPUT_DIR ${CMAKE_BINARY_DIR}/tools/mlir/include)
include_directories(${MLIR_INCLUDE_DIR})
include_directories(${MLIR_TABLEGEN_OUTPUT_DIR})

if(EXISTS  "${CMAKE_CURRENT_SOURCE_DIR}/Dialect")
  add_subdirectory(Dialect)
endif()
if(EXISTS  "${CMAKE_CURRENT_SOURCE_DIR}/Interfaces")
  add_subdirectory(Interfaces)
endif()
