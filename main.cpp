#include <iostream>
#include <vector>
#include <string>
#include "inputParser.hpp"
#include "execute.hpp"
#include <filesystem>
#include "cd.hpp"
#include "mkdir.hpp"
#include "pwd.hpp"
#include "rmdir.hpp"
#include "touch.hpp"
#include "echo.hpp"
#include <readline/readline.h>
#include <readline/history.h>
#include "cmdHistory.hpp"

//global string to be overwritten with readline input.
std::string input;


std::string getPathFromHome()
{
    std::string string = std::filesystem::current_path();
    return string.substr(string.find_last_of("/") + 1);
}

char* getInput()
{
    char* line = readline("μ ");
    if(!line){
       
        return line;
    }

    if(*line) {
        add_history(line);
    }

    input = line;

    free(line);
    return line;
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
    }else if(input[0] == "clear"){
        return "\033[2J\033[H";
    }else if(input[0] == "mkdir"){
        if(input.size() == 1){
            return "No name for directory provided...\n";
        }
        makeDir(input[1]);
        return "";
    }else if(input[0] == "pwd"){
        return printWorkingDir();
    }else if(input[0] == "rmdir"){
        if(input.size() == 1){
            return "No name for directory provided...\n";
        }
        removeDir(input[1]);
        return "";
    }else if(input[0] == "touch"){
        touchCommand(input[1]);
        return "";
    }else if(input[0] == "echo"){
        if(input.size() == 2){
            echoPrint(input[1]);
            return "";
        }
        int i = 2;
        std::string concatString;
        if(input[1] == "\""){
            
            while(input[i] != "\""){
                concatString = concatString.append(input[i]).append(" ");
                i++;
            }
            if(input[i+1] == ">"){
            echoWriteToFile(input[i+2],concatString);
            return "";
            }else if(input[i+1] == ">>"){
            echoAppendToFile(input[i+2],concatString);
            return "";
        }
        }
        return "";
    }else {
        return "Invalid command...\n";
    }

}

void logo()
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
}

int main()
{
    logo();

    while(true)
    {
        std::cout << "[~/" << getPathFromHome() << "] ";

        getInput();
        //std::getline(std::cin,input);

        if(input == "exit"){
            std::cout << "Thanks for using nanoShell!" << std::endl;
            return 0;
        }
        
        std::vector<std::string> parsedInput = parser(input);
        //commands(parsedInput);
        std::cout << handleCommands(parsedInput) << std::endl;
    }

    return 0;

}
