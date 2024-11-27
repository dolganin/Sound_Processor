#include "include/converter/mute_converter.h"
#include <vector>
#include <iostream>

MuteConverter::MuteConverter(int start, int finish, const std::vector<Sound>& songs, int sampleRate)
    : start(start), finish(finish), songs(songs), sampleRate(sampleRate) {}

std::vector<std::int16_t> MuteConverter::convert() {
    std::cout << "MuteConverter: мьют звука с " << start << " до " << finish << " секунд" << std::endl;

    // Convert start and finish from seconds to sample indices
    int startIndex = start * sampleRate;
    int finishIndex = finish * sampleRate;

    // Ensure indices are within the bounds of the audio data
    if (startIndex < 0) {
        startIndex = 0;
    }
    if (finishIndex > songs[1].samples.size()) {
        finishIndex = songs[1].samples.size();
    }

    // Copy the input samples to avoid modifying the original data
    std::vector<std::int16_t> output = songs[1].samples;

    // Mute the samples between start and finish indices
    for (int i = startIndex; i < finishIndex; i++) {
        output[i] = 0;
    }

    return output;
}