#ifndef CONFIG_PARSER_H
#define CONFIG_PARSER_H

#include <vector>
#include <string>

class ConfigParser {
public:
    std::vector<std::string> splitString(const std::string& str, char delimiter);
    int readConfig(const std::string& filename);
    std::vector<std::string> commands;
    std::vector<std::vector<int>> argum;
};

#endif // CONFIG_PARSER_H