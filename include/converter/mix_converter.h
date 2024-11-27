#ifndef MIX_CONVERTER_H
#define MIX_CONVERTER_H

#include "converter.h"
#include <vector>
#include "include/base/wav_parser.h"  // Include the full definition of Sound

class MixConverter : public Converter {
public:
    MixConverter(int number, int start, const std::vector<Sound>& songs, int sampleRate);
    std::vector<int16_t> convert() override;
private:
    int number;
    int start;
    const std::vector<Sound>& songs;
    int sampleRate;
};

#endif // MIX_CONVERTER_H