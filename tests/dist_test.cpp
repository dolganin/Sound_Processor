#include "include/converter/dist_converter.h"
#include "base_test.cpp"

class DistConverterTest : public BaseConverterTest {
protected:
    virtual void SetUp() {
        BaseConverterTest::SetUp();
    }
};

TEST_F(DistConverterTest, Constructor) {
    DistConverter converter(songs, sampleRate);
    // Add relevant checks
}

TEST_F(DistConverterTest, Convert_DistortsCorrectly) {
    DistConverter converter(songs, sampleRate);
    std::vector<std::int16_t> output = converter.convert();
    // Define expected_output based on distortion logic
    std::vector<std::int16_t> expected_output = {1, 4, 9, 16, 25};
    EXPECT_EQ(output, expected_output);
}