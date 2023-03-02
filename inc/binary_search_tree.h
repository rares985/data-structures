#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_

#include <binary_tree.h>
#include <binary_tree_node.h>

template <typename T>
class BinarySearchTree : public BinaryTree<T>
{
    bool Find(T key) override
    {
        if (value_ == key)
        {
            return true;
        }

        if (key < value_)
        {
            return HasLeft() && Left()->Find(key);
        }
        if (key > value_)
        {
            return HasRight() && Right()->Find(key);
        }
    }

    void Insert(T key)
};

#endif /* BINARY_SEARCH_TREE_H_ */