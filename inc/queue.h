#ifndef QUEUE_H_
#define QUEUE_H_

#include "single_linked_list.h"

template <typename T>
class Queue
{
    private:
        SingleLinkedList<T> *lst;

    public:
        Queue()
        {
            lst = new SingleLinkedList<T>();
        }

        ~Queue()
        {
            delete lst;
        }

        T front()
        {
            T *temp = lst->front();
            return (temp ? *temp : 0);
        }

        T back()
        {
            T *temp = lst->back();
            return (temp ? *temp : 0);
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

        template <typename U>
        friend std::ostream& operator<< (std::ostream &out, const Queue<U> &q)
        {
            out << "Queue(" << *(q.lst) << ")";
            return out;
        }
};

#endif /* QUEUE_H_ */