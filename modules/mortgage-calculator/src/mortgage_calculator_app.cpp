// Copyright 2017 Grechukhin Nikita

#include "../include/mortgage_calculator_app.h"
#include "../include/mortgage_calculator.h"

#include <string>
#include <sstream>
#include <stdexcept>

double parseDouble(const std::string &arg);
int parseInt(const std::string &arg);

Application::Application() : message_("") {}

void Application::help(const char *appName, const char *message) {
    message_ = std::string(message) +
        "This is a mortgage calculator application. \n\n" +
        "Arguments should be provided in the following format: \n" +

        " $ " + appName + " <amount> <period> <year interest> \n\n" +
        "Where \n     <amout> is the amount of money required\n" +
            "        to purchase an apartment \n" +
        "    <period> is the period on which the mortgage is taken \n" +
        "    <year interest> is interest on which a mortgage is taken \n";
}

std::string Application::operator()(int argc, const char** argv) {
    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }

    double amount;
    int period;
    double year_interest;

    try {
        amount = parseDouble(argv[1]);
        period = parseInt(argv[2]);
        year_interest = parseDouble(argv[3]);
    } catch (std::invalid_argument &e) {
        return e.what();
    }

    CalculatorResult calculatorResult;
    try {
        calculatorResult = MortgageCalculator::Calculate(amount,
                                            period, year_interest);
    } catch (std::invalid_argument &e) {
        return e.what();
    }

    std::ostringstream stream;
    stream << "Monthly payment : " << calculatorResult.monthly_payment <<
        "\nOverpayment amount : " << calculatorResult.overpayment_amount <<
        "\nTotal payout : " << calculatorResult.total_payout << "\0";

    message_ = stream.str();
    return message_;
}

bool Application::validateNumberOfArguments(int argc, const char **argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 4) {
        help(argv[0], "ERROR: Should be 3 arguments.\n\n");
        return false;
    }
    return true;
}

double parseDouble(const std::string &arg) {
    char *end;
    double value = static_cast<double>(strtod(arg.c_str(), &end));

    if (end[0]) {
        throw std::invalid_argument("Wrong number format!");
    }

    return value;
}

int parseInt(const std::string &arg) {
    char *end;
    int value = static_cast<int>(strtol(arg.c_str(), &end, 10));

    if (end[0]) {
        throw std::invalid_argument("Wrong number format!");
    }

    return value;
}
