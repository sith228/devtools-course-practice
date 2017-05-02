// Copyright 2017 Dmitrichev Nikita

#ifndef MODULES_CONVERTER_CURRENCY_INCLUDE_CONVERTERCURRENCY_H_
#define MODULES_CONVERTER_CURRENCY_INCLUDE_CONVERTERCURRENCY_H_

namespace Currency {
    const static float RURtoUSD = 0.0175f;
    const static float RURtoEUR = 0.0161f;
    const static float RURtoUAH = 0.4658f;
    const static float RURtoCNY = 0.121f;
    const static float RURtoJPY = 1.9538f;
    const static float RURtoGBP = 0.0136f;
    const static int Error_1000 = 1000;
    enum CurrencyName { RUR, USD, EUR, UAH, CNY, JPY, GBP };
};

class ConverterCurrency {
 private:
     static float CurrentToRubles(const float MoneySize,
         Currency::CurrencyName OldCurrency);
     static float RublesToTarget(float OldMoney,
                                const Currency::CurrencyName TargetMoney);
 public:
     static float Convert(const float MoneySize,
                  const Currency::CurrencyName OldCurrency,
                  const Currency::CurrencyName NewCurrency);
};

#endif  // MODULES_CONVERTER_CURRENCY_INCLUDE_CONVERTERCURRENCY_H_
