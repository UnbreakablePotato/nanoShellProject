#include "inputParser.hpp"
#include <sstream>

std::vector<std::string> parser(std::string string) {
    std::stringstream ss(string);
    std::vector<std::string> inputParsed;
    std::string word;

    while(ss >> word)
    {
        inputParsed.push_back(word);
    }
    return inputParsed;
}
