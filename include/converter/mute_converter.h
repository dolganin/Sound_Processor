#ifndef MUTE_CONVERTER_H
#define MUTE_CONVERTER_H

#include "converter.h"
#include <vector>
#include "include/base/wav_parser.h"

class MuteConverter : public Converter {
public:
    MuteConverter(int start, int finish, const std::vector<Sound>& songs, int sampleRate);
    std::vector<int16_t> convert() override;
private:
    int start;
    int finish;
    const std::vector<Sound>& songs;
    int sampleRate;
};

#endif // MUTE_CONVERTER_H