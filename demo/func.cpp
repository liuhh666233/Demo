#include <functional>
#include <iostream>
#include <map>
using namespace std;

namespace MyNamespace
{
    int add(int a, int b)
    {
        return a + b;
    }
} // namespace MyNamespace

int main()
{
    map<string, function<int(int, int)>> binops = {
        {"+", plus<int>()},
        {"-", minus<int>()},
        {"*", multiplies<int>()},
        {"/", divides<int>()},
        {"%", modulus<int>()}};
    int left, right;
    string op;
    cin >> left >> op >> right;
    cout << binops[op](left, right) << endl;
    cout << MyNamespace::add(1, 2) << endl;
    return 0;
}