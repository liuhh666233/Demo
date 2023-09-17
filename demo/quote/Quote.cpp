#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include "Quote.h"

using namespace std;

int main()
{
    Quote q("C++ Primer", 128.0);
    BulkQuote bq("C++ Primer", 128.0, 10, 0.2);
    vector<shared_ptr<Quote>> vq;
    vq.push_back(make_shared<Quote>(q));
    vq.push_back(make_shared<BulkQuote>(bq));
    for (auto &i : vq)
    {
        cout << i->net_price(10) << endl;
    }
    return 0;
}