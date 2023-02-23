#ifndef UNIQUE_PTR_H_
#define UNIQUE_PTR_H_

template <typename T>
class UniquePtr
{
private:
    T *raw_;

public:
    UniquePtr() = delete;
    UniquePtr(UniquePtr &other) = delete;

    UniquePtr(UniquePtr &&other)
    {
        this->raw_ = other.raw_;
        other.raw_ = nullptr;
    }

    UniquePtr(T *raw) : raw_(raw) {}
    ~UniquePtr()
    {
        delete this->raw_;
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
        this->raw_ = raw_;
    }
};

#endif /* UNIQUE_PTR_H_ */