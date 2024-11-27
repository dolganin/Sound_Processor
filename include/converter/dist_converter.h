#ifndef DIST_CONVERTER_H
#define DIST_CONVERTER_H

#include "converter.h"
#include <vector>

class Sound;

class DistConverter : public Converter {
public:
    DistConverter(int clip, int start, const std::vector<Sound>& songs);
    std::vector<int16_t> convert() override;
private:
    int clip;
    int start;
    const std::vector<Sound>& songs;
};

#endif // DIST_CONVERTER_H