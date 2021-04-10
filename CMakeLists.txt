cmake_minimum_required(VERSION 3.5)

project(data_structures_trees)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(bst_tree STATIC
        src/node.cpp include/node.hpp
        src/traversal_algorithm.cpp include/traversal_algorithm.hpp
        src/binary_search_tree.cpp include/binary_search_tree.hpp)

target_include_directories(bst_tree PUBLIC include)

# add executables
add_executable(main main.cpp)
target_link_libraries(main PRIVATE bst_tree)