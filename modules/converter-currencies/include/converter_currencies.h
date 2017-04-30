// Copyright 2017 Dmitrichev Nikita

#ifndef MODULES_CONVERTER_CURRENCIES_INCLUDE_CONVERTER_CURRENCIES_H_
#define MODULES_CONVERTER_CURRENCIES_INCLUDE_CONVERTER_CURRENCIES_H_

#define RURtoUSD 0.0175f
#define RURtoEUR 0.0161f
#define RURtoUAH 0.4658f
#define RURtoCNY 0.121f
#define RURtoJPY 1.9538f
#define RURtoGBP 0.0136f

#define Error_1000 1000
enum Currency { RUR, USD, EUR, UAH, CNY, JPY, GBP };

class converter_currencies {
 private:
     float UniversalMoney;
     Currency CurrencyName;
     float CurrentToRubles(void);
     void RublesToTarget(float* OldMoney, const Currency TargetMoney);
 public:
     converter_currencies(const float CurrencySize, const Currency MoneyName);
     void SetCurrentMoney(const float CurrencySize, const Currency MoneyName);
     void Convert(const Currency TargetMoney);
     Currency GetCurrentCurrency(void) const;
     float GetCurrentSize(void) const;
};

#endif  // MODULES_CONVERTER_CURRENCIES_INCLUDE_CONVERTER_CURRENCIES_H_
