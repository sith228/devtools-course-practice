// Copyright 2017 Dmitrichev Nikita

#define ERROR_INVALIDMONEYSIZE 1000 // MoneySize on Convert() can't be negative

#include "include/ConverterCurrency.h"

float ConverterCurrency::CurrentToRubles(const float MoneySize,
    Currency::CurrencyName OldCurrency) {
    float ResultMoneySize = 0;
    switch (OldCurrency) {
    case Currency::RUR:
        ResultMoneySize = MoneySize;
        break;
    case Currency::USD:
        ResultMoneySize = MoneySize / Currency::RURtoUSD;
        break;
    case Currency::EUR:
        ResultMoneySize = MoneySize / Currency::RURtoEUR;
        break;
    case Currency::UAH:
        ResultMoneySize = MoneySize / Currency::RURtoUAH;
        break;
    case Currency::CNY:
        ResultMoneySize = MoneySize / Currency::RURtoCNY;
        break;
    case Currency::JPY:
        ResultMoneySize = MoneySize / Currency::RURtoJPY;
        break;
    case Currency::GBP:
        ResultMoneySize = MoneySize / Currency::RURtoGBP;
        break;
    }
    return ResultMoneySize;
}

float ConverterCurrency::RublesToTarget(const float MoneySize,
                               const Currency::CurrencyName TargetMoney) {
    float ResultMoneySize = MoneySize;
    switch (TargetMoney) {
    case Currency::RUR:
        break;
    case Currency::USD:
        ResultMoneySize *= Currency::RURtoUSD;
        break;
    case Currency::EUR:
        ResultMoneySize *= Currency::RURtoEUR;
        break;
    case Currency::UAH:
        ResultMoneySize *= Currency::RURtoUAH;
        break;
    case Currency::CNY:
        ResultMoneySize *= Currency::RURtoCNY;
        break;
    case Currency::JPY:
        ResultMoneySize *= Currency::RURtoJPY;
        break;
    case Currency::GBP:
        ResultMoneySize *= Currency::RURtoGBP;
        break;
    }
    return ResultMoneySize;
}

float ConverterCurrency::Convert(const float MoneySize,
                                 const Currency::CurrencyName OldCurrency,
                                 const Currency::CurrencyName NewCurrency) {
    if (MoneySize >= 0) {
        float ResultMoneySize;
        if (MoneySize == 0) {
            ResultMoneySize = 0;
        } else if (OldCurrency == NewCurrency) {
            ResultMoneySize = MoneySize;
        } else {
            ResultMoneySize = CurrentToRubles(MoneySize, OldCurrency);
            ResultMoneySize = RublesToTarget(ResultMoneySize, NewCurrency);
        }
        return ResultMoneySize;
    } else {
        throw ERROR_INVALIDMONEYSIZE;
    }
}
