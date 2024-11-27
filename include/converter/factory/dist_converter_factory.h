#ifndef DIST_CONVERTER_FACTORY_H
#define DIST_CONVERTER_FACTORY_H

#include "converter_factory.h"

class DistConverterFactory : public ConverterFactory {
public:
    Converter* createConverter(int start, int finish, const std::vector<Sound>& songs, int sampleRate) override;
};

#endif // DIST_CONVERTER_FACTORY_H