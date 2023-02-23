#ifndef DOUBLE_LINKED_LIST_NODE_H_
#define DOUBLE_LINKED_LIST_NODE_H_

#include <ostream>
#include <unique_ptr.h>

template <typename T>
struct DoubleLinkedListNode
{
    UniquePtr<T> data;
    DoubleLinkedListNode *next;
    DoubleLinkedListNode *prev;

    DoubleLinkedListNode() = delete;
    DoubleLinkedListNode(T value, DoubleLinkedListNode<T> *prev_ = nullptr, DoubleLinkedListNode<T> *next_ = nullptr) : data{new T{value}}, next{next_}, prev{prev_} {}

    ~DoubleLinkedListNode() {}

    DoubleLinkedListNode(DoubleLinkedListNode<T> &other)
    {
        this->data = other.data;
        this->next = other.next;
    }

    DoubleLinkedListNode(DoubleLinkedListNode<T> &&other)
    {
        this->data = other.data;
        other.data = nullptr;

        this->next = other.next;
        other.next = nullptr;
    }

    friend std::ostream &operator<<(std::ostream &out, const DoubleLinkedListNode<T> &other)
    {
        out << "(" << *(other.data) << ")";
        return out;
    }
};

#endif /* DOUBLE_LINKED_LIST_NODE_H_ */
