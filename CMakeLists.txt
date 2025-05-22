cmake_minimum_required(VERSION 3.10)

project(c_unleashed_cd C)

set(CMAKE_C_STANDARD 23)


set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

# --  Set default build type depending on the build directory  --
message(STATUS "")
if (NOT CMAKE_BUILD_TYPE)
    if ("${CMAKE_BINARY_DIR}" MATCHES ".*(D|d)ebug$")
        set(CMAKE_BUILD_TYPE "Debug")
    else()
        # Add debug symbols (required 4 `perf`) 2 Release build
        #   ( NOTE: other types (SEE: https://stackoverflow.com/a/59314670):
        #             - `Debug` (`-O0 -g`), `MinSizeRel` (`-Os -DNDEBUG`),
        #             - `Release` (`-O3 -DNDEBUG`), `RelWithDebInfo` (`-O2 -g -DNDEBUG`)
        set(CMAKE_BUILD_TYPE "RelWithDebInfo")
    endif()
    message(STATUS "No build type selected, defaulting to ** ${CMAKE_BUILD_TYPE} **")
endif()
message(STATUS "Build type            : ${CMAKE_BUILD_TYPE}")
message(STATUS "")

# --  Ninja: Colorize output  --
#   ( DERIVED FROM: https://medium.com/@alasher/colored-c-compiler-output-with-ninja-clang-gcc-10bfe7f2b949 )
option(FORCE_COLORED_OUTPUT "Always produce ANSI-colored output" TRUE)
if (${FORCE_COLORED_OUTPUT})
    if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
       add_compile_options(-fdiagnostics-color=always)
    elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
       add_compile_options(-fcolor-diagnostics)
    else()
        message(STATUS "`FORCE_COLORED_OUTPUT`: Unsupported compiler")
    endif ()
endif ()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


add_subdirectory(ch02/)
add_subdirectory(ch03/)
add_subdirectory(ch04/)
# NOTE: ch05 is N/A
add_subdirectory(ch06/)
add_subdirectory(ch07/)
add_subdirectory(ch08/)
add_subdirectory(ch09/)
add_subdirectory(ch10/)
add_subdirectory(ch11/)
add_subdirectory(ch12/)
# TODO: ch13
add_subdirectory(ch14/)
# TODO: ch15
# TODO: ch16
add_subdirectory(ch17/)
add_subdirectory(ch18/)
add_subdirectory(ch19/)
add_subdirectory(ch20/)
add_subdirectory(ch21/)
add_subdirectory(ch22/)
add_subdirectory(ch23/)
# TODO: ch24
# NOTE: ch25 is empty
add_subdirectory(ch26/)
add_subdirectory(Bonus/)
