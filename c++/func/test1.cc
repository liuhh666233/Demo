#include <iostream>
#include <vector>

using namespace std;

int func1(int &i, int &j)
{
    return i + j;
}
int func2(int &i, int &j)
{
    return i - j;
}
int func3(int &i, int &j)
{
    return i * j;
}
int func4(int &i, int &j)
{
    return i / j;
}

void print(vector<int> &vInt, unsigned index)
{
    unsigned size = vInt.size();
#ifdef NDEBUG
    cout << "index: " << index << " size: " << size << endl;
#endif
    if (!vInt.empty() && index < size)
    {
        cout << vInt[index] << endl;
        print(vInt, index + 1);
    }
}

int main()
{
    vector<decltype(func1) *> vFunc = {
        func1,
        func2,
        func3,
        func4,
    };
    int i = 10, j = 5;
    for (auto &func : vFunc)
    {
        cout << func(i, j) << endl;
    }

    return 0;
}
