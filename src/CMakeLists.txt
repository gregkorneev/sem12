# Часть 1: игра с Greedy DFS

add_executable(game_ai
    main.cpp
    ai.cpp
    game.cpp
    greedy_dfs.cpp
)

target_include_directories(game_ai PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)
