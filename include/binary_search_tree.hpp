#pragma once

#include <iostream>

#include "node.hpp"
#include "traversal_algorithm.hpp"

namespace itis {

  template<typename T = int>
  struct BinarySearchTree final {
    void Clear();
    void Insert(const T &key);
    void Remove(const T &key);
    Node<T> *Search(const T &key) const;
    void Traverse(TraversalAlgorithm<T> &algorithm) const;

    ~BinarySearchTree();

   private:
    Node<T> *root_{nullptr};

    void clear(Node<T> *node);
    void insert(const T &key, Node<T> *node);
    Node<T> *remove(const T &key, Node<T> *node);
    Node<T> *search(const T &key, Node<T> *node) const;

    Node<T> *findMin(Node<T> *node) const;
  };

  template<typename T>
  BinarySearchTree<T>::~BinarySearchTree() {
    Clear();
  }

  template<typename T>
  void BinarySearchTree<T>::Insert(const T &key) {
    if (root_ != nullptr) {
      insert(key, root_);
    } else {
      root_ = new Node<T>(key);
    }
  }

  template<typename T>
  void BinarySearchTree<T>::insert(const T &key, Node<T> *node) {
    // Task 1: перепишите рекурсивную реализацию в итеративную
    auto &insert_node = key < node->key ? node->left : node->right;

    if (insert_node != nullptr) {
      insert(key, insert_node);
    } else {
      insert_node = new Node<T>(key);
    }
  }

  template<typename T>
  Node<T> *BinarySearchTree<T>::Search(const T &key) const {
    return search(key, root_);
  }

  template<typename T>
  Node<T> *BinarySearchTree<T>::search(const T &key, Node<T> *node) const {
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

  template<typename T>
  void BinarySearchTree<T>::Clear() {
    clear(root_);
    root_ = nullptr;
  }

  template<typename T>
  void BinarySearchTree<T>::clear(Node<T> *node) {
    if (node != nullptr) {
      clear(node->left);
      clear(node->right);
      delete node;
    }
  }

  template<typename T>
  void BinarySearchTree<T>::Remove(const T &key) {
    remove(key, root_);
  }

  template<typename T>
  Node<T> *BinarySearchTree<T>::remove(const T &key, Node<T> *node) {
    if (node == nullptr) {
      return nullptr;
    }

    if (key < node->key) {
      node->left = remove(key, node->left);
    } else if (key > node->key) {
      node->right = remove(key, node->right);
    } else if (node->degree() == 2) {
      Node<T> *tmp = findMin(node->right);
      node->key = tmp->key;
      node->right = remove(node->key, node->right);
    } else {
      Node<T> *tmp = node;

      if (node->left == nullptr) {
        node = node->right;
      } else {
        node = node->left;
      }
      delete tmp;
    }

    return node;
  }

  template<typename T>
  Node<T> *BinarySearchTree<T>::findMin(Node<T> *node) const {
    if (node == nullptr) {
      return nullptr;
    }

    // there is no min element in the right sub-tree
    if (node->left == nullptr) {
      return node;
    }

    return findMin(node->left);
  }

  template<typename T>
  void BinarySearchTree<T>::Traverse(TraversalAlgorithm<T> &algorithm) const {
    algorithm.Print(std::cout, root_);
  }

}  // namespace itis