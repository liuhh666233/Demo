#include <iostream>

using namespace std;
using int_array = int[4];
int main()
{
    int ia[3][4] = {
        0,
        1,
        2,
        3,
        4,
        5,
        6,
        7,
        8,
        9,
        10,
        11};
    for (int(&row)[4] : ia)
    {
        for (int col : row)
        {
            cout << "First: " << col;
        }
    }
    cout << endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << "Second:" << ia[i][j];
        }
    }
    cout << endl;
    for (int(*p)[4] = ia; p != ia + 3; p++)
    {
        for (int *q = *p; q != *p + 4; q++)
        {
            cout << "Third: " << *q;
        }
    }
    cout << endl;

    for (int_array *p = ia; p != ia + 3; p++)
    {
        for (int *q = *p; q != *p + 4; q++)
        {
            cout << "Fourth: " << *q;
        }
    }
    cout << endl;

    for (int_array &row : ia)
    {
        for (int col : row)
        {
            cout << "Fifth: " << col;
        }
    }
    cout << endl;

    for (auto &row : ia)
    {
        for (auto col : row)
        {
            cout << "Sixth: " << col;
        }
    }
    cout << endl;

    for (auto p = ia; p != ia + 3; p++)
    {
        for (auto q = *p; q != *p + 4; q++)
        {
            cout << "Seventh: " << *q;
        }
    }
    cout << endl;
}