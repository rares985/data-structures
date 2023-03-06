#include <iostream>
#include <climits>

#ifndef MIN_HEAP_H_
#define MIN_HEAP_H_

class HeapFullException : public std::exception
{
    const char *what() { return "Heap is full!"; }
};

class HeapEmptyException : public std::exception
{
    const char *what() { return "Heap is empty!"; };
};

template <typename T>
class MinHeap
{
    T *arr_;       // pointer to array of elements in heap
    int capacity_; // maximum possible size of min heap
    int size_;     // Current number of elements in min heap

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }

    void MinHeapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < size_ && arr_[l] < arr_[i])
            smallest = l;
        if (r < size_ && arr_[r] < arr_[smallest])
            smallest = r;
        if (smallest != i)
        {
            std::swap(arr_[i], arr_[smallest]);
            MinHeapify(smallest);
        }
    }

    void DecreaseKey(int i, T new_val)
    {
        arr_[i] = new_val;
        while (i != 0 && arr_[parent(i)] > arr_[i])
        {
            std::swap(arr_[i], arr_[parent(i)]);
            i = parent(i);
        }
    }

    // Deletes a key stored at index i
    void DeleteKeyAtIdx(int i)
    {
        DecreaseKey(i, INT_MIN);
        ExtractMin();
    }

public:
    MinHeap(int capacity) : arr_{new T[capacity]}, capacity_{capacity}, size_{0} {}
    ~MinHeap() { delete[] arr_; }

    T ExtractMin()
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
        int root = arr_[0];
        arr_[0] = arr_[size_ - 1];
        size_--;
        MinHeapify(0);

        return root;
    }

    T Peek() { return arr_[0]; }

    void Insert(T k)
    {
        if (size_ == capacity_)
        {
            throw HeapFullException();
        }

        // First insert the new key at the end
        size_++;
        int i = size_ - 1;
        arr_[i] = k;

        // Fix the min heap property if it is violated
        while (i != 0 && arr_[parent(i)] > arr_[i])
        {
            std::swap(arr_[i], arr_[parent(i)]);
            i = parent(i);
        }
    }
};
#endif /* MIN_HEAP_H_ */