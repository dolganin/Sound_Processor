#ifndef MIX_CONVERTER_H
#define MIX_CONVERTER_H

#include "converter.h"
#include <vector>

class Sound;

class MixConverter : public Converter {
public:
    MixConverter(int number, int start, const std::vector<Sound>& songs);
    std::vector<int16_t> convert() override;
private:
    int number;
    int start;
    const std::vector<Sound>& songs;
};

#endif // MIX_CONVERTER_H