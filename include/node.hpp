#pragma once

namespace itis {

  template<class T = int>
  struct Node {
    T key;
    Node *left;
    Node *right;

    explicit Node(const T &key, Node *l = nullptr, Node *r = nullptr);

    int degree() const;
  };

  template<class T>
  Node<T>::Node(const T &key, Node *l, Node *r) : key{key}, left{l}, right{r} {}

  template<class T>
  int Node<T>::degree() const {
    if (left == nullptr && right == nullptr) {
      return 0;
    }

    if (left != nullptr && right != nullptr) {
      return 2;
    }
    return 1;
  }

}  // namespace itis