#ifndef QUEUE_H_
#define QUEUE_H_

#include "single_linked_list.h"
#include <unique_ptr.h>

namespace Queue
{

    template <typename T>
    struct ArrayStoragePolicy
    {
        bool Empty() const { return size_ == 0; }

        int Size() const { return size_; }

        int Capacity() const { return capacity_; }

        T Front() const { return arr_[0]; }
        T Back() const { return arr_[size_ - 1]; }

        bool PushBack(T value)
        {
            arr_[size_++] = value;
            return true;
        }

        T PopFront()
        {
            T popped = arr_[0];
            for (int i = 0; i < size_ - 1; i++)
            {
                arr_[i] = arr_[i + 1];
            }
            size_--;
            return popped;
        }

        ArrayStoragePolicy(int capacity) : arr_{new T[capacity]}, capacity_{capacity}, size_{0} {}
        virtual ~ArrayStoragePolicy() { delete[] arr_; }

        std::string Print()
        {
            std::stringstream ss;
            for (int i = 0; i < size_; i++)
            {
                ss << arr_[i] << (i == size_ - 1 ? "->" : "");
            }
            return ss.str();
        }

    private:
        T *arr_;
        int capacity_;
        int size_;
    };

    template <typename T>
    struct LinkedListStoragePolicy
    {
        bool Empty() const { return lst_->Empty(); }
        int Size() const { return lst_->Size(); }
        int Capacity() const { return capacity_; }
        T Front() const { return lst_->Front(); }
        T Back() const { return lst_->Back(); }

        bool PushBack(T value)
        {
            return lst_->PushBack(value);
        }

        T PopFront()
        {
            return lst_->PopFront();
        }

        LinkedListStoragePolicy(int capacity) : lst_{new SingleLinkedList<T>{}}, capacity_{capacity} {}
        virtual ~LinkedListStoragePolicy() {}

        std::string Print()
        {
            std::stringstream ss;
            ss << *lst_;
            return ss.str();
        }

    private:
        UniquePtr<SingleLinkedList<T>> lst_;
        int capacity_;
    };

    class QueueEmptyException : public std::exception
    {
        const char *what() { return "Queue is empty!"; }
    };
    class QueueFullException : public std::exception
    {
        const char *what() { return "Queue is empty!"; }
    };

    template <typename T,
              template <typename> typename StoragePolicy = LinkedListStoragePolicy>
    class Queue : public StoragePolicy<T>
    {
    public:
        /* Copy semantics are disabled */
        template <typename T1, template <typename> typename SP1>
        Queue(Queue<T1, SP1> &other) = delete;

        template <typename T1, template <typename> typename SP1>
        Queue<T, StoragePolicy> &operator=(Queue<T1, SP1> &other) = delete;

        /* Move semantics */
        template <typename T1, template <typename> typename SP1>
        Queue(Queue<T1, SP1> &&other) = delete;

        template <typename T1, template <typename> typename SP1>
        Queue<T, StoragePolicy> &operator=(Queue<T1, SP1> &&other) = delete;

        Queue(int capacity = 50) : StoragePolicy<T>{capacity} {}
        ~Queue() {}

        T Back()
        {
            if (Size() == 0)
            {
                throw QueueEmptyException();
            }
            return StoragePolicy<T>::Back();
        }

        bool Empty() const
        {
            return StoragePolicy<T>::Empty();
        }

        int Size() const
        {
            return StoragePolicy<T>::Size();
        }

        int Capacity() const
        {
            return StoragePolicy<T>::Capacity();
        }

        T Front()
        {
            if (Size() == 0)
            {
                throw QueueEmptyException();
            }
            return StoragePolicy<T>::Front();
        }

        bool Push(T value)
        {
            if (Size() == Capacity())
            {
                throw QueueFullException();
            }
            return StoragePolicy<T>::PushBack(value);
        }

        T Pop()
        {
            if (Size() == 0)
            {
                throw QueueEmptyException();
            }
            return StoragePolicy<T>::PopFront();
        }

        std::string Print()
        {
            return StoragePolicy<T>::Print();
        }

        friend std::ostream &operator<<(std::ostream &out, const Queue<T> &q)
        {
            out << "Queue(" << *(q.lst) << ")";
            return out;
        }
    };
};

#endif /* QUEUE_H_ */