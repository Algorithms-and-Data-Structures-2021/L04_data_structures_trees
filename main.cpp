#include <iostream>

#include "binary_search_tree.hpp"

using namespace itis;

int main(int argc, char **argv) {

  BinaryTree tree;

  tree.Clear();

  tree.Insert("3");

  tree.Insert("1");

  tree.Insert("4");

  Node* found_node = tree.Search("1");
  found_node = tree.Search("6");

  tree.Clear();

  return 0;
}