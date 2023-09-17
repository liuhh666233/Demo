#include <iostream>
#include <tuple>
#include <type_traits>

template <typename T>
T sum(T t)
{
    return t;
}

template <typename T, typename... Args>
T sum(T t, Args... args)
{
    return t + sum(args...);
}

template <typename T>
void printData(const T &t)
{
    std::cout << t << std::endl;
}

template <>
void printData(const std::string &t)
{
    std::cout << "string: " << t << std::endl;
}
template <typename K, typename V>
class MyPair
{
public:
    MyPair(K key, V value) : key(key), value(value) {}
    void print() const
    {
        std::cout << "key: " << key << ", value: " << value << std::endl;
    }

private:
    K key;
    V value;
};
template <typename T>
class MyPair<T, int>
{
public:
    MyPair(T key, int value) : key(key), value(value) {}
    void print() const
    {
        std::cout << "Partial specialization for int values: "
                  << "key: " << key << ", value: " << value << std::endl;
    }

private:
    T key;
    int value;
};

template <typename T>
typename std::enable_if<std::is_arithmetic<T>::value, T>::type find_max(T a, T b)
{
    return a > b ? a : b;
}

int main()
{
    int result = sum(1, 2, 3, 4, 5);
    std::cout << result << std::endl;
    std::tuple<int, int, int> t = {1, 2, 3};
    printData(1);
    printData("hello");
    MyPair<std::string, int> p1("hello", 1);
    p1.print();
    MyPair<std::string, std::string> p2("hello", "world");
    p2.print();

    return 0;
}