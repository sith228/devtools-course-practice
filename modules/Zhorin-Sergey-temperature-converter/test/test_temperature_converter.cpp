// Copyright 2017 Zhorin Sergey

#include <gtest/gtest.h>

#include <string>

#include "include/temperature_converter.h"

TEST(TemperatureConverterTest, Can_Create_Converter_And_Get_Fahrenheit) {
    // Arrange
    double temperature = 26.0;

    // Act
    TemperatureConverter p(temperature);

    // Assert
    double expectedFahrenheit = 32.0 + 26*(9.0 / 5.0);
    EXPECT_EQ(p.getFahrenheit(), expectedFahrenheit);
}

TEST(TemperatureConverterTest,
    Cant_Create_Converter_With_Temeprature_Less_Than_Absolute_Zero) {
    // Arrange
    double temperature = -274;

    // Act & Assert
    EXPECT_THROW(TemperatureConverter p(temperature), std::string);
}

TEST(TemperatureConverterTest, Can_Create_Converter_And_Get_Newton) {
    // Arrange
    double temperature = 26.0;

    // Act
    TemperatureConverter p(temperature);

    // Assert
    double expectedNewton = 26.0*(33.0 / 100.0);
    EXPECT_EQ(p.getNewton(), expectedNewton);
}

TEST(TemperatureConverterTest, Can_Create_Converter_And_Get_Kelvin) {
    // Arrange
    double temperature = 26.0;

    // Act
    TemperatureConverter p(temperature);

    // Assert
    double expectedKelvin = 273.15 + 26.0;
    EXPECT_EQ(p.getKelvin(), expectedKelvin);
}

TEST(TemperatureConverterTest, Can_Create_Converter_And_Get_Celsius) {
    // Arrange
    double temperature = 26.0;

    // Act
    TemperatureConverter p(temperature);

    // Assert
    double expectedCelsius = 26.0;
    EXPECT_EQ(p.getCelsius(), expectedCelsius);
}

TEST(TemperatureConverterTest, Can_Create_Default_Converter_And_Get_Kelvin) {
    // Act
    TemperatureConverter p;

    // Assert
    double expectedKelvin = 273.15;
    EXPECT_EQ(p.getKelvin(), expectedKelvin);
}

TEST(TemperatureConverterTest, Can_Set_Temperature_And_Get_Newton) {
    // Arrange
    double temperature = 26.0;
    TemperatureConverter p;

    // Act
    p.setTemperature(temperature);

    // Assert
    double expectedNewton = 26.0*(33.0 / 100.0);
    EXPECT_EQ(p.getNewton(), expectedNewton);
}
