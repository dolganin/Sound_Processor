#include "include/converter/factory/mix_converter_factory.h"
#include "include/converter/mix_converter.h"

Converter* MixConverterFactory::createConverter(int number, int start, const std::vector<Sound>& songs) {
    return new MixConverter(number, start, songs);
}