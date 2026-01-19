#include "include/converter/mix_converter.h"

MixConverter::MixConverter(int number, int start, const std::vector<Sound>& songs, int sampleRate)
    : number(number), start(start), songs(songs), sampleRate(sampleRate) {}

std::vector<std::int16_t> MixConverter::convert() {
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

    int trackIndex = number;
    if (trackIndex <= 0) {
        trackIndex = 1;
    }
    if (trackIndex >= static_cast<int>(songs.size())) {
        return output;
    }
    const std::vector<std::int16_t>& other = songs[trackIndex].getSamples();
    if (other.empty()) {
        return output;
    }

    long long startIndex = static_cast<long long>(start) * sampleRate;
    if (startIndex < 0) {
        startIndex = 0;
    }
    size_t startPos = static_cast<size_t>(startIndex);
    size_t baseSize = output.size();
    if (startPos >= baseSize) {
        return output;
    }

    size_t maxMix = baseSize - startPos;
    size_t otherSize = other.size();
    size_t mixCount = otherSize < maxMix ? otherSize : maxMix;

    for (size_t i = 0; i < mixCount; ++i) {
        size_t baseIndex = startPos + i;
        int mixed = static_cast<int>(output[baseIndex]) + static_cast<int>(other[i]);
        output[baseIndex] = static_cast<std::int16_t>(mixed / 2);
    }
    return output;
}
