#include <iostream>
#include <typeinfo>
int main()
{
    // unsigned u = 42, u2 = 10;
    // std::cout << u - u2 << std::endl; // 32
    // std::cout << u2 - u << std::endl; // 4294967264
    // int i = 10, i2 = 42;
    // std::cout << i - i2 << std::endl;       // -32
    // std::cout << i2 - i << std::endl;       // 32
    // std::cout << i - u << std::endl;        // 4294967264
    // std::cout << u - i << std::endl;        // 32
    // std::cout << u + i << std::endl;        // 52
    // double salary = 999.99, wage = 9999.99; // error: ‘wage’ was not declared in this scope

    // std::cout << "global_str: " << global_str << std::endl;
    // std::cout << "global_int: " << global_int << std::endl;
    // int local_int;
    // std::cout << "local_int: " << local_int << std::endl;
    // // int double = 3.14; // error: expected ‘;’ before ‘=’ token
    // // int _;
    // // int catch - 22; // error: expected ‘;’ before ‘-’ token
    // // int 1_or_2 = 1; // error: expected ‘;’ before numeric constant
    // double Double = 3.14;
    // int i = 100;
    // int j = i;
    // std::cout << "i: " << i << std::endl;
    // std::cout << "j: " << j << std::endl;
    // int sum = 0;

    // for (int i = 0; i < 10; ++i)
    // {
    //     sum += i;
    // }

    // std::cout << "i: " << i << " sum: " << sum << std::endl;

    // int ival = 1.01;
    // int &rval1 = 1.01;
    // int &rval2 = ival;
    // int &rval3 =;
    // int i = 0, &r1 = i;
    // double d = 0, &r2 = d;
    // r2 = 3.14159;
    // std::cout << "i: " << i << " d: " << d << std::endl;
    // r2 = r1;
    // std::cout << "r2: " << r2 << std::endl;
    // i = r2;
    // std::cout << "i: " << i << std::endl;
    // r1 = d;
    // std::cout << "r1: " << r1 << std::endl;

    // int i, &ri = i;
    // i = 5;
    // ri = 10;
    // std::cout << "i: " << i << " ri: " << ri << std::endl;

    // int i = 42;
    // int *p1 = &i;
    // *p1 = *p1 * *p1;
    // std::cout << "i: " << i << " *p1: " << *p1 << std::endl;

    // int i = 0;
    // double *dp = &i;
    // int *ip = i;
    // int *p = &i;
    // int *p = nullptr;
    // std::cout << "p: " << *p << std::endl;
    // const int i = 2;
    // const int *const p1 = &i;
    // p = &i;

    // int i = 0, &r = i;
    // auto a = r;
    // const int ci = i, &cr = ci;
    // auto b = ci;
    // auto c = cr;
    // auto d = &i;
    // auto e = &ci;
    // const auto f = ci;
    // auto &g = ci;
    // const auto &j = 42;
    // auto k = ci, &l = i;
    // auto &m = ci, *p = &ci;
    // const auto &n = i, *p2 = &ci;
    // std::cout << "a: " << a << " b: " << b << " c: " << c << " d: " << d
    //           << " e: " << e << " f: " << f << " g: " << g << " j: " << j << " k: " << k << " l: " << l << " m: " << m << " p: " << p << " n: " << n << " p2: " << p2 << std::endl;
    // a = 42;
    // b = 42;
    // c = 42;
    // // d = 42;
    // // e = 42;
    // // g = 42;
    // std::cout << "a: " << a << " b: " << b << " c: " << c << " d: " << d
    //           << " e: " << e << " f: " << f << " g: " << g << " j: " << j << " k: " << k << " l: " << l << " m: " << m << " p: " << p << " n: " << n << " p2: " << p2 << std::endl;
    const int i = 42;

    auto j = i;
    const auto &k = i;
    auto *p = &i;
    const auto j2 = i, &k2 = i;
    std::cout << "i: " << typeid(i).name() << std::endl;
    std::cout << "j: " << typeid(j).name() << std::endl;
    std::cout << "k: " << typeid(k).name() << std::endl;
    std::cout << "p: " << typeid(p).name() << std::endl;
    std::cout << "j2: " << typeid(j2).name() << std::endl;
    std::cout << "k2: " << typeid(k2).name() << std::endl;

    return 0;
}