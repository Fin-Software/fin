add_llvm_component_group(DirectX)

set(LLVM_TARGET_DEFINITIONS DirectX.td)

tablegen(LLVM DirectXGenSubtargetInfo.inc -gen-subtarget)
tablegen(LLVM DirectXGenInstrInfo.inc -gen-instr-info)
tablegen(LLVM DirectXGenRegisterInfo.inc -gen-register-info)

set(LLVM_TARGET_DEFINITIONS DXIL.td)
tablegen(LLVM DXILOperation.inc -gen-dxil-operation)

add_public_tablegen_target(DirectXCommonTableGen)

add_llvm_target(DirectXCodeGen
  CBufferDataLayout.cpp
  DirectXAsmPrinter.cpp
  DirectXInstrInfo.cpp
  DirectXRegisterInfo.cpp
  DirectXSubtarget.cpp
  DirectXTargetMachine.cpp
  DirectXTargetTransformInfo.cpp
  DXContainerGlobals.cpp
  DXILCBufferAccess.cpp
  DXILDataScalarization.cpp
  DXILFinalizeLinkage.cpp
  DXILForwardHandleAccesses.cpp
  DXILFlattenArrays.cpp
  DXILIntrinsicExpansion.cpp
  DXILMemIntrinsics.cpp
  DXILOpBuilder.cpp
  DXILOpLowering.cpp
  DXILPostOptimizationValidation.cpp
  DXILPrepare.cpp
  DXILPrettyPrinter.cpp
  DXILResourceAccess.cpp
  DXILResourceImplicitBinding.cpp
  DXILShaderFlags.cpp
  DXILTranslateMetadata.cpp
  DXILRootSignature.cpp
  DXILLegalizePass.cpp

  LINK_COMPONENTS
  Analysis
  AsmPrinter
  BinaryFormat
  CodeGen
  CodeGenTypes
  Core
  DXILBitWriter
  DirectXDesc
  DirectXInfo
  DirectXPointerTypeAnalysis
  FrontendHLSL
  IPO
  MC
  ScalarOpts
  SelectionDAG
  Support
  Target
  TargetParser
  TransformUtils

  ADD_TO_COMPONENT
  DirectX
  )

if(EXISTS  "${CMAKE_CURRENT_SOURCE_DIR}/MCTargetDesc")
  add_subdirectory(MCTargetDesc)
endif()
if(EXISTS  "${CMAKE_CURRENT_SOURCE_DIR}/TargetInfo")
  add_subdirectory(TargetInfo)
endif()
if(EXISTS  "${CMAKE_CURRENT_SOURCE_DIR}/DirectXIRPasses")
  add_subdirectory(DirectXIRPasses)
endif()
if(EXISTS  "${CMAKE_CURRENT_SOURCE_DIR}/DXILWriter")
  add_subdirectory(DXILWriter)
endif()
