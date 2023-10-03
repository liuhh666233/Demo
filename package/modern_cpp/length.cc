#include <dbg.h>
struct length
{
    double value;
    enum unit
    {
        metre,
        kilometre,
        millimetre,
        cetimetre,
        inch,
        foot,
        yard,
        mile,
    };
    static constexpr double factors[] = {
        1.0,
        1000.0,
        1e-3,
        1e-2,
        0.0254,
        0.3408,
        0.9144,
        1609.344,
    };
    explicit length(double v, unit u = metre)
    {
        value = v * factors[u];
    };
};
length operator+(length lhs, length rhs)
{
    return length(lhs.value + rhs.value);
};
length operator"" _m(long double v)
{
    return length(v, length::metre);
};
length operator"" _cm(long double v)
{
    return length(v, length::cetimetre);
};
int main()
{
    length a = 10.0_m + 10.0_cm;
    dbg(a.value);
    return 0;
}