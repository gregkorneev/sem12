# Часть 2: выбор алгоритма для конкретной системы

cmake_minimum_required(VERSION 3.10)

project(algorithm_selector_proj LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(algorithm_selector
    src/main.cpp
)

target_include_directories(algorithm_selector PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
