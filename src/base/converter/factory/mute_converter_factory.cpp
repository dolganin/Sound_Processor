#include "include/converter/factory/mute_converter_factory.h"
#include "include/converter/mute_conveter.h"

Converter* MuteConverterFactory::createConverter(int start, int finish, const std::vector<Sound>& songs) {
    return new MuteConverter(start, finish, songs);
}