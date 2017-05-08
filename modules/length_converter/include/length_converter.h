// Copyright 2017 Tarasov Oleg

/* 
Использование:
Length length(LENGTH_LYPE in_type, double value);
double converted_val = length.ConverTo(LENGTH_LYPE out_type);

LENGTH_LYPE in_type - входная единица измерения
double val - входное значение
out_type - выходная единица измерения
*/


#ifndef MODULES_LENGTH_CONVERTER_INCLUDE_LENGTH_CONVERTER_H_
#define MODULES_LENGTH_CONVERTER_INCLUDE_LENGTH_CONVERTER_H_

enum LENGTH_TYPE {
    /* Метрические единицы измерения */
    MICROMETRE,     // микрометр = 0.000001 метра
    MILLIMETRE,     // миллиметр = 0.001 метра
    CENTIMETRE,     // сантиметр = 0.01 метра
    DECIMETRE,      // дециметр = 0.1 метра
    METRE,          // метр
    KILOMETRE,      // километр = 1000 метров

    /* Английская система мер */
    INCH,           // дюйм = 2.54 см
    HAND,           // хэнд = 10.16 см
    LINK,           // линк = 20.1168 см
    FOOT,           // фут = 30.48 см
    YARD,           // ярд = 91.44 см
    ROD,            // род/перч = 5.0292 м
    CHAIN,          // чейн = 20.1168 м
    FURHLONG,       // фурлонг = 201.16 м
    MILE,           // миля = 1,609344 км
    LEAGUE          // лига = 4,828032 км
};


class Length {
 public:
    Length(LENGTH_TYPE type, double value);
    void SetValue(LENGTH_TYPE type, double value);
    double ConvertTo(LENGTH_TYPE type) const;

 private:
    double length_cm_;  // Длина в сантиметрах
    double GetConvertCoef(LENGTH_TYPE type) const;

    static constexpr const double micrometre_to_cm_ = 0.0001;
    static constexpr const double millimetre_to_cm_ = 0.1;
    static constexpr const double centimetre_to_cm_ = 1.0;
    static constexpr const double decimetre_to_cm_ = 10.0;
    static constexpr const double metre_to_cm_ = 100.0;
    static constexpr const double kilometre_to_cm_ = 100000.0;
    static constexpr const double inch_to_cm_ = 2.54;
    static constexpr const double hand_to_cm_ = 10.16;
    static constexpr const double link_to_cm_ = 20.1168;
    static constexpr const double foot_to_cm_ = 30.48;
    static constexpr const double yard_to_cm_ = 91.44;
    static constexpr const double rod_to_cm_ = 502.92;
    static constexpr const double chain_to_cm_ = 2011.68;
    static constexpr const double furhlong_to_cm_ = 20116.8;
    static constexpr const double mile_to_cm_ = 160934.4;
    static constexpr const double league_to_cm_ = 482803.2;
};

#endif  // MODULES_LENGTH_CONVERTER_INCLUDE_LENGTH_CONVERTER_H_
