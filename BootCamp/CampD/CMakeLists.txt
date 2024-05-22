cmake_minimum_required(VERSION 3.29.3)

project(
CampD
VERSION 1.0
DESCRIPTION "C CampD"
HOMEPAGE_URL "%%https://www.vivakr.com"
LANGUAGES C)

file(GLOB_RECURSE SOURCES
    "src/*.c"
    "src/*.h")

add_executable(CampD
    CampD.c
    ${SOURCES}
)
# set(CMAKE_C_COMPILER /opt/homebrew/opt/llvm/bin/clang)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set_target_properties(CampD
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)

set_property(TARGET CampD PROPERTY C_STANDARD 17)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})


set(CMAKE_BUILD_TYPE Debug)

# message(STATUS " - ID       \t: ${CMAKE_CXX_COMPILER_ID}")
# message(STATUS " - Version  \t: ${CMAKE_CXX_COMPILER_VERSION}")
# message(STATUS " - Path     \t: ${CMAKE_CXX_COMPILER}")

# message("${CMAKE_C_COMPILER_ID}")
# message("${CMAKE_C_COMPILER_VERSION}")
message("${CMAKE_C_COMPILER}")

include(CPack)
