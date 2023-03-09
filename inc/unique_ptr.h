#ifndef UNIQUE_PTR_H_
#define UNIQUE_PTR_H_

template <typename T>
class UniquePtr
{
private:
    T *raw_;

public:
    UniquePtr() = delete;
    UniquePtr(UniquePtr<T> &other) = delete;

    UniquePtr(UniquePtr<T> &&other) : raw_{other.raw_}
    {
        other.raw_ = nullptr;
    }

    UniquePtr<T> &operator=(UniquePtr<T> &other) = delete;
    UniquePtr<T> &operator=(const UniquePtr<T> &other) = delete;

    UniquePtr<T> &operator=(const UniquePtr<T> &&other)
    {
        raw_ = other.raw_;
        other.raw_ = nullptr;
    }

    UniquePtr(T *raw) : raw_(raw) {}
    ~UniquePtr()
    {
        delete raw_;
    }

    T *operator->() const
    {
        return raw_;
    }

    T &operator*() const
    {
        return *raw_;
    }

    void reset(T *raw)
    {
        delete raw_;
        raw_ = raw;
    }
};

#endif /* UNIQUE_PTR_H_ */