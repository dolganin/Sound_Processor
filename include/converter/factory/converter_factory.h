#ifndef CONVERTER_FACTORY_H
#define CONVERTER_FACTORY_H

#include "include/converter/converter.h"
#include <vector>

class Sound;

class ConverterFactory {
public:
    virtual Converter* createConverter(int start, int finish, const std::vector<Sound>& songs, int sampleRate) = 0;
};

#endif // CONVERTER_FACTORY_H