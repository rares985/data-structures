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

    SharedPtr(SharedPtr &other) : raw_{other.raw_}, counter_{other.counter_}
    {
        (*this->counter_)++;
    }

    SharedPtr(SharedPtr &&other) : raw_{other.raw_}, counter_{other.counter_}
    {
        other.raw_ = nullptr;
        other.counter_ = nullptr;
    }

    ~SharedPtr()
    {
        if (this->raw_ == nullptr)
        {
            return;
        }
        (*this->counter_)--;
        if (*this->counter_ == 0)
        {
            delete raw_;
            delete counter_;
        }
    }

    SharedPtr &operator=(const SharedPtr &other)
    {
    }

    SharedPtr &operator=(const SharedPtr &&other)
    {
    }

    T *operator->()
    {
        return this->raw_;
    }

    T &operator*()
    {
        return *this->raw_;
    }

    void reset(T *raw_)
    {
        delete this->raw_;
        *(this->counter_) = 0;
    }
};

#endif /* SHARED_PTR_H_ */