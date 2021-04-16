#pragma once

namespace itis {

  struct Node final {
    // ключ (задает порядок узлов в дереве)
    int key;

    // левый и правый узлы-потомки
    Node *left{nullptr};
    Node *right{nullptr};

    /**
     * Создание узла дерева с определенным значением ключа.
     * @param key - значение ключа
     */
    explicit Node(int key);
  };

}  // namespace itis