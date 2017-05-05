// Copyright 2017 Zhorin Sergey

#ifndef MODULES_ZHORIN_SERGEY_TEMPERATURE_CONVERTER_INCLUDE_TEMPERATURE_CONVERTER_H_
#define MODULES_ZHORIN_SERGEY_TEMPERATURE_CONVERTER_INCLUDE_TEMPERATURE_CONVERTER_H_

class TemperatureConverter {
 public:
    TemperatureConverter();

    double CelsiusToFahrenheit(const double t);
    double CelsiusToNewton(const double t);
    double CelsiusToKelvin(const double t);
};

#endif  // MODULES_ZHORIN_SERGEY_TEMPERATURE_CONVERTER_INCLUDE_TEMPERATURE_CONVERTER_H_
