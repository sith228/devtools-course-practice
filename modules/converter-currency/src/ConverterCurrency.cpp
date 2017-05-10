// Copyright 2017 Dmitrichev Nikita

#include "include/ConverterCurrency.h"

const std::vector<double> ConverterCurrency::convert_coefficients_ = {
    30.84,  // BYN to RUR
    8.413,  // CNY to RUR
    2.368,  // CZK to RUR
    63.26,  // EUR to RUR
    75.41,  // GBP to RUR
    0.1824,  // KZT to RUR
    1.0,  // RUR to RUR
    58.08,  // USD to RUR
    2.194,  // UAH to RUR
    0.521197,  // JPY to RUR
    0.05118,  // KRW to RUR
};

double ConverterCurrency::Convert(const double MoneySize,
                         const CurrencyName OldCurrency,
                         const CurrencyName NewCurrency) {
    if (MoneySize >= 0) {
        float ResultMoneySize;

        if (MoneySize == 0) {
            ResultMoneySize = 0;
        } else if (OldCurrency == NewCurrency) {
            ResultMoneySize = MoneySize;
        } else {
            ResultMoneySize = MoneySize * convert_coefficients_[OldCurrency]
                / convert_coefficients_[NewCurrency];
        }

        return ResultMoneySize;
    } else {
        throw "First parameter can't be negative.";
    }
}
