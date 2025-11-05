# Discover the tools that use CMake in the subdirectories.
# Note that explicit cmake invocation is required every time a new tool
# is added or removed.
file(GLOB entries *)
foreach(entry ${entries})
  if(IS_DIRECTORY ${entry} AND EXISTS ${entry}/CMakeLists.txt)
if(EXISTS  "${CMAKE_CURRENT_SOURCE_DIR}/${entry}")
  add_subdirectory(${entry})
endif()
  endif()
endforeach(entry)
