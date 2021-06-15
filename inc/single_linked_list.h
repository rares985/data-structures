#ifndef SINGLE_LINKED_LIST_H_
#define SINGLE_LINKED_LIST_H_

#include <single_linked_list_node.h>
#include <ostream>
#include <iostream>

template <typename T>
class SingleLinkedList
{
    private:
        template <typename U>
        using Node = SingleLinkedListNode<U>;

        Node<T> *head_;

        Node<T> *CreateNode(T value)
        {
            Node<T> *elem = nullptr;
            try {
                elem = new Node<T>();
                elem->data = new T();

                *(elem->data) = value;
                elem->next = nullptr;
            } catch(std::exception &exc)
            {
                elem = nullptr;
            }

            return elem;
        }

    public:
        SingleLinkedList()
        {
            head_ = nullptr;
        }

        ~SingleLinkedList()
        {
            Node<T> *it = nullptr;
            Node<T> *temp = nullptr;

            if (empty())
            {
                return;
            }

            it = head_;
            while (it)
            {
                temp = it;
                it = it->next;

                delete temp->data;
                temp->data = nullptr;

                delete temp;
                temp = nullptr;

            }
            head_ = nullptr;
        }

        bool empty()
        {
            return (head_ == nullptr);
        }

        int size()
        {
            int size = 0;
            Node<T> *it = head_;

            while (it != nullptr)
            {
                size += 1;
                it = it->next;
            }

            return size;
        }

        T *front()
        {
            return (head_ ? head_->data : nullptr);
        }

        T *back()
        {
            Node<T> *it = nullptr;
            T *ret = nullptr;

            it = head_;
            while (it != nullptr)
            {
                ret = it->data;
                it = it->next;
            }

            return ret;
        }

        bool push_front(T value)
        {
            bool ret = false;

            Node<T> *elem = CreateNode(value);
            if (nullptr != elem)
            {
                elem->next = head_;
                head_ = elem;

                ret = true;
            }

            return ret;
        }

        T pop_front()
        {

            if (empty())
            {
                return 0;
            }

            Node<T> *temp = head_;
            T ret = *(head_->data);

            head_ = head_->next;

            delete temp->data;
            temp->data = nullptr;

            delete temp;
            temp = nullptr;

            return ret;
        }

        bool push_back(T value)
        {
            bool ret = false;

            Node<T> *elem = CreateNode(value);
            if (elem)
            {
                if (head_ == nullptr)
                {
                    head_ = elem;
                }
                else
                {
                    Node<T> *it = head_;
                    while (it->next != nullptr)
                    {
                        it = it->next;
                    }

                    it->next = elem;
                    elem->next = nullptr;
                }
            }

            return ret;
        }

        T pop_back()
        {
            Node<T> *it = nullptr;
            Node<T> *prev = nullptr;
            T ret = 0;

            if (empty())
            {
                return 0;
            }

            it = head_;
            while(it->next)
            {
                prev = it;
                it = it->next;
            }

            if (it == head_)
            {
                /* List has only one element */
                head_ = nullptr;
            }
            else
            {
                prev->next = nullptr;
            }

            ret = *(it->data);

            delete it->data;
            it->data = nullptr;

            delete it;
            it = nullptr;

            return ret;
        }

        template <typename U>
        friend std::ostream& operator<< (std::ostream &out, const SingleLinkedList<U> &lst)
        {
            out << "SLL(";

            Node<U> *it = lst.head_;
            while (it != nullptr)
            {
                out << *(it->data);
                if (it->next != nullptr)
                {
                    out << "->";
                }

                it = it->next;
            }

            out << ")";

            return out;
        }
};


#endif /* SINGLE_LINKED_LIST_H_ */
