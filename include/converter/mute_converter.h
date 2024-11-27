#ifndef MUTE_CONVERTER_H
#define MUTE_CONVERTER_H

#include "converter.h"
#include <vector>

class Sound;

class MuteConverter : public Converter {
public:
    MuteConverter(int start, int finish, const std::vector<Sound>& songs);
    std::vector<int16_t> convert() override;
private:
    int start;
    int finish;
    const std::vector<Sound>& songs;
};

#endif // MUTE_CONVERTER_H