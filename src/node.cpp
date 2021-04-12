#include "node.hpp"

namespace itis {

  Node::Node(int key) : key{key} {}

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