// Copyright 2017 Dmitrichev Nikita

#include "include/ConverterCurrency.h"

float ConverterCurrency::getConvertCoeff(
                         const currency::CurrencyName Currency) {
    switch (Currency) {
    case currency::RUR:
        return currency::RURtoRUR;
    case currency::USD:
        return currency::RURtoUSD;
    case currency::EUR:
        return currency::RURtoEUR;
    case currency::UAH:
        return currency::RURtoUAH;
    case currency::CNY:
        return currency::RURtoCNY;
    case currency::JPY:
        return currency::RURtoJPY;
    case currency::GBP:
        return currency::RURtoGBP;
    }
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
            ResultMoneySize = MoneySize /
                getConvertCoeff(OldCurrency) * getConvertCoeff(NewCurrency);
        }

        return ResultMoneySize;
    } else {
        throw "First parameter can't be negative.";
    }
}
