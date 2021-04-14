#include "traversal_algorithm.hpp"

#include <queue>
#include <stack>

namespace itis {

  // L N R
  void InOrderTraversalAlgorithm::Print(std::ostream &os, Node *node) const {
    if (node != nullptr) {
      Print(os, node->left);
      os << node->key << '\t';
      Print(os, node->right);
    }
  }

  // N L R
  void PreOrderTraversalAlgorithm::Print(std::ostream &os, Node *node) const {
    if (node != nullptr) {
      os << node->key << '\t';
      Print(os, node->left);
      Print(os, node->right);
    }
  }

  // L R N
  void PostOrderTraversalAlgorithm::Print(std::ostream &os, Node *node) const {
    if (node != nullptr) {
      Print(os, node->left);
      Print(os, node->right);
      os << node->key << '\t';
    }
  }

  // from to to bottom, from left to right
  void BreadthFirstTraversalAlgorithm::Print(std::ostream &os, Node *node) const {
    std::queue<Node *> nodes_queue;
    nodes_queue.push(node);

    while (!nodes_queue.empty()) {
      const auto *curr_node = nodes_queue.front();
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

  // N L R on stack
  void DepthFirstTraversalAlgorithm::Print(std::ostream &os, Node *node) const {
    if (node == nullptr) {
      return;
    }

    std::stack<Node *> nodes_stack;
    nodes_stack.push(node);

    while (!nodes_stack.empty()) {
      Node *curr_node = nodes_stack.top();
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