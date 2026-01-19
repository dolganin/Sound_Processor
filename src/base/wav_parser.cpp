#include "include/base/wav_parser.h"
#include <fstream>
#include <iostream>

int Sound::getHeader(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл " << filename << "\n";
        return 1;
    }
    if (!file.read(reinterpret_cast<char*>(&header), sizeof(WAVHeader))) {
        std::cerr << "Не удалось прочитать заголовок WAV\n";
        return 1;
    }
    if (header.subchunk2Size % sizeof(int16_t) != 0) {
        std::cerr << "Некорректный размер данных\n";
        return 1;
    }
    samples.resize(header.subchunk2Size / sizeof(int16_t));
    if (!file.read(reinterpret_cast<char*>(samples.data()), header.subchunk2Size)) {
        std::cerr << "Не удалось прочитать данные WAV\n";
        return 1;
    }
    file.close();
    return 0;
}

int Sound::checkFile() {
    if (std::string(header.chunkID, 4) != "RIFF" ||
        std::string(header.format, 4) != "WAVE" ||
        std::string(header.subchunk1ID, 4) != "fmt " ||
        std::string(header.subchunk2ID, 4) != "data" ||
        header.audioFormat != 1 ||
        header.bitsPerSample != 16) {
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
    header.subchunk2Size = static_cast<uint32_t>(samples.size() * sizeof(int16_t));
    header.blockAlign = static_cast<uint16_t>(header.numChannels * header.bitsPerSample / 8);
    header.byteRate = header.sampleRate * header.blockAlign;
    header.chunkSize = 36 + header.subchunk2Size;
    outputFile.write(reinterpret_cast<const char*>(&header), sizeof(WAVHeader));
    if (!samples.empty()) {
        outputFile.write(reinterpret_cast<const char*>(samples.data()), header.subchunk2Size);
    }
    outputFile.close();
    std::cout << "Изменения успешно внесены. Результат сохранен в файле " << outputFileName << "\n";
    return 0;
}
