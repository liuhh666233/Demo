#ifndef MY_STRBLOB_H
#define MY_STRBLOB_H

#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <stdexcept>

using namespace std;
class StrBlob
{
    friend class StrBlobPtr;

public:
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> il);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const string &t) { data->push_back(t); }
    void pop_back();
    string &front();
    string &back();
    const string &front() const;
    const string &back() const;

private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const;
};

StrBlob::StrBlob() : data(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}
void StrBlob::check(size_type i, const string &msg) const
{
    if (i >= data->size())
        throw out_of_range(msg);
}
string &StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
}
string &StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}
const string &StrBlob::front() const
{
    check(0, "front on empty StrBlob");
    return data->front();
}
const string &StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return data->back();
}
void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

class StrBlobPtr
{
public:
    StrBlobPtr(StrBlob &a) : wptr(a.data), curr(0){};
    string &operator*() const;
    string *operator->() const;
    StrBlobPtr &operator++()
    {
        curr++;
        return *this;
    };

private:
    weak_ptr<vector<string>> wptr;
    size_t curr;
};

string &StrBlobPtr::operator*() const
{
    auto sp = wptr.lock();
    return (*sp)[curr];
}
string *StrBlobPtr::operator->() const
{
    return &this->operator*();
}

#endif // MY_STRBLOB_H