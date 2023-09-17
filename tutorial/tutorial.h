#include <iostream>

class Tutorial
{
private:
    int m_value;

public:
    Tutorial(int value) : m_value(value) {}
    void printValue(std::ostream &out) const;
    ~Tutorial() = default;
};

void Tutorial::printValue(
    std::ostream &out) const
{
    out << "Value: " << m_value << std::endl;
}