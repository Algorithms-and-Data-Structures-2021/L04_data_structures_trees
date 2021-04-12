#pragma once

#include <ostream>
#include <queue>
#include <stack>

#include "node.hpp"

namespace itis {

  template<typename T>
  struct TraversalAlgorithm {
    virtual ~TraversalAlgorithm() = default;
    virtual void Print(std::ostream &os, Node<T> *node) = 0;
  };

  template<typename T>
  struct InOrderTraversalAlgorithm final : TraversalAlgorithm<T> {
    void Print(std::ostream &os, Node<T> *node) override;
  };

  template<typename T>
  struct PreOrderTraversalAlgorithm final : TraversalAlgorithm<T> {
    void Print(std::ostream &os, Node<T> *node) override;
  };

  template<typename T>
  struct PostOrderTraversalAlgorithm final : TraversalAlgorithm<T> {
    void Print(std::ostream &os, Node<T> *node) override;
  };

  // Level order traversal
  template<typename T>
  struct BreadthFirstTraversalAlgorithm final : TraversalAlgorithm<T> {
    void Print(std::ostream &os, Node<T> *node) override;
  };

  template<typename T>
  struct DepthFirstTraversalAlgorithm final : TraversalAlgorithm<T> {
    void Print(std::ostream &os, Node<T> *node) override;
  };

  // definition

  template<typename T>
  void InOrderTraversalAlgorithm<T>::Print(std::ostream &os, Node<T> *node) {
    if (node != nullptr) {
      Print(os, node->left);
      os << node->key << '\t';
      Print(os, node->right);
    }
  }

  template<typename T>
  void PreOrderTraversalAlgorithm<T>::Print(std::ostream &os, Node<T> *node) {
    if (node != nullptr) {
      os << node->key << '\t';
      Print(os, node->left);
      Print(os, node->right);
    }
  }

  template<typename T>
  void PostOrderTraversalAlgorithm<T>::Print(std::ostream &os, Node<T> *node) {
    if (node != nullptr) {
      Print(os, node->left);
      Print(os, node->right);
      os << node->key << '\t';
    }
  }

  template<typename T>
  void BreadthFirstTraversalAlgorithm<T>::Print(std::ostream &os, Node<T> *node) {
    std::queue<Node<T> *> nodes_queue;
    nodes_queue.push(node);

    while (!nodes_queue.empty()) {
      const auto curr_node = nodes_queue.front();
      nodes_queue.pop();

      os << curr_node->key << '\t';

      if (curr_node->left != nullptr) {
        nodes_queue.push(curr_node->left);
      }

      if (curr_node->right != nullptr) {
        nodes_queue.push(curr_node->right);
      }
    }
  }

  template<typename T>
  void DepthFirstTraversalAlgorithm<T>::Print(std::ostream &os, Node<T> *node) {
    if (node == nullptr) {
      return;
    }

    std::stack<Node<T> *> nodes_stack;
    nodes_stack.push(node);

    while (!nodes_stack.empty()) {
      Node<T> *curr_node = nodes_stack.top();
      nodes_stack.pop();

      os << curr_node->key << '\t';

      if (curr_node->right != nullptr) {
        nodes_stack.push(curr_node->right);
      }

      if (curr_node->left != nullptr) {
        nodes_stack.push(curr_node->left);
      }
    }
  }

}  // namespace itis