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

public:
    SingleLinkedList()
    {
        head_ = nullptr;
    }

    SingleLinkedList(SingleLinkedList<T> &other) = delete;
    SingleLinkedList(SingleLinkedList<T> &&other)
    {
        /* Is this enough? Yes, because data is allocated on heap */
        this->head_ = other.head_;
        other.head_ = nullptr;
    }

    ~SingleLinkedList()
    {
        Node<T> *it = nullptr;
        Node<T> *temp = nullptr;

        if (Empty())
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

    bool Empty()
    {
        return (head_ == nullptr);
    }

    int Size()
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

    T Front()
    {
        if (head_)
        {
            return *head_->data;
        }
        else
        {
            throw std::out_of_range("List is empty!");
        }
    }

    T Back()
    {
        if (!head_)
        {
            throw std::out_of_range("List is empty");
        }

        Node<T> *it = head_;
        while (it->next != nullptr)
        {
            it = it->next;
        }

        return *(it->data);
    }

    bool PushFront(T value)
    {
        Node<T> *elem = new Node<T>{value, head_};
        head_ = elem;

        return true;
    }

    T PopFront()
    {

        if (Empty())
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

    bool PushBack(T value)
    {
        bool ret = false;

        Node<T> *elem = new Node<T>{value};
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

    T PopBack()
    {
        Node<T> *it = nullptr;
        Node<T> *prev = nullptr;
        T ret = 0;

        if (Empty())
        {
            return 0;
        }

        it = head_;
        while (it->next)
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

        delete it;
        it = nullptr;

        return ret;
    }

    void Reverse()
    {
        Node<T> *current = head_;
        Node<T> *prev = nullptr;
        Node<T> *next = nullptr;

        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head_ = prev;
    }

    bool HasCycle()
    {
        if (!head_ || !head_->next)
        {
            /* 1 element list with nullptr at end cannot have cycle */
            return false;
        }

        Node<T> *slow = head_;
        Node<T> *fast = head_->next;

        while (slow && fast)
        {
            slow = slow->next;
            if (!fast->next)
            {
                /* Fast reached end, no cycle exists */
                return false;
            }
            fast = fast->next->next;
            if (slow == fast)
            {
                return true;
            }
        }

        /* One of the pointers reached nullptr, no cycle exists */
        return false;
    }

    template <typename U>
    friend std::ostream &operator<<(std::ostream &out, const SingleLinkedList<U> &lst)
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
