#ifndef SOUND_PROCESSOR_H
#define SOUND_PROCESSOR_H

#include <vector>
#include <string>
#include <cstdint>
#include <fstream>
#include "include/wav_parser.h"

// Base Converter class declaration
class Converter {
public:
    virtual std::vector<std::int16_t> convert() = 0;
};

// MuteConverter class declaration
class MuteConverter : public Converter {
public:
    MuteConverter(int start, int finish, const std::vector<Sound>& songs);
    std::vector<std::int16_t> convert() override;
private:
    int start;
    int finish;
    const std::vector<Sound>& songs;
};

// MixConverter class declaration
class MixConverter : public Converter {
public:
    MixConverter(int number, int start, const std::vector<Sound>& songs);
    std::vector<std::int16_t> convert() override;
private:
    int number;
    int start;
    const std::vector<Sound>& songs;
};

// DistConverter class declaration
class DistConverter : public Converter {
public:
    DistConverter(int clip, int start, const std::vector<Sound>& songs);
    std::vector<std::int16_t> convert() override;
private:
    int clip;
    int start;
    const std::vector<Sound>& songs;
};

// ConverterFactory base class declaration
class ConverterFactory {
public:
    virtual Converter* createConverter(int arg1, int arg2, const std::vector<Sound>& songs) = 0;
};

// MuteConverterFactory class declaration
class MuteConverterFactory : public ConverterFactory {
public:
    Converter* createConverter(int start, int finish, const std::vector<Sound>& songs) override;
};

// MixConverterFactory class declaration
class MixConverterFactory : public ConverterFactory {
public:
    Converter* createConverter(int number, int start, const std::vector<Sound>& songs) override;
};

// DistConverterFactory class declaration
class DistConverterFactory : public ConverterFactory {
public:
    Converter* createConverter(int clip, int start, const std::vector<Sound>& songs) override;
};

#endif // SOUND_PROCESSOR_H