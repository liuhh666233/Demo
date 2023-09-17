#include <iostream>
#include <vector>
#include <iterator>

using namespace std;
namespace MyNameSpace
{
    class MyClass
    {
    private:
        /* data */
    public:
        int value;
    };
    std::ostream &operator<<(std::ostream &os, const MyClass &myClass)
    {
        os << "MyClass:" << myClass.value;
        return os;
    }

}

int main()
{

    MyNameSpace::MyClass myClass;
    myClass.value = 100;
    using std::cout;
    using std::endl;
    cout << myClass << endl;

    std::vector<int> nums = {1, 2, 3, 4};
    std::istream_iterator<int> input(std::cin);
    std::copy(input, std::istream_iterator<int>(), std::back_inserter(nums));
    for (auto &i : nums)
    {
        cout << i << endl;
    }
    return 0;
}