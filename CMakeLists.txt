cmake_minimum_required(VERSION 3.10)
project(AudioConverterProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR})

include_directories(src)

set(SRC_BASE
    src/base/config_parser.cpp
    src/base/wav_parser.cpp
    )

set(SRC_CONVERTER
    src/base/converter/dist_converter.cpp
    src/base/converter/factory/dist_converter_factory.cpp
    src/base/converter/factory/mix_converter_factory.cpp
    src/base/converter/factory/mute_converter_factory.cpp
    src/base/converter/mix_converter.cpp
    src/base/converter/mute_converter.cpp
    )

set(SRC_MAIN
    src/main.cpp
    )

add_library(base_lib ${SRC_BASE})
add_library(converter_lib ${SRC_CONVERTER})

target_link_libraries(converter_lib base_lib)

add_executable(audio_converter ${SRC_MAIN})
target_link_libraries(audio_converter converter_lib base_lib)

# set(TEST_SOURCES
#     tests/base_test.cpp
#     tests/config_test.cpp
#     tests/dist_test.cpp
#     tests/mix_test.cpp
#     tests/mute_test.cpp
#     tests/test_sound.cpp
#     )

# add_executable(tests_exec ${TEST_SOURCES})
# target_link_libraries(tests_exec ${GTEST_LIBRARIES} gtest_main base_lib converter_lib)

# # Add test runner
# add_test(NAME runTests COMMAND tests_exec)
