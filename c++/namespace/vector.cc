#include <vector>
#include <string>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

template <typename T>
void print_vector(string name, vector<T> &v)
{
    cout << name << " " << v.size() << " " << v.capacity() << " --> ";
    if (v.empty())
    {
        cout << "empty" << endl;
        return;
    }
    else
    {
        for (auto i : v)
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main()
{
    vector<int> v1;
    print_vector("v1", v1);

    vector<int> v2(10);
    print_vector("v2", v2);

    vector<int> v3(10, 42);
    print_vector("v3", v3);

    vector<int> v4{10};
    print_vector("v4", v4);

    vector<int> v5{10, 42};
    print_vector("v5", v5);

    vector<string> v6{10};
    print_vector("v6", v6);

    vector<string> v7{10, "hi"};
    print_vector("v7", v7);

    return 0;
}