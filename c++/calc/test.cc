#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    vector<int> vInt;
    const int sz = 10;
    srand((unsigned)time(NULL));
    cout << "The random number is: " << endl;
    for (int i = 0; i < sz; i++)
    {
        vInt.push_back(rand() % 100);
        cout << vInt[i] << " ";
    }
    cout << endl;
    for (auto &i : vInt)
    {
        i = (i % 2 == 0) ? i : i * 2;
    }
    cout << "The new number is: " << endl;
    for (auto it = vInt.begin(); it != vInt.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}