#include <iostream>
#include <typeinfo>
#include <type_traits>

bool is_const(int x)
{
    return std::is_const<decltype(x)>::value;
}

int main()
{
    // const int i = 42;
    // auto j = i;
    // const auto &k = i;
    // auto *p = &i;
    // const auto j2 = i, &k2 = i;

    // std::cout << "i -> type: " << typeid(i).name() << " ;is const: " << std::is_const<decltype(i)>::value << std::endl;
    // std::cout << "j -> type: " << typeid(j).name() << " ;is const: " << std::is_const<decltype(j)>::value << std::endl;
    // std::cout << "k -> type: " << typeid(k).name() << " ;is const: " << std::is_const<decltype(k)>::value << std::endl;
    // std::cout << "p -> type: " << typeid(p).name() << " ;is const: " << std::is_const<decltype(*p)>::value << std::endl;
    // std::cout << "j2 -> type: " << typeid(j2).name() << " ;is const: " << std::is_const<decltype(j2)>::value << std::endl;
    // std::cout << "k2 -> type: " << typeid(k2).name() << " ;is const: " << std::is_const<decltype(k2)>::value << std::endl;

    int i = 42, *p = &i, &r = i;
    decltype(r + 0) b;
    std::cout << "b -> type: " << typeid(b).name() << " ;is const: " << std::is_const<decltype(b)>::value << std::endl;
    decltype(*p) c = i;
    std::cout << "c -> type: " << typeid(c).name() << " ;is const: " << std::is_const<decltype(c)>::value << std::endl;
    return 0;
}
