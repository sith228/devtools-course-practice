// Copyright 2017 Maxim Doronin

#include <stdlib.h>
#include <string>
#include <vector>

#include "include/function-factory.h"
#include "include/newton-method.h"
#include "include/newton-method-app.h"

NewtonMethodApplication::NewtonMethodApplication() : message_("") {}

void NewtonMethodApplication::help(const char* appname,
    const std::string message) {
    message_ =
        std::string(message) +
        "This is a Newton Method application\n" +
        "for finding roots of monotony functions.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + " <FunctionId> <left bound> <right bound> " +
        "<list of coefficients>\n\n" +
        "Where all coefficients are float numbers, " +
        "and <FunctionId> is one of the following strings: \n" +
        "POLINOMIAL_2_DEGREE (3 coefficients)\n" +
        "POLINOMIAL_3_DEGREE (4 coefficients)\n" +
        "POLINOMIAL_4_DEGREE (5 coefficients)\n" +
        "EXPONENT            (3 coefficients a*exp(bx) + c)\n\n";
}

bool NewtonMethodApplication::isThereArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    }
    return true;
}

float NewtonMethodApplication::parseFloat(const char* arg) {
    char* end;
    double value = strtof(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

std::vector<float> NewtonMethodApplication::getBounds(int argc,
    const char** argv) {
    std::vector<float> bounds;
    if (argc < 4) {
        help(argv[0], "ERROR: Input bounds at first.\n\n");
        throw std::string("ERROR: No bounds!");
    }
    bounds.push_back(parseFloat(argv[2]));
    bounds.push_back(parseFloat(argv[3]));
    return bounds;
}

std::vector<float> NewtonMethodApplication::getKoefs(int argc,
    const char** argv) {
    std::vector<float> koefs;
    if (argc <= 4) {
        help(argv[0], "ERROR: There is should be coefficients.\n\n");
        throw std::string("ERROR: No coefficients!");
    }
    for (int i = 4; i < argc; i++) {
        koefs.push_back(parseFloat(argv[i]));
    }
    return koefs;
}

std::string NewtonMethodApplication::operator()(int argc, const char** argv) {
    if (!isThereArguments(argc, argv)) {
        return message_;
    }
    if (FunctionId.find(argv[1]) == FunctionId.end()) {
        help(argv[0], "Function doesn't exist\n\n");
        return message_;
    }
    std::vector<float> bounds;
    std::vector<float> koefs;
    try {
        bounds = getBounds(argc, argv);
        koefs = getKoefs(argc, argv);
    }
    catch (std::string& str) {
        help(argv[0], str + std::string("\n"));
        return message_;
    }
    Function* function = FunctionFactory::createFunction(argv[1], koefs);
    NewtonMethod* newtonMethod = new NewtonMethod();
    newtonMethod->SetAB(bounds.at(0), bounds.at(1));
    newtonMethod->SetAccuracy(0.001f);
    float root;
    try {
        root = newtonMethod->FindRoot(function);
    }
    catch (std::string& str) {
        help(argv[0], str + std::string("\n"));
        return message_;
    }

    message_ = "Root: " + std::to_string(root);
    return message_;
}
