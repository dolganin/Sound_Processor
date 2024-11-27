#ifndef CONVERTER_FACTORY_H
#define CONVERTER_FACTORY_H

#include "converter.h"
#include <vector>

class Sound;

class ConverterFactory {
public:
    virtual Converter* createConverter(int arg1, int arg2, const std::vector<Sound>& songs) = 0;
    virtual ~ConverterFactory() = default;
};

#endif // CONVERTER_FACTORY_H