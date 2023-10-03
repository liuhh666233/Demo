#include <iostream>
#include <dbg.h>

enum struct ShapeType
{
    Circle,
    Square,
    Triangle,
};

class Shape
{
public:
    Shape()
    {
        std::cout << "Shape constructor" << std::endl;
    };
    virtual ~Shape()
    {
        std::cout << "Shape destructor" << std::endl;
    };
    virtual void print()
    {
        std::cout << "Shape print" << std::endl;
    };
};

class Circle : public Shape
{
public:
    Circle()
    {
        std::cout << "Circle constructor" << std::endl;
    };
    ~Circle()
    {
        std::cout << "Circle destructor" << std::endl;
    };
    void print() override
    {
        std::cout << "Circle print" << std::endl;
    };
};

class Square : public Shape
{
public:
    Square()
    {
        std::cout << "Square constructor" << std::endl;
    };
    ~Square()
    {
        std::cout << "Square destructor" << std::endl;
    };
    void print() override
    {
        std::cout << "Square print" << std::endl;
    };
};
class Triangle : public Shape
{
public:
    Triangle()
    {
        std::cout << "Triangle constructor" << std::endl;
    };
    ~Triangle()
    {
        std::cout << "Triangle destructor" << std::endl;
    };
    void print() override
    {
        std::cout << "Triangle print" << std::endl;
    };
};

Shape *CreateShape(ShapeType type)
{
    switch (type)
    {
    case ShapeType::Circle:
        return new Circle();
    case ShapeType::Square:
        return new Square();
    case ShapeType::Triangle:
        return new Triangle();
    default:
        return nullptr;
    }
}

class ShapeWrapper
{
public:
    explicit ShapeWrapper(Shape *ptr = nullptr) : ptr_(ptr){};
    ~ShapeWrapper()
    {
        delete ptr_;
    };
    Shape *get() const
    {
        return ptr_;
    };

private:
    Shape *ptr_;
};

void func()
{
    ShapeWrapper ptr(CreateShape(ShapeType::Circle));
    ptr.get()->print();
}

template <typename T>
class SmartPtr
{
public:
    explicit SmartPtr(T *ptr = nullptr) : ptr_(ptr){};

    template <typename U>
    SmartPtr(SmartPtr<U> &&rhs)
    {
        ptr_ = rhs.release();
    };

    ~SmartPtr()
    {
        delete ptr_;
    };

    SmartPtr &operator=(SmartPtr rhs)
    {
        rhs.swap(*this);
        return *this;
    };

    T *get() const
    {
        return ptr_;
    };

    T *release()
    {
        T *tmp = ptr_;
        ptr_ = nullptr;
        return tmp;
    };

    void swap(SmartPtr &rhs)
    {
        using std::swap;
        swap(ptr_, rhs.ptr_);
    };

    T &operator*() const
    {
        return *ptr_;
    };
    // 重载->运算符
    // 通过->运算符,会先检查对象是否为指针,如果是指针,则直接返回,如果不是指针,则先调用对象的operator->,然后再调用返回的对象的operator->,直到最后返回一个指针为止
    T *operator->() const
    {
        return ptr_;
    };
    operator bool() const
    {
        return ptr_;
    };

private:
    T *ptr_;
};

int main()
{

    // SmartPtr<Shape> ptr2(CreateShape(ShapeType::Square));
    // ptr2->print();
    // SmartPtr<Shape> ptr3;
    // ptr3 = std::move(ptr2);
    // ptr3->print();
    // SmartPtr<Shape> ptr4{std::move(ptr3)};
    // ptr4->print();
    SmartPtr<Shape> ptr5{std::move(CreateShape(ShapeType::Circle))};
    ptr5->print();

    return 0;
}
