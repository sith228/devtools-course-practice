// Copyright 2017 Maxim Doronin

#include "include/function-factory.h"
#include "include/newton-method.h"
#include "include/newton-method-app.h"

NewtonMethodApplication::NewtonMethodApplication() : message_("") {}

void NewtonMethodApplication::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a Newton Method application\n" +
          "for finding roots of monotony functions.\n\n" +
          "Please provide arguments in the following format:\n\n"+

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

double NewtonMethodApplication::parseFloat(const char* arg) {
    char* end;
    double value = strtof(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

std::vector<float> NewtonMethodApplication::getBounds(int argc, const char** argv) {
	std::vector<float> bounds;
	if (argc < 4) {
		help(argv[0], "ERROR: Input bounds at first.\n\n");
		return bounds;
	}
	bounds.push_back(parseFloat(argv[2]));
	bounds.push_back(parseFloat(argv[3]));
	return bounds;
}

std::vector<float> NewtonMethodApplication::getKoefs(int argc, const char** argv) {
    std::vector<float> koefs;
	if (argc <= 4) {
		help(argv[0], "ERROR: There is should be coefficients.\n\n");
		return koefs;
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
	//std::vector<float> bounds = getBounds(argc, argv);
    //std::vector<float> koefs = getKoefs(argc, argv);
	//Function* function = FunctionFactory::createFunction(argv[1], koefs);

    return message_;
}
