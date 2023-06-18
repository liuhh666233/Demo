#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main()
{
    // string line;
    // while (getline(cin, line))
    // {
    //     if (line == "w")
    //     {
    //         cout << "break" << endl;
    //         break;
    //     }
    //     cout << line << endl;
    //     auto len = line.size();
    //     cout << "num: " << len << endl;
    // }

    // string str("some string!!!!");
    // decltype(str.size()) punct_cnt = 0;
    // for (auto c : str)
    // {
    //     if (ispunct(c))
    //     {
    //         ++punct_cnt;
    //     }
    // }
    // cout << punct_cnt << endl;

    // string str("hello world!!!");
    // for (auto &c : str)
    // {
    //     c = toupper(c);
    // }
    // cout << str << endl;
    // if (!str.empty())
    // {
    //     cout << str[0] << endl;
    // }

    // for (decltype(str.size()) index = 0; index != str.size() && !isspace(str[index]); ++index)
    // {
    //     str[index] = toupper(str[index]);
    // }
    // cout << str << endl;
    string str("hello world!!!");
    char x = 'X';
    for (char &c : str)
    {
        c = x;
    }
    cout << str << endl;
}