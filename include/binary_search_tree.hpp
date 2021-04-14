#pragma once

#include <iostream>  // cout

#include "node.hpp"
#include "traversal_algorithm.hpp"

namespace itis {

  struct BinarySearchTree final {
    void Clear();
    void Insert(int key);
    void Remove(int key);
    Node *Search(int key) const;

    void Traverse(const TraversalAlgorithm &algorithm) const;

    ~BinarySearchTree();

   private:
    Node *root_{nullptr};

    void clear(Node *node);
    void insert(int key, Node *node);
    void remove(int key, Node *node);
    Node *search(int key, Node *node) const;

    Node *findMin(Node *node) const;
  };

}  // namespace itis