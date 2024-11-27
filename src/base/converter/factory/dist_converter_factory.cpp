#include "include/converter/factory/dist_converter_factory.h"   
#include "include/converter/dist_converter.h"

Converter* DistConverterFactory::createConverter(int start, int finish, const std::vector<Sound>& songs, int sampleRate) {
    return new DistConverter(start, finish, songs, sampleRate);
}