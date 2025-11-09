#include "touch.hpp"
#include <iostream>
#include <fstream>

void touchCommand(std::string filename)
{
    std::ofstream newFile(filename);

    newFile.close();
}