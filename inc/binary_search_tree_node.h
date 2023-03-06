#ifndef BINARY_SEARCH_TREE_NODE_H_
#define BINARY_SEARCH_TREE_NODE_H_

#include <binary_tree_node.h>

template <typename T>
class BinarySearchTreeNode : public BinaryTreeNode<T>
{

protected:
    BinarySearchTreeNode() : BinaryTreeNode<T>{} {}
    BinarySearchTreeNode(BinarySearchTreeNode<T> *left, BinarySearchTreeNode<T> *right) : BinaryTreeNode<T>{left, right} {}

public:
    BinarySearchTreeNode(T value) : BinaryTreeNode<T>{value} {}
    BinarySearchTreeNode(T value, BinarySearchTreeNode<T> *left, BinarySearchTreeNode<T> *right) : BinaryTreeNode<T>{value, left, right} {}

    bool Find(T key) const override
    {
        if (this->Value() == key)
        {
            return true;
        }

        if (key < this->Value())
        {
            return this->Left()->Find(key);
        }

        if (key > this->Value())
        {
            return this->Right()->Find(key);
        }

        return false;
    }
};

#endif /* BINARY_SEARCH_TREE_NODE_H_ */