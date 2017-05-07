// Copyright 2017 Dmitrichev Nikita

#include "include/ConverterCurrency.h"

float ConverterCurrency::currentToRubles(const float MoneySize,
                         const currency::CurrencyName OldCurrency) {
    float ResultMoneySize = 0;

    switch (OldCurrency) {
    case currency::RUR:
        ResultMoneySize = MoneySize;
        break;
    case currency::USD:
        ResultMoneySize = MoneySize / currency::RURtoUSD;
        break;
    case currency::EUR:
        ResultMoneySize = MoneySize / currency::RURtoEUR;
        break;
    case currency::UAH:
        ResultMoneySize = MoneySize / currency::RURtoUAH;
        break;
    case currency::CNY:
        ResultMoneySize = MoneySize / currency::RURtoCNY;
        break;
    case currency::JPY:
        ResultMoneySize = MoneySize / currency::RURtoJPY;
        break;
    case currency::GBP:
        ResultMoneySize = MoneySize / currency::RURtoGBP;
        break;
    }

    return ResultMoneySize;
}

float ConverterCurrency::rublesToTarget(const float MoneySize,
                         const currency::CurrencyName NewCurrency) {
    float ResultMoneySize = MoneySize;

    switch (NewCurrency) {
    case currency::RUR:
        break;
    case currency::USD:
        ResultMoneySize *= currency::RURtoUSD;
        break;
    case currency::EUR:
        ResultMoneySize *= currency::RURtoEUR;
        break;
    case currency::UAH:
        ResultMoneySize *= currency::RURtoUAH;
        break;
    case currency::CNY:
        ResultMoneySize *= currency::RURtoCNY;
        break;
    case currency::JPY:
        ResultMoneySize *= currency::RURtoJPY;
        break;
    case currency::GBP:
        ResultMoneySize *= currency::RURtoGBP;
        break;
    }

    return ResultMoneySize;
}

float ConverterCurrency::Convert(const float MoneySize,
                         const currency::CurrencyName OldCurrency,
                         const currency::CurrencyName NewCurrency) {
    if (MoneySize >= 0) {
        float ResultMoneySize;

        if (MoneySize == 0) {
            ResultMoneySize = 0;
        } else if (OldCurrency == NewCurrency) {
            ResultMoneySize = MoneySize;
        } else {
            ResultMoneySize = currentToRubles(MoneySize, OldCurrency);
            ResultMoneySize = rublesToTarget(ResultMoneySize, NewCurrency);
        }

        return ResultMoneySize;
    } else {
        throw "First parameter can't be negative.";
    }
}
