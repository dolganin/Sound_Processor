#include "include/converter/dist_converter.h"

DistConverter::DistConverter(int clip, int start, const std::vector<Sound>& songs, int sampleRate)
    : clip(clip), start(start), songs(songs), sampleRate(sampleRate) {}

std::vector<std::int16_t> DistConverter::convert() {
    if (songs.empty()) {
        return {};
    }
    std::vector<std::int16_t> output = songs[0].getSamples();
    if (output.empty()) {
        return output;
    }
    if (sampleRate <= 0) {
        return output;
    }

    int clipValue = clip < 0 ? -clip : clip;
    if (clipValue == 0) {
        return output;
    }

    long long startIndex = static_cast<long long>(start) * sampleRate;
    if (startIndex < 0) {
        startIndex = 0;
    }
    size_t startPos = static_cast<size_t>(startIndex);
    size_t finish = output.size();
    if (startPos >= finish) {
        return output;
    }

    for (size_t i = startPos; i < finish; ++i) {
        int value = output[i];
        if (value > clipValue) {
            value = clipValue;
        } else if (value < -clipValue) {
            value = -clipValue;
        }
        output[i] = static_cast<std::int16_t>(value);
    }
    return output;
}
