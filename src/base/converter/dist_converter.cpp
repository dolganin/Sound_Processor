#include "include/converter/dist_converter.h"
#include <iostream>

DistConverter::DistConverter(int clip, int start, const std::vector<Sound>& songs, int sampleRate)
    : clip(clip), start(start), songs(songs), sampleRate(sampleRate) {}

std::vector<std::int16_t> DistConverter::convert() {
    std::cout << "DistConverter: Дисторшн " << clip << " начиная с " << start << std::endl;
    start *= sampleRate; // Используем sampleRate вместо жестко заданного значения 44100
    std::vector<std::int16_t> inp = songs[1].getSamples();
    int finish = inp.size();
    for (size_t i = start; i < finish; i++) {
        if (inp[i] > clip && inp[i] > 0) {
            inp[i] = clip;
        }
        if (inp[i] < -clip && inp[i] < 0) {
            inp[i] = -clip;
        }
    }
    return inp;
}