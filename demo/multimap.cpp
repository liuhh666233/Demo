#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
    multimap<string, string> authors;
    authors.insert({"Barth, John", "Sot-Weed Factor"});
    authors.insert({"Barth, John", "Lost in the Funhouse"});
    authors.insert({"Alain de Botton", "On Love"});
    authors.insert({"Alain de Botton", "Status Anxiety"});
    for (const auto &author : authors)
        cout << author.first << " " << author.second << endl;
}