#include "inputParser.hpp"
#include <sstream>

std::vector<std::string> parser(std::string string) {
    std::stringstream ss(string);
    std::vector<std::string> inputParsed;
    std::vector<std::string> stringParsed;
    std::string word;

    while(ss >> word /*&& word != "\""*/)
    {
        inputParsed.push_back(word);
    }

    /*if(word == "\""){
        while(word!="\""){
            stringParsed.push_back(word);
        }
        return stringParsed;
    }*/
    return inputParsed;
}
