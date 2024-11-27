#include "include/converter/mix_converter.h"
#include <iostream>

MixConverter::MixConverter(int number, int start, const std::vector<Sound>& songs)
    : number(number), start(start), songs(songs) {}

std::vector<std::int16_t> MixConverter::convert() {
    std::cout << "MixConverter: Смешивание " << number << " с " << start << std::endl;
    start *= 44100;
    std::vector<std::int16_t> inp1(songs[1].getSamples());
    std::vector<std::int16_t> inp2(songs[number].getSamples());
    int finish1 = inp1.size();
    int finish2 = inp2.size();
    int fin = (finish1 > finish2) ? finish2 : finish1;
    for (size_t i = start; i < fin; i++) {
        inp1[i] = (inp1[i] + inp2[i]) / 2;
    }
    return inp1;
}