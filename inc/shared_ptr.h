#ifndef SHARED_PTR_H_
#define SHARED_PTR_H_

#include <ostream>
#include <iostream>

template <typename T>
class SharedPtr
{
private:
    T *raw_;
    int *counter_;

public:
    SharedPtr() = delete;

    SharedPtr(T *raw) : raw_{raw}, counter_{new int{1}}
    {
    }

    SharedPtr(SharedPtr<T> &other) : raw_{other.raw_}, counter_{other.counter_}
    {
        (*counter_)++;
    }

    SharedPtr(SharedPtr<T> &&other) : raw_{other.raw_}, counter_{other.counter_}
    {
        other.raw_ = nullptr;
        other.counter_ = nullptr;
    }

    ~SharedPtr()
    {
        if (raw_ == nullptr)
        {
            return;
        }
        (*counter_)--;
        if (*counter_ == 0)
        {
            delete raw_;
            delete counter_;
        }
    }

    SharedPtr<T> &operator=(const SharedPtr<T> &other)
    {
        raw_ = other.raw_;
        (*counter++);
        return *this;
    }

    SharedPtr<T> &operator=(const SharedPtr<T> &&other)
    {
        raw_ = other.raw_;
        counter_ = other.counter_;

        other.raw_ = nullptr;
        other.counter_ = nullptr;
    }

    T *operator->()
    {
        return raw_;
    }

    T &operator*()
    {
        return *raw_;
    }

    void reset(T *raw)
    {
        delete raw_;
        raw_ = raw;
        *counter_ = 1;
    }
};

#endif /* SHARED_PTR_H_ */