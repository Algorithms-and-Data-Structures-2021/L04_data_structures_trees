#include "binary_search_tree.hpp"

namespace itis {

  BinarySearchTree::~BinarySearchTree() {
    Clear();
  }

  void BinarySearchTree::Insert(int key) {
    if (root_ != nullptr) {
      insert(key, root_);
    } else {
      root_ = new Node(key);
    }
  }

  void BinarySearchTree::insert(int key, Node *node) {
    // Task 1: перепишите рекурсивную реализацию в итеративную
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
    // Task 2: перепишите рекурсивную реализацию в итеративную
    if (node != nullptr) {

      if (key == node->key) {
        return node;
      }

      if (key < node->key) {
        // search in left sub-tree
        return search(key, node->left);
      }

      // search in right sub-tree
      return search(key, node->right);
    }

    return nullptr;  // not found
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

  void BinarySearchTree::Remove(int key) {
    remove(key, root_);
  }

  Node *BinarySearchTree::remove(int key, Node *node) {
    if (node == nullptr) {
      return nullptr;
    }

    if (key < node->key) {
      node->left = remove(key, node->left);
    } else if (key > node->key) {
      node->right = remove(key, node->right);
    } else if (node->degree() == 2) {
      Node *tmp = findMin(node->right);
      node->key = tmp->key;
      node->right = remove(node->key, node->right);
    } else {
      Node *tmp = node;

      if (node->left == nullptr) {
        node = node->right;
      } else {
        node = node->left;
      }
      delete tmp;
    }

    return node;
  }

  Node *BinarySearchTree::findMin(Node *node) const {
    if (node == nullptr) {
      return nullptr;
    }

    // there is no min element in the right sub-tree
    if (node->left == nullptr) {
      return node;
    }

    return findMin(node->left);
  }

  void BinarySearchTree::Traverse(const TraversalAlgorithm &algorithm) const {
    algorithm.Print(std::cout, root_);
  }

}  // namespace itis