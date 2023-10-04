#include <iostream>

struct Noisy
{
    Noisy() { std::cout << "constructed at " << this << '\n'; }
    Noisy(const Noisy &) { std::cout << "copy-constructed\n"; }
    Noisy(Noisy &&) { std::cout << "move-constructed\n"; }
    ~Noisy() { std::cout << "destructed at " << this << '\n'; }
    Noisy operator=(Noisy &) { std::cout << "copy-assigned\n"; }
    Noisy operator=(Noisy &&) { std::cout << "move-assigned\n"; }
};

Noisy f()
{
    Noisy v = Noisy(); // (until C++17) copy elision initializing v from a temporary;
                       //               the move constructor may be called
                       // (since C++17) "guaranteed copy elision"
    return v;          // copy elision ("NRVO") from v to the result object;
                       // the move constructor may be called
}

void g(Noisy arg)
{
    std::cout << "&arg = " << &arg << '\n';
}

int main()
{
    Noisy v = f(); // (until C++17) copy elision initializing v from the result of f()
                   // (since C++17) "guaranteed copy elision"
    std::cout << "&v = " << &v << '\n';

    Noisy w = std::move(v);
    std::cout << "&w=" << &w << std::endl;

    g(f()); // (until C++17) copy elision initializing arg from the result of f()
            // (since C++17) "guaranteed copy elision"
}