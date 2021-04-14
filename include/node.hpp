#pragma once

namespace itis {

  struct Node final {
    int key;
    Node *left{nullptr};
    Node *right{nullptr};
    Node *parent_{nullptr};

    /**
     * Создание узла дерева с определенным значением ключа.
     * @param key - значение хранимого ключа
     * @param p - указатель на родительский узел
     */
    explicit Node(int key, Node *p = nullptr);

    /**
     * Кол-во детей у узла дерева.
     * @return неотрицательное число в интервале [0..2]
     */
    int degree() const;
  };

}  // namespace itis