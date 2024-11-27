#ifndef SOUND_H
#define SOUND_H

#include <cstdint>
#include <vector>
#include <string>

struct WAVHeader {
    char chunkID[4];
    uint32_t chunkSize;
    char format[4];
    char subchunk1ID[4];
    uint32_t subchunk1Size;
    uint16_t audioFormat;
    uint16_t numChannels;
    uint32_t sampleRate;
    uint32_t byteRate;
    uint16_t blockAlign;
    uint16_t bitsPerSample;
    char subchunk2ID[4];
    uint32_t subchunk2Size;
};

class Sound {
private:
    WAVHeader header;
    std::vector<int16_t> audioData;
    std::vector<char> data_label;
    std::vector<uint32_t> sample_size;
    std::vector<int16_t> samples;

public:
    int getHeader(const std::string& filename);
    int checkFile();
    int writeFile(const std::string& outputFileName);

    // Public accessor functions for samples
    const std::vector<int16_t>& getSamples() const { return samples; }
    std::vector<int16_t>& getSamples() { return samples; }
};

#endif // SOUND_H