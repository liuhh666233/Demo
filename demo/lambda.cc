#include <iostream>
#include <typeinfo>
#include <iomanip>
#include <map>
#include <string>

template <typename T>
constexpr T pi = T(3.1415926535897932385);

int main()
{
    int x = 5;
    auto a = x;           // a的类型是int
    auto b = &x;          // b的类型是int*
    int &c = x;           // c的类型是int&
    auto &d = c;          // d的类型是int
    decltype(auto) e = c; // e的类型是int &
    c = 10;
    std::cout << "x: " << x << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << *b << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "d: " << d << std::endl;
    std::cout << "e: " << e << std::endl;
    auto sum = [](auto a, auto b)
    { return a + b; };
    std::cout << "sum: " << sum(1, 2) << std::endl;
    decltype(auto) z = sum(1, 2);
    std::cout << "z: " << z << std::endl;
    // float r = pi<float>;
    // std::cout << "r: " << r << std::endl;
    double s = pi<double>;
    double t = 3.1415926535897932385;
    std::cout << std::setprecision(15) << "t: " << t << std::endl;

    std::map<std::string, int> m;
    m["hello"] = 1;
    m["world"] = 2;
    auto [iter, success] = m.emplace("hello", 3);
    std::cout << "iter->first: " << iter->first << success << std::endl;
    return 0;
}