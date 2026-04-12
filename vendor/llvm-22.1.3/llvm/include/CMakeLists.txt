if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/llvm")
  add_subdirectory(llvm)
endif()

# If we're doing an out-of-tree build, copy a module map for generated
# header files into the build area.
if (NOT "${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
  configure_file(module.modulemap.build module.modulemap COPYONLY)
endif (NOT "${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
