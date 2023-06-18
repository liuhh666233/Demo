#include <iostream>
#include <string>

using namespace std;

istream &read(istream &is, Person &person)
{
    is >> person.name >> person.address;
    return is;
}

ostream &print(ostream &os, const Person &person)
{
    os << person.getName() << person.getAddress();
    return os;
}

class Person
{
private:
public:
    string name;
    string address;
    string getName() const { return name; }
    string getAddress() const { return address; }

public:
    Person() = default;
    Person(const string &n, const string &a) : name(n), address(a) {}
    Person(istream &is) { read(is, *this); }
};
