#include <iostream>
#include <type_traits>
#include <vector>
using namespace std;
template <typename T, typename = void>
struct foo_impl
{
    void operator()(T t)
    {
        std::cout << "Called when T is not arithmetic" << std::endl;
    }
};

template <typename T>
struct foo_impl<T, std::enable_if_t<std::is_arithmetic<T>::value>>
{
    void operator()(T t)
    {
        std::cout << "Called when T is arithmetic" << std::endl;
    }
};

template <typename T>
void foo(T t)
{
    foo_impl<T>()(t);
}

int main()
{
    int a = 5;
    foo(a); // output: Called when T is arithmetic

    std::string s = "example";
    foo(s); // output: Called when T is not arithmetic

    double f = 1.0;
    foo(f); // output: Called when T is arithmetic

    std::vector<int> v = {1, 2, 3};
    foo(v); // output: Called when T is not arithmetic

    char c = 'a';
    foo(c);

    cout << std::is_integral_v<int> << endl;
    return 0;
}