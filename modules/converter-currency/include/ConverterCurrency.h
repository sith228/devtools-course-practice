// Copyright 2017 Dmitrichev Nikita

#ifndef MODULES_CONVERTER_CURRENCY_INCLUDE_CONVERTERCURRENCY_H_
#define MODULES_CONVERTER_CURRENCY_INCLUDE_CONVERTERCURRENCY_H_

namespace currency {
    enum CurrencyName { RUR, USD, EUR, UAH, CNY, JPY, GBP };
    const float RURtoUSD = 0.0175f;
    const float RURtoEUR = 0.0161f;
    const float RURtoUAH = 0.4658f;
    const float RURtoCNY = 0.121f;
    const float RURtoJPY = 1.9538f;
    const float RURtoGBP = 0.0136f;
};

class ConverterCurrency {
 public:
    static float Convert(const float MoneySize,
        const currency::CurrencyName OldCurrency,
        const currency::CurrencyName NewCurrency);
 private:
     static float currentToRubles(const float MoneySize,
        const currency::CurrencyName OldCurrency);
     static float rublesToTarget(float OldMoney,
        const currency::CurrencyName TargetMoney);
};

#endif  // MODULES_CONVERTER_CURRENCY_INCLUDE_CONVERTERCURRENCY_H_
