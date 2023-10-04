#include <type_traits>
using namespace std;

template <typename T>
struct has_reserve
{
    struct good
    {
        char dummy;
    };
    struct bad
    {
        char dummy[2];
    };
    template <class U, void (U::*)(size_t)>
    struct SFINAE
    {
    };
    template <class U>
    static good reserve(SFINAE<U, &U::reserve> *);
    template <class U>
    static bad reserve(...);
    static const bool value = sizeof(reserve<T>(nullptr)) == sizeof(good);
};

template <typename T, typename = void()>
struct has_reserve : false_type
{
};

template <typename T>
struct has_reserve<T, void_t<decltype(declval<T &>().reverse(1U))>> : true_type
{
};

template <typename C, typename T>
enable_if_t<has_reserve<C>::value,
            void>
append(C &container, T *ptr,
       size_t size)
{
    container.reserve(
        container.size() + size);
    for (size_t i = 0; i < size;
         ++i)
    {
        container.push_back(ptr[i]);
    }
}

template <typename C, typename T>
enable_if_t<!has_reserve<C>::value,
            void>
append(C &container, T *ptr,
       size_t size)
{
    for (size_t i = 0; i < size;
         ++i)
    {
        container.push_back(ptr[i]);
    }
}

template <typename C, typename T>
auto append(C &container, T *ptr, size_t size) -> decltype(declval<C &>().reserve(1U), void())
{
    container.reserve(
        cotainer.size() + size);
    for (size_t i = 0; i < size; ++i)
    {
        container.push_back(ptr[i]);
    }
}