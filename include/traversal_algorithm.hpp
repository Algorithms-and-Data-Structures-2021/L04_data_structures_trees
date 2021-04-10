#pragma once

#include <ostream>

#include "node.hpp"

namespace itis {

struct TraversalAlgorithm {
  virtual ~TraversalAlgorithm() = default;
  virtual void Print(std::ostream &os, Node *node) = 0;
};

struct InOrderTraversalAlgorithm final : TraversalAlgorithm {
  void Print(std::ostream &os, Node *node) override;
};

struct PreOrderTraversalAlgorithm final : TraversalAlgorithm {
  void Print(std::ostream &os, Node *node) override;
};

struct PostOrderTraversalAlgorithm final : TraversalAlgorithm {
  void Print(std::ostream &os, Node *node) override;
};

// Level order traversal
struct BreadthFirstTraversalAlgorithm final : TraversalAlgorithm {
  void Print(std::ostream &os, Node *node) override;
};

struct DepthFirstTraversalAlgorithm final : TraversalAlgorithm {
  void Print(std::ostream &os, Node *node) override;
};

} // namespace itis