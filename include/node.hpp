#pragma once

namespace itis {

template<class T = int>
struct Node {
  T key;

  Node *left;

  Node *right;

  Node(const T &key, Node *l = nullptr, Node *r = nullptr);

  bool IsLeaf() const;

  int degree() const;
};

template<class T>
Node<T>::Node(const T &key, Node *l, Node *r)
    : key{key}, left{l}, right{r} {}

template<class T>
bool Node<T>::IsLeaf() const { return left == nullptr && right == nullptr; }

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

} // namespace itis