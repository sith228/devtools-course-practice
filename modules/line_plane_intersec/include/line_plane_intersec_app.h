// Copyright 2017 Pletnev Nikita

#ifndef MODULES_LINE_PLANE_INTERSEC_INCLUDE_LINE_PLANE_INTERSEC_APP_H_
#define MODULES_LINE_PLANE_INTERSEC_INCLUDE_LINE_PLANE_INTERSEC_APP_H_

#include <string>

class Application {
 public:
    Application();
    std::string operator()(int argc, const char** argv);

 private:
    void Help(const char* appname, const char* message = "");
    bool ValidateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        double line_x;
        double line_y;
        double line_z;
        double dir_x;
        double dir_y;
        double dir_z;
        double plane_a;
        double plane_b;
        double plane_c;
        double plane_d;
    } Arguments;
};

#endif  // MODULES_LINE_PLANE_INTERSEC_INCLUDE_LINE_PLANE_INTERSEC_APP_H_
