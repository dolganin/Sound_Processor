#include "include/base/wav_parser.h"
#include <gtest/gtest.h>
#include <fstream>

TEST(SoundTest, GetHeader_ValidFile) {
    Sound sound;
    int result = sound.getHeader("valid.wav");
    EXPECT_EQ(result, 0);
    // Verify header and audioData are correctly populated
}

TEST(SoundTest, GetHeader_NonExistentFile) {
    Sound sound;
    int result = sound.getHeader("nonexistent.wav");
    EXPECT_EQ(result, 1);
    // Verify header and audioData are not modified
}

TEST(SoundTest, CheckFile_ValidFile) {
    Sound sound;
    sound.getHeader("valid.wav");
    int result = sound.checkFile();
    EXPECT_EQ(result, 1);
}

TEST(SoundTest, CheckFile_InvalidFile) {
    Sound sound;
    sound.getHeader("invalid.wav");
    int result = sound.checkFile();
    EXPECT_EQ(result, 0);
}

TEST(SoundTest, WriteFile_NewFile) {
    Sound sound;
    sound.getHeader("valid.wav");
    int result = sound.writeFile("output.wav");
    EXPECT_EQ(result, 0);
    // Verify that "output.wav" is created and contains correct data
}