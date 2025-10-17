set(LLVM_LINK_COMPONENTS
  AllTargetsAsmParsers
  AllTargetsDescs
  AllTargetsDisassemblers
  AllTargetsInfos
  MC
  MCParser
  Object
  Support
  Symbolize
  )

add_llvm_tool(llvm-cfi-verify
  llvm-cfi-verify.cpp
  )

if(EXISTS  "${CMAKE_CURRENT_SOURCE_DIR}/lib")
  add_subdirectory(lib)
endif()
target_link_libraries(llvm-cfi-verify PRIVATE LLVMCFIVerify)
