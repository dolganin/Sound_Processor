#include <gtest/gtest.h>
#include "include/converter/converter.h"
#include "include/base/wav_parser.h"

class BaseConverterTest : public ::testing::Test {
protected:
    virtual void SetUp() {
        // Initialize sample sounds
        Sound primarySound;
        primarySound.samples = {1, 2, 3, 4, 5};
        songs.push_back(primarySound);

        Sound secondarySound;
        secondarySound.samples = {6, 7, 8, 9, 10};
        songs.push_back(secondarySound);

        sampleRate = 1; // 1 sample per second for simplicity
    }

    virtual void TearDown() {
        // Clean up if necessary
    }

    std::vector<Sound> songs;
    int sampleRate;
};