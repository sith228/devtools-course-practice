// Copyright 2017 Zhorin Sergey

#ifndef MODULES_ZHORIN_SERGEY_TEMPERATURE_CONVERTER_INCLUDE_TEMPERATURE_CONVERTER_H_
#define MODULES_ZHORIN_SERGEY_TEMPERATURE_CONVERTER_INCLUDE_TEMPERATURE_CONVERTER_H_

class TemperatureConverter {
 public:
    TemperatureConverter();
    TemperatureConverter(const double t);

    void setTemperature(const double t);
    double getFahrenheit() const;
    double getNewton() const;
    double getKelvin() const;
    double getCelsius() const;

 private:
    double Fahrenheit;
    double Newton;
    double Kelvin;
    double Celsius;
};

#endif  // MODULES_ZHORIN_SERGEY_TEMPERATURE_CONVERTER_INCLUDE_TEMPERATURE_CONVERTER_H_
