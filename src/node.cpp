#include "node.hpp"

namespace itis {

  Node::Node(int key, Node* p) : key{key}, parent_{p} {}

  int Node::degree() const {
    if (left == nullptr && right == nullptr) {
      return 0;
    }

    if (left != nullptr && right != nullptr) {
      return 2;
    }
    return 1;
  }

}  // namespace itis