#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <unistd.h>
#include <string>
#include "include/base/wav_parser.h"
#include "include/base/config_parser.h"
#include "include/converter/factory/dist_converter_factory.h"
#include "include/converter/factory/mix_converter_factory.h"
#include "include/converter/factory/mute_converter_factory.h"

int main(int argc, char **argv) {
    int opt;
    bool helpFlag = false;
    char* configFile = nullptr;
    char* outputFile = nullptr;

    while ((opt = getopt(argc, argv, "hc:")) != -1) {
        switch (opt) {
            case 'h':
                helpFlag = true;
                break;
            case 'c':
                configFile = optarg;
                break;
            default:
                std::cerr << "Unknown option: " << optopt << std::endl;
                return 1;
        }
    }

    // Check help flag
    if (helpFlag) {
        std::cout << "Usage: sound_processor [-h] [-c config.txt] output.wav input1.wav [input2.wav ...]" << '\n'
                  << "mute(start,finish) - mute song on interval(start,finish) \n mix(song,start) - mix main song with $songnumber song, starts in start \n dist(clip,start) - make distortion with start"
                  << std::endl;
        return 0;
    }

    // Check for required arguments
    if (configFile == nullptr || optind >= argc) {
        std::cerr << "Missing required arguments: -c and output filename." << std::endl;
        return 1;
    }

    outputFile = argv[optind];
    optind++;

    std::vector<std::string> songnames;
    std::vector<Sound> songs;
    for (int i = optind; i < argc; ++i) {
        songnames.push_back(std::string(argv[i]));
        Sound song;
        song.getHeader(std::string(argv[i]));
        song.checkFile();
        songs.push_back(song);
    }

    if (songs.empty()) {
        std::cerr << "No input songs provided." << std::endl;
        return 1;
    }

    int sampleRate = songs[0].getSampleRate();

    ConfigParser parser;
    parser.readConfig(std::string(configFile));
    int k = 0;

    for (std::string& command : parser.commands) {
        if (command == "mute") {
            if (k >= parser.argum.size()) {
                std::cerr << "Missing arguments for mute command." << std::endl;
                return 1;
            }
            if (songs.size() < 2) {
                std::cerr << "Not enough songs to apply mute." << std::endl;
                return 1;
            }
            ConverterFactory* factory = new MuteConverterFactory();
            Converter* muteConverter = factory->createConverter(parser.argum[k][0], parser.argum[k][1], songs, sampleRate);
            songs[1].setSamples(muteConverter->convert());
            delete muteConverter;
            delete factory;
            k++;
        } else if (command == "dist") {
            if (k >= parser.argum.size()) {
                std::cerr << "Missing arguments for dist command." << std::endl;
                return 1;
            }
            if (songs.size() < 2) {
                std::cerr << "Not enough songs to apply distortion." << std::endl;
                return 1;
            }
            ConverterFactory* factory = new DistConverterFactory();
            Converter* distConverter = factory->createConverter(parser.argum[k][0], parser.argum[k][1], songs, sampleRate);
            songs[1].setSamples(distConverter->convert());
            delete distConverter;
            delete factory;
            k++;
        } else if (command == "mix") {
            if (k >= parser.argum.size()) {
                std::cerr << "Missing arguments for mix command." << std::endl;
                return 1;
            }
            if (songs.size() < 2) {
                std::cerr << "Not enough songs to apply mix." << std::endl;
                return 1;
            }
            ConverterFactory* factory = new MixConverterFactory();
            Converter* mixConverter = factory->createConverter(parser.argum[k][0], parser.argum[k][1], songs, sampleRate);
            songs[1].setSamples(mixConverter->convert());
            delete mixConverter;
            delete factory;
            k++;
        } else {
            std::cerr << "Unknown command: " << command << std::endl;
            return 1;
        }
    }

    if (songs.size() > 1) {
        songs[1].writeFile(outputFile);
    } else {
        std::cerr << "No song to write output." << std::endl;
        return 1;
    }

    return 0;
}