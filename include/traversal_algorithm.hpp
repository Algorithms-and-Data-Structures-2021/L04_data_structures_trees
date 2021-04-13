#pragma once

#include <ostream>

#include "node.hpp"

namespace itis {

  struct TraversalAlgorithm {
    virtual ~TraversalAlgorithm() = default;
    virtual void Print(std::ostream &os, Node *node) const  = 0;
  };

  struct InOrderTraversalAlgorithm final : TraversalAlgorithm {
    void Print(std::ostream &os, Node *node) const override;
  };

  struct PreOrderTraversalAlgorithm final : TraversalAlgorithm {
    void Print(std::ostream &os, Node *node) const override;
  };

  struct PostOrderTraversalAlgorithm final : TraversalAlgorithm {
    void Print(std::ostream &os, Node *node) const override;
  };

  // Level order traversal
  struct BreadthFirstTraversalAlgorithm final : TraversalAlgorithm {
    void Print(std::ostream &os, Node *node) const override;
  };

  // In-order, Pre-order, Post-order based on stack (non-recursive)
  struct DepthFirstTraversalAlgorithm final : TraversalAlgorithm {
    void Print(std::ostream &os, Node *node) const override;
  };

}  // namespace itis