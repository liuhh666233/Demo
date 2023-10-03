#include <utility>
#include <dbg.h>
#include <printf.h>
class SharedCount
{
public:
    SharedCount() noexcept : count_(1){};
    void AddCount() noexcept
    {
        ++count_;
    }
    long ReduceCount() noexcept
    {
        return --count_;
    }
    long GetCount() const noexcept
    {
        return count_;
    }

private:
    long count_;
};

template <typename T>
class SmartPtr
{
public:
    template <typename U>
    friend class SmartPtr;
    SmartPtr(T *ptr = nullptr) : ptr_(ptr)
    {
        if (ptr_)
        {
            shared_count_ = new SharedCount();
        }
    };
    ~SmartPtr()
    {
        if (ptr_ && !shared_count_->ReduceCount())
        {
            delete ptr_;
            delete shared_count_;
        }
    }
    SmartPtr(const SmartPtr &other)
    {
        ptr_ = other.ptr_;
        if (ptr_)
        {
            other.shared_count_->AddCount();
            shared_count_ = other.shared_count_;
        }
    }
    template <typename U>
    SmartPtr(const SmartPtr<U> &other) noexcept
    {
        ptr_ = other.ptr_;
        if (ptr_)
        {
            other.shared_count_->AddCount();
            shared_count_ = other.shared_count_;
        }
    }

    template <typename U>
    SmartPtr(SmartPtr<U> &&other) noexcept
    {
        ptr_ = other.ptr_;
        if (ptr_)
        {
            shared_count_ = other.shared_count_;
            other.shared_count_ = nullptr;
        }
    }

    template <typename U>
    SmartPtr(const SmartPtr<U> &other, T *ptr)
    {
        ptr_ = ptr;
        if (ptr_)
        {
            other.shared_count_->AddCount();
            shared_count_ = other.shared_count_;
        }
    }
    SmartPtr &operator=(SmartPtr rhs) noexcept
    {
        rhs.swap(*this);
        return *this;
    }
    T *get() const noexcept
    {
        return ptr_;
    }
    long use_count() const noexcept
    {
        if (ptr_)
        {
            return shared_count_->GetCount();
        }
        else
        {
            return 0;
        }
    }
    void swap(SmartPtr &rhs) noexcept
    {
        using std::swap;
        swap(ptr_, rhs.ptr_);
        swap(shared_count_, rhs.shared_count_);
    }
    T &operator*() const noexcept
    {
        return *ptr_;
    }
    T *operator->() const noexcept
    {
        return ptr_;
    }
    operator bool() const noexcept
    {
        return ptr_;
    }

private:
    SharedCount *shared_count_;
    T *ptr_;
};

template <typename T>
void swap(SmartPtr<T> &lhs, SmartPtr<T> &rhs) noexcept
{
    lhs.swap(rhs);
};

template <typename T, typename U>
SmartPtr<T> static_pointer_cast(
    const SmartPtr<U> &other) noexcept
{
    T *ptr = static_cast<T *>(other.get());
    return SmartPtr<T>(other, ptr);
};

template <typename T, typename U>
SmartPtr<T> reinterpret_pointer_cast(
    const SmartPtr<U> &other) noexcept
{
    T *ptr = reinterpret_cast<T *>(other.get());
    return SmartPtr<T>(other, ptr);
};
template <typename T, typename U>
SmartPtr<T> const_pointer_cast(
    const SmartPtr<U> &other) noexcept
{
    T *ptr = const_cast<T *>(other.get());
    return SmartPtr<T>(other, ptr);
};
template <typename T, typename U>
SmartPtr<T> dynamic_pointer_cast(
    const SmartPtr<U> &other) noexcept
{
    T *ptr = dynamic_cast<T *>(other.get());
    return SmartPtr<T>(other, ptr);
}

class shape
{
public:
    virtual ~shape() {}
};

class circle : public shape
{
public:
    ~circle() { puts("~circle()"); }
};

int main()
{
    SmartPtr<circle> ptr1(new circle());
    std::printf("use count of ptr1 is %ld\n",
                ptr1.use_count());
    SmartPtr<shape> ptr2;
    std::printf("use count of ptr2 was %ld\n",
                ptr2.use_count());
    ptr2 = ptr1;
    std::printf("use count of ptr2 is now %ld\n",
                ptr2.use_count());
    if (ptr1)
    {
        dbg("ptr1 is not empty");
    }

    SmartPtr<circle> ptr3 =
        dynamic_pointer_cast<circle>(ptr2);
    std::printf("use count of ptr3 is %ld\n",
                ptr3.use_count());
}