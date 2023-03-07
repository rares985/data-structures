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

template <typename T, typename Compare>
class Heap
{
private:
    Compare cmp;
    T *arr_;
    int capacity_;
    int size_;

private:
    void ReheapDown(int i)
    {
        int l = left(i);
        int r = right(i);

        int largest = i;

        if (l < this->size_ && cmp(this->arr_[l], this->arr_[i]))
        {
            largest = l;
        }
        if (r < this->size_ && cmp(this->arr_[r], this->arr_[largest]))
        {
            largest = r;
        }
        if (largest != i)
        {
            std::swap(this->arr_[i], this->arr_[largest]);
            ReheapDown(largest);
        }
    }

    void ReheapUp(int i)
    {
        while (i != 0 && cmp(this->arr_[i], this->arr_[parent(i)]))
        {
            std::swap(this->arr_[i], this->arr_[parent(i)]);
            i = parent(i);
        }
    }

public:
    Heap(int capacity) : arr_{new T[capacity]}, capacity_{capacity}, size_{0} {}
    virtual ~Heap() { delete[] arr_; }

    T Peek() { return arr_[0]; }

    void Insert(T key)
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

    T Pop()
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
};

#endif /* HEAP_H_ */