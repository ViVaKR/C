cmake_minimum_required(VERSION 3.30.4)
project(DemoC VERSION 0.1.0 LANGUAGES C)

include(CTest)
enable_testing()

add_executable(DemoC main.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
