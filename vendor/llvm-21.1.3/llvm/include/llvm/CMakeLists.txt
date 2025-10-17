# Use LLVM_HEADERS for each `tablegen(LLVM)` in subdirectories
# LLVM_HEADERS_TABLEGEN points to `llvm-min-tblgen`
set(LLVM_TABLEGEN_PROJECT LLVM_HEADERS)

if(EXISTS  "${CMAKE_CURRENT_SOURCE_DIR}/CodeGen")
  add_subdirectory(CodeGen)
endif()
if(EXISTS  "${CMAKE_CURRENT_SOURCE_DIR}/IR")
  add_subdirectory(IR)
endif()
if(EXISTS  "${CMAKE_CURRENT_SOURCE_DIR}/Support")
  add_subdirectory(Support)
endif()
if(EXISTS  "${CMAKE_CURRENT_SOURCE_DIR}/Frontend")
  add_subdirectory(Frontend)
endif()
if(EXISTS  "${CMAKE_CURRENT_SOURCE_DIR}/TargetParser")
  add_subdirectory(TargetParser)
endif()
