cmake_minimum_required(VERSION 3.10)

project(sem12 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Часть 1: ИИ для игры (Greedy DFS)
add_subdirectory(src)

# Часть 2: выбор алгоритма для конкретной системы
add_subdirectory(part2)
add_custom_target(copy_docs ALL
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/docs
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${CMAKE_SOURCE_DIR}/docs/greedy_dfs_visualization.html
            ${CMAKE_BINARY_DIR}/docs/greedy_dfs_visualization.html
)
