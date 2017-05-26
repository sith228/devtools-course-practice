// Copyright 2017 Baranov Evgeny

#ifndef MODULES_COLOR_SPACES_INCLUDE_COLORCONVERTER_H_
#define MODULES_COLOR_SPACES_INCLUDE_COLORCONVERTER_H_

#include <stdint.h>
#include <string>

typedef struct {
    uint16_t value1;
    uint16_t value2;
    uint16_t value3;

    uint8_t inType;
    uint8_t outType;
} Arguments;

class ColorConverter {
 public:
    ColorConverter();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool ValidateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    Arguments arg_;
};

#endif  // MODULES_COLOR_SPACES_INCLUDE_COLORCONVERTER_H_
