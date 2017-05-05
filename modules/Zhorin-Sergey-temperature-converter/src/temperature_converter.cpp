// Copyright 2017 Zhorin Sergey

#include "include/temperature_converter.h"

#include <string>

TemperatureConverter::TemperatureConverter() {}

void TemperatureConverter::CelsiusToFahrenheit(const double t, double* F) {
    if (t < -273.15) {
        throw std::string("Temperature can't be less than absolute zero");
    }
    *F = 32 + t*(9.0 / 5.0);
}

void TemperatureConverter::CelsiusToKelvin(const double t, double* K) {
    if (t < -273.15) {
        throw std::string("Temperature can't be less than absolute zero");
    }
    *K = 273.15 + t;
}

void TemperatureConverter::CelsiusToNewton(const double t, double* N) {
    if (t < -273.15) {
        throw std::string("Temperature can't be less than absolute zero");
    }
     *N = t*(33.0 / 100.0);
}
