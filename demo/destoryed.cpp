#include <iostream>

class A {
public:
    A() { std::cout << "A constructed" << std::endl; }
    ~A() { std::cout << "A destroyed" << std::endl; }
};

class B {
    A a;
public:
    B() { std::cout << "B constructed" << std::endl; }
    ~B() {
        std::cout << "B destructor body" << std::endl;
        // 在此处，我们可以访问并使用成员变量 'a'
    }
};


int main() {
    B b;
    return 0;
}
