#ifndef VECTOR_H_
#define VECTOR_H_

#include <ostream>

/* TODO: add begin(), end(), cbegin(), cend(), constructor from iterators for merge-sort */
template <typename T>
class Vector
{
private:
    int size_;
    int capacity_;
    T *arr_;

public:
    Vector() = delete;
    Vector(int n) : size_{0}, capacity_{n}, arr_{new T[n]} {}

    Vector(Vector<T> &other) : size_{other.size_}, capacity_{other.capacity_}, arr_{other.arr_} {}
    Vector(Vector<T> &&other) : size_{other.size_}, capacity_{other.capacity_}, arr_{other.arr_} {}

    ~Vector()
    {
        delete[] arr_;
    }

    Vector &operator=(const Vector &other)
    {
        this->size_ = other.size_;
        this->capacity_ = other.capacity_;
        this->arr_ = other.arr_;

        return *this;
    }

    Vector &operator=(Vector &&other)
    {
        this->size_ = other.size_;
        other.size_ = 0;

        this->capacity_ = other.capacity_;
        other.capacity_ = 0;

        this->arr_ = other.arr_;
        other.arr_ = 0;

        return *this;
    }

    void PushBack(T elem)
    {
        if (size_ == capacity_ - 1)
        {
            /* Double the capacity */
            capacity_ *= 2;

            T *temp = new T[capacity_];
            for (int i = 0; i < size_; i++)
            {
                temp[i] = arr_[i];
            }
            delete[] arr_;
            arr_ = temp;
        }
        arr_[size_++] = elem;
    }

    int Size()
    {
        return size_;
    }

    int Capacity()
    {
        return capacity_;
    }

    T &operator[](int index)
    {
        if (index >= size_)
        {
            throw std::out_of_range("Invalid index!");
        }
        return arr_[index];
    }

    friend std::ostream &operator<<(std::ostream &out, const Vector<T> &v)
    {
        out << "Vector(";
        for (int i = 0; i < v.size_; i++)
        {
            out << v.arr_[i] << " ";
        }
        out << ")";
        return out;
    }
};
#endif /* VECTOR_H_ */