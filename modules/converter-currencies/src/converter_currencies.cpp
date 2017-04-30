// Copyright 2017 Dmitrichev Nikita

#ifndef MODULES_CONVERTER_CURRENCIES_INCLUDE_CONVERTER_CURRENCIES_CPP_
#define MODULES_CONVERTER_CURRENCIES_INCLUDE_CONVERTER_CURRENCIES_CPP_

#include "include/converter_currencies.h"

converter_currencies::converter_currencies(const float CurrencySize,
                                           const Currency MoneyName) {
     SetCurrentMoney(CurrencySize, MoneyName);
}

Currency converter_currencies::GetCurrentCurrency(void) const {
     return CurrencyName;
}

float converter_currencies::GetCurrentSize(void) const {
    return UniversalMoney;
}

float converter_currencies::CurrentToRubles(void) {
    float ResultMoney = 0;
    switch (CurrencyName) {
    case RUR:
        ResultMoney = UniversalMoney;
        break;
    case USD:
        ResultMoney = UniversalMoney / RURtoUSD;
        break;
    case EUR:
        ResultMoney = UniversalMoney / RURtoEUR;
        break;
    case UAH:
        ResultMoney = UniversalMoney / RURtoUAH;
        break;
    case CNY:
        ResultMoney = UniversalMoney / RURtoCNY;
        break;
    case JPY:
        ResultMoney = UniversalMoney / RURtoJPY;
        break;
    case GBP:
        ResultMoney = UniversalMoney / RURtoGBP;
        break;
    }
    return ResultMoney;
}

void converter_currencies::RublesToTarget(float* OldMoney, 
                                           const Currency TargetMoney) {
    switch (TargetMoney) {
    case RUR:
        break;
    case USD:
        *OldMoney *= RURtoUSD;
        break;
    case EUR:
        *OldMoney *= RURtoEUR;
        break;
    case UAH:
        *OldMoney *= RURtoUAH;
        break;
    case CNY:
        *OldMoney *= RURtoCNY;
        break;
    case JPY:
        *OldMoney *= RURtoJPY;
        break;
    case GBP:
        *OldMoney *= RURtoGBP;
        break;
    }
}
void converter_currencies::SetCurrentMoney(const float CurrencySize,
                                           const Currency MoneyName) {
     if (CurrencySize < 0)
          throw Error_1000;
     else {
         UniversalMoney = CurrencySize;
         CurrencyName = MoneyName;
     }
}
void converter_currencies::Convert(const Currency TargetMoney) {
     float ResultMoney;
     if (UniversalMoney == 0)
          ResultMoney = 0;
     else {
         ResultMoney = CurrentToRubles();
         RublesToTarget(&ResultMoney, TargetMoney);
     }
     SetCurrentMoney(ResultMoney, TargetMoney);
}

#endif  // MODULES_CONVERTER_CURRENCIES_INCLUDE_CONVERTER_CURRENCIES_CPP_
