#include "include/converter/factory/mix_converter_factory.h"
#include "include/converter/mix_converter.h"

Converter* MixConverterFactory::createConverter(int start, int finish, const std::vector<Sound>& songs, int sampleRate) {
    return new MixConverter(start, finish, songs, sampleRate);
}

