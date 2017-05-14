// Copyright 2017 Buldakov Vladislav

#include <gtest/gtest.h>

#include "include/weight_converter.h"

const double EPS = 0.00001;

TEST(WeightConverterTest, Can_create_with_default_constructor) {
    // Arrange
    // Act
    // Assert
    ASSERT_NO_THROW(WeightConverter wc);
}

TEST(WeightConverterTest, Can_create_with_data) {
    // Arrange
    // Act
    // Assert
    ASSERT_NO_THROW(WeightConverter wc(1.0, G));
}

TEST(WeightConverterTest, Can_get_weight) {
    // Arrange
    double weight = 1.0;
    double weight_kg = 0.001;
    WeightConverter wc(weight, G);
    // Act
    // Assert
    ASSERT_NEAR(weight_kg, wc.getWeight(), EPS);
}

TEST(WeightConverterTest, Can_set_weight) {
    // Arrange
    double weight = 1.0;
    double weight_kg = 0.001;
    WeightConverter wc;
    // Act
    wc.setWeight(weight, G);
    // Assert
    ASSERT_NEAR(weight_kg, wc.getWeight(), EPS);
}

TEST(WeightConverterTest, Can_convert_inner_value) {
    // Arrange
    double weight = 1.0;
    double weight_kg = 0.001;
    WeightConverter wc(weight_kg, KG);
    // Act
    double converted_weight = wc.Convert(G);
    // Assert
    ASSERT_NEAR(weight, converted_weight, EPS);
}

TEST(WeightConverterTest, Can_convert_outer_value) {
    // Arrange
    WeightConverter wc;
    double actual_weight = 0.625;
    // Act
    double converted_weight = wc.Convert(10, OZ, LB);
    // Assert
    ASSERT_NEAR(actual_weight, converted_weight, EPS);
}















