#ifndef STACK_H_
#define STACK_H_

#include "single_linked_list.h"
#include <unique_ptr.h>

template <typename T>
class Stack
{
private:
    UniquePtr<SingleLinkedList<T>> lst;

public:
    Stack(Stack<T> &other) = delete;

    Stack() : lst{new SingleLinkedList<T>{}} {}
    ~Stack() {}

    Stack(Stack<T> &&other)
    {
        this->lst = std::move(other.lst);
    }

    bool Empty()
    {
        return lst->Empty();
    }

    int Size()
    {
        return lst->Size();
    }

    T Top()
    {
        try
        {
            return lst->Front();
        }
        catch (std::out_of_range &ex)
        {
            throw std::out_of_range("Stack is empty");
        }
    }

    bool Push(T value)
    {
        return lst->PushFront(value);
    }

    T Pop()
    {
        return lst->PopFront();
    }

    friend std::ostream &operator<<(std::ostream &out, const Stack<T> &st)
    {
        out << "Stack(" << *(st.lst) << ")";
        return out;
    }
};

#endif /* STACK_H_ */
