// Copyright 2017 Dmitrichev Nikita

#include "include/ConverterCurrency.h"

using namespace Currency;

float ConverterCurrency::CurrentToRubles(const float MoneySize,
                                         CurrencyName OldCurrency) {
    float ResultMoney = 0;
    switch (OldCurrency) {
    case RUR:
        ResultMoney = MoneySize;
        break;
    case USD:
        ResultMoney = MoneySize / RURtoUSD;
        break;
    case EUR:
        ResultMoney = MoneySize / RURtoEUR;
        break;
    case UAH:
        ResultMoney = MoneySize / RURtoUAH;
        break;
    case CNY:
        ResultMoney = MoneySize / RURtoCNY;
        break;
    case JPY:
        ResultMoney = MoneySize / RURtoJPY;
        break;
    case GBP:
        ResultMoney = MoneySize / RURtoGBP;
        break;
    }
    return ResultMoney;
}

float ConverterCurrency::RublesToTarget(const float MoneySize,
                                           const CurrencyName TargetMoney) {
    float ResultMoney = MoneySize;
    switch (TargetMoney) {
    case RUR:
        break;
    case USD:
        ResultMoney *= RURtoUSD;
        break;
    case EUR:
        ResultMoney *= RURtoEUR;
        break;
    case UAH:
        ResultMoney *= RURtoUAH;
        break;
    case CNY:
        ResultMoney *= RURtoCNY;
        break;
    case JPY:
        ResultMoney *= RURtoJPY;
        break;
    case GBP:
        ResultMoney *= RURtoGBP;
        break;
    }
    return ResultMoney;
}

float ConverterCurrency::Convert(const float MoneySize,
                                 const CurrencyName OldCurrency,
                                 const CurrencyName NewCurrency) {
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
        throw Error_1000;
    }
}
