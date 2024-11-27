#include <gtest/gtest.h>
#include "include/converter/converter.h"
#include "include/base/wav_parser.h"
#include "include/converter/factory/mix_converter_factory.h"
#include "include/converter/factory/dist_converter_factory.h"

class BaseConverterTest : public ::testing::Test {
protected:
    virtual void SetUp() {
        // Initialize sample sounds
        Sound primarySound;
        primarySound.setSamples({1, 2, 3, 4, 5});
        primarySound.getHeader().sampleRate = 44100; // Set sample rate for primary sound
        songs.push_back(primarySound);

        Sound secondarySound;
        secondarySound.setSamples({6, 7, 8, 9, 10});
        secondarySound.getHeader().sampleRate = 44100; // Set sample rate for secondary sound
        songs.push_back(secondarySound);

        sampleRate = 44100; // 44100 samples per second
    }

    virtual void TearDown() {
        // Clean up if necessary
    }

    std::vector<Sound> songs;
    int sampleRate;
};

TEST_F(BaseConverterTest, MixConverterTest) {
    MixConverterFactory mixFactory;
    Converter* mixConverter = mixFactory.createConverter(0, 0, songs, sampleRate);

    std::vector<int16_t> result = mixConverter->convert();

    // Expected result after mixing
    std::vector<int16_t> expected = {3, 4, 5, 6, 7}; // (1+6)/2, (2+7)/2, ..., (5+10)/2

    ASSERT_EQ(result, expected);

    delete mixConverter;
}

TEST_F(BaseConverterTest, DistConverterTest) {
    DistConverterFactory distFactory;
    Converter* distConverter = distFactory.createConverter(5, 0, songs, sampleRate);

    std::vector<int16_t> result = distConverter->convert();

    // Expected result after distortion with clip value 5
    std::vector<int16_t> expected = {1, 2, 3, 4, 5}; // No change as all values are within the clip range

    ASSERT_EQ(result, expected);

    delete distConverter;
}