#include "include/converter/mute_converter.h"
#include <vector>

MuteConverter::MuteConverter(int start, int finish, const std::vector<Sound>& songs, int sampleRate)
    : start(start), finish(finish), songs(songs), sampleRate(sampleRate)
{
}

std::vector<int16_t> MuteConverter::convert()
{
    if (songs.empty()) {
        return {};
    }
    std::vector<int16_t> output = songs[0].getSamples();
    if (output.empty()) {
        return output;
    }
    if (sampleRate <= 0) {
        return output;
    }

    long long startIndex = static_cast<long long>(start) * sampleRate;
    long long finishIndex = static_cast<long long>(finish) * sampleRate;
    if (finishIndex < startIndex) {
        long long temp = startIndex;
        startIndex = finishIndex;
        finishIndex = temp;
    }
    if (finishIndex <= 0) {
        return output;
    }
    if (startIndex < 0) {
        startIndex = 0;
    }

    size_t size = output.size();
    size_t startPos = static_cast<size_t>(startIndex);
    size_t finishPos = static_cast<size_t>(finishIndex);
    if (startPos >= size) {
        return output;
    }
    if (finishPos > size) {
        finishPos = size;
    }

    for (size_t i = startPos; i < finishPos; ++i) {
        output[i] = 0;
    }
    return output;
}
