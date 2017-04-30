// Copyright 2017 Dmitrichev Nikita

#ifndef MODULES_CONVERTER_CURRENCY_INCLUDE_CONVERTER_CURRENCY_H_
#define MODULES_CONVERTER_CURRENCY_INCLUDE_CONVERTER_CURRENCY_H_

#define RURtoUSD 0.0175f
#define RURtoEUR 0.0161f
#define RURtoUAH 0.4658f
#define RURtoCNY 0.121f
#define RURtoJPY 1.9538f
#define RURtoGBP 0.0136f

#define Error_1000 1000
enum Currency { RUR, USD, EUR, UAH, CNY, JPY, GBP };

class converter_currency {
 private:
     float CurrentToRubles(const float MoneySize,
                           Currency OldCurrency);
     float RublesToTarget(float OldMoney, const Currency TargetMoney);
 public:
     converter_currency();
     float Convert(const float MoneySize,
                  const Currency OldCurrency,
                  const Currency NewCurrency);
};

#endif  // MODULES_CONVERTER_CURRENCY_INCLUDE_CONVERTER_CURRENCY_H_
