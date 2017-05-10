// Copyright 2017 Zhorin Sergey

#ifndef MODULES_ZHORIN_SERGEY_TEMPERATURE_CONVERTER_INCLUDE_TEMPERATURE_CONVERTER_H_
#define MODULES_ZHORIN_SERGEY_TEMPERATURE_CONVERTER_INCLUDE_TEMPERATURE_CONVERTER_H_

class TemperatureConverter {
 public:
    TemperatureConverter();

    double CelsiusToFahrenheit(const double t);
    double CelsiusToNewton(const double t);
    double CelsiusToKelvin(const double t);
    double FahrenheitToCelsius(const double t);
    double FahrenheitToNewton(const double t);
    double FahrenheitToKelvin(const double t);
    double NewtonToFahrenheit(const double t);
    double NewtonToCelsius(const double t);
    double NewtonToKelvin(const double t);
    double KelvinToFahrenheit(const double t);
    double KelvinToNewton(const double t);
    double KelvinToCelsius(const double t);
};

#endif  // MODULES_ZHORIN_SERGEY_TEMPERATURE_CONVERTER_INCLUDE_TEMPERATURE_CONVERTER_H_
