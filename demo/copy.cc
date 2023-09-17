#include <iostream>
#include <string>
#include <memory>

class MyString
{
public:
    MyString(const std::string &str) : data(std::make_shared<std::string>(str)){};
    MyString(const MyString &other) : data(other.data)
    {
        std::cout << "Copied using the copy-write idiom" << std::endl;
    };

    void write(const std::string &str)
    {
        if (!data.unique())
        {
            data = std::make_shared<std::string>(*data);
            std::cout << "Copied the data" << std::endl;
        }
        *data = str;
    }

private:
    std::shared_ptr<std::string> data;
};

int main()
{
    MyString s1("Hello");
    MyString s2(s1);
    s1.write("World");
    s2.write("World");
    return 0;
}