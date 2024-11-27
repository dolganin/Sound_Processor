# Sound_Processor

Описание
Sound Processor — это программа для обработки звуковых файлов в формате WAV. Она позволяет применять эффекты, такие как заглушение (mute), смешивание треков (mix), и дисторшн (distortion), на основе конфигурационного файла. Программа написана на языке C++ и предоставляет гибкие возможности для работы с аудиофайлами.

## Ключевые возможности:

- Поддержка формата WAV.
- Обработка нескольких входных аудиофайлов.
- Использование конфигурационных файлов для задания эффектов.
- Эффекты: заглушение (mute), смешивание (mix), дисторшн (distortion).
## Требования перед установкой:

- C++17 или более новая версия компилятора.
- g++ (GNU Compiler Collection).
- Google Tests (для разработки, тесты в текущей версии не описаны).
- CMake (система сборки).
## Структура проекта:
Проект имеет следующую структуру:

```tree

.
├── CMakeLists.txt        // Основной файл для сборки проекта с CMake.
├── LICENSE               // Лицензионное соглашение.
├── README.md             // Описание проекта.
├── configs               // Директория с конфигурационными файлами.
│   └── config.txt        // Пример конфигурационного файла.
├── include               // Заголовочные файлы.
│   ├── base              // Базовые компоненты программы.
│   │   ├── config_parser.h
│   │   └── wav_parser.h
│   └── converter         // Конвертеры эффектов.
│       ├── converter.h
│       ├── dist_converter.h
│       ├── factory       // Фабрики для создания конвертеров.
│       │   ├── converter_factory.h
│       │   ├── dist_converter_factory.h
│       │   ├── mix_converter_factory.h
│       │   └── mute_converter_factory.h
│       ├── mix_converter.h
│       └── mute_converter.h
├── samples               // Примеры аудиофайлов для обработки.
│   ├── district_four.wav
│   ├── funkorama.wav
│   └── severe_tire_damage.wav
├── scripts               // Скрипты для автоматизации.
│   └── build.sh          // Скрипт для сборки проекта.
├── src                   // Исходный код.
│   ├── base              // Реализации базовых компонентов.
│   │   ├── config_parser.cpp
│   │   └── wav_parser.cpp
│   ├── converter         // Реализации конвертеров эффектов.
│   │   ├── dist_converter.cpp
│   │   ├── mix_converter.cpp
│   │   ├── mute_converter.cpp
│   │   └── factory       // Реализации фабрик.
│   │       ├── dist_converter_factory.cpp
│   │       ├── mix_converter_factory.cpp
│   │       └── mute_converter_factory.cpp
│   └── main.cpp          // Главный файл программы.

```


## Установка:

Склонируйте репозиторий:

```bash
git clone https://github.com/username/sound_processor.git

```

Перейдите в каталог проекта:

```bash
cd sound_processor
```

Дайте права на выполнение скрипта сборки:

```bash
chmod +x scripts/build.sh
```

Запустите скрипт сборки:

```bash
./scripts/build.sh

```

Скрипт сделает следующее:

1. Удалит директорию build, если она существует.
2. Создаст новую директорию build.
3. Соберёт проект с помощью CMake и make.
4. Скопирует исполняемый файл audio_converter в корневую директорию проекта.


## Запуск:

```bash
./sound_processor -c configs/config.txt output.wav samples/input1.wav samples/input2.wav
```

Эта команда применит эффекты из конфигурационного файла configs/config.txt к аудиофайлам input1.wav и input2.wav, сохранив результат в output.wav.


### Пример конфигурационного файла

Файл config.txt содержит команды и параметры для обработки звука. Пример:

```txt
mute(1000, 5000)    // Заглушить отрезок с 1 до 5 секунд.
mix(1, 3000)        // Смешать основной трек с первым дополнительным треком, начиная с 3-й секунды.
dist(2000, 8000)    // Применить дисторшн к отрезку с 2 до 8 секунд.
```

### Вывод справки:
```bash
./sound_processor -h
```

#### Пример вывода:

```bash

Usage: sound_processor [-h] [-c config.txt] output.wav input1.wav [input2.wav ...]
mute(start,finish) - mute song on interval(start,finish)
mix(song,start) - mix main song with $songnumber song, starts in start
dist(clip,start) - make distortion with start
```