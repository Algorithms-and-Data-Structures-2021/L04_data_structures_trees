#include <iostream>

#include "binary_search_tree.hpp"
#include "traversal_algorithm.hpp"

using namespace itis;

int main(int argc, char **argv) {

  BinarySearchTree tree;

  tree.Insert("F");
  tree.Insert("B");
  tree.Insert("G");
  tree.Insert("A");
  tree.Insert("D");
  tree.Insert("C");
  tree.Insert("E");
  tree.Insert("I");
  tree.Insert("H");

  DepthFirstTraversalAlgorithm algorithm;
  tree.Traverse(algorithm);

  return 0;
}