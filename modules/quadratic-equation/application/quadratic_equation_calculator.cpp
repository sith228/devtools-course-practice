// Copyright 2017 Kiseleva Olga

#include "include/quadratic_equation_app.h"

#include <map>
#include <string>

int main(int argc, const char** argv) {
    QuadraticEquationCalculator app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}