#include "binary_search_tree.hpp"
#include "traversal_algorithm.hpp"

using namespace itis;

int main(int argc, char **argv) {

  BinarySearchTree tree;

  tree.Insert(50);
  tree.Insert(30);
  tree.Insert(70);
  tree.Insert(20);
  tree.Insert(40);
  tree.Insert(60);
  tree.Insert(80);

//  tree.Remove(20);
//  tree.Remove(30);
//  tree.Remove(50);

  BreadthFirstTraversalAlgorithm algorithm;
  tree.Traverse(algorithm);

  // Tasks
  // 1. Даны два дерева t1 и t2. Получить список общих ключей двух деревьев.
  // 2. Переписать реализацию BST-дерева, чтобы оно хранило пару (key: int, value: string).

  return 0;
}