#include <iostream>

template <typename T>
void print(const T &t)
{
    std::cout << t << std::endl;
}
template <typename... Args>
void print(Args... args)
{
    (..., (std::cout << args << ' '));
}
template <typename... Args>
auto sum(Args... args)
{
    return (... + args);
}

int main()
{
    print(1);
    print(1.1);
    print("hello");
    print(std::string("world"));
    print(1, 2, 3, 4, 5);
    int args[] = {1, 2, 3, 4, 5};
    print(sum(1, 2, 3, 4, 5));
    return 0;
}
