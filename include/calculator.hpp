#include <fstream>
#include <iostream>
#include "json.hpp"
#include "vec.hpp"

using json = nlohmann::json;

class calculator {
private:
    std::vector<std::string> itemList;
    json itemJSON;
public:
    calculator(const std::string);
};