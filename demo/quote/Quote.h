
#include <string>
#include <iostream>

using namespace std;

class Quote
{
private:
    /* data */
    std::string bookNo;

protected:
    double price = 0.0;

public:
    Quote() = default;
    Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) {}
    std::string isbn() const { return bookNo; }
    virtual double net_price(std::size_t n) const { return n * price; }
    virtual ~Quote() = default;
};

double print_total(std::ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
    return ret;
}

class DiscQuote : public Quote
{
protected:
    /* data */
    std::size_t quantity = 0;
    double discount = 0.0;

public:
    DiscQuote() = default;
    DiscQuote(const std::string &book, double price, std::size_t qty, double disc) : Quote(book, price), quantity(qty), discount(disc) {}
    double net_price(std::size_t) const = 0;
};

class BulkQuote : public DiscQuote
{
public:
    BulkQuote(const std::string &book, double sales_price, std::size_t qty, double disc) : DiscQuote(book, sales_price, qty, disc){};
    double net_price(std::size_t n) const override;
};

double BulkQuote::net_price(std::size_t n) const
{
    if (n >= quantity)
    {
        return n * (1 - discount) * price;
    }
    else
    {
        return n * price;
    }
}