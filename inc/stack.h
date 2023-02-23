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

    bool empty()
    {
        return lst->empty();
    }

    int size()
    {
        return lst->size();
    }

    T top()
    {
        try
        {
            return lst->front();
        }
        catch (std::out_of_range &ex)
        {
            throw std::out_of_range("Stack is empty");
        }
    }

    bool push(T value)
    {
        return lst->push_front(value);
    }

    T pop()
    {
        return lst->pop_front();
    }

    friend std::ostream &operator<<(std::ostream &out, const Stack<T> &st)
    {
        out << "Stack(" << *(st.lst) << ")";
        return out;
    }
};

#endif /* STACK_H_ */
