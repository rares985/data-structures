#ifndef QUEUE_H_
#define QUEUE_H_

#include "single_linked_list.h"
#include <unique_ptr.h>

template <typename T>
class Queue
{
private:
    UniquePtr<SingleLinkedList<T>> lst;

public:
    Queue() : lst{new SingleLinkedList<T>{}} {}
    ~Queue() {}

    Queue(Queue &other) = delete;
    Queue(Queue &&other) : lst{std::move(other.lst)} {}

    T Front()
    {
        try
        {
            return lst->Front();
        }
        catch (std::out_of_range &ex)
        {
            throw std::out_of_range("Queue is empty");
        }
    }

    T Back()
    {
        try
        {
            return lst->Back();
        }
        catch (std::out_of_range &ex)
        {
            throw std::out_of_range("Queue is empty");
        }
    }

    bool Empty()
    {
        return lst->Empty();
    }

    int Size()
    {
        return lst->Size();
    }

    bool Push(T value)
    {
        return lst->PushBack(value);
    }

    T Pop()
    {
        return lst->PopFront();
    }

    friend std::ostream &operator<<(std::ostream &out, const Queue<T> &q)
    {
        out << "Queue(" << *(q.lst) << ")";
        return out;
    }
};

#endif /* QUEUE_H_ */