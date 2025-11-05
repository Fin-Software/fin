set(LLVM_LINK_COMPONENTS
  Option
  FrontendOpenMP
  Support
  TargetParser
  )

if(EXISTS  "${CMAKE_CURRENT_SOURCE_DIR}/Core")
  add_subdirectory(Core)
endif()
if(EXISTS  "${CMAKE_CURRENT_SOURCE_DIR}/Inclusions")
  add_subdirectory(Inclusions)
endif()
if(EXISTS  "${CMAKE_CURRENT_SOURCE_DIR}/Refactoring")
  add_subdirectory(Refactoring)
endif()
if(EXISTS  "${CMAKE_CURRENT_SOURCE_DIR}/ASTDiff")
  add_subdirectory(ASTDiff)
endif()
if(EXISTS  "${CMAKE_CURRENT_SOURCE_DIR}/Syntax")
  add_subdirectory(Syntax)
endif()
if(EXISTS  "${CMAKE_CURRENT_SOURCE_DIR}/DependencyScanning")
  add_subdirectory(DependencyScanning)
endif()
if(EXISTS  "${CMAKE_CURRENT_SOURCE_DIR}/Transformer")
  add_subdirectory(Transformer)
endif()

add_clang_library(clangTooling
  AllTUsExecution.cpp
  ArgumentsAdjusters.cpp
  CommonOptionsParser.cpp
  CompilationDatabase.cpp
  Execution.cpp
  ExpandResponseFilesCompilationDatabase.cpp
  FileMatchTrie.cpp
  FixIt.cpp
  GuessTargetAndModeCompilationDatabase.cpp
  InterpolatingCompilationDatabase.cpp
  JSONCompilationDatabase.cpp
  LocateToolCompilationDatabase.cpp
  Refactoring.cpp
  RefactoringCallbacks.cpp
  StandaloneExecution.cpp
  Tooling.cpp

  DEPENDS
  ClangDriverOptions
  omp_gen

  LINK_LIBS
  clangAST
  clangASTMatchers
  clangBasic
  clangDriver
  clangFormat
  clangFrontend
  clangLex
  clangRewrite
  clangSerialization
  clangToolingCore
  ${LLVM_PTHREAD_LIB}
  )
