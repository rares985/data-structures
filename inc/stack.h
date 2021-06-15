#ifndef STACK_H_
#define STACK_H_

#include "single_linked_list.h"

template <typename T>
class Stack
{
    private:
        SingleLinkedList<T> *lst;

    public:
        Stack()
        {
            lst = new SingleLinkedList<T>();
        }

        ~Stack()
        {
            delete lst;
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
            T *temp = lst->front();

            return (temp ? *temp : 0);
        }

        bool push(T value)
        {
            return lst->push_front(value);
        }

        T pop()
        {
            return lst->pop_front();
        }

        template <typename U>
        friend std::ostream& operator<< (std::ostream &out, const Stack<U> &st)
        {
            out << "Stack(" << *(st.lst) << ")";
            return out;
        }

};

#endif  /* STACK_H_ */
