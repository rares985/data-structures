#ifndef BinarySearchTree_H_
#define BinarySearchTree_H_

#include <iostream>
#include <queue>
#include <algorithm>

#include <binary_tree_node.h>

template <typename T>
class BinarySearchTree
{
    template <typename U>
    using Node = BinaryTreeNode<U>;

private:
    Node<T> *root_;

    bool IsLeafNode(Node<T> *t)
    {
        if (t != nullptr && t->IsLeaf())
        {
            return true;
        }
        return false;
    }

    Node<T> *Find(Node<T> *leaf, T key)
    {
        if (leaf == nullptr)
        {
            return nullptr;
        }
        else if (key == leaf->data)
        {
            return leaf;
        }
        else if (key < leaf->data)
        {
            return Find(leaf->left, key);
        }
        else
            return Find(leaf->right, key);
    }

    void Insert(Node<T> *leaf, T key)
    {
        if (key < leaf->data)
        {
            if (leaf->left != nullptr)
            {
                Insert(leaf->left, key);
            }
            else
            {
                leaf->left = new BinaryTreeNode<T>{key, nullptr, nullptr};
            }
        }
        else
        {
            if (leaf->right != nullptr)
            {
                Insert(leaf->right, key);
            }
            else
            {
                leaf->right = new BinaryTreeNode<T>{key, nullptr, nullptr};
            }
        }
    }

    Node<T> *FindMin(Node<T> *t)
    {
        if (t == nullptr)
            return t;
        else if (t->left == nullptr)
            return t;
        else
            return FindMin(t->left);
    }

    Node<T> *FindMax(Node<T> *t)
    {
        if (t == nullptr)
            return t;
        else if (t->right == nullptr)
            return t;
        else
            return FindMax(t->right);
    }

    Node<T> *Remove(Node<T> *t, T key)
    {
        Node<T> *temp;

        // base case with empty node
        if (t == nullptr)
            return nullptr;

        if (key < t->data)
        {
            t->left = Remove(t->left, key); // look in left subtree
        }
        else if (key > t->data)
        {
            t->right = Remove(t->right, key); // look in right subtree
        }
        else
        {
            // key has been found.
            if (IsLeafNode(t))
            {
                delete t;
                t = nullptr;
            }
            else if (t->right && t->left)
            {
                // removing a node with two childen is tricky.
                // first we find the minimum leaf on the right side of the node we're deleting.
                // copy the data from the mimimum node to the node we're deleting.
                // finally delete the minimum node in the right subtree.
                Node<T> *temp = FindMin(t->right);
                t->data = temp->data;
                t->right = Remove(t->right, t->data);
            }
            else
            {
                temp = t;
                if (t->right == nullptr)
                    t = t->left;
                else if (t->left == nullptr)
                    t = t->right;
                delete temp;
            }
        }
        // eventually returns root node after node removal completes
        return t;
    }

    void DestroyTree(Node<T> *leaf)
    {
        if (leaf != nullptr)
        {
            DestroyTree(leaf->left);
            DestroyTree(leaf->right);
        }

        delete leaf;
    }

    void Inorder(Node<T> *t)
    {
        if (t != nullptr)
        {
            Inorder(t->left);
            std::cout << t->data << " ";
            Inorder(t->right);
        }
    }

    void Preorder(Node<T> *t)
    {
        if (t != nullptr)
        {
            std::cout << t->data << " ";
            Preorder(t->left);
            Preorder(t->right);
        }
    }

    void Postorder(Node<T> *t)
    {
        if (t != nullptr)
        {
            Postorder(t->left);
            Postorder(t->right);
            std::cout << t->data << " ";
        }
    }

    // time complexity is always O(n). aaverage space complexity is O(n) for worst case. O(1) for best case
    void Levelorder(Node<T> *t)
    {
        if (t != nullptr)
        {
            std::queue<Node<T> *> q;

            // enque root node
            q.push(t);

            // deque root node, enque left and right children. exit loop when std::queue is empty.
            while (!q.empty())
            {
                Node<T> *current = q.front();
                std::cout << current->data << " ";
                if (current->left)
                    q.push(current->left);
                if (current->right)
                    q.push(current->right);
                q.pop(); // remove the element at the front
            }
        }
    }

    int MaxDepth(Node<T> *t)
    {
        if (t == nullptr)
        {
            return 0;
        }
        else
        {
            int ld = MaxDepth(t->left);
            int rd = MaxDepth(t->right);

            return (std::max(ld, rd) + 1);
        }
    }

    int NbNodes(Node<T> *t)
    {
        if (t == nullptr)
        {
            return 0;
        }
        else
        {
            int lnb = NbNodes(t->left);
            int rnb = NbNodes(t->right);
            return 1 + lnb + rnb;
        }
    }

public:
    BinarySearchTree() : root_{nullptr} {}

    ~BinarySearchTree() { DestroyTree(root_); }

    void Insert(T key)
    {
        if (root_ != nullptr)
        {
            Insert(root_, key);
        }
        else
        {
            root_ = new BinaryTreeNode<T>{key, nullptr, nullptr};
        }
    }

    Node<T> *Find(T key)
    {
        // start from the root
        return Find(root_, key);
    }

    Node<T> *Remove(T key)
    {
        Remove(root_, key);
    }

    void Display()
    {
        std::cout << "Preorder: ";
        Preorder(root_);
        std::cout << "\nInorder: ";
        Inorder(root_);
        std::cout << "\nPostorder: ";
        Postorder(root_);
        std::cout << "\nLevelorder: ";
        Levelorder(root_);
    }

    Node<T> *GetRoot() { return root_; }

    int MaxDepth()
    {
        return MaxDepth(root_);
    }

    int NbNodes()
    {
        return NbNodes(root_);
    }

    std::vector<T> ToVector()
    {
        /* TODO: To Be Implemented */
        return std::vector<T>{};
    }
};

#endif /* BinarySearchTree_H_ */