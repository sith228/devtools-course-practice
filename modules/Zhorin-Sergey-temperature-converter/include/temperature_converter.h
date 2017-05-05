// Copyright 2017 Zhorin Sergey

#ifndef MODULES_ZHORIN_SERGEY_TEMPERATURE_CONVERTER_INCLUDE_TEMPERATURE_CONVERTER_H_
#define MODULES_ZHORIN_SERGEY_TEMPERATURE_CONVERTER_INCLUDE_TEMPERATURE_CONVERTER_H_

class TemperatureConverter {
 public:
    TemperatureConverter();

    void CelsiusToFahrenheit(const double t, double* F);
    void CelsiusToNewton(const double t, double* N);
    void CelsiusToKelvin(const double t, double* K);
};

#endif  // MODULES_ZHORIN_SERGEY_TEMPERATURE_CONVERTER_INCLUDE_TEMPERATURE_CONVERTER_H_
