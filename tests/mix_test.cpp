#include "include/converter/mix_converter.h"
#include "base_test.cpp"

class MixConverterTest : public BaseConverterTest {
protected:
    virtual void SetUp() {
        BaseConverterTest::SetUp();
    }
};

TEST_F(MixConverterTest, Constructor) {
    int number = 1;
    int start = 0;
    MixConverter converter(number, start, songs, sampleRate);
    // Add relevant checks
}

TEST_F(MixConverterTest, Convert_MixesCorrectly) {
    int number = 1;
    int start = 0;
    MixConverter converter(number, start, songs, sampleRate);
    std::vector<std::int16_t> output = converter.convert();

    // Define expected_output based on mixing logic
    std::vector<std::int16_t> expected_output = {3, 4, 5, 6, 7}; // (1+6)/2, (2+7)/2, ..., (5+10)/2

    EXPECT_EQ(output, expected_output);
}

TEST_F(MixConverterTest, Convert_MixesCorrectlyWithDifferentStart) {
    int number = 1;
    int start = 1;
    MixConverter converter(number, start, songs, sampleRate);
    std::vector<std::int16_t> output = converter.convert();

    // Define expected_output based on mixing logic with different start
    std::vector<std::int16_t> expected_output = {2, 3, 4, 5, 6}; // (2+7)/2, (3+8)/2, ..., (5+10)/2

    EXPECT_EQ(output, expected_output);
}