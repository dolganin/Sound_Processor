#include "include/converter/mix_converter.h"

class MixConverterTest : public BaseConverterTest {
protected:
    virtual void SetUp() {
        BaseConverterTest::SetUp();
    }
};

TEST_F(MixConverterTest, Constructor) {
    MixConverter converter(songs, sampleRate);
    // Assuming MixConverter takes songs and sampleRate in constructor
    // Add relevant checks
}

TEST_F(MixConverterTest, Convert_MixesCorrectly) {
    MixConverter converter(songs, sampleRate);
    std::vector<std::int16_t> output = converter.convert();
    // Define expected_output based on mixing logic
    std::vector<std::int16_t> expected_output = {7, 9, 11, 13, 15};
    EXPECT_EQ(output, expected_output);
}