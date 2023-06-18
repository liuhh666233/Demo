#include <iostream>
#include <vector>
using namespace std;

int &get(int *arry, int index)
{
    return arry[index];
}

int factorial(int val)
{
    if (val > 1)
    {
        return factorial(val - 1) * val;
    }
    return 1;
}

int recursivePrint(vector<int> &vec, int index)
{
    if (index < vec.size())
    {
        cout << vec[index] << endl;
        return recursivePrint(vec, index + 1);
    }
    return 0;
}

int odd[] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8};

decltype(odd) &arrPtr(int i)
{
    return (i % 2) ? odd : even;
}

int main()
{
    int ia[10] = {0};
    for (int i = 0; i < 10; i++)
    {
        get(ia, i) = i;
    }
    for (auto i : ia)
    {
        cout << i << endl;
    }
    cout << factorial(5) << endl;
    vector<int> vec = {1, 2, 3, 4, 5};
    recursivePrint(vec, 0);
}