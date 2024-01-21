#include <iostream>
#include <filesystem>

void print_files(const std::filesystem::path &path)
{
    if (!std::filesystem::exists(path))
    {
        std::cout << "Path does not exist: " << path << '\n';
        return;
    }

    for (const auto &entry : std::filesystem::recursive_directory_iterator(path))
    {
        if (std::filesystem::is_regular_file(entry))
        {
            std::cout << entry.path() << '\n';
        }
    }
}

int main()
{
    std::filesystem::path path_to_traverse = "/home/lhh/github";
    print_files(path_to_traverse);
    return 0;
}
