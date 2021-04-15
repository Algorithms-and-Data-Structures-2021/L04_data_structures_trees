#include <iostream>  // cout

#include "binary_search_tree.hpp"
#include "traversal_algorithm.hpp"

using namespace itis;

int main(int argc, char** argv) {

  BinarySearchTree tree;

  /**
   *             8
   *        3       10
   *    1     6        14
   * x   x  4   7    13   x
   *
   * x - это nullptr
   */

  tree.Insert(8);
  tree.Insert(3);
  tree.Insert(10);
  tree.Insert(1);
  tree.Insert(6);
  tree.Insert(4);
  tree.Insert(7);
  tree.Insert(14);
  tree.Insert(13);

  //  tree.Remove(4);
  //  tree.Remove(7);
  //  tree.Remove(14);  // <-- not working
  //  tree.Remove(6);   // <-- not working
  //  tree.Remove(8);   // <-- not working

  // обход узлов дерева в порядке неубывания ключей
  TraversalAlgorithm* algorithm = new InOrderTraversalAlgorithm;

  std::cout << "In-order (LNR):    ";
  tree.Traverse(*algorithm);
  std::cout << std::endl;

  algorithm = new PreOrderTraversalAlgorithm;

  std::cout << "Pre-order (NLR):   ";
  tree.Traverse(*algorithm);
  std::cout << std::endl;

  algorithm = new PostOrderTraversalAlgorithm;

  std::cout << "Post-order (LRN):  ";
  tree.Traverse(*algorithm);
  std::cout << std::endl;

  algorithm = new BreadthFirstTraversalAlgorithm;
  
  std::cout << "Level-order (BFS): ";
  tree.Traverse(*algorithm);
  std::cout << std::endl;

  delete algorithm;

  return 0;
}
