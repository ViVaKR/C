cmake_minimum_required(VERSION 3.20.0)
project(VivCProject)

include(CTest)
enable_testing()

add_executable(VivCProject 
main.c
)

set(CMAKE_CXX_COMPILER /usr/local/bin/g++-12)
set(CMAKE_BUILD_TYPE Debug)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
