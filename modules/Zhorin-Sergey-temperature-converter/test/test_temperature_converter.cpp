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

    // Act & Assert
    EXPECT_THROW(p.CelsiusToNewton(Celsius), std::string);
}

TEST(TemperatureConverterTest,
    Cant_Convert_To_Fahrenheit_Temeprature_Less_Than_Absolute_Zero) {
    // Arrange
    double Celsius = -274;
    TemperatureConverter p;

    // Act & Assert
    EXPECT_THROW(p.CelsiusToFahrenheit(Celsius), std::string);
}

TEST(TemperatureConverterTest,
    Cant_Convert_To_Kelvin_Temeprature_Less_Than_Absolute_Zero) {
    // Arrange
    double Celsius = -274;
    TemperatureConverter p;

    // Act & Assert
    EXPECT_THROW(p.CelsiusToKelvin(Celsius), std::string);
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

TEST(TemperatureConverterTest, Can_Convert_Kelvin_To_Newton) {
    // Arrange
    double Kelvin = 26.0;
    TemperatureConverter p;

    // Act
    double Newton = p.KelvinToNewton(Kelvin);

    // Assert
    double expectedNewton = (26.0 - 273.15)*(33.0 / 100.0);
    EXPECT_EQ(Newton, expectedNewton);
}
TEST(TemperatureConverterTest, Can_Convert_Kelvin_To_Celsius) {
    // Arrange
    double Kelvin = 26.0;
    TemperatureConverter p;

    // Act
    double Celsius = p.KelvinToCelsius(Kelvin);

    // Assert
    double expectedCelsius = 26.0 - 273.15;
    EXPECT_EQ(Celsius, expectedCelsius);
}
TEST(TemperatureConverterTest, Can_Convert_Kelvin_To_Fahrenheit) {
    // Arrange
    double Kelvin = 26.0;
    TemperatureConverter p;

    // Act
    double Fahrenheit = p.KelvinToFahrenheit(Kelvin);

    // Assert
    double expectedFahrenheit = 32.0 + (26.0 - 273.15)*(9.0 / 5.0);
    EXPECT_EQ(Fahrenheit, expectedFahrenheit);
}
TEST(TemperatureConverterTest, Can_Convert_Newton_To_Kelvin) {
    // Arrange
    double Newton = 26.0;
    TemperatureConverter p;

    // Act
    double Kelvin = p.NewtonToKelvin(Newton);

    // Assert
    double expectedKelvin = 26.0*(100.0 / 33.0) + 273.15;
    EXPECT_EQ(Kelvin, expectedKelvin);
}
TEST(TemperatureConverterTest, Can_Convert_Newton_To_Celsius) {
    // Arrange
    double Newton = 26.0;
    TemperatureConverter p;

    // Act
    double Celsius = p.NewtonToCelsius(Newton);

    // Assert
    double expectedCelsius = 26.0*(100.0 / 33.0);
    EXPECT_EQ(Celsius, expectedCelsius);
}
TEST(TemperatureConverterTest, Can_Convert_Newton_To_Fahrenheit) {
    // Arrange
    double Newton = 26.0;
    TemperatureConverter p;

    // Act
    double Fahrenheit = p.NewtonToFahrenheit(Newton);

    // Assert
    double expectedFahrenheit = 26.0*(100.0 / 33.0)*(9.0 / 5.0) + 32.0;
    EXPECT_EQ(Fahrenheit, expectedFahrenheit);
}
TEST(TemperatureConverterTest, Can_Convert_Fahrenheit_To_Kelvin) {
    // Arrange
    double Fahrenheit = 26.0;
    TemperatureConverter p;

    // Act
    double Kelvin = p.FahrenheitToKelvin(Fahrenheit);

    // Assert
    double expectedKelvin = (5.0 / 9.0)*(26.0 - 32.0) + 273.15;
    EXPECT_EQ(Kelvin, expectedKelvin);
}
TEST(TemperatureConverterTest, Can_Convert_Fahrenheit_To_Newton) {
    // Arrange
    double Fahrenheit = 26.0;
    TemperatureConverter p;

    // Act
    double Newton = p.FahrenheitToNewton(Fahrenheit);

    // Assert
    double expectedNewton = (5.0 / 9.0)*(26.0 - 32.0)*(33.0 / 100.0);
    EXPECT_EQ(Newton, expectedNewton);
}
TEST(TemperatureConverterTest, Can_Convert_Fahrenheit_To_Celsius) {
    // Arrange
    double Fahrenheit = 26.0;
    TemperatureConverter p;

    // Act
    double Celsius = p.FahrenheitToCelsius(Fahrenheit);

    // Assert
    double expectedCelsius = (5.0 / 9.0)*(26.0 - 32.0);
    EXPECT_EQ(Celsius, expectedCelsius);
}
