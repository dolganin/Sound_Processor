#ifndef DIST_CONVERTER_H
#define DIST_CONVERTER_H

#include "converter.h"
#include <vector>
#include "include/base/wav_parser.h" // Include the full definition of Sound

class DistConverter : public Converter {
public:
    DistConverter(int clip, int start, const std::vector<Sound>& songs, int sampleRate);
    std::vector<int16_t> convert() override;
private:
    int clip;
    int start;
    const std::vector<Sound>& songs;
    int sampleRate;
};

#endif // DIST_CONVERTER_H