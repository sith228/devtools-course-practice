// Copyright 2017 Komarov Nikolay

#ifndef MODULES_INTEGRATION_METHODS_INCLUDE_INTEGRATION_METHODS_APP_H_
#define MODULES_INTEGRATION_METHODS_INCLUDE_INTEGRATION_METHODS_APP_H_

#include <string>

class Application {
 public:
    Application();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    bool validateOperationName(const char *arg);
    double parseDouble(const char* arg);
    int parseInteger(const char* arg);
    std::string message_;
    typedef struct {
        std::string integrand;
        double low_limit;
        double upper_limit;
        const char* method_name;
        int quantity_of_steps;
        double epsilon;
    } Arguments;
};

#endif  // MODULES_INTEGRATION_METHODS_INCLUDE_INTEGRATION_METHODS_APP_H_
