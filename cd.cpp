#include "cd.hpp"
#include <filesystem>
#include <unistd.h>
#include <iostream>

void changeDir(std::string givenPath)
{
    std::filesystem::path newPath;

    if(givenPath == "."){
        return;
    }else if(givenPath == ".."){
        newPath = std::filesystem::current_path().parent_path();
    }else{
        newPath = std::filesystem::absolute(givenPath);
    }

    if(newPath.empty()){
        std::cerr << "cd: No parent directory.\\n";
        return;
    }
    if(chdir(newPath.c_str()) != 0){
        perror("cd");
    }

    return;
}