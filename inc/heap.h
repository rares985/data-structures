#ifndef HEAP_H_
#define HEAP_H_

#include <iostream>
#include <climits>

class HeapFullException : public std::exception
{
    const char *what() { return "Heap is full!"; }
};

class HeapEmptyException : public std::exception
{
    const char *what() { return "Heap is empty!"; };
};

static constexpr int parent(int i) { return (i - 1) / 2; }
static constexpr int left(int i) { return (2 * i + 1); }
static constexpr int right(int i) { return (2 * i + 2); }

template <typename T>
class Heap
{
protected:
    T *arr_;       // pointer to array of elements in heap
    int capacity_; // maximum possible size of min heap
    int size_;     // Current number of elements in min heap

    Heap(int capacity) : arr_{new T[capacity]}, capacity_{capacity}, size_{0} {}
    virtual ~Heap() { delete[] arr_; }

    virtual void Insert(T key)
    {
        if (size_ == capacity_)
        {
            throw HeapFullException();
        }

        // First insert the new key at the end
        size_++;
        int i = size_ - 1;
        arr_[i] = key;

        // Fix the heap property if it is violated
        ReheapUp(i);
    }

    virtual T Pop()
    {
        if (size_ <= 0)
        {
            throw HeapEmptyException();
        }

        if (size_ == 1)
        {
            size_--;
            return arr_[0];
        }

        // Store the minimum value, and remove it from heap
        T root = arr_[0];
        arr_[0] = arr_[size_ - 1];
        size_--;
        ReheapDown(0);

        return root;
    }

    virtual T Peek() { return arr_[0]; }

    virtual void ReheapDown(int i) = 0;
    virtual void ReheapUp(int i) = 0;
};
#endif /* HEAP_H_ */