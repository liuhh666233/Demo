#include "reader.h"
#include <iostream>
using namespace Reader;

int main()
{
    JsonReader reader("config.json");
    std::vector<std::string_view> keys = reader.getKeys();
    for (auto &key : keys)
    {
        std::cout << key << " : " << reader.getValue(key) << std::endl;
        reader.setValue(key, "new_value");
        std::cout << key << " : " << reader.getValue(key) << std::endl;
    }
    reader.save("config_new.json");
    return 0;
}