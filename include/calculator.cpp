#include "calculator.hpp"

calculator::calculator(const std::string path) {
    std::ifstream file(path);
    file >> itemJSON;

    std::clog << "Caught JSON file: " + path << std::endl;
    for (json::iterator it = itemJSON.begin(); it != itemJSON.end(); ++it) {
        if(it.value()) {
            std::clog << it.key() << ": " << itemList.size() << std::endl;
            itemList.push_back(it.key());
        }
    }
}