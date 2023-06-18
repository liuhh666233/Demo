#include <iostream>
#include <string>
#include "Sales_data.h"
using namespace std;

int main()
{
    Sales_data data1;
    Sales_data data2("0-201-78345-X");
    Sales_data data3("0-201-78345-X", 3, 20.00);
    Sales_data data4(cin);
    cout << data1.bookNo << " " << data1.units_sold << " " << data1.revenue << endl;
    cout << data2.bookNo << " " << data2.units_sold << " " << data2.revenue << endl;
    cout << data3.bookNo << " " << data3.units_sold << " " << data3.revenue << endl;
    cout << data4.bookNo << " " << data4.units_sold << " " << data4.revenue << endl;
    return 0;
}