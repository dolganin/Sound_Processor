#include "include/base/wav_parser.h"
#include <fstream>
#include <iostream>

int Sound::getHeader(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл " << filename << "\n";
        return 1;
    }
    file.read(reinterpret_cast<char*>(&header), sizeof(WAVHeader));
    audioData.resize(header.subchunk2Size / sizeof(int16_t));
    file.read(reinterpret_cast<char*>(audioData.data()), header.subchunk2Size);
    data_label.resize(4);
    sample_size.resize(1);
    file.read(reinterpret_cast<char*>(data_label.data()), sizeof(uint32_t));
    file.read(reinterpret_cast<char*>(sample_size.data()), sizeof(uint32_t));
    samples.resize(sample_size[0] / sizeof(int16_t));
    file.read(reinterpret_cast<char*>(samples.data()), sample_size[0]);
    file.close();
    return 0;
}

int Sound::checkFile() {
    if (std::string(header.chunkID, 4) != "RIFF" ||
        std::string(header.format, 4) != "WAVE" ||
        std::string(header.subchunk1ID, 4) != "fmt " ||
        header.audioFormat != 1) {
        std::cerr << "Неподдерживаемый формат WAV-файла\n";
        return 0;
    }
    return 1;
}

int Sound::writeFile(const std::string& outputFileName) {
    std::ofstream outputFile(outputFileName, std::ios::binary);
    if (!outputFile.is_open()) {
        std::cerr << "Не удалось создать файл\n";
        return 1;
    }
    outputFile.write(reinterpret_cast<const char*>(&header), sizeof(WAVHeader));
    outputFile.write(reinterpret_cast<const char*>(audioData.data()), header.subchunk2Size);
    outputFile.write(reinterpret_cast<const char*>(data_label.data()), sizeof(uint32_t));
    outputFile.write(reinterpret_cast<const char*>(sample_size.data()), sizeof(uint32_t));
    outputFile.write(reinterpret_cast<const char*>(samples.data()), sample_size[0]);
    outputFile.close();
    std::cout << "Изменения успешно внесены. Результат сохранен в файле " << outputFileName << "\n";
    return 0;
}