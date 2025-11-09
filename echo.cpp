#include "echo.hpp"
#include <iostream>
#include <fstream>

void echoPrint(std::string givenString)
{
    std::cout << givenString;
}

void echoWriteToFile(std::string filename, std::string input)
{
    std::ofstream file(filename);

    file << input;

    file.close();
}

void echoAppendToFile(std::string filename, std::string input)
{
    std::ofstream file;

    file.open(filename,std::ios::out);

    file << input;

    file.close();
}

