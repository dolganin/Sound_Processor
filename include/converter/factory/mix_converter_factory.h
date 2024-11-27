#ifndef MIX_CONVERTER_FACTORY_H
#define MIX_CONVERTER_FACTORY_H

#include "converter_factory.h"

class MixConverterFactory : public ConverterFactory {
public:
    Converter* createConverter(int number, int start, const std::vector<Sound>& songs) override;
};

#endif // MIX_CONVERTER_FACTORY_H