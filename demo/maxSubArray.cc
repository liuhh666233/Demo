#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main()
{
    string first_word = "acb";
    string second_word("cba");
    string third_word = "cdb";

    auto decode = [](const string &s) -> int
    {
        int res = 0;
        for (char ch : s)
        {
            res *= 10;
            res += ch - 'a';
        }
        return res;
    };

    if (decode(first_word) + decode(second_word) == decode(third_word))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    };
}