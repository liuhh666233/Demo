#include <iostream>
#include <string>

using namespace std;

class Window_mgr
{
public:
    void clear();
};

class Screen
{
    friend void Window_mgr::clear();

private:
    unsigned height = 0, width = 0;
    unsigned cursor = 0;
    string contents;

public:
    Screen() = default;
    Screen(unsigned ht, unsigned wd) : height(ht), width(wd), contents(ht * wd, ' ') {}
    Screen(unsigned ht, unsigned wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}

public:
    Screen &move(unsigned r, unsigned c)
    {
        cursor = r * width + c;
        return *this;
    }
    Screen &set(char c)
    {
        contents[cursor] = c;
        return *this;
    }
    Screen &set(unsigned r, unsigned c, char ch)
    {
        contents[r * width + c] = ch;
        return *this;
    }
    Screen &display()
    {
        cout << contents;
        return *this;
    }
};

void Window_mgr::clear()
{
    Screen myScreen(5, 5, 'X');
    cout << "Before clearing:" << endl;
    myScreen.display();
    cout << endl;
    myScreen.contents = "";
    cout << "After clearing:" << endl;
    myScreen.display();
    cout << endl;
};