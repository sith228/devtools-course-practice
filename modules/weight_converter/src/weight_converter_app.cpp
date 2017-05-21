// Copyright 2017 Simonyan Vaginak

#include "include/weight_converter.h"
#include "include/weight_converter_app.h"

#include <map>
#include <sstream>

Application::Application() : message_("") {}

void Application::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a weight converter application.\n\n" +
          "Please provide arguments in the following format:\n\n"+

          "  $ " + appname + " <weight> <type_from> " +
          "<type_to> <operation>\n\n" +

          "Where the first argument is a positive double-precision number \n" +
          "<type_from> and <type_to> are one of  'KG', 'MG', 'G', 'GR'," +
          "'DR', 'OZ', 'LB', 'CR' \n"+
          "<operation> is one of 'set' for SetWeight," +
          "'get' for GetWeight,'t' for Convert(to)," +
          "'ft' for Convert(from, to).\n";
}

bool Application::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    }
    else if (argc != 5) {
        help(argv[0], "ERROR: Should be 4 arguments.\n\n");
        return false;
    }
    return true;
}

double parseWeight(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0] || value < 0) {
        throw std::string("Wrong number format!");
    }

    return value;
}

Weights parseWeightType(const char* arg) {
    Weights wt;

    if (strcmp(arg, "KG") == 0) {
        wt = Weights::KG;
    }
    else if (strcmp(arg, "MG") == 0) {
        wt = Weights::MG;
    }
    else if (strcmp(arg, "G") == 0) {
        wt = Weights::G;
    }
    else if (strcmp(arg, "GR") == 0) {
        wt = Weights::GR;
    }
    else if (strcmp(arg, "DR") == 0) {
        wt = Weights::DR;
    }
    else if (strcmp(arg, "OZ") == 0) {
        wt = Weights::OZ;
    }
    else if (strcmp(arg, "LB") == 0) {
        wt = Weights::LB;
    }
    else if (strcmp(arg, "CR") == 0) {
        wt = Weights::CR;
    }
    else {
        throw std::string("Wrong weight's type format!");
    }
    return wt;
}

char parseOperation(const char* arg) {
    char op;
    if (strcmp(arg, "set") == 0) {
        op = 's';
    } else if (strcmp(arg, "get") == 0) {
        op = 'g';
    } else if (strcmp(arg, "t") == 0) {
        op = 't';
    } else if (strcmp(arg, "ft") == 0) {
        op = 'ft';
    } else {
        throw std::string("Wrong operation format!");
    }
    return op;
}

std::string Application::operator()(int argc, const char** argv) {
    Arguments args;
    Weights type_from;
    Weights type_to;
    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.weight = parseWeight(argv[1]);
        type_from = parseWeightType(argv[2]);
        type_to = parseWeightType(argv[3]);
        args.operation = parseOperation(argv[4]);
    }
    catch (std::string& str) {
        return str;
    }

    WeightConverter weight_converter(0.001,Weights::KG);

    std::ostringstream stream;

    switch (args.operation) {
    case 's':
        weight_converter.SetWeight(args.weight,type_from);
        stream << "Weight = " << weight_converter.GetWeight() << " ";
        break;
    case 'g':
        stream << "Weight = " << weight_converter.GetWeight() << " ";
        break;
    case 't':
        weight_converter.Convert(type_to);
        stream << "Weight = " << weight_converter.GetWeight() << " ";
        break;
    case 'ft':
        try {
            weight_converter.Convert(args.weight, type_from, type_to);
            stream << "Weight = " << weight_converter.GetWeight() << " ";
            break;
        }
        catch (std::string& str) {
            return str;
        }
    }

    message_ = stream.str();

    return message_;
}