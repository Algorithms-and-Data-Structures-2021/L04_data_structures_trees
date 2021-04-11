#pragma once

#include <string>

namespace itis {

struct Node {
  std::string key;

  Node *left;
  Node *right;

  Node(const std::string &key, Node *l, Node *r)
      : key{key}, left{l}, right{r} {}

  bool IsLeaf() const {
    return left == nullptr && right == nullptr;
  }

  int degree() const {
    if (left == nullptr && right == nullptr) return 0;
    if (left != nullptr && right != nullptr) return 2;
    return 1;
  }
};

} // namespace itis