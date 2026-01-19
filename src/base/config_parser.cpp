#include "include/base/config_parser.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>

std::vector<std::string> ConfigParser::splitString(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

static std::string trimString(const std::string& value) {
    const std::string whitespace = " \t\r\n";
    size_t start = value.find_first_not_of(whitespace);
    if (start == std::string::npos) {
        return "";
    }
    size_t end = value.find_last_not_of(whitespace);
    return value.substr(start, end - start + 1);
}

static std::string stripComment(const std::string& line) {
    size_t cut = std::string::npos;
    size_t slashPos = line.find("//");
    if (slashPos != std::string::npos) {
        cut = slashPos;
    }
    size_t hashPos = line.find('#');
    if (hashPos != std::string::npos) {
        cut = (cut == std::string::npos) ? hashPos : std::min(cut, hashPos);
    }
    if (cut == std::string::npos) {
        return line;
    }
    return line.substr(0, cut);
}

int ConfigParser::readConfig(const std::string& filename) {
    commands.clear();
    argum.clear();

    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cout << "Ошибка открытия файла." << std::endl;
        return 1;
    }
    
    std::string line;
    while (std::getline(inputFile, line)) {
        std::string cleaned = trimString(stripComment(line));
        if (cleaned.empty()) {
            continue;
        }

        size_t start = cleaned.find_first_of('(');
        size_t end = cleaned.find_last_of(')');
        if (start == std::string::npos || end == std::string::npos || end <= start) {
            continue;
        }
        
        std::string command = trimString(cleaned.substr(0, start));
        std::string argumentsStr = cleaned.substr(start + 1, end - start - 1);
        if (command.empty()) {
            continue;
        }
        
        std::vector<std::string> arguments = splitString(argumentsStr, ',');
        std::vector<int> args;
        for (const std::string& arg : arguments) {
            std::string trimmedArg = trimString(arg);
            if (trimmedArg.empty()) {
                continue;
            }
            try {
                args.push_back(std::stoi(trimmedArg));
            } catch (const std::exception&) {
                std::cout << "Ошибка парсинга аргумента: " << trimmedArg << std::endl;
                return 1;
            }
        }
        if (args.empty()) {
            continue;
        }
        commands.push_back(command);
        argum.push_back(args);
    }
    
    inputFile.close();
    return 0;
}
