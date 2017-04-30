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
    double ConvertTo(LENGTH_TYPE type) const;

 private:
    double length_sm;  // Длина в сантиметрах
    double GetConvertCoef(LENGTH_TYPE type) const;
};

#endif  // MODULES_LENGTH_CONVERTER_INCLUDE_LENGTH_CONVERTER_H_
