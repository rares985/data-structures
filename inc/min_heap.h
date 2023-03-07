#ifndef MIN_HEAP_H_
#define MIN_HEAP_H_

#include "heap.h"

template <typename T>
class MinHeap : public Heap<T>
{

private:
    void ReheapDown(int i) override
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < this->size_ && this->arr_[l] < this->arr_[i])
            smallest = l;
        if (r < this->size_ && this->arr_[r] < this->arr_[smallest])
            smallest = r;
        if (smallest != i)
        {
            std::swap(this->arr_[i], this->arr_[smallest]);
            ReheapDown(smallest);
        }
    }

    void ReheapUp(int i) override
    {
        while (i != 0 && this->arr_[parent(i)] > this->arr_[i])
        {
            std::swap(this->arr_[i], this->arr_[parent(i)]);
            i = parent(i);
        }
    }

public:
    MinHeap(int capacity) : Heap<T>{capacity} {}
    ~MinHeap() {}

    T Pop() override
    {
        return Heap<T>::Pop();
    }

    T Peek() override { return this->arr_[0]; }
    void Insert(T key) override
    {
        Heap<T>::Insert(key);
    }
};
#endif /* MIN_HEAP_H_ */