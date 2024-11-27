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

    // Проверка флага '-h'
    if (helpFlag) {
        std::cout << "Usage: sound_processor [-h] [-c config.txt output.wav input1.wav [input2.wav ...]]" <<'\n'
                  << "mute(start,finish) - mute song on interval(start,finish) \n mix(song,start) - mix main song with $songnumber song, starts in start \n dist(clip,start) - make distortion with clip from start"
                  << std::endl;
        // Дополнительная информация о программе
        return 0;
    }

    // Проверка наличия обязательных аргументов
    if (configFile == nullptr && !helpFlag) {
        std::cerr << "Missing required argument: -c" << std::endl;
        return 1;
    }

    
    std::vector<std::string> songnames;
    std::vector<Sound> songs;
    for (int i = optind; i < argc; ++i) {
        // std::cout << std::string(argv[i]) << '\n';
        songnames.push_back(std::string(argv[i]));
        Sound song;
        song.getHeader(std::string(argv[i]));
        song.checkFile();
        songs.push_back(song);
    }
    ConfigParser parser;
    parser.readConfig(std::string(configFile));
    int k =0;

    for (std::string& command : parser.commands)
    {
        if (command=="mute"){
            ConverterFactory* factory = new MuteConverterFactory();
            Converter* muteConverter = factory->createConverter(parser.argum[k][0],parser.argum[k][1],songs);
            songs[1].samples =  muteConverter->convert();
            delete muteConverter;
            delete factory;
            k++;
        }
        if (command=="dist"){
            ConverterFactory* factory =  new DistConverterFactory();
            Converter* distConverter = factory->createConverter(parser.argum[k][0],parser.argum[k][1],songs);
            songs[1].samples = distConverter->convert();
            delete distConverter;
            delete factory;
            k++;
        }
        if (command=="mix"){
            ConverterFactory* factory =  new MixConverterFactory();
            Converter* mixConverter = factory->createConverter(parser.argum[k][0],parser.argum[k][1],songs);
            songs[1].samples = mixConverter->convert();
            delete mixConverter;
            delete factory;
            k++;
        }
    }
    songs[1].writeFile(songnames[0]);
    
    
    
    return 0;
}