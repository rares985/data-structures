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
    DoubleLinkedListNode(DoubleLinkedListNode<T> &other) = delete;

    DoubleLinkedListNode(T value, DoubleLinkedListNode<T> *prev_ = nullptr, DoubleLinkedListNode<T> *next_ = nullptr) : data{new T{value}}, next{next_}, prev{prev_} {}

    ~DoubleLinkedListNode() {}

    DoubleLinkedListNode(DoubleLinkedListNode<T> &&other) : data{std::move(other.data)}, next{other.next}, prev{other.prev} {}
    {
        other.next = nullptr;
        other.prev = nullptr;
    }

    friend std::ostream &operator<<(std::ostream &out, const DoubleLinkedListNode<T> &other)
    {
        out << "(" << *(other.data) << ")";
        return out;
    }
};

#endif /* DOUBLE_LINKED_LIST_NODE_H_ */
