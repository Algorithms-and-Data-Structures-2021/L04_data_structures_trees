#pragma once

#include <cmath>  // max

#include "node.hpp"
#include "traversal_algorithm.hpp"

namespace itis {

  struct BinarySearchTree final {
    /**
     * Добавление нового узла с ключом в дерево.
     * @param key - ключ нового узла
     */
    void Insert(int key);

    /**
     * Удаление узла дерева по ключу.
     * @param key - ключ удаляемого узла
     */
    void Remove(int key);

    /**
     * Поиск узла дерева по ключу.
     * @param key - ключ узла
     * @return
     */
    Node *Search(int key) const;

    /**
     * Очистка дерева с высвобождением памяти.
     */
    void Clear();

    /**
     * Вычисление высоты дерева.
     * @return неотрицательное значение высоты дерева
     */
    int height() const;

    /**
     * Вычисление кол-ва узлов в дереве (считая nullptr).
     * @return неотрицательное значение кол-ва узлов в дереве
     */
    int size() const;

    // обход дерева на базе указанного алгоритма
    void Traverse(const TraversalAlgorithm &algorithm) const;

    // эквивалетно методу BinarySearchTree::Clear()
    ~BinarySearchTree();

   private:
    // корень дерева
    Node *root_{nullptr};

    // вспомогательные методы
    void clear(Node *node);
    void insert(int key, Node *node);
    Node *remove(int key, Node *node);
    Node *search(int key, Node *node) const;
    int height(Node *node) const;

    /**
     * Поиск узла с минимальным значением ключа.
     * @param node - корневой узел поддерева
     * @return указатель на узел с минимальным значением ключа
     */
    Node *findMin(Node *node);
  };

}  // namespace itis
