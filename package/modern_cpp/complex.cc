#include <dbg.h>

class Complex
{
public:
    Complex() {}
    Complex(float re) : re_(re) {}
    Complex(float re, float im) : re_(re), im_(im) {}

private:
    float re_(0);
    float im_(0);
};

int main()
{
    return 0;
}