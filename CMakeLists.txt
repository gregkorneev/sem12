cmake_minimum_required(VERSION 3.10)

project(GameAI LANGUAGES CXX)

# Используем C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Наши исходники
set(SOURCES
    main.cpp
    game.cpp
    greedy_dfs.cpp
    ai.cpp
)

add_executable(game_ai ${SOURCES})
