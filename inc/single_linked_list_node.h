#ifndef SINGLE_LINKED_LIST_NODE_H_
#define SINGLE_LINKED_LIST_NODE_H_

#include <ostream>
#include <unique_ptr.h>
template <typename T>
struct SingleLinkedListNode
{
    UniquePtr<T> data;
    SingleLinkedListNode *next;

    SingleLinkedListNode() = delete;

    SingleLinkedListNode(T value, SingleLinkedListNode<T> *next_ = nullptr) : data{new T{value}}, next{next_} {}

    ~SingleLinkedListNode() {}

    SingleLinkedListNode(SingleLinkedListNode<T> &other)
    {
        this->data = other.data;
        this->next = other.next;
    }

    SingleLinkedListNode(SingleLinkedListNode<T> &&other)
    {
        this->data = other.data;
        other.data = nullptr;

        this->next = other.next;
        other.next = nullptr;
    }

    friend std::ostream &operator<<(std::ostream &out, const SingleLinkedListNode<T> &other)
    {
        out << "(" << *(other.data) << ")";
        return out;
    }
};

#endif /* SINGLE_LINKED_LIST_NODE_H_ */
