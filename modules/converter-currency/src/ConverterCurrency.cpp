// Copyright 2017 Dmitrichev Nikita

#include "include/ConverterCurrency.h"

float ConverterCurrency::CurrentToRubles(const float MoneySize,
    Currency::CurrencyName OldCurrency) {
    float ResultMoney = 0;
    switch (OldCurrency) {
    case Currency::RUR:
        ResultMoney = MoneySize;
        break;
    case Currency::USD:
        ResultMoney = MoneySize / Currency::RURtoUSD;
        break;
    case Currency::EUR:
        ResultMoney = MoneySize / Currency::RURtoEUR;
        break;
    case Currency::UAH:
        ResultMoney = MoneySize / Currency::RURtoUAH;
        break;
    case Currency::CNY:
        ResultMoney = MoneySize / Currency::RURtoCNY;
        break;
    case Currency::JPY:
        ResultMoney = MoneySize / Currency::RURtoJPY;
        break;
    case Currency::GBP:
        ResultMoney = MoneySize / Currency::RURtoGBP;
        break;
    }
    return ResultMoney;
}

float ConverterCurrency::RublesToTarget(const float MoneySize,
                                       const Currency::CurrencyName TargetMoney) {
    float ResultMoney = MoneySize;
    switch (TargetMoney) {
    case Currency::RUR:
        break;
    case Currency::USD:
        ResultMoney *= Currency::RURtoUSD;
        break;
    case Currency::EUR:
        ResultMoney *= Currency::RURtoEUR;
        break;
    case Currency::UAH:
        ResultMoney *= Currency::RURtoUAH;
        break;
    case Currency::CNY:
        ResultMoney *= Currency::RURtoCNY;
        break;
    case Currency::JPY:
        ResultMoney *= Currency::RURtoJPY;
        break;
    case Currency::GBP:
        ResultMoney *= Currency::RURtoGBP;
        break;
    }
    return ResultMoney;
}

float ConverterCurrency::Convert(const float MoneySize,
                                 const Currency::CurrencyName OldCurrency,
                                 const Currency::CurrencyName NewCurrency) {
    if (MoneySize >= 0) {
        float ResultMoney;
        if (MoneySize == 0) {
            ResultMoney = 0;
        } else if (OldCurrency == NewCurrency) {
            ResultMoney = MoneySize;
        } else {
            ResultMoney = CurrentToRubles(MoneySize, OldCurrency);
            ResultMoney = RublesToTarget(ResultMoney, NewCurrency);
        }
        return ResultMoney;
    } else {
        throw Currency::Error_1000;
    }
}
