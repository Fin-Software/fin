

add_llvm_component_library(LLVMExecutionEngine
  ExecutionEngine.cpp
  ExecutionEngineBindings.cpp
  GDBRegistrationListener.cpp
  SectionMemoryManager.cpp
  TargetSelect.cpp

  ADDITIONAL_HEADER_DIRS
  ${LLVM_MAIN_INCLUDE_DIR}/llvm/ExecutionEngine

  DEPENDS
  intrinsics_gen

  LINK_COMPONENTS
  Core
  MC
  Object
  OrcTargetProcess
  RuntimeDyld
  Support
  Target
  TargetParser
  )

if(BUILD_SHARED_LIBS)
  target_link_libraries(LLVMExecutionEngine PUBLIC LLVMRuntimeDyld)
endif()

if( LLVM_USE_INTEL_JITEVENTS )
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/IntelJITProfiling")
  add_subdirectory(IntelJITProfiling)
endif()
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/IntelJITEvents")
  add_subdirectory(IntelJITEvents)
endif()
endif( LLVM_USE_INTEL_JITEVENTS )

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/Interpreter")
  add_subdirectory(Interpreter)
endif()
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/JITLink")
  add_subdirectory(JITLink)
endif()
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/MCJIT")
  add_subdirectory(MCJIT)
endif()
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/Orc")
  add_subdirectory(Orc)
endif()
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/RuntimeDyld")
  add_subdirectory(RuntimeDyld)
endif()

if( LLVM_USE_OPROFILE )
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/OProfileJIT")
  add_subdirectory(OProfileJIT)
endif()
endif( LLVM_USE_OPROFILE )

if( LLVM_USE_PERF )
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/PerfJITEvents")
  add_subdirectory(PerfJITEvents)
endif()
endif( LLVM_USE_PERF )
