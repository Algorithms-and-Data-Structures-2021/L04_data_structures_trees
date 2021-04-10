#pragma once

#include <string>

#include "node.hpp"

namespace itis {

struct TraversalAlgorithm;

struct BinarySearchTree final {
  ~BinarySearchTree();
  void Clear();

  void Insert(const std::string &key);
  Node *Search(const std::string &key) const;

  void Traverse(TraversalAlgorithm& algorithm) const;

  Node* root() const;

private:
  Node *root_{nullptr};

private:
  void clear(Node *node);
  void insert(const std::string &key, Node *node);
  Node *search(const std::string &key, Node *node) const;
};

} // namespace itis