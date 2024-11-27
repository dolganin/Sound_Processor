#ifndef CONVERTER_H
#define CONVERTER_H

#include <vector>
#include <stdint.h>

class Converter {
public:
    virtual std::vector<int16_t> convert() = 0;
    virtual ~Converter() = default;
};

#endif // CONVERTER_H