cmake_minimum_required(VERSION 3.15)

project(data_structures_trees)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# header-only library
add_library(bst_tree STATIC
        include/node.hpp src/node.cpp
        include/binary_search_tree.hpp
        include/traversal_algorithm.hpp src/traversal_algorithm.cpp)

target_include_directories(bst_tree PUBLIC include)

# add executables
add_executable(main main.cpp)
target_link_libraries(main PRIVATE bst_tree)