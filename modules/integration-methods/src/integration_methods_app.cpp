// Copyright 2017 Komarov Nikolay

#include "include/integratoin_methods_app.h"
#include "include/integration_methods.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

Application::Application() : message_("") {}

void Application::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a Integration Methods application.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + " <integrand> <low_limit> " +
        "<upper_limit> <integration_method> <option>\n\n" +

        "<integrand> - string of integrand" +
        "<low_limit>, <upper_limit> - low and upper integration" +
        " limits which are double-precision" +
        "<integration_method> - input 'r' for rectangle method," +
        "'t' for trapezoid method or 's' for Simpson method" +
        "<option> - input a quantity of steps for rectangle and" +
        "trapezoid methods or precision for Simpson method\n";
}

bool Application::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    }
    else if (argc != 6) {
        help(argv[0], "ERROR: Should be 5 arguments.\n\n");
        return false;
    }
    return true;
}

double Application::parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

int Application::parseInteger(const char* arg) {
    char* end;
    int value = std::strtol(arg, &end, 10);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

bool Application::validateOperationName(const char* arg) {
    std::string value = arg;
    
    if (value == "t" || value == "r" || value == "s") {
        return true;
    } else {
        return false;
    }
}

std::string Application::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.integrand = argv[1];
        args.low_limit = parseDouble(argv[2]);
        args.upper_limit = parseDouble(argv[3]);
        args.method_name = argv[4];
        if (args.method_name == "s") {
            args.epsilon = parseDouble(argv[5]);
        } else {
            args.quantity_of_steps = parseInteger(argv[5]);
        }
    }
    catch (std::string& str) {
        return str;
    }

    IntegrationMethod integration_method;

    double result;
    std::ostringstream stream;
    if (args.method_name == "r") {
        result = integration_method.RectangleMethod(args.integrand,
            args.low_limit, args.upper_limit, args.quantity_of_steps);
        stream << "The integration value of rectangle method equals " <<
            result;
    }
    else if (args.method_name == "t") {
        result = integration_method.TrapezoidMethod(args.integrand,
            args.low_limit, args.upper_limit, args.quantity_of_steps);
        stream << "The integration value of trapezoid method equals " <<
            result;
    } else if (args.method_name == "s") {
        try {
            result = integration_method.SimpsonMethod(args.integrand,
                args.low_limit, args.upper_limit, args.epsilon);
            stream << "The integration value of Simpson method equals " <<
                result;
        }
        catch (std::runtime_error& str) {
            return str.what();
        }
    }

    message_ = stream.str();

    return message_;
}
