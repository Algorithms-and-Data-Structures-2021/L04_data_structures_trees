#include "binary_search_tree.hpp"
#include "traversal_algorithm.hpp"

using namespace itis;

int main(int argc, char **argv) {

  BinarySearchTree<int> tree;

  tree.Insert(50);
  tree.Insert(30);
  tree.Insert(70);
  tree.Insert(20);
  tree.Insert(40);
  tree.Insert(60);
  tree.Insert(80);

  tree.Remove(20);
  tree.Remove(30);
  tree.Remove(50);

  BreadthFirstTraversalAlgorithm<int> algorithm;
  tree.Traverse(algorithm);

  return 0;
}