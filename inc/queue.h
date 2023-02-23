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

    T front()
    {
        try
        {
            return lst->front();
        }
        catch (std::out_of_range &ex)
        {
            throw std::out_of_range("Queue is empty");
        }
    }

    T back()
    {
        try
        {
            return lst->back();
        }
        catch (std::out_of_range &ex)
        {
            throw std::out_of_range("Queue is empty");
        }
    }

    bool empty()
    {
        return lst->empty();
    }

    int size()
    {
        return lst->size();
    }

    bool push(T value)
    {
        return lst->push_back(value);
    }

    T pop()
    {
        return lst->pop_front();
    }

    friend std::ostream &operator<<(std::ostream &out, const Queue<T> &q)
    {
        out << "Queue(" << *(q.lst) << ")";
        return out;
    }
};

#endif /* QUEUE_H_ */