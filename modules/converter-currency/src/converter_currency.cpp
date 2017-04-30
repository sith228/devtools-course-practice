// Copyright 2017 Dmitrichev Nikita

#include "include/converter_currency.h"

converter_currency::converter_currency() {
}

float converter_currency::CurrentToRubles(const float MoneySize,
                                          Currency OldCurrency) {
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

float converter_currency::RublesToTarget(const float MoneySize, 
                                           const Currency TargetMoney) {
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

float converter_currency::Convert(const float MoneySize,
                                 const Currency OldCurrency,
                                 const Currency NewCurrency) {
    if (MoneySize >= 0) {
        float ResultMoney;
        if (MoneySize == 0)
            ResultMoney = 0;
        else if (OldCurrency == NewCurrency)
            ResultMoney = MoneySize;
        else {
            ResultMoney = CurrentToRubles(MoneySize, OldCurrency);
            ResultMoney = RublesToTarget(ResultMoney, NewCurrency);
        }
        return ResultMoney;
    }
    else
        throw Error_1000;
}
