#include <iostream>
#include <typeinfo>
#include <vector>
#include <boost/core/demangle.hpp>

using namespace std;
using boost::core::demangle;

int main()
{
    vector<int> v;
    auto it = v.begin();
    cout << typeid(it).name() << endl;
    cout << demangle(typeid(it).name()) << endl;

    cout << typeid(v).name() << endl;
    cout << demangle(typeid(v).name()) << endl;
    return 0;
}