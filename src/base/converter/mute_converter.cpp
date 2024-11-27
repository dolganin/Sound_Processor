#include "include/converter/mute_converter.h"
#include <vector>
#include <iostream>

MuteConverter::MuteConverter(int start, int finish, const std::vector<Sound>& songs, int sampleRate)
    : start(start), finish(finish), songs(songs), sampleRate(sampleRate)
{
}

std::vector<int16_t> MuteConverter::convert()
{
    std::vector<int16_t> output;

    int startIndex = start * sampleRate;
    int finishIndex = finish * sampleRate;

    // Ensure indices are within bounds
    if (startIndex < 0) {
        startIndex = 0;
    }
    if (!songs.empty()) {
        const auto& samples = songs[0].getSamples();
        if (finishIndex > samples.size()) {
            finishIndex = samples.size();
        }
        if (startIndex < samples.size()) {
            if (finishIndex > samples.size()) {
                finishIndex = samples.size();
            }
            output = std::vector<int16_t>(samples.begin() + startIndex, samples.begin() + finishIndex);
        }
    }

    return output;
}