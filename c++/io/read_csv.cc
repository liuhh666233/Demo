#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <chrono>

int main()
{
    auto start = std::chrono::high_resolution_clock::now();

    std::ifstream file("data/510500.csv");
    std::string line;

    while (std::getline(file, line))
    {
        std::stringstream lineStream(line);
        std::string cell;

        while (std::getline(lineStream, cell, ','))
        {
            // process cell
            // std::cout << cell << std::endl;
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "Time taken in C++: " << duration.count() / 1000.0 << " ms" << std::endl;

    return 0;
}
