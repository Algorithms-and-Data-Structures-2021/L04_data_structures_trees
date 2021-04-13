#include "binary_search_tree.hpp"

namespace itis {

  BinarySearchTree::~BinarySearchTree() {
    Clear();
  }

  void BinarySearchTree::Insert(int key) {
    if (root_ != nullptr) {
      insert(key, root_);
    } else {
      root_ = new Node(key);
    }
  }

  void BinarySearchTree::insert(int key, Node *node) {
    // Task 1: перепишите рекурсивную реализацию в итеративную
    auto &insert_node = key < node->key ? node->left : node->right;

    if (insert_node != nullptr) {
      insert(key, insert_node);
    } else {
      insert_node = new Node(key, node);
    }
  }

  Node *BinarySearchTree::Search(int key) const {
    return search(key, root_);
  }

  Node *BinarySearchTree::search(int key, Node *node) const {
    // Task 2: перепишите рекурсивную реализацию в итеративную
    if (node != nullptr) {

      if (key == node->key) {
        // found it!
        return node;
      }

      if (key < node->key) {
        // search in left sub-tree
        return search(key, node->left);
      }

      // search in right sub-tree
      return search(key, node->right);
    }

    return nullptr;  // not found :(
  }

  void BinarySearchTree::Clear() {
    clear(root_);
    root_ = nullptr;
  }

  void BinarySearchTree::clear(Node *node) {
    if (node != nullptr) {
      clear(node->left);
      clear(node->right);
      delete node;
    }
  }

  void BinarySearchTree::Remove(int key) {
    remove(key, root_);
  }

  void BinarySearchTree::remove(int key, Node *node) {
    // Task 3: найдите ошибки в реализации и исправьте их

    if (node == nullptr) {
      return;
    }

    if (key < node->key) {
      // recursively remove from the left sub-tree
      remove(key, node->left);

    } else if (key > node->key) {
      // recursively remove from the right sub-tree
      remove(key, node->right);

    } else {
      // found the node to remove!

      // case 1: no children
      if (node->degree() == 0) {

        if (node->key < node->parent_->key) {
          node->parent_->left = nullptr;
        } else {
          node->parent_->right = nullptr;
        }

        delete node;

      } else if (node->degree() == 2) {

        // case 2: there are 2 children

        Node *min_node = findMin(node->right);  // the leftmost node

        if (min_node->degree() == 0) {
          node->key = min_node->key;
          min_node->parent_->left = nullptr;  // надо ли это?
          delete min_node;

        } else {
          node->key = min_node->key;
          min_node->parent_->left = min_node->right;
          delete min_node;
        }

      } else {

        // case 3: there is 1 child

        // TBD

        delete node;
      }
    }
  }

  Node *BinarySearchTree::findMin(Node *node) const {
    if (node == nullptr) {
      return nullptr;
    }

    // there is no min element in the right sub-tree
    if (node->left == nullptr) {
      return node;
    }

    return findMin(node->left);
  }

  void BinarySearchTree::Traverse(const TraversalAlgorithm &algorithm) const {
    algorithm.Print(std::cout, root_);
  }

}  // namespace itis