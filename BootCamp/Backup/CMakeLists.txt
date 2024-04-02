# CMake 최소버전
cmake_minimum_required(VERSION 3.16...3.29)

project(
ViVaKR
VERSION 1.0
DESCRIPTION "C Boot Camp"
HOMEPAGE_URL "%%https://www.vivakr.com"
LANGUAGES C CXX)

add_executable(ViVaKR main.c)

set(CMAKE_BUILD_TYPE Debug)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
message(STATUS "Compiler")
message(STATUS " - ID       \t: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS " - Version  \t: ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS " - Path     \t: ${CMAKE_CXX_COMPILER}")

include(CPack)
