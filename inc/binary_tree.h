#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include <sstream>
#include <vector>
#include <binary_tree_node.h>
#include <vector>
#include <iostream>

template <typename T>
class BinaryTree
{
private:
    BinaryTreeNode<T> *root_;

public:
    BinaryTree(T value) : root_{new BinaryTreeNode<T>{value}} {}
    BinaryTree(T value, BinaryTree<int> *left, BinaryTree<int> *right) : root_{new BinaryTreeNode<T>{value, left->root_, right->root_}} {}

    ~BinaryTree()
    {
        delete root_;
    }

    int Depth() const { return root_->Depth(); }

    bool Find(T key) const { return root_->Find(key); }

    int NbNodes() const { return root_->NbNodes(); }

    std::string Preorder() const { return root_->Preorder(); }
    std::string Inorder() const { return root_->Inorder(); }
    std::string Postorder() const { return root_->Postorder(); }
    friend std::ostream &operator<<(std::ostream &out, const BinaryTree<T> &lst)
    {
        out << lst.root_->Str(0);
        return out;
    }
};

#endif /* BINARY_TREE_H_ */