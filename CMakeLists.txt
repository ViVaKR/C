cmake_minimum_required(VERSION 3.16...3.23)
project(
VivCProject
VERSION 0.0.1
DESCRIPTION ""
HOMEPAGE_URL "%%https://www.vivabm.com%%"
LANGUAGES CXX C)

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
