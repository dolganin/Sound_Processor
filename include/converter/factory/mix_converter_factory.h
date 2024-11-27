#ifndef MIX_CONVERTER_FACTORY_H
#define MIX_CONVERTER_FACTORY_H

#include "converter_factory.h"

class MixConverterFactory : public ConverterFactory {
public:
    Converter* createConverter(int start, int finish, const std::vector<Sound>& songs, int sampleRate) override;
};

#endif // MIX_CONVERTER_FACTORY_H