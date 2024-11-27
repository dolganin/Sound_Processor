#include "include/base/config_parser.h"
#include <fstream>
#include <iostream>
#include <sstream> // Добавленный заголовочный файл

std::vector<std::string> ConfigParser::splitString(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

int ConfigParser::readConfig(const std::string& filename) {
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cout << "Ошибка открытия файла." << std::endl;
        return 1;
    }
    
    std::string line;
    while (std::getline(inputFile, line)) {
        size_t start = line.find_first_of('(');
        size_t end = line.find_last_of(')');
        if (start == std::string::npos || end == std::string::npos || end <= start) {
            continue;
        }
        
        std::string command = line.substr(0, start);
        std::string argumentsStr = line.substr(start + 1, end - start - 1);
        
        std::vector<std::string> arguments = splitString(argumentsStr, ',');
        std::vector<int> args;
        for (const std::string& arg : arguments) {
            args.push_back(std::stoi(arg));
        }
        commands.push_back(command);
        argum.push_back(args);
    }
    
    inputFile.close();
    return 0;
}