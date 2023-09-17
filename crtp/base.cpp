#include <iostream>
#include <vector>

class NonCopyable
{
public:
    NonCopyable() = default;
    ~NonCopyable() = default;

    // Delete the copy constructor
    NonCopyable(const NonCopyable &) = delete;

    // Delete the copy assignment operator
    NonCopyable &operator=(const NonCopyable &) = delete;
};

template <typename Derived>
class Base : private NonCopyable
{
public:
    void interface()
    {
        static_cast<Derived *>(this)->implementation();
    };
    void implementation()
    {
        std::cout << "Base implementation" << std::endl;
    };
};
class Derived1 : public Base<Derived1>
{
public:
    Derived1(std::vector<int> &x) : v(x){};

    void implementation()
    {
        std::cout << "Derived1 implementation" << std::endl;
        for (auto &i : v)
        {
            std::cout << i << std::endl;
        }
    };

private:
    std::vector<int> v;
};

class Derived2 : public Base<Derived2>
{
public:
    // void implementation()
    // {
    //     std::cout << "Derived2 implementation" << std::endl;
    // };
};

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5};
    Derived1 d1(v);
    d1.interface();
    Derived2 d2;
    d2.interface();
    return 0;
}