add_llvm_component_library(LLVMDWARFLinker
  DWARFLinkerBase.cpp
  Utils.cpp

  ADDITIONAL_HEADER_DIRS
  ${LLVM_MAIN_INCLUDE_DIR}/llvm/DWARFLinker
  DEPENDS
  intrinsics_gen

  LINK_COMPONENTS
  BinaryFormat
  CodeGen
  DebugInfoDWARF
  Object
  Support
  )

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/Classic")
  add_subdirectory(Classic)
endif()
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/Parallel")
  add_subdirectory(Parallel)
endif()
