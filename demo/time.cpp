#include <chrono>
#include <iostream>
#include <vector>

std::vector<long long> memo;

long Fibonacci(unsigned n)
{
    if (n <= 1)
        return n;
    if (memo[n] != -1)
        return memo[n];
    return memo[n] = Fibonacci(n - 1) + Fibonacci(n - 2);
}
long fib(int n)
{
    if (n <= 1)
        return n;
    long long a = 0, b = 1;
    for (int i = 2; i <= n; i++)
    {
        long long next = a + b;
        a = b;
        b = next;
    }
    return b;
}
int main()
{
    const auto start{std::chrono::steady_clock::now()};
    int n = 42;
    memo.assign(n + 1, -1);
    const auto fb{fib(n)};
    const auto end{std::chrono::steady_clock::now()};
    const std::chrono::duration<double> elapsed_seconds{end - start};

    std::cout << "Fibonacci(42): " << fb << " Elapsed time: ";
    std::cout << elapsed_seconds.count() * 1000000 << "us\n"; // Before C++20
}