// Copyright 2017 Ivan Kuchkov

#include "include/arithmetic_calculator.h"
#include "include/arithmetic_parser.h"

#include <cstdlib>
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <cstring>
#include <tuple>
#include <utility>

using std::vector;
using std::string;
using std::endl;
using std::cerr;

namespace {

static std::pair<bool, double> TryParseDouble(const char *s) {
    char *end = nullptr;
    double val = std::strtod(s, &end);
    return std::make_pair(end[0] == 0, val);
}

static void printHelp(const char *appname, std::ostream *ofs) {
    *ofs <<
    appname << ": a simple arithmetic calculator application. Usage:\n"
    "\n    " << appname << " <expr>"
    "\n        -- evaluate a basic arithmetic expression <expr> "
                           "and print the result"
    "\n    " << appname << " <expr> <number>"
    "\n        -- evaluate an arithmetic expression containing"
    "\n           a formal parameter \"x\" substituted with "
                           "real number <number>"
    "\n";
}

static std::ostream& printError(const char* appname) {
    cerr << appname << ": error: ";
    return cerr;
}

}  // namespace

int ArithmeticCalculator(int argc, const char * const *argv) {
    auto appname = argc > 0 ? argv[0] : "ArithmeticCalculator";
    if (argc <= 1) {
        printHelp(appname, &cerr);
        return RESULT_BAD_ARGUMENTS;
    }

    if (argc > 3) {
        printError(appname) << "wrong number of arguments\n";
        return RESULT_BAD_ARGUMENTS;
    }

    double x = 0;
    if (argc == 3) {
        bool ok;
        std::tie(ok, x) = TryParseDouble(argv[2]);
        if (!ok) {
            printError(appname) << "cannot parse formal parameter: \""
                                << argv[2] << "\" is not a number\n";
            return RESULT_ERROR_PARSING;
        }
    }

    string expr(argv[1]);

    ArithmeticParser ap;

    if (!ap.Parse(expr)) {
        printError(appname) << "cannot parse expression\n";
        return RESULT_ERROR_PARSING;
    }

    return RESULT_SUCESS;
}
