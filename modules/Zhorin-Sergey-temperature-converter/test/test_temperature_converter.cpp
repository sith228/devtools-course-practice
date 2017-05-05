// Copyright 2017 Zhorin Sergey

#include <gtest/gtest.h>

#include <string>

#include "include/temperature_converter.h"

TEST(TemperatureConverterTest, Can_Convert_Celsius_To_Fahrenheit) {
    // Arrange
    double Celsius = 26.0;
    TemperatureConverter p;

    // Act
    double Fahrenheit = p.CelsiusToFahrenheit(Celsius);

    // Assert
    double expectedFahrenheit = 32.0 + 26*(9.0 / 5.0);
    EXPECT_EQ(Fahrenheit, expectedFahrenheit);
}

TEST(TemperatureConverterTest,
    Cant_Convert_To_Newton_Temeprature_Less_Than_Absolute_Zero) {
    // Arrange
    double Celsius = -274;
    TemperatureConverter p;
    double Newton = 0;

    // Act & Assert
    EXPECT_THROW(Newton = p.CelsiusToNewton(Celsius), std::string);
}

TEST(TemperatureConverterTest,
    Cant_Convert_To_Fahrenheit_Temeprature_Less_Than_Absolute_Zero) {
    // Arrange
    double Celsius = -274;
    TemperatureConverter p;
    double Fahrenheit = 0;

    // Act & Assert
    EXPECT_THROW(Fahrenheit = p.CelsiusToFahrenheit(Celsius), std::string);
}

TEST(TemperatureConverterTest,
    Cant_Convert_To_Kelvin_Temeprature_Less_Than_Absolute_Zero) {
    // Arrange
    double Celsius = -274;
    double Kelvin = 0;
    TemperatureConverter p;

    // Act & Assert
    EXPECT_THROW(Kelvin = p.CelsiusToKelvin(Celsius), std::string);
}

TEST(TemperatureConverterTest, Can_Convert_Celsius_To_Newton) {
    // Arrange
    double Celsius = 26.0;
    TemperatureConverter p;

    // Act
    double Newton = p.CelsiusToNewton(Celsius);

    // Assert
    double expectedNewton = 26.0*(33.0 / 100.0);
    EXPECT_EQ(Newton, expectedNewton);
}

TEST(TemperatureConverterTest, Can_Convert_Celsius_To_Kelvin) {
    // Arrange
    double Celsius = 26.0;
    TemperatureConverter p;

    // Act
    double Kelvin = p.CelsiusToKelvin(Celsius);

    // Assert
    double expectedKelvin = 273.15 + 26.0;
    EXPECT_EQ(Kelvin, expectedKelvin);
}
