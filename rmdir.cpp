#include "rmdir.hpp"
#include <filesystem>

bool removeDir(std::string givenPath)
{
    bool isRemoved = std::filesystem::remove(givenPath);

    return isRemoved;
}