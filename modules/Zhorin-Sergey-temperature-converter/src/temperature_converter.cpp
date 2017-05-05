// Copyright 2017 Zhorin Sergey

#include "include/temperature_converter.h"

#include <string>

TemperatureConverter::TemperatureConverter() {}

double TemperatureConverter::CelsiusToFahrenheit(const double t) {
    if (t < -273.15) {
        throw std::string("Temperature can't be less than absolute zero");
    }
    return(32 + t*(9.0 / 5.0));
}

double TemperatureConverter::CelsiusToKelvin(const double t) {
    if (t < -273.15) {
        throw std::string("Temperature can't be less than absolute zero");
    }
    return(273.15 + t);
}

double TemperatureConverter::CelsiusToNewton(const double t){
    if (t < -273.15) {
        throw std::string("Temperature can't be less than absolute zero");
    }
    return(t*(33.0 / 100.0));
}
