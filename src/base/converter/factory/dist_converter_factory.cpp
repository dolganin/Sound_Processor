#include "include/converter/factory/dist_converter_factory.h"   
#include "include/converter/dist_converter.h"

Converter* DistConverterFactory::createConverter(int clip, int start, const std::vector<Sound>& songs) {
    return new DistConverter(clip, start, songs);
}