cmake_minimum_required(VERSION 3.10)

project(sem12 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Часть 1: ИИ для игры (Greedy DFS)
add_subdirectory(src)

# Часть 2: выбор алгоритма для конкретной системы
add_subdirectory(part2)
