#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_

#include <binary_search_tree_node.h>

template <typename T>
class BinarySearchTree
{
private:
    BinarySearchTreeNode<T> *root_;

public:
    BinarySearchTree(T value) : root_{new BinarySearchTreeNode<T>{value}} {}
    BinarySearchTree(T value, BinarySearchTree<T> *left, BinarySearchTree<T> *right)
    {
        BinarySearchTreeNode<T> *leftt = left ? left->root_ : nullptr;
        BinarySearchTreeNode<T> *rightt = right ? right->root_ : nullptr;
        root_ = new BinarySearchTreeNode<T>{value, leftt, rightt};
    }

    int Depth() const { return root_->Depth(); }

    bool Find(T key) const { return root_->Find(key); }

    int NbNodes() const { return root_->NbNodes(); }

    std::string Preorder() const { return root_->Preorder(); }
    std::string Inorder() const { return root_->Inorder(); }
    std::string Postorder() const { return root_->Postorder(); }
    friend std::ostream &operator<<(std::ostream &out, const BinarySearchTree<T> &lst)
    {
        out << lst.root_->Str(0);
        return out;
    }

    // void Insert(T key)
    // {
    //     if (this->HasLeft() && key < this->value_)
    //     {
    //         /* Recurse left */
    //         return this->left_->Insert(key);
    //     }

    //     if (this->HasRight() && key > this->value_)
    //     {
    //         /* Recurse right */
    //         return this->right_->Insert(key);
    //     }

    //     /* Insert left/right depending on root's value */
    //     if (key < this->value_)
    //     {
    //         return this->InsertLeft(new BinarySearchTree<T>{key});
    //     }
    //     else
    //     {
    //         return this->InsertRight(new BinarySearchTree<T>{key});
    //     }
    // }
};

#endif /* BINARY_SEARCH_TREE_H_ */