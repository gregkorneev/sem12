cmake_minimum_required(VERSION 3.10)

project(GameAI LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Папка с заголовками
include_directories(${CMAKE_SOURCE_DIR}/include)

# Наши исходники (только .cpp из src)
set(SOURCES
    src/main.cpp
    src/game.cpp
    src/greedy_dfs.cpp
    src/ai.cpp
)

add_executable(game_ai ${SOURCES})
