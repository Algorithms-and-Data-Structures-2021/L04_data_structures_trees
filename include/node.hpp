#pragma once

#include <string>

namespace itis {

struct Node {
  std::string key;

  Node *left;
  Node *right;

  Node(const std::string &key, Node *left, Node *right)
      : key{key}, left{left}, right{right} {}
};

/**
 * IsRoot
 * IsLeaf
 * degree (
 * parent
 * children
 * insert(Node* parent)
 * size - number of nodes in a tree
 */

} // namespace itis