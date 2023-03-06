#ifndef BINARY_TREE_NODE_H_
#define BINARY_TREE_NODE_H_

#include <string>
#include <sstream>
#include <iostream>

template <typename T>
class BinaryTreeNode;

template <typename T>
class EmptyNode : public BinaryTreeNode<T>
{
public:
    EmptyNode() : BinaryTreeNode<T>{nullptr, nullptr} {}
    ~EmptyNode() {}

    bool Find(T /* key */) const override { return false; }

    std::string Str(int /* tabs */) const override
    {
        return std::string{};
    }

    std::string Preorder() const override
    {
        std::stringstream ss;
        return ss.str();
    }

    std::string Postorder() const override
    {
        std::stringstream ss;
        return ss.str();
    }

    std::string Inorder() const override
    {
        std::stringstream ss;
        return ss.str();
    }

    int Depth() const override { return 0; }
    int NbNodes() const override { return 0; }

    bool IsEmpty() const override { return true; }
};

template <typename T>
class BinaryTreeNode
{
private:
    T value_;
    BinaryTreeNode<T> *left_;
    BinaryTreeNode<T> *right_;

protected:
    BinaryTreeNode() {}
    BinaryTreeNode(BinaryTreeNode<T> *left, BinaryTreeNode<T> *right) : left_{left}, right_{right} {}

    T Value() const { return value_; }

public:
    BinaryTreeNode(T value) : value_{value}, left_{new EmptyNode<T>{}}, right_{new EmptyNode<T>{}} {}
    BinaryTreeNode(T value, BinaryTreeNode<T> *left, BinaryTreeNode<T> *right) : value_{value}
    {
        if (left)
        {
            left_ = left;
        }
        else
        {
            left_ = new EmptyNode<T>{};
        }

        if (right)
        {
            right_ = right;
        }
        else
        {
            right_ = new EmptyNode<T>{};
        }
    }

    BinaryTreeNode(const BinaryTreeNode<T> &other)
    {
        std::cout << "BinaryTreeNode copy constructor...";
    }

    virtual ~BinaryTreeNode()
    {
        if (Left())
        {
            if (Left()->IsEmpty())
            {
                delete left_;
            }
        }

        if (Right())
        {
            if (Right()->IsEmpty())
            {
                delete right_;
            }
        }
    }

    BinaryTreeNode<T> *Left() const { return left_; }
    BinaryTreeNode<T> *Right() const { return right_; }

    void SetLeft(BinaryTreeNode<T> *left)
    {
        left_ = left;
    }

    void SetRight(BinaryTreeNode<T> *right)
    {
        right_ = right;
    }

    virtual int Depth() const
    {
        return 1 + std::max(this->left_->Depth(), this->right_->Depth());
    }

    virtual int NbNodes() const
    {
        return this->left_->NbNodes() + this->right_->NbNodes() + 1;
    }

    virtual bool
    Find(T key) const
    {
        if (this->value_ == key)
        {
            return true;
        }

        bool isInLeftSubtree = this->left_->Find(key);
        bool isInRightSubtree = this->right_->Find(key);

        return isInLeftSubtree || isInRightSubtree;
    }

    virtual bool IsEmpty() const { return false; }

    virtual std::string Preorder() const
    {
        std::stringstream ss;
        ss << this->value_ << " ";
        ss << this->left_->Preorder();
        ss << this->right_->Preorder();
        return ss.str();
    }

    virtual std::string Inorder() const
    {
        std::stringstream ss;
        ss << this->left_->Inorder();
        ss << this->value_ << " ";
        ss << this->right_->Inorder();
        return ss.str();
    }

    virtual std::string Postorder() const
    {
        std::stringstream ss;
        ss << this->left_->Postorder();
        ss << this->right_->Postorder();
        ss << this->value_ << " ";
        return ss.str();
    }

    virtual std::string Str(int tabs) const
    {
        std::stringstream ss;
        for (int i = 0; i < tabs; i++)
        {
            ss << "\t";
        }
        ss << value_ << "\n";
        ss << left_->Str(tabs + 1);
        ss << right_->Str(tabs + 1);
        return ss.str();
    }

    friend std::ostream &operator<<(std::ostream &out, const BinaryTreeNode<T> &lst)
    {
        out << lst.Str(0);
        return out;
    }
};

#endif /* BINARY_TREE_NODE_H_ */