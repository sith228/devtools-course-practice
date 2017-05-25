// Copyright 2017 Pletnev Nikita

#include "include/line_plane_intersec.h"
#include "include/line_plane_intersec_app.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>

Application::Application() : message_("") {}

void Application::Help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is an application " +
        "of calculating the intersection of line and plane.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + " <line_x> <line_y> <line_z> " +
        "<dir_x> <dir_y> <dir_z> " +
        "<plane_a> <plane_b> <plane_c> <plane_d>\n\n" +

        "Where all arguments are double-precision numbers,\n" +
        "<line_x>, <line_y>, <line_z> are coordinates of point of line,\n" +
        "<dir_x>, <dir_y>, <dir_z> " +
        "are coordinates of line direction vector,\n" +
        "<plane_a>, <plane_b>, <plane_c>, <plane_d> " +
        "are coefficients of plane ax+by+cz+d=0.\n";
}

bool Application::ValidateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
		Help(argv[0]);
        return false;
    } else if (argc != 11) {
		Help(argv[0], "ERROR: Should be 10 arguments.\n\n");
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

std::string Application::operator()(int argc, const char** argv) {
    Arguments args;

    if (!ValidateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.line_x = parseDouble(argv[1]);
        args.line_y = parseDouble(argv[2]);
        args.line_z = parseDouble(argv[3]);

        args.dir_x = parseDouble(argv[4]);
        args.dir_y = parseDouble(argv[5]);
        args.dir_z = parseDouble(argv[6]);

        args.plane_a = parseDouble(argv[7]);
        args.plane_b = parseDouble(argv[8]);
        args.plane_c = parseDouble(argv[9]);
        args.plane_d = parseDouble(argv[10]);
    }
    catch (std::string& str) {
        return str;
    }

    Intersection intersection;

    intersection.SetLine(args.line_x, args.line_y, args.line_z,
        args.dir_x, args.dir_y, args.dir_z);
    intersection.SetPlane(
        args.plane_a, args.plane_b, args.plane_c, args.plane_d);

    std::vector<double> intersection_result;
    try {
        intersection_result = intersection.CalculateIntersection();
    }
    catch (std::string& str) {
        return str;
    }

    std::ostringstream stream;
    stream << "coordinates of intersection point:\n"
        << " x: " << intersection_result[0] << "\n"
        << " y: " << intersection_result[1] << "\n"
        << " z: " << intersection_result[2];
    message_ = stream.str();

    return message_;
}

