set(LLVM_LINK_COMPONENTS
  Core
  IRReader
  Support
  )

add_llvm_tool(llvm-diff
  llvm-diff.cpp

  DEPENDS
  intrinsics_gen
  )

if(EXISTS  "${CMAKE_CURRENT_SOURCE_DIR}/lib")
  add_subdirectory(lib)
endif()
target_link_libraries(llvm-diff PRIVATE LLVMDiff)
