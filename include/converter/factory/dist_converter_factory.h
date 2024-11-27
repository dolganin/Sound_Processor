#ifndef DIST_CONVERTER_FACTORY_H
#define DIST_CONVERTER_FACTORY_H

#include "converter_factory.h"

class DistConverterFactory : public ConverterFactory {
public:
    Converter* createConverter(int clip, int start, const std::vector<Sound>& songs) override;
};

#endif // DIST_CONVERTER_FACTORY_H