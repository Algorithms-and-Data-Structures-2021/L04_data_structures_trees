cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

project(BSTree
        DESCRIPTION "Binary Search Tree (BST) implementation"
        LANGUAGES CXX
        VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# library
add_library(${PROJECT_NAME} STATIC
        include/node.hpp src/node.cpp
        include/binary_search_tree.hpp src/binary_search_tree.cpp
        include/traversal_algorithm.hpp src/traversal_algorithm.cpp)

add_library(BSTree::BSTree ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC include)

# add executables
add_executable(main main.cpp)
target_link_libraries(main PRIVATE ${PROJECT_NAME})