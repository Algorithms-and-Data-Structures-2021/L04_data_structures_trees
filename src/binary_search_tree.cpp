#include "binary_search_tree.hpp"

#include <iostream> // cout

#include "traversal_algorithm.hpp"

namespace itis {

BinarySearchTree::~BinarySearchTree() {
  Clear();
}

void BinarySearchTree::Insert(const std::string &key) {
  if (root_ != nullptr) {
    insert(key, root_);
  } else {
    root_ = new Node(key, nullptr, nullptr);
  }
}

Node *BinarySearchTree::Search(const std::string &key) const {
  return search(key, root_);
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

void BinarySearchTree::insert(const std::string &key, Node *node) {
  if (key < node->key) {

    if (node->left != nullptr) {
      insert(key, node->left);
    } else {
      node->left = new Node(key, nullptr, nullptr);
    }

  } else {  // key >= node->key

    if (node->right != nullptr) {
      insert(key, node->right);
    } else {
      node->right = new Node(key, nullptr, nullptr);
    }
  }
}

Node *BinarySearchTree::search(const std::string &key, Node *node) const {
  if (node != nullptr) {
    if (key == node->key) {
      return node;
    }
    if (key < node->key) {
      return search(key, node->left);
    }

    return search(key, node->right);
  }
  return nullptr;
}

Node *findMin(Node* node) {
  if (node == nullptr) return nullptr;
  if (node->left == nullptr) return node;
  return findMin(node->left);
}

Node *findMax(Node* node) {
  if (node == nullptr) return nullptr;
  if (node->right == nullptr) return node;
  return findMax(node->right);
}

Node *BinarySearchTree::remove(const std::string& key, Node* node) {
  if (node == nullptr) return nullptr;

  if (key < node->key) {
    node->left = remove(key, node->left);
  } else if (key > node->key) {
    node->right = remove(key, node->right);
  } else if (node->degree() == 2) {
    Node* tmp = findMin(node->right);
    node->key = tmp->key;
    node->right = remove(node->key, node->right);
  } else {
    Node* tmp = node;
    if (node->left == nullptr) {
      node = node->right;
    } else {
      node = node->left;
    }
    delete tmp;
  }

  return node;
}

void BinarySearchTree::Traverse(TraversalAlgorithm &algorithm) const {
  algorithm.Print(std::cout, root_);
}

} // namespace itis