# First, add the subdirectories which contain feature-based runtime libraries
# and several convenience helper libraries.

include(AddCompilerRT)
include(SanitizerUtils)

# Hoist the building of sanitizer_common on whether we're building either the
# sanitizers or xray (or both).
#
#TODO: Refactor sanitizer_common into smaller pieces (e.g. flag parsing, utils).
if (COMPILER_RT_HAS_SANITIZER_COMMON AND
    (COMPILER_RT_BUILD_SANITIZERS OR COMPILER_RT_BUILD_XRAY OR COMPILER_RT_BUILD_MEMPROF OR COMPILER_RT_BUILD_CTX_PROFILE))
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/sanitizer_common")
  add_subdirectory(sanitizer_common)
endif()
endif()

if(COMPILER_RT_BUILD_BUILTINS)
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/builtins")
  add_subdirectory(builtins)
endif()
endif()

function(compiler_rt_build_runtime runtime)
  string(TOUPPER ${runtime} runtime_uppercase)
  if(COMPILER_RT_HAS_${runtime_uppercase})
    if(${runtime} STREQUAL tsan)
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tsan/dd")
  add_subdirectory(tsan/dd)
endif()
    endif()
    if(${runtime} STREQUAL scudo_standalone)
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/scudo/standalone")
  add_subdirectory(scudo/standalone)
endif()
    else()
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${runtime}")
  add_subdirectory(${runtime})
endif()
    endif()
  endif()
endfunction()

if(COMPILER_RT_BUILD_SANITIZERS OR COMPILER_RT_BUILD_MEMPROF)
  compiler_rt_build_runtime(interception)
endif()

if(COMPILER_RT_BUILD_SANITIZERS)
  if(COMPILER_RT_HAS_SANITIZER_COMMON)
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/stats")
  add_subdirectory(stats)
endif()
    # Contains RTLSanCommon used even without COMPILER_RT_HAS_LSAN.
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/lsan")
  add_subdirectory(lsan)
endif()
    # Contains RTUbsan used even without COMPILER_RT_HAS_UBSAN.
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/ubsan")
  add_subdirectory(ubsan)
endif()
  endif()

  foreach(sanitizer ${COMPILER_RT_SANITIZERS_TO_BUILD})
    compiler_rt_build_runtime(${sanitizer})
  endforeach()
endif()

if(COMPILER_RT_BUILD_PROFILE)
  compiler_rt_build_runtime(profile)
endif()

if(COMPILER_RT_BUILD_CTX_PROFILE)
  compiler_rt_build_runtime(ctx_profile)
endif()

if(COMPILER_RT_BUILD_XRAY)
  compiler_rt_build_runtime(xray)
endif()

if(COMPILER_RT_BUILD_LIBFUZZER)
  compiler_rt_build_runtime(fuzzer)
endif()

if(COMPILER_RT_BUILD_MEMPROF AND COMPILER_RT_HAS_SANITIZER_COMMON)
  compiler_rt_build_runtime(memprof)
endif()

if(COMPILER_RT_BUILD_ORC)
  compiler_rt_build_runtime(orc)
endif()

# It doesn't normally make sense to build runtimes when a sanitizer is enabled,
# so we don't add_subdirectory the runtimes in that case. However, the opposite
# is true for fuzzers that exercise parts of the runtime. So we add the fuzzer
# directories explicitly here.
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/scudo/standalone/fuzz")
  add_subdirectory(scudo/standalone/fuzz)
endif()
