#include <algorithm>
#include <iostream>
#include <cstring>
class String
{
private:
    /* data */
    char *data;

public:
    String(/* args */) = default;
    String(const String &s) : data(new char[std::strlen(s.data) + 1])
    {
        std::strcpy(data, s.data);
    }
    void swap(String &rhs)
    {
        std::swap(this->data, rhs.data);
    }
    String &operator=(String rhs)
    {
        swap(rhs);
        return *this;
    }
    bool operator==(const String &rhs) const
    {
        return std::strcmp(this->data, rhs.data) == 0;
    }
};

int main()
{
    String s1;
    String s2;
    s1 = s2;
    if (s1 == s2)
        std::cout << "s1 == s2" << std::endl;
    else
        std::cout << "s1 != s2" << std::endl;
    return 0;
}