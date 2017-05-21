// Copyright 2017 Simonyan Vaginak

#include <map>
#include <string>

#ifndef MODULES_WEIGHT_CONVERTER_INCLUDE_WEIGHT_CONVERTER_APP_H_
#define MODULES_WEIGHT_CONVERTER_INCLUDE_WEIGHT_CONVERTER_APP_H_

class Application {
 public:
    Application();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        double weight;
        char type_from;
        char type_to;
        char operation;
    } Arguments;
};

#endif  // MODULES_WEIGHT_CONVERTER_INCLUDE_WEIGHT_CONVERTER_APP_H_
