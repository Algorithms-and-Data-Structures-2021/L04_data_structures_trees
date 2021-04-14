#include <iostream>  // cout

#include "binary_search_tree.hpp"
#include "traversal_algorithm.hpp"

using namespace itis;

int main(int argc, char** argv) {

  BinarySearchTree tree;

  /**
   *         8
   *    3       10
   * 1     6        14
   *     4   7    13
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

//    tree.Remove(4);
  //  tree.Remove(7);
  //  tree.Remove(13);
  //  tree.Remove(14);
  //  tree.Remove(6);
  //  tree.Remove(8);

  // обход в порядке возрастания ключей
  TraversalAlgorithm* algorithm = new InOrderTraversalAlgorithm;
  tree.Traverse(*algorithm);
  std::cout << std::endl;

  algorithm = new PreOrderTraversalAlgorithm;
  tree.Traverse(*algorithm);
  std::cout << std::endl;

  algorithm = new PostOrderTraversalAlgorithm;
  tree.Traverse(*algorithm);
  std::cout << std::endl;

  algorithm = new BreadthFirstTraversalAlgorithm;
  tree.Traverse(*algorithm);
  std::cout << std::endl;


  delete algorithm;

  // Tasks
  // 1. Даны два дерева t1 и t2. Получить список общих ключей двух деревьев.                (0.5 pts)
  // 2. Переписать реализацию BST-дерева, чтобы оно хранило пару (key: int, value: string). (0.5 pts)
  // 3. Перепишите рекурсивные реализации поиска и добавления на итеративные.               (0.5 pts)
  // 4. Реализуйте до конца метод BinarySearchTree::Remove(key).                            (1 pt)

  return 0;
}