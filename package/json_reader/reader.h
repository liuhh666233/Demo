#include <string>
#include <vector>
#include <fstream>
#include <nlohmann/json.hpp>
#include <filesystem>
#include <spdlog/spdlog.h>

namespace Reader
{
    class JsonReader
    {
    public:
        JsonReader(const std::string &file_path);
        ~JsonReader() = default;

        std::vector<std::string_view> getKeys();
        template <typename T>
        std::string getValue(T &&key);
        template <typename T, typename B>
        std::string setValue(T &&key, B &&value);
        bool save(const std::string &file_path);

    private:
        nlohmann::json json;
    };
}

Reader::JsonReader::JsonReader(const std::string &file_path)
{
    // 1.Check if file exists
    if (!std::filesystem::exists(file_path))
    {
        throw std::runtime_error("File does not exist");
    }
    spdlog::info("File {} exists", file_path);

    // 2. Read the file
    std::ifstream file(file_path);
    json = nlohmann::json::parse(file);
};

std::vector<std::string_view> Reader::JsonReader::getKeys()
{
    std::vector<std::string_view> keys;
    for (auto it = json.begin(); it != json.end(); ++it)
    {
        keys.push_back(it.key());
    };
    return keys;
};

template <typename T>
std::string Reader::JsonReader::getValue(T &&key)
{
    if (json.contains(key) == false)
    {
        spdlog::error("Key {} does not exist", key);
        throw std::runtime_error("Key does not exist");
    };
    return json[std::forward<T>(key)];
};

template <typename T, typename B>
std::string Reader::JsonReader::setValue(T &&key, B &&value)
{
    json[std::forward<T>(key)] = std::forward<B>(value);
    return json[std::forward<T>(key)];
};

bool Reader::JsonReader::save(
    const std::string &file_path)
{
    // 1. Check if file exists
    if (std::filesystem::exists(file_path))
    {
        spdlog::error("File {} already exists", file_path);
        return false;
    }
    spdlog::info("File {} does not exist", file_path);
    // 2. Write to file
    std::ofstream file(file_path);
    file << std::setw(4) << json << std::endl;
    spdlog::info("File {} saved", file_path);
    return true;
}