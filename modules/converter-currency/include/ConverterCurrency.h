// Copyright 2017 Dmitrichev Nikita

#ifndef MODULES_CONVERTER_CURRENCY_INCLUDE_CONVERTERCURRENCY_H_
#define MODULES_CONVERTER_CURRENCY_INCLUDE_CONVERTERCURRENCY_H_

#include <vector>

// Names were taken from "svali.ru/currency/index.htm"
enum CurrencyName { BYN, CNY, CZK, EUR, GBP, KZT, RUR, USD, UAH, JPY, KRW};

class ConverterCurrency {
 public:
    static double Convert(const double MoneySize,
        const CurrencyName OldCurrency,
        const CurrencyName NewCurrency);
 private:
     static const std::vector<double> convert_coefficients_;
};

#endif  // MODULES_CONVERTER_CURRENCY_INCLUDE_CONVERTERCURRENCY_H_
