#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <array>
using namespace std;

int main()
{
    array<string, 12> exclude = {"The", "But", "And", "Or", "An", "A",
                                 "the", "but", "and", "or", "an", "a"};
    array<int, 12> ia1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 0};
    vector<pair<int, string>> word_count;
    auto it1 = ia1.begin();
    auto it2 = exclude.begin();
    for (; it1 != ia1.end() && it2 != exclude.end(); ++it1, ++it2)
        word_count.push_back(make_pair(*it1, *it2));
    for (auto &p : word_count)
        cout << p.first << " " << p.second << endl;
}