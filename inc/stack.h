#ifndef STACK_H_
#define STACK_H_

#include "single_linked_list.h"
#include <unique_ptr.h>

class StackEmptyException : public std::exception
{
    const char *what() { return "Stack is empty!"; }
};
class StackFullException : public std::exception
{
    const char *what() { return "Stack is empty!"; }
};

template <typename T>
struct ArrayStoragePolicy
{
    bool Empty() const { return size_ == 0; }

    bool Size() const { return size_; }

    int Capacity() const { return capacity_; }

    T Front() const { return arr_[size_ - 1]; }

    bool PushFront(T value)
    {
        arr_[size_++] = value;
        return true;
    }

    T PopFront()
    {
        T popped = arr_[size_ - 1];
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
    int size_ = 0;
};

template <typename T>
struct LinkedListStoragePolicy
{
    bool Empty() const { return lst_->Empty(); }
    bool Size() const { return lst_->Size(); }
    int Capacity() const { return capacity_; }
    T Front() const { return lst_->Front(); }
    bool PushFront(T value)
    {
        capacity_++;
        return lst_->PushFront(value);
    }

    T PopFront()
    {
        capacity_--;
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

template <typename T,
          template <typename> typename StoragePolicy = LinkedListStoragePolicy>
class Stack : public StoragePolicy<T>
{
public:
    /* Copy semantics are disabled */
    template <typename T1, template <typename> typename SP1>
    Stack(Stack<T1, SP1> &other) = delete;

    template <typename T1, template <typename> typename SP1>
    Stack<T, StoragePolicy> &operator=(Stack<T1, SP1> &other) = delete;

    /* Move semantics */
    template <typename T1, template <typename> typename SP1>
    Stack(Stack<T1, SP1> &&other) = delete;

    template <typename T1, template <typename> typename SP1>
    Stack<T, StoragePolicy> &operator=(Stack<T1, SP1> &&other) = delete;

    Stack(int capacity = 50) : StoragePolicy<T>{capacity} {}
    ~Stack() {}

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

    T Top()
    {
        if (Size() == 0)
        {
            throw StackEmptyException();
        }
        return this->Front();
    }

    bool Push(T value)
    {
        if (Size() == Capacity())
        {
            throw StackFullException();
        }
        return this->PushFront(value);
    }

    T Pop()
    {
        if (Size() == 0)
        {
            throw StackEmptyException();
        }
        return this->PopFront();
    }

    std::string Print()
    {
        return StoragePolicy<T>::Print();
    }
};

#endif /* STACK_H_ */
