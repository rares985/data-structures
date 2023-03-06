#ifndef BINARY_TREE_NODE_H_
#define BINARY_TREE_NODE_H_

#include <string>
#include <sstream>
#include <iostream>

template <typename T>
struct EmptyNode;

template <typename T>
struct BinaryTreeNode
{
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T value, BinaryTreeNode<T> *left, BinaryTreeNode<T> *right) : data{value}, left{left}, right{right} {}

protected:
    /* Will only be used by EmptyNode constructor to skip initializing data */
    BinaryTreeNode(BinaryTreeNode<T> *left, BinaryTreeNode<T> *right) : left{left}, right{right} {}

    bool IsLeaf() { return left == nullptr && right == nullptr; }
};

#endif /* BINARY_TREE_NODE_H_ */