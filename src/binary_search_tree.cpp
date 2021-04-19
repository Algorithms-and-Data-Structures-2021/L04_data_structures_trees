#include "binary_search_tree.hpp"

#include <iostream>  // cout
#include <cassert>   // assert

namespace itis {

  BinarySearchTree::~BinarySearchTree() {
    Clear();
  }

  void BinarySearchTree::Clear() {
    clear(root_);
    root_ = nullptr;
  }

  void BinarySearchTree::clear(Node *node) {
    if (node != nullptr) {
      clear(node->left);
      clear(node->right);
      delete node;
    }
  }

  void BinarySearchTree::Insert(int key) {
    if (root_ != nullptr) {
      insert(key, root_);
    } else {
      root_ = new Node(key);
    }
  }

  void BinarySearchTree::insert(int key, Node *node) {
    auto &insert_node = key < node->key ? node->left : node->right;

    if (insert_node != nullptr) {
      insert(key, insert_node);
    } else {
      insert_node = new Node(key);
    }
  }

  Node *BinarySearchTree::Search(int key) const {
    return search(key, root_);
  }

  Node *BinarySearchTree::search(int key, Node *node) const {
    if (node != nullptr) {

      if (key == node->key) {
        return node;  // узел найден, возвращаем его!
      }

      if (key < node->key) {
        // search in left sub-tree
        return search(key, node->left);
      }

      // search in right sub-tree
      return search(key, node->right);
    }

    return nullptr;  // not found :(
  }

  void BinarySearchTree::Remove(int key) {
    remove(key, root_);
  }

  Node *BinarySearchTree::remove(int key, Node *node) {
    // Примечение: найдите ошибки в реализации и исправьте их.

    if (node == nullptr) {
      return nullptr;
    }

    if (key < node->key) {
      // recursively remove from the left sub-tree
      node->left = remove(key, node->left);

    } else if (key > node->key) {
      // recursively remove from the right sub-tree
      node->right = remove(key, node->right);

    } else {  // found the node to remove!

      if (node->left == nullptr) {

        // case 1: node with a right child or no children

        Node *right_node = node->right;
        delete node;
        return right_node;
      }

      if (node->right == nullptr) {

        // case 2: node with a left child

        Node *left_child = node->left;
        delete node;
        return left_child;
      }

      // case 3: there are 2 children

      Node *min_node = findMin(node->right);  // the leftmost node in the right sub-tree

      node->key = min_node->key;

      // recursively remove the node with a min key
      node->right = remove(min_node->key, node->right);
    }

    return node;
  }

  Node *BinarySearchTree::findMin(Node *node) {
    Node *min_node = node;

    while (min_node->left != nullptr) {
      min_node = min_node->left;
    }

    return min_node;
  }

  int BinarySearchTree::height() const {
    return height(root_);
  }

  int BinarySearchTree::size() const {
    return static_cast<int>(std::pow(2, height()) - 1);
  }

  int BinarySearchTree::height(Node *node) const {
    if (node == nullptr) {
      return 0;
    }

    const int left_height = height(node->left);
    const int right_height = height(node->right);

    return std::max(left_height, right_height) + 1;
  }

  Node *BinarySearchTree::root() const {
    return root_;
  }

  void BinarySearchTree::Traverse(const TraversalAlgorithm &algorithm) const {
    algorithm.Print(std::cout, root_);
  }

}  // namespace itis
