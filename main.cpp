#include <iostream>
#include <vector>
#include <string>
#include "inputParser.hpp"
#include "execute.hpp"
#include <filesystem>
#include "cd.hpp"

std::string getPathFromHome()
{
    std::string string = std::filesystem::current_path();
    return string.substr(string.find_last_of("/") + 1);
}

std::string handleCommands(std::vector<std::string> input){
    if(input.empty()){
        return "";
    }
    
    //cd command
    if(input[0] == "cd"){
        if(input.size()==1){
            return "Path not provided...\n";
        }
        changeDir(input[1]);
        return "";
    }
}

int main()
{
    while(true)
    {
        std::cout << "=================================================================" <<"\n";
        std::cout << "=================================================================" <<"\n";
        std::cout << "      ___           ___           ___           ___     " << "\n";
        std::cout << "     /\\__\\         /\\  \\         /\\__\\         /\\  \\    " << "\n";
        std::cout << "    /::|  |       /::\\  \\       /::|  |       /::\\  \\   " << "\n";
        std::cout << "   /:|:|  |      /:/\\:\\  \\     /:|:|  |      /:/\\:\\  \\  " << "\n";
        std::cout << "  /:/|:|  |__   /::\\~\\:\\  \\   /:/|:|  |__   /:/  \\:\\  \\ " << "\n";
        std::cout << " /:/ |:| /\\__\\ /:/\\:\\ \\:\\__\\ /:/ |:| /\\__\\ /:/__/ \\:\\__\\" << "\n";
        std::cout << " \\/__|:|/:/  / \\/__\\:\\/:/  / \\/__|:|/:/  / \\:\\  \\ /:/  /" << "\n";
        std::cout << "     |:/:/  /       \\::/  /      |:/:/  /   \\:\\  /:/  / " << "\n";
        std::cout << "     |::/  /        /:/  /       |::/  /     \\:\\/:/  /  " << "\n";
        std::cout << "     /:/  /        /:/  /        /:/  /       \\::/  /   " << "\n";
        std::cout << "     \\/__/         \\/__/         \\/__/         \\/__/    " << "\n";
        std::cout << "=================================================================" <<"\n";
        std::cout << "=================================================================" <<"\n";

        std::cout << "\n";
        

        std::cout << "[~/" << getPathFromHome() << "] μ ";
        
        std::string input;
        std::getline(std::cin,input);

        if(input == "exit"){
            std::cout << "Thanks for using nanoShell!" << std::endl;
            return 0;
        }
        
        std::vector<std::string> parsedInput = parser(input);
        std::cout << handleCommands(parsedInput) << std::endl;
    }

    return 0;

}
