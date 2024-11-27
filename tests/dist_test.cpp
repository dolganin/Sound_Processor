#include "include/converter/dist_converter.h"
#include "base_test.cpp"

class DistConverterTest : public BaseConverterTest {
protected:
    virtual void SetUp() {
        BaseConverterTest::SetUp();
    }
};

TEST_F(DistConverterTest, Constructor) {
    int clip = 5;
    int start = 0;
    DistConverter converter(clip, start, songs, sampleRate);
    // Add relevant checks
}

TEST_F(DistConverterTest, Convert_DistortsCorrectly) {
    int clip = 5;
    int start = 0;
    DistConverter converter(clip, start, songs, sampleRate);
    std::vector<std::int16_t> output = converter.convert();

    // Define expected_output based on distortion logic
    std::vector<std::int16_t> expected_output = {1, 2, 3, 4, 5}; // No change as all values are within the clip range

    EXPECT_EQ(output, expected_output);
}

TEST_F(DistConverterTest, Convert_DistortsCorrectlyWithClipping) {
    int clip = 3;
    int start = 0;
    DistConverter converter(clip, start, songs, sampleRate);
    std::vector<std::int16_t> output = converter.convert();

    // Define expected_output based on distortion logic with clipping
    std::vector<std::int16_t> expected_output = {1, 2, 3, 3, 3}; // Values 4 and 5 are clipped to 3

    EXPECT_EQ(output, expected_output);
}