#include "include/vector3D.h"
#include "include/vector3D-app.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

Vector3DApp::Vector3DApp() : message_("") {}

void Vector3DApp::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a vector calculator application.\n\n" +
          "Please provide arguments in the following format:\n\n"+

          "  $ " + appname + " <v1_x> <v1_y> <v1_z>" +
          "<v2_x> <v2_y> <v2_z> <operation>\n\n" +

          "Where all arguments are double-precision numbers, " +
          "and <operation> is one of '+', '-', '*', '^', 'n', 'N'.\n";
}

bool Vector3DApp::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    }
    else if (!(argc == 5 || argc == 8)) {
        help(argv[0], "ERROR: Should be 7 or 4 arguments.\n\n");
        return false;
    }
    return true;
}

double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

char parseOperationBinary(const char* arg) {
    char op;
    if (strcmp(arg, "+") == 0) {
        op = '+';
    }
    else if (strcmp(arg, "-") == 0) {
        op = '-';
    }
    else if (strcmp(arg, "*") == 0) {
        op = '*';
    }
    else if (strcmp(arg, "^") == 0) {
        op = '^';
    }
    else {
        throw std::string("Wrong operation format!");
    }
    return op;
}

char parseOperationUnary(const char* arg) {
    char op;
    if (strcmp(arg, "n") == 0) {
        op = 'n';
    }
    else if (strcmp(arg, "N") == 0) {
        op = 'N';
    }
    else {
        throw std::string("Wrong operation format!");
    }
    return op;
}

std::string Vector3DApp::operator()(int argc, const char** argv) {
    ArgumentsBinary argsBinary;
    ArgumentsUnary argsUnary;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        if (argc == 8) {
            argsBinary.v1_x = parseDouble(argv[1]);
            argsBinary.v1_y = parseDouble(argv[2]);
            argsBinary.v1_z = parseDouble(argv[3]);
            argsBinary.v2_x = parseDouble(argv[4]);
            argsBinary.v2_y = parseDouble(argv[5]);
            argsBinary.v2_z = parseDouble(argv[6]);
            argsBinary.operation = parseOperationBinary(argv[7]);
        }
        if (argc == 5)
        {
            argsUnary.v1_x = parseDouble(argv[1]);
            argsUnary.v1_y = parseDouble(argv[2]);
            argsUnary.v1_z = parseDouble(argv[3]);
            argsUnary.operation = parseOperationUnary(argv[4]);
        }
    }
    catch (std::string& str) {
        return str;
    }

    std::ostringstream stream;

    if (argc == 5) {
        Vector3D v1(argsUnary.v1_x, argsUnary.v1_y, argsUnary.v1_z);
        switch (argsUnary.operation) {
            case 'n':
                stream << "Norm = " << v1.Norm();
                break;
            case 'N':
                Vector3D resultVector = v1.Normalize();
                stream << "Normalization vector = <" <<
                            resultVector.GetX() <<
                    "; " << resultVector.GetY() << 
                    "; " << resultVector.GetZ() << ">";
                break;
        }
    }

    if (argc == 8) {
        Vector3D v1(argsBinary.v1_x, argsBinary.v1_y, argsBinary.v1_z);
        Vector3D v2(argsBinary.v2_x, argsBinary.v2_y, argsBinary.v2_z);
        Vector3D resultVector;
        switch (argsBinary.operation) {
            case '+':
                resultVector = v1 + v2;
                stream << "Sum = <" <<
                            resultVector.GetX() <<
                    "; " << resultVector.GetY() <<
                    "; " << resultVector.GetZ() << ">";
                break;
            case '-':
                resultVector = v1 - v2;
                stream << "Difference = <" <<
                            resultVector.GetX() <<
                    "; " << resultVector.GetY() <<
                    "; " << resultVector.GetZ() << ">";
                break;
            case '*':
                stream << "Scalar multiplication = " << v1 * v2;
                break;
            case '^':
                resultVector = v1 ^ v2;
                stream << "Vector multiplication = <" <<
                            resultVector.GetX() <<
                    "; " << resultVector.GetY() <<
                    "; " << resultVector.GetZ() << ">";
                break;
        }
    }

    message_ = stream.str();

    return message_;
}