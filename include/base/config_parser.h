#ifndef CONFIG_PARSER_H
#define CONFIG_PARSER_H

#include <vector>
#include <string>
#include <sstream>

class ConfigParser {
private:
    std::vector<std::string> splitString(const std::string& str, char delimiter);
public:
    int readConfig(const std::string& filename);
    std::vector<std::vector<int>> argum;
    std::vector<std::string> commands;
};

#endif // CONFIG_PARSER_H