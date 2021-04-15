#pragma once

#include <ostream>

#include "node.hpp"

namespace itis {

  // интерфейс алгоритма обхода узлов дерева
  struct TraversalAlgorithm {
    virtual ~TraversalAlgorithm() = default;
    
    /**
     * Вывод ключей дерева в порядке, задаваемом стратегией обхода.  
     * @param os - поток вывода 
     * @param node - узел дерева (например, корневой) 
     */
    virtual void Print(std::ostream &os, Node *node) const  = 0;
  };

  // инфиксный обход узлов дерева
  struct InOrderTraversalAlgorithm final : TraversalAlgorithm {
    void Print(std::ostream &os, Node *node) const override;
  };

  // префиксный обход узлов дерева
  struct PreOrderTraversalAlgorithm final : TraversalAlgorithm {
    void Print(std::ostream &os, Node *node) const override;
  };

  // постфиксный обход узлов дерева
  struct PostOrderTraversalAlgorithm final : TraversalAlgorithm {
    void Print(std::ostream &os, Node *node) const override;
  };

  // level order traversal (обход в ширину)
  struct BreadthFirstTraversalAlgorithm final : TraversalAlgorithm {
    void Print(std::ostream &os, Node *node) const override;
  };

  // обход в глубину на базе стека (итеративная реализация)
  struct DepthFirstTraversalAlgorithm final : TraversalAlgorithm {
    void Print(std::ostream &os, Node *node) const override;
  };

}  // namespace itis
