if(EXISTS  "${CMAKE_CURRENT_SOURCE_DIR}/Dynamic")
  add_subdirectory(Dynamic)
endif()

set(LLVM_LINK_COMPONENTS
  FrontendOpenMP
  Support
)

add_clang_library(clangASTMatchers
  ASTMatchFinder.cpp
  ASTMatchersInternal.cpp
  LowLevelHelpers.cpp

  LINK_LIBS
  clangAST
  clangBasic
  clangLex

  DEPENDS
  omp_gen
  ClangDriverOptions
  )
