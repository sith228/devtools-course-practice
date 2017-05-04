// Copyright 2017 Zhorin Sergey

#include "include/temperature_converter.h"

#include <string>

TemperatureConverter::TemperatureConverter() {
    Celsius = 0;
    Kelvin = 273.15;
    Newton = 0;
    Fahrenheit = 32;
}

TemperatureConverter::TemperatureConverter(const double t) {
    setTemperature(t);
}

double TemperatureConverter::getFahrenheit() const {
    return Fahrenheit;
}

double TemperatureConverter::getKelvin() const {
    return Kelvin;
}

double TemperatureConverter::getNewton() const {
    return Newton;
}

double TemperatureConverter::getCelsius() const {
    return Celsius;
}
void TemperatureConverter::setTemperature(const double t) {
    if (t < -273.15) {
        throw std::string("Temperature can't be less than absolute zero");
    }
    Celsius = t;
    Kelvin = 273.15 + t;
    Newton = t*(33.0/100.0);
    Fahrenheit = 32 + t*(9.0/5.0);
}
