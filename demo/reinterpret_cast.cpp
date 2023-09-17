#include <iostream>

int main()
{
    int num = 42;
    int *num_ptr = &num;

    // Disguise the integer pointer as a char pointer
    char *char_ptr = reinterpret_cast<char *>(num_ptr);

    for (size_t i = 0; i < sizeof(int); ++i)
    {
        // Print the individual bytes of the integer as characters
        std::cout << "Byte " << i << ": " << char_ptr[i] << std::endl;
    }

    return 0;
}