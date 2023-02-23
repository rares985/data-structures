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

public:
    DoubleLinkedList()
    {
        head_ = nullptr;
    }

    DoubleLinkedList(DoubleLinkedList<T> &other)
    {
        /* Should we copy? */
    }

    DoubleLinkedList(DoubleLinkedList<T> &&other)
    {
        this->head_ = other.head_;
        other.head_ = nullptr;
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
        Node<T> *elem = new Node<T>{value, nullptr, head_};

        elem->next = head_;
        head_->prev = elem;

        head_ = elem;

        return true;
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

        delete temp;
        temp = nullptr;

        return ret;
    }

    bool push_back(T value)
    {
        bool ret = false;

        Node<T> *elem = new Node<T>{value, nullptr, nullptr};
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
        while (it->next)
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

        delete it;
        it = nullptr;

        return ret;
    }

    template <typename U>
    friend std::ostream &operator<<(std::ostream &out, const DoubleLinkedList<U> &lst)
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
