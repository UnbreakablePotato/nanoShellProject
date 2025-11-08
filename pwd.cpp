#include "pwd.hpp"
#include <filesystem>
#include <unistd.h>
#include <iostream>

std::string printWorkingDir()
{
    std::string path = std::filesystem::current_path().string();
    return path;
}