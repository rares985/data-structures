#ifndef DOUBLE_LINKED_LIST_H_
#define DOUBLE_LINKED_LIST_H_

#include <double_linked_list_node.h>
#include <ostream>

template <typename T>
class DoubleLinkedList
{
    template <typename U>
    using Node = DoubleLinkedListNode<U>;

    private:
        Node<T> *head_;

        Node<T> *CreateNode(T value)
        {
            Node<T> *elem = nullptr;
            try {
                elem = new Node<T>();
                elem->data = new T();

                *(elem->data) = value;
                elem->next = nullptr;
                elem->prev = nullptr;
            } catch(std::exception &exc)
            {
                elem = nullptr;
            }

            return elem;
        }

    public:
        DoubleLinkedList()
        {
            head_ = nullptr;
        }

        ~DoubleLinkedList()
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
                head_->prev = elem;

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
                    elem->prev = it;
                    elem->next = nullptr;
                }
            }

            return ret;
        }

        T pop_back()
        {
            Node<T> *it = nullptr;
            T ret = 0;

            if (empty())
            {
                return 0;
            }

            it = head_;
            while(it->next)
            {
                it = it->next;
            }

            if (it == head_)
            {
                /* List has only one element */
                head_ = nullptr;
            }
            else
            {
                it->prev->next = nullptr;
            }

            ret = *(it->data);

            delete it->data;
            it->data = nullptr;

            delete it;
            it = nullptr;

            return ret;
        }

        template <typename U>
        friend std::ostream& operator<< (std::ostream &out, const DoubleLinkedList<U> &lst)
        {
            out << "DLL(";

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


#endif /* DOUBLE_LINKED_LIST_H_ */
