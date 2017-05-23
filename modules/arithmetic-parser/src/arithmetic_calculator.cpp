// Copyright 2017 Ivan Kuchkov

#include "include/arithmetic_calculator.h"
#include "include/arithmetic_parser.h"

#include <cstdlib>
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <cstring>

using std::vector;
using std::string;
using std::endl;
using std::cerr;
    
namespace {

static bool TryParseDouble(const char *s, double &val) {
    char *end = nullptr;
    val = std::strtod(s, &end);
    return end[0] == 0;
}

static void printHelp(const char *appname, std::ostream &ofs) {
    ofs <<
        appname << ": a simple arithmetic calculator application. Usage:\n"
        "\n    " << appname << " <expr>"
        "\n        -- evaluate a basic arithmetic expression <expr> and print the result"
        "\n    " << appname << " <expr> <number>"
        "\n        -- evaluate an arithmetic expression containing"
        "\n           a formal parameter \"x\" substituted with real number <number>"
        "\n";
}

static std::ostream& printError(const char* appname) {
    cerr << appname << ": error: ";
    return cerr;
}

} // namespace

int ArithmeticCalculator(int argc, const char * const *argv) {
    auto appname = argc > 0 ? argv[0] : "ArithmeticCalculator";
    if(argc <= 1) {
        printHelp(appname, cerr);
        return RESULT_BAD_ARGUMENTS;
    }

    if(argc > 3) {
        printError(appname) << "wrong number of arguments\n";
        return RESULT_BAD_ARGUMENTS;
    }

    double x = 0;
    if(argc == 3 && !TryParseDouble(argv[2], x)) {
        printError(appname) << "cannot parse formal parameter: \""
                            << argv[2] << "\" is not a number\n";
        return RESULT_ERROR_PARSING;
    }

    string expr(argv[1]);

    ArithmeticParser ap;

    if(!ap.Parse(expr)) {
        printError(appname) << "cannot parse expression\n";
        return RESULT_ERROR_PARSING;
    }

    double result;
    if(!ap.Evaluate(x, &result)) {
        printError(appname) << "cannot evaluate expression\n";
        return RESULT_ERROR_EVALUATING;
    }

    std::cout << result << endl;

    return RESULT_SUCESS;
}
