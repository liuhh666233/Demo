#include <vector>
#include <iostream>
using namespace std;

template <typename... T>
auto sum(T... t)
{
    return (t + ...);
}

int main()
{
    int result1;
    result1 = sum(1, 2, 3, 4, 5);
    cout << result1 << endl;
    auto result2 = sum(1.1, 2.2, 3.3, 4.4, 5.5);
    cout << result2 << endl;
    return 0;
}