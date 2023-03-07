#ifndef MAX_HEAP_H_
#define MAX_HEAP_H_

#include "heap.h"

template <typename T>
class MaxHeap : public Heap<T>
{

private:
    void ReheapDown(int i) override
    {
        int l = left(i);
        int r = right(i);

        int largest = i;

        if (l<this->size_ &&this->arr_[l]> this->arr_[i])
        {
            largest = l;
        }
        if (r<this->size_ &&this->arr_[r]> this->arr_[largest])
        {
            largest = r;
        }
        if (largest != i)
        {
            std::swap(this->arr_[i], this->arr_[largest]);
            ReheapDown(largest);
        }
    }

    void ReheapUp(int i) override
    {
        while (i != 0 && this->arr_[parent(i)] < this->arr_[i])
        {
            std::swap(this->arr_[i], this->arr_[parent(i)]);
            i = parent(i);
        }
    }

public:
    MaxHeap(int capacity) : Heap<T>{capacity} {}
    ~MaxHeap() {}

    void Insert(T key) override
    {
        Heap<T>::Insert(key);
    }

    T Pop() override
    {
        return Heap<T>::Pop();
    }
};
#endif /* MAX_HEAP_H_ */