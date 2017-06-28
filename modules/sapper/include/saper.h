// Copyright 2017 Fedorov Igor

#ifndef MODULES_SAPPER_INCLUDE_SAPER_H_
#define MODULES_SAPPER_INCLUDE_SAPER_H_

#include <string>
#include<iostream>
#include"../include/field.h"

class Saper {
 public:
    explicit Saper(int wth = 10, int hght = 10, int countbomb = 10);
    bool TouchResult(int x_, int y_);
    std::string operator()(int argc, const char** argv);
 private:
    bool validateNumberOfArguments(int argc, const char** argv);
    void help(const char* appname, const char* message = "");
    std::string message_;
    Field *field_;
    int parseInt(const char* arg);
    typedef struct {
        int x;
        int y;
        int choose;
    } Arguments;
};

#endif  // MODULES_SAPPER_INCLUDE_SAPER_H_
