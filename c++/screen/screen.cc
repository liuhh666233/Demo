#include "screen.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display();
    cout << endl;
    myScreen.display();
    return 0;
}