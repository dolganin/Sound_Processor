#include "include/converter/mute_converter.h"
#include "base_test.cpp"

class MuteConverterTest : public BaseConverterTest {
protected:
    virtual void SetUp() {
        BaseConverterTest::SetUp();
    }
};


TEST_F(MuteConverterTest, Convert_MutesCorrectly) {
    int start = 1;
    int finish = 3;
    MuteConverter converter(start, finish, songs, sampleRate);
    std::vector<std::int16_t> output = converter.convert();

    // Define expected_output based on muting logic
    std::vector<std::int16_t> expected_output = {1, 0, 0, 0, 5};

    EXPECT_EQ(output, expected_output);
}

TEST_F(MuteConverterTest, Convert_MutesCorrectlyWithDifferentRange) {
    int start = 2;
    int finish = 4;
    MuteConverter converter(start, finish, songs, sampleRate);
    std::vector<std::int16_t> output = converter.convert();

    // Define expected_output based on muting logic with different range
    std::vector<std::int16_t> expected_output = {1, 2, 0, 0, 5};

    EXPECT_EQ(output, expected_output);
}