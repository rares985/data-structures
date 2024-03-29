#ifndef DOUBLE_LINKED_LIST_H_
#define DOUBLE_LINKED_LIST_H_

#include <double_linked_list_node.h>
#include <ostream>

class ListEmptyException : public std::exception
{
    const char *what() { return "List is empty!"; }
};

// Node creation policy (Single or Double)
template <typename T>
class DoubleLinkedList
{
    template <typename U>
    using Node = DoubleLinkedListNode<U>;

private:
    Node<T> *head_;

    Node<T> *GetTail()
    {
        Node<T> *it = head_;
        while (it->next != nullptr)
        {
            it = it->next;
        }
        return it;
    }

public:
    DoubleLinkedList() : head_{nullptr} {}
    DoubleLinkedList(DoubleLinkedList<T> &other) = delete;
    DoubleLinkedList(DoubleLinkedList<T> &&other) : head_{other.head}
    {
        other.head_ = nullptr;
    }

    ~DoubleLinkedList()
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

    T *Front()
    {
        return (head_ ? head_->data : nullptr);
    }

    T *Back()
    {

        Node<T> *it = GetTail();

        return *(it->data);
    }

    bool PushFront(T value)
    {
        Node<T> *elem = new Node<T>{value, nullptr, head_};

        head_->prev = elem;

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

        Node<T> *elem = new Node<T>{value, nullptr, nullptr};
        if (head_ == nullptr)
        {
            head_ = elem;
        }
        else
        {
            Node<T> *tail = GetTail();
            elem = new Node<T>{value, tail, nullptr};
            it->next = elem;
        }

        return ret;
    }

    T PopBack()
    {
        Node<T> *it = nullptr;
        T ret = 0;

        if (Empty())
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
