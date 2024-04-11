cmake_minimum_required(VERSION 3.29.1)
project(GraphTraversal VERSION 0.1.0 LANGUAGES C)

include(CTest)
enable_testing()

add_executable(HashTable main.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
