#include <string>
#include <iostream>

using namespace std;

class Sales_data
{
private:
    /* data */
public:
    Sales_data() = default;
    Sales_data(const std::string &s) : bookNo(s){};
    Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n){};
    Sales_data(istream &is);

public:
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

istream &read(istream &is, Sales_data &data)
{
    is >> data.bookNo >> data.units_sold >> data.revenue;
    return is;
}

Sales_data::Sales_data(std::istream &is)
{
    read(is, *this);
}

const Sales_data &combine(const Sales_data &data)
{
    return data;
};

int main()
{
    string a = "123";
    cout << combine(a).bookNo << endl;
    return 0;
}
