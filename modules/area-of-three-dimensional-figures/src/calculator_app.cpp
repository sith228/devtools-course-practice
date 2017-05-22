// Copyright 2017 Zhorin Sergey

#include "include/calculator.h"
#include "include/calculator_app.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

CalculatorApp::CalculatorApp() : message_("") {}

void CalculatorApp::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is an area calculator " +
          "application for tgree dimensional figures.\n\n" +
          "Please provide arguments in the following format:\n\n"+

          "  $ " + appname + " Sphere " +
          " <r> or\n\n " +

          "  $ " + appname + " Cone "+
          " <r> <l> or\n\n " +

          "  $ " + appname + " Conoid " +
          " <r1> <r2> <l> or\n\n " +

          "  $ " + appname + " Cube " +
          " <h> or\n\n " +

          "  $ " + appname + " Cylinder " +
          " <r> <h> or\n\n " +

          "  $ " + appname + " Parallelepiped " +
          " <a> <b> <c> or\n\n " +

          "  $ " + appname + " Prism " +
          " <a> <b> <c> <h> or\n\n " +

          "  $ " + appname + " Pyramid " +
          "<a> <b> <l> or\n\n" +

          "  $ " + appname + " Tetra " +
          " <a> <b> <c> <l>\n\n " +

          "Where all arguments are double-precision numbers.\n";
}

bool CalculatorApp::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    }
    if (strcmp(argv[1], "Sphere") == 0) {
        if ((argc != 3)) {
            help(argv[0], " ERROR: wrong number of arguments! \n");
            return false;
        }
    } else if (strcmp(argv[1], "Cone") == 0) {
        if ((argc != 4)) {
            help(argv[0], " ERROR: wrong number of arguments! \n");
            return false;
        }
    } else if (strcmp(argv[1], "Conoid") == 0) {
        if ((argc != 5)) {
            help(argv[0], " ERROR: wrong number of arguments! \n");
            return false;
        }
    } else if (strcmp(argv[1], "Cube") == 0) {
        if ((argc != 3)) {
            help(argv[0], " ERROR: wrong number of arguments! \n");
            return false;
        }
    } else if (strcmp(argv[1], "Cylinder") == 0) {
        if ((argc != 4)) {
            help(argv[0], " ERROR: wrong number of arguments! \n");
            return false;
        }
    } else if (strcmp(argv[1], "Parallelepiped") == 0) {
        if ((argc != 5)) {
            help(argv[0], " ERROR: wrong number of arguments! \n");
            return false;
        }
    } else if (strcmp(argv[1], "Prism") == 0) {
        if ((argc != 6)) {
            help(argv[0], " ERROR: wrong number of arguments! \n");
            return false;
        }
    } else if (strcmp(argv[1], "Pyramid") == 0) {
        if ((argc != 5)) {
            help(argv[0], " ERROR: wrong number of arguments! \n");
            return false;
        }
    } else if (strcmp(argv[1], "Tetra") == 0) {
        if ((argc != 6)) {
            help(argv[0], " ERROR: wrong number of arguments! \n");
            return false;
        }
    }
    
    return true;
}

double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);
    if (end[0]) {
        throw std::string(" Wrong number format! \n");
    }
    return value;
}

std::string parseOperation(const char* arg) {
    std::string op;
    if (strcmp(arg, "Sphere") == 0) {
        op = "Sphere";
    } else if (strcmp(arg, "Cone") == 0) {
        op = "Cone";
    } else if (strcmp(arg, "Conoid") == 0) {
        op = "Conoid";
    }  else if (strcmp(arg, "Cube") == 0) {
        op = "Cube";
    }  else if (strcmp(arg, "Cylinder") == 0) {
        op = "Cylinder";
    }  else if (strcmp(arg, "Parallelepiped") == 0) {
        op = "Parallelepiped";
    }  else if (strcmp(arg, "Prism") == 0) {
        op = "Prism";
    }  else if (strcmp(arg, "Pyramid") == 0) {
        op = "Pyramid";
    }  else if (strcmp(arg, "Tetra") == 0) {
        op = "Tetra";
    } else {
        throw std::string("Wrong figure format!");
    }
    return op;
}

std::string CalculatorApp::operator()(int argc, const char** argv) {
    std::string figure;
    double a = 0;
    double b = 0;
    double c = 0;
    double d = 0;
    double s = 0;
    Calculator calc;
    std::ostringstream stream;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        figure = parseOperation(argv[1]);
    }
    catch (std::string& str) {
        return str;
    }

    if (figure == "Sphere") {
        try {
            a = parseDouble(argv[2]);
        }
        catch (std::string& str) {
            return str;
        }
        try {
            s = calc.Calculate_Sphere(a);
        }
        catch (std::string& str) {
            return str;
        }
    }  else if (figure == "Cone") {
        try {
            a = parseDouble(argv[2]);
            b = parseDouble(argv[3]);
        }
        catch (std::string& str) {
            return str;
        }
        try {
            s = calc.Calculate_Cone(a, b);
        }
        catch (std::string& str) {
            return str;
        }
    }  else if (figure == "Conoid") {
        try {
            a = parseDouble(argv[2]);
            b = parseDouble(argv[3]);
            c = parseDouble(argv[4]);
        }
        catch (std::string& str) {
            return str;
        }
        try {
            s = calc.Calculate_Conoid(a, b, c);
        }
        catch (std::string& str) {
            return str;
        }
    }  else if (figure == "Cube") {
        try {
            a = parseDouble(argv[2]);
        }
        catch (std::string& str) {
            return str;
        }
        try {
            s = calc.Calculate_Cube(a);
        }
        catch (std::string& str) {
            return str;
        }
    }  else if (figure == "Cylinder") {
        try {
            a = parseDouble(argv[2]);
            b = parseDouble(argv[3]);
        }
        catch (std::string& str) {
            return str;
        }
        try {
            s = calc.Calculate_Cylinder(a, b);
        }
        catch (std::string& str) {
            return str;
        }
    }  else if (figure == "Parallelepiped") {
        try {
            a = parseDouble(argv[2]);
            b = parseDouble(argv[3]);
            c = parseDouble(argv[4]);
        }
        catch (std::string& str) {
            return str;
        }
        try {
            s = calc.Calculate_Parallelepiped(a, b, c);
        }
        catch (std::string& str) {
            return str;
        }
    }  else if (figure == "Prism") {
        try {
            a = parseDouble(argv[2]);
            b = parseDouble(argv[3]);
            c = parseDouble(argv[4]);
            d = parseDouble(argv[5]);
        }
        catch (std::string& str) {
            return str;
        }
        try {
            s = calc.Calculate_Prism(a, b, c, d);
        }
        catch (std::string& str) {
            return str;
        }
    }  else if (figure == "Pyramid") {
        try {
            a = parseDouble(argv[2]);
            b = parseDouble(argv[3]);
            c = parseDouble(argv[4]);
        }
        catch (std::string& str) {
            return str;
        }
        try {
            s = calc.Calculate_Pyramid(a, b, c);
        }
        catch (std::string& str) {
            return str;
        }
    }  else if (figure == "Tetra") {
        try {
            a = parseDouble(argv[2]);
            b = parseDouble(argv[3]);
            c = parseDouble(argv[4]);
            d = parseDouble(argv[5]);
        }
        catch (std::string& str) {
            return str;
        }
        try {
            s = calc.Calc_Tetra(a, b, c, d);
        }
        catch (std::string& str) {
            return str;
        }
    }
    stream << "S = " << s;
    message_ = stream.str();
    return message_;
}
