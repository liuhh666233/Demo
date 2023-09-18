#include <iostream>
#include <filesystem>

int main(int argc, char **argv)
{
    if (argc < 1)
    {
        std::cout << "Usage: " << argv[0] << " <path>" << std::endl;
        return 1;
    }

    std::filesystem::path p(argv[1]);
    std::cout << "Loading " << p << std::endl;
    if (std::filesystem::exists(p))
    {
        if (std::filesystem::is_directory(p))
        {
            std::cout << "Is a directory" << std::endl;
        }
        else if (std::filesystem::is_regular_file(p))
        {
            std::cout << "Is a regular file" << std::endl;
        }
        else
        {
            std::cout << "Is a special file" << std::endl;
        }
    }
    else
    {
        std::cout << "File does not exist" << std::endl;
    }

    return 0;
}