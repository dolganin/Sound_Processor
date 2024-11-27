#ifndef MUTE_CONVERTER_FACTORY_H
#define MUTE_CONVERTER_FACTORY_H

#include "converter_factory.h"

class MuteConverterFactory : public ConverterFactory {
public:
    Converter* createConverter(int start, int finish, const std::vector<Sound>& songs) override;
};

#endif // MUTE_CONVERTER_FACTORY_H