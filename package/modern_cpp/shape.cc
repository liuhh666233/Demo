#include <stdio.h>
#include <utility>
#include <dbg.h>

class shape
{
public:
    virtual ~shape() {}
};

class circle : public shape
{
public:
    circle() { puts("circle()"); }
    ~circle() { puts("~circle()"); }
};

class triangle : public shape
{
public:
    triangle() { puts("triangle()"); }
    ~triangle() { puts("~triangle()"); }
};

class result
{
public:
    result() { puts("result()"); }
    ~result() { puts("~result()"); }
};

result
process_shape(const shape &shape1,
              const shape &shape2)
{
    puts("process_shape()");
    return result();
};

void foo(const shape &)
{
    puts("foo(const shape &)");
};

void foo(shape &&)
{
    puts("foo(shape &&)");
}

template <typename T>
void bar(T &&s)
{
    // puts("bar(T&&)");
    foo(std::forward<T>(s));
}
template <typename T>
void myFunction(T &arg)
{
    dbg(arg);
}
int main()
{
    int x = 10;
    myFunction(x);
    int &y = x;
    myFunction(y);
    int &&z = std::move(x);
    myFunction(z);
    // myFunction(std::move(y));
    // puts("something else");
}