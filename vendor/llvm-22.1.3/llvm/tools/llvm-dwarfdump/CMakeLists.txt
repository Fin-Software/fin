set(LLVM_LINK_COMPONENTS
  BinaryFormat
  DebugInfoDWARF
  DebugInfoDWARFLowLevel
  AllTargetsDescs
  AllTargetsInfos
  MC
  Object
  Support
  TargetParser
  )

add_llvm_tool(llvm-dwarfdump
  SectionSizes.cpp
  Statistics.cpp
  llvm-dwarfdump.cpp
  )

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/fuzzer")
  add_subdirectory(fuzzer)
endif()
