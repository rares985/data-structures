#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include <sstream>

template <typename T>
class BinaryTree
{
private:
    T value_;
    BinaryTree<T> *left_;
    BinaryTree<T> *right_;

public:
    BinaryTree(T value, BinaryTree<T> *left = nullptr, BinaryTree<T> *right = nullptr) : value_{value}, left_{left}, right_{right} {}
    ~BinaryTree() {}

    BinaryTree(BinaryTree<T> &other) : value_{other.value_}, left_{other.left_}, right_{other.right_}
    {
    }
    BinaryTree &operator=(BinaryTree<T> &other)
    {
        value_ = other.value_;
        left_ = other.left_;
        right_ = other.right_;
    }

    BinaryTree(BinaryTree<T> &&other) = delete;
    BinaryTree &operator=(BinaryTree<T> &&other) = delete;

    bool IsLeaf() const
    {
        return (left_ == nullptr && right_ == nullptr);
    }

    bool HasLeft() const
    {
        return (left_ != nullptr);
    }

    bool HasRight() const
    {
        return (right_ != nullptr);
    }

    T Value() const
    {
        return value_;
    }

    BinaryTree<T> *Left() const { return left_; }
    BinaryTree<T> *Right() const { return right_; }

    std::string Preorder() const
    {
        std::stringstream ss;
        ss << Value() << " ";
        if (HasLeft())
        {
            ss << Left()->Preorder() << " ";
        }
        if (HasRight())
        {
            ss << Right()->Preorder() << " ";
        }
        return ss.str();
    }

    std::string Inorder() const
    {
        std::stringstream ss;
        if (HasLeft())
        {
            ss << Left()->Inorder() << " ";
        }
        ss << Value() << " ";
        if (HasRight())
        {
            ss << Right()->Inorder() << " ";
        }
        return ss.str();
    }

    std::string Postorder() const
    {
        std::stringstream ss;
        if (HasLeft())
        {
            ss << Left()->Postorder() << " ";
        }
        if (HasRight())
        {
            ss << Right()->Postorder() << " ";
        }
        ss << Value() << " ";
        return ss.str();
    }

    std::string Str(int tabs) const
    {
        std::stringstream ss;
        for (int i = 0; i < tabs; i++)
        {
            ss << "\t";
        }
        ss << value_ << "\n";
        if (left_)
        {
            ss << left_->Str(tabs + 1) << "\n";
        }
        if (right_)
        {
            ss << right_->Str(tabs + 1) << "\n";
        }
        return ss.str();
    }

    virtual bool Find(T key)
    {
        if (value_ == key)
        {
            return true;
        }
        bool isInLeftSubtree = HasLeft() && Left()->Find(key);
        bool isInRightSubtree = HasRight() && Right()->Find(key);

        return isInLeftSubtree || isInRightSubtree;
    }

    // template <typename U>
    friend std::ostream &operator<<(std::ostream &out, const BinaryTree<T> &lst)
    {
        out << lst.Str(0);
        return out;
    }
};

#endif /* BINARY_TREE_H_ */