cmake_minimum_required(VERSION 3.29.3)

project(
ViVaKR
VERSION 1.0
DESCRIPTION "C Boot Camp"
HOMEPAGE_URL "%%https://www.vivakr.com"
LANGUAGES C)

file(GLOB_RECURSE SOURCES
    "src/*.c"
    "src/*.h")

add_executable(ViVaKR
    main.c
    ${SOURCES}
    )

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set_target_properties(ViVaKR
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
set_property(TARGET ViVaKR PROPERTY C_STANDARD 17)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

set(CMAKE_BUILD_TYPE Debug)

message(STATUS "Compiler")
message(STATUS " - ID       \t: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS " - Version  \t: ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS " - Path     \t: ${CMAKE_CXX_COMPILER}")

message("${CMAKE_C_COMPILER_ID}")
message("${CMAKE_C_COMPILER_VERSION}")
message("${CMAKE_C_COMPILER}")

include(CPack)
