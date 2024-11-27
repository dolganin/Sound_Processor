#include "include/base/config_parser.h"
#include <gtest/gtest.h>

TEST(ConfigParserTest, SplitString_NoDelimiter) {
    ConfigParser parser;
    std::vector<std::string> tokens = parser.splitString("HelloWorld", ',');
    EXPECT_EQ(tokens.size(), 1);
    EXPECT_EQ(tokens[0], "HelloWorld");
}

TEST(ConfigParserTest, SplitString_WithDelimiter) {
    ConfigParser parser;
    std::vector<std::string> tokens = parser.splitString("a,b,c", ',');
    EXPECT_EQ(tokens.size(), 3);
    EXPECT_EQ(tokens[0], "a");
    EXPECT_EQ(tokens[1], "b");
    EXPECT_EQ(tokens[2], "c");
}

TEST(ConfigParserTest, ReadConfig_ValidFile) {
    ConfigParser parser;
    int result = parser.readConfig("test.config");
    EXPECT_EQ(result, 0);
    // Verify commands and arguments are parsed correctly
}

TEST(ConfigParserTest, ReadConfig_NonExistentFile) {
    ConfigParser parser;
    int result = parser.readConfig("nonexistent.config");
    EXPECT_EQ(result, 1);
    // Verify commands and arguments are not modified
}