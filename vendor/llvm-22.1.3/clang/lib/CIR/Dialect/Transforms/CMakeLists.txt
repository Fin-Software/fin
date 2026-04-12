if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/TargetLowering")
  add_subdirectory(TargetLowering)
endif()

add_clang_library(MLIRCIRTransforms
  CIRCanonicalize.cpp
  CIRSimplify.cpp
  CXXABILowering.cpp
  FlattenCFG.cpp
  HoistAllocas.cpp
  LoweringPrepare.cpp
  LoweringPrepareItaniumCXXABI.cpp
  GotoSolver.cpp

  DEPENDS
  MLIRCIRPassIncGen

  LINK_LIBS PUBLIC
  clangAST
  clangBasic

  MLIRAnalysis
  MLIRIR
  MLIRPass
  MLIRTransformUtils

  MLIRCIR
  MLIRCIRInterfaces
  MLIRCIRTargetLowering
)
