#pragma once

#include <string>

#include "node.hpp"

namespace itis {

struct BinaryTree final {
  BinaryTree() = default;

  ~BinaryTree() { Clear(); }

  void Insert(const std::string &key) {
    if (root_ != nullptr) {
      insert(key, root_);
    } else {
      root_ = new Node(key, nullptr, nullptr);
    }
  }

  Node *Search(const std::string &key) const {
    return search(key, root_);
  }

  void Clear() {
    clear(root_);
    root_ = nullptr;
  }

private:
  Node *root_{nullptr};

private:
  void clear(Node *node) {

    if (node != nullptr) {
      clear(node->left);
      clear(node->right);
      delete node;
    }
  }

  void insert(const std::string &key, Node *node) {
    if (key < node->key) {

      if (node->left != nullptr) {
        insert(key, node->left);
      } else {
        node->left = new Node(key, nullptr, nullptr);
      }

    } else {

      if (node->right != nullptr) {
        insert(key, node->right);
      } else {
        node->right = new Node(key, nullptr, nullptr);
      }
    }
  }

  Node *search(const std::string &key, Node *node) const {
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
};

} // namespace itis