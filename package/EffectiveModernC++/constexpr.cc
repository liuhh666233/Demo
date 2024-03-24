#include <iostream>

using namespace std;

constexpr int pow(int base, int exp)
{
    return (exp == 0 ? 1 : base * pow(base, exp - 1));
};

class Point
{

public:
    constexpr Point(double xVal = 0, double yVal = 0) noexcept : x(xVal), y(yVal)
    {
    }
    Point(const Point &p) noexcept : x(p.x), y(p.y)
    {
        cout << "Point copy constructor called" << endl;
    }
    Point(Point &&p) noexcept : x(p.x), y(p.y)
    {
        cout << "Point move constructor called" << endl;
    }
    Point &operator=(const Point &p) noexcept
    {
        cout << "Point copy assignment operator called" << endl;
        x = p.x;
        y = p.y;
        return *this;
    }
    constexpr double xValue() const noexcept { return x; }
    constexpr double yValue() const noexcept { return y; }
    constexpr void setX(double newX) noexcept { x = newX; }
    constexpr void setY(double newY) noexcept { y = newY; }

private:
    double x, y;
};
using ConstPointRef = const Point &;

constexpr Point midPoint(ConstPointRef p1, ConstPointRef p2) noexcept
{
    return {(p1.xValue() + p2.xValue()) / 2, (p1.yValue() + p2.yValue()) / 2};
};

int main()
{
    constexpr Point p(9.4, 27.7);
    cout << "p.xValue() = " << p.xValue() << ", p.yValue() = " << p.yValue() << endl;
    cout << "p.xValue() = " << p.xValue() << ", p.yValue() = " << p.yValue() << endl;
    constexpr Point p1 = {9.4, 27.7};
    // NVRO 返回的临时对象，会直接在调用处构造，不会调用拷贝构造函数和移动构造函数
    constexpr Point p2 = midPoint(p, p1);
    // Point p2{move(midPoint(p, p1))};
    cout << "p2.xValue() = " << p2.xValue() << ", p2.yValue() = " << p2.yValue() << endl;
    return 0;
}