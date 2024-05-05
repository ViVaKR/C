cmake_minimum_required(VERSION 3.29.2)
project(Demo VERSION 0.1.0 LANGUAGES C)

include(CTest)
enable_testing()

add_executable(Demo main.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
