#include <string>
using namespace std;

class StrVec
{
public:
    std::string &operator[](std::size_t n);
    const std::string &operator[](std::size_t n) const
    {
        return elements[n];
    }

private:
    std::string *elements;
    std::string *first_free;
    std::string *cap;
};

std::string &StrVec::operator[](std::size_t n)
{
    return elements[n];
}

int main()
{
    StrVec sv;
    sv[0] = "hello";
    return 0;
}