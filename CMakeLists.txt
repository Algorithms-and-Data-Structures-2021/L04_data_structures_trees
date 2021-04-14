cmake_minimum_required(VERSION 3.15)

project(binary_search_tree)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# library
add_library(bs_tree STATIC
        include/node.hpp src/node.cpp
        include/binary_search_tree.hpp src/binary_search_tree.cpp
        include/traversal_algorithm.hpp src/traversal_algorithm.cpp)

target_include_directories(bs_tree PUBLIC include)

# add executables
add_executable(main main.cpp)
target_link_libraries(main PRIVATE bs_tree)