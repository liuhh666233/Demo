#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ifstream in("./data/510500.csv");
    if (!in)
    {
        cerr << "Cannot open the file" << endl;
        return -1;
    }
    string line;
    vector<string> words;
    while (getline(in, line))
    {
        words.push_back(line);
    }
    in.close();
    for (const auto &word : words)
    {
        cout << word << endl;
    }
    return 0;
}