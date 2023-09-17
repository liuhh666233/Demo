#include <iostream>
#include "tutorial.h"
#include "TutorialConfig.h"
#include "MathFunctions.h"

int main(int argc, char **argv)
{
    // Suppress unused parameter warning.
    (void)argc;
    std::cout << "Hello World!" << std::endl;
    Tutorial t(5);
    t.printValue(std::cout);
    std::cout << "Tutorial version: " << Tutorial_VERSION_MAJOR << "." << Tutorial_VERSION_MINOR << std::endl;
    const double inputValue = std::stod(argv[1]);
    std::cout << "Input value: " << inputValue << std::endl;
    const double outputValue = mathfunctions::sqrt(inputValue);
    std::cout << "Output value: " << outputValue << std::endl;
    return 0;
}