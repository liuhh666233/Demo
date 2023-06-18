#include <iostream>
#include <string>
#include <vector>

using namespace std;

string sa[10];
int ia[10];

int main()
{
    // unsigned buf_size = 1024;
    // int ia[buf_size]; // error: buf_size is not a constant expression
    // int id[4 * 7 - 14]; // ok: 4 * 7 - 14 is a constant expression
    // // int ia[txt_size()]; // error: txt_size() is not a constant expression
    // // char st[11] = "fundamental"; // error: no space for the null
    // cout << ia[0] << endl;

    // string sa2[10];
    // int ia2[10];
    // // for (int i = 0; i < 10; i++) {
    // //     cout << sa[i] << " " << sa2[i] << " " << ia[i] << " " << ia2[i] << endl;
    // // }
    // unsigned scores[11] = {};
    // unsigned grade;
    // while (cin >> grade) {
    //     if (grade <= 100) {
    //         ++scores[grade/10];
    //     }
    // }
    // for (auto i : scores) {
    //     cout << i << " ";
    // }
    // int ia[10] = {};
    // for (
    //     int ix = 0;
    //     ix != 10;
    //     ++ix)
    //     ia[ix] = ix;
    // for (auto i : ia)
    // {
    //     cout << i << " ";
    // }
    int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (
        auto i = ia;
        i != ia + 10;
        ++i)
    {
        *i = 0;
        cout << *i << " ";
    }

    return 0;
}