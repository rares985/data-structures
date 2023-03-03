#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_

#include <binary_tree.h>

template <typename T>
class BinarySearchTree : public BinaryTree<T>
{
public:
    bool Find(T key) override
    {
        if (this->value_ == key)
        {
            return true;
        }

        if (key < this->value_)
        {
            return this->HasLeft() && this->left_->Find(key);
        }
        if (key > this->value_)
        {
            return this->HasRight() && this->right_->Find(key);
        }
        return false;
    }

    void Insert(T key) override
    {
        if (this->HasLeft() && key < this->value_)
        {
            /* Recurse left */
            return this->left_->Insert(key);
        }

        if (this->HasRight() && key > this->value_)
        {
            /* Recurse right */
            return this->right_->Insert(key);
        }

        /* Insert left/right depending on root's value */
        if (key < this->value_)
        {
            return this->InsertLeft(new BinarySearchTree<T>{key});
        }
        else
        {
            return this->InsertRight(new BinarySearchTree<T>{key});
        }
    }

    bool Delete(T key)
    {
        if (!Find(key))
        {
            return false;
        }

        if (key ==)

            return false;
    }
};

#endif /* BINARY_SEARCH_TREE_H_ */