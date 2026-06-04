add_llvm_component_group(VE)

set(LLVM_TARGET_DEFINITIONS VE.td)

tablegen(LLVM VEGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM VEGenInstrInfo.inc -gen-instr-info)
tablegen(LLVM VEGenDisassemblerTables.inc -gen-disassembler)
tablegen(LLVM VEGenMCCodeEmitter.inc -gen-emitter)
tablegen(LLVM VEGenAsmWriter.inc -gen-asm-writer)
tablegen(LLVM VEGenAsmMatcher.inc -gen-asm-matcher)
tablegen(LLVM VEGenDAGISel.inc -gen-dag-isel)
tablegen(LLVM VEGenSDNodeInfo.inc -gen-sd-node-info)
tablegen(LLVM VEGenSubtargetInfo.inc -gen-subtarget)
tablegen(LLVM VEGenCallingConv.inc -gen-callingconv)
add_public_tablegen_target(VECommonTableGen)

add_llvm_target(VECodeGen
  LVLGen.cpp
  VEAsmPrinter.cpp
  VECustomDAG.cpp
  VEFrameLowering.cpp
  VEISelDAGToDAG.cpp
  VEISelLowering.cpp
  VEInstrInfo.cpp
  VEMachineFunctionInfo.cpp
  VEMCInstLower.cpp
  VERegisterInfo.cpp
  VESelectionDAGInfo.cpp
  VESubtarget.cpp
  VETargetMachine.cpp
  VVPISelLowering.cpp

  LINK_COMPONENTS
  Analysis
  AsmPrinter
  CodeGen
  CodeGenTypes
  Core
  MC
  SelectionDAG
  Support
  Target
  TargetParser
  TransformUtils
  VEDesc
  VEInfo

  ADD_TO_COMPONENT
  VE
  )

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/AsmParser")
  add_subdirectory(AsmParser)
endif()
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/Disassembler")
  add_subdirectory(Disassembler)
endif()
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/TargetInfo")
  add_subdirectory(TargetInfo)
endif()
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/MCTargetDesc")
  add_subdirectory(MCTargetDesc)
endif()
