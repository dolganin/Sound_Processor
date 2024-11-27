#include "include/converter/mute_converter.h"
#include "base_test.cpp"

class MuteConverterTest : public BaseConverterTest {
protected:
    virtual void SetUp() {
        BaseConverterTest::SetUp();
    }
};

TEST_F(MuteConverterTest, Constructor) {
    MuteConverter converter(1, 3, songs, sampleRate);
    EXPECT_EQ(converter.getStart(), 1);
    EXPECT_EQ(converter.getFinish(), 3);
    EXPECT_EQ(converter.getSampleRate(), sampleRate);
}

TEST_F(MuteConverterTest, Convert_MutesCorrectly) {
    MuteConverter converter(1, 3, songs, sampleRate);
    std::vector<std::int16_t> output = converter.convert();
    std::vector<std::int16_t> expected_output = {1, 0, 0, 0, 5};
    EXPECT_EQ(output, expected_output);
}