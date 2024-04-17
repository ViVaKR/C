cmake_minimum_required(VERSION 3.1...3.29.2)
project(
    Algorithm
    VERSION 1.0
    LANGUAGES C)

set(CMAKE_C_STANDARD 23)

add_executable(Algorithm main.c)
set(EXECUTABLE_OUTPUT_PATH "bin")

# 실행파일 경로
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

set_target_properties(Algorithm
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin"
)
