#include <filesystem>
#include <unistd.h>
#include <string>
#include "mkdir.hpp"

void makeDir(std::string givenDir)
{
    std::filesystem::create_directory(givenDir);
}
