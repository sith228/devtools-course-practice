// Copyright 2017 Karev Boris

#include "include/ConverterCurrencyApp.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

#include "include/ConverterCurrency.h"

ConverterCurrencyApp::ConverterCurrencyApp() : message_("") {}

void ConverterCurrencyApp::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a converter currency application.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + " <money size> <old currency> " +
        "<new currency> <convert coefficient of the old currency> " +
        "<convert coefficient of the new currency>\n\n" +

        "Where 1,3 and 4 arguments is double-precision number, " +
        "2 and 3 arguments is one of type of currency, " +
        "which you can find on the svali.ru/currency/index.htm. " +
        "If selected meaning '0' for 3 or 4 arguments, " +
        "will use default meaning of convert coefficient\n";
}

bool ConverterCurrencyApp::validateNumberOfArguments
(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 6) {
        help(argv[0], "ERROR: Should be 5 arguments.\n\n");
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

CurrencyName parseCurrency(const char* arg) {
    CurrencyName currency;
    if (strcmp(arg, "BYN") == 0) {
        currency = BYN;
    } else if (strcmp(arg, "CNY") == 0) {
        currency = CNY;
    } else if (strcmp(arg, "CZK") == 0) {
        currency = CZK;
    } else if (strcmp(arg, "EUR") == 0) {
        currency = EUR;
    } else if (strcmp(arg, "GBP") == 0) {
        currency = GBP;
    } else if (strcmp(arg, "KZT") == 0) {
        currency = KZT;
    } else if (strcmp(arg, "RUR") == 0) {
        currency = RUR;
    } else if (strcmp(arg, "USD") == 0) {
        currency = USD;
    } else if (strcmp(arg, "UAH") == 0) {
        currency = UAH;
    } else if (strcmp(arg, "JPY") == 0) {
        currency = JPY;
    } else if (strcmp(arg, "KRW") == 0) {
        currency = KRW;
    } else {
        throw std::string("Wrong currency format!");
    }
    return currency;
}

std::string ConverterCurrencyApp::operator()(int argc, const char** argv) {
    Arguments args;
    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }

    try {
        args.money_size = parseDouble(argv[1]);
        args.old_currency = parseCurrency(argv[2]);
        args.new_currency = parseCurrency(argv[3]);
        args.first_convert_coeff = parseDouble(argv[4]);
        args.second_convert_coeff = parseDouble(argv[5]);
    }
    catch(std::string& str) {
        return str;
    }

    double result;
    std::ostringstream stream;

    if (args.first_convert_coeff != 0) {
        try {
            ConverterCurrency::SetExchangeRateToRUR(args.old_currency,
                args.first_convert_coeff);
        } catch (std::string& str) {
            return str;
        }
    }

    if (args.second_convert_coeff != 0) {
        try {
            ConverterCurrency::SetExchangeRateToRUR(args.new_currency,
                args.second_convert_coeff);
        } catch (std::string& str) {
            return str;
        }
    }

    try {
        result = ConverterCurrency::Convert(args.money_size,
            args.old_currency, args.new_currency);
        stream << "Result of convertation = " << result;
    } catch (std::string& str) {
        return str;
    }

    message_ = stream.str();

    return message_;
}
