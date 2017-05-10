// Copyright 2017 Bakalin Andrey

#include <gtest/gtest.h>

#include "include/mortgage_calculator.h"

TEST(Bakalin_Andrey_MortgageCalculator, throws_if_amount_less_than_zero) {
    // Arrange
    double amount = -1000.0;
    int period = 240;
    double interest = 10;

    // Act & Assert
    ASSERT_ANY_THROW(MortgageCalculator::mortgage_calculator(amount, 
        period, interest));
}

TEST(Bakalin_Andrey_MortgageCalculator, throws_if_amount_is_equal_to_zero) {
    // Arrange
    double amount = 0;
    int period = 240;
    double interest = 10;

    // Act & Assert
    ASSERT_ANY_THROW(MortgageCalculator::mortgage_calculator(amount,
        period, interest));
}

TEST(Bakalin_Andrey_MortgageCalculator,
    throws_if_period_less_than_zero) {
    // Arrange
    double amount = 1000000.0;
    int period = -240;
    double interest = 10;

    // Act & Assert
    ASSERT_ANY_THROW(MortgageCalculator::mortgage_calculator(amount,
        period, interest));
}

TEST(Bakalin_Andrey_MortgageCalculator,
    throws_if_period_is_equal_to_zero) {
    // Arrange
    double amount = 1000000.0;
    int period = 0;
    double interest = 10;

    // Act & Assert
    ASSERT_ANY_THROW(MortgageCalculator::mortgage_calculator(amount,
        period, interest));
}

TEST(Bakalin_Andrey_MortgageCalculator,
    throws_if_period_more_than_six_hundred) {
    // Arrange
    double amount = 1000000.0;
    int period = 601;
    double interest = 10;

    // Act & Assert
    ASSERT_ANY_THROW(MortgageCalculator::mortgage_calculator(amount,
        period, interest));
}

TEST(Bakalin_Andrey_MortgageCalculator, throws_if_interest_less_than_zero) {
    // Arrange
    double amount = -1000.0;
    int period = 240;
    double interest = -10;

    // Act & Assert
    ASSERT_ANY_THROW(MortgageCalculator::mortgage_calculator(amount,
        period, interest));
}

TEST(Bakalin_Andrey_MortgageCalculator, throws_if_interest_is_equal_to_zero) {
    // Arrange
    double amount = -1000.0;
    int period = 240;
    double interest = 0;

    // Act & Assert
    ASSERT_ANY_THROW(MortgageCalculator::mortgage_calculator(amount,
        period, interest));
}

TEST(Bakalin_Andrey_MortgageCalculator,
    throws_if_interest_more_than_one_hundred) {
    // Arrange
    double amount = -1000.0;
    int period = 240;
    double interest = 146;

    // Act & Assert
    ASSERT_ANY_THROW(MortgageCalculator::mortgage_calculator(amount,
        period, interest));
}

TEST(Bakalin_Andrey_MortgageCalculator,
    throws_if_interest_is_equal_to_one_hundred) {
    // Arrange
    double amount = -1000.0;
    int period = 240;
    double interest = 100;

    // Act & Assert
    ASSERT_ANY_THROW(MortgageCalculator::mortgage_calculator(amount,
        period, interest));
}

TEST(Bakalin_Andrey_MortgageCalculator, throws_if_interest_is_very_low) {
    // Arrange
    double amount = 1000000.0;
    int period = 240;
    double interest = 1e-20;

    // Act & Assert
    ASSERT_ANY_THROW(MortgageCalculator::mortgage_calculator(amount,
        period, interest));
}

TEST(Bakalin_Andrey_MortgageCalculator, can_get_monthly_payment) {
    // Arrange
    double amount = 3000000.0;
    int period = 240;
    double interest = 12;
    double right_mothly_payment = 33033.0;
    double error = 0.2;

    // Act
    calculator_result result = MortgageCalculator::mortgage_calculator(amount,
        period, interest);

    // Assert
    EXPECT_NEAR(right_mothly_payment, result.monthly_payment, error * period);
}

TEST(Bakalin_Andrey_MortgageCalculator, can_get_total_payout) {
    // Arrange
    double amount = 2500000.0;
    int period = 300;
    double interest = 11;
    double right_total_payout = 7350900.0;
    double error = 0.2;

    // Act
    calculator_result result = MortgageCalculator::mortgage_calculator(amount,
        period, interest);

    // Assert
    EXPECT_NEAR(right_total_payout, result.total_payout, error * period);
}

TEST(Bakalin_Andrey_MortgageCalculator, can_get_overpayment_amount) {
    // Arrange
    double amount = 4300000.0;
    int period = 120;
    double interest = 15;
    double right_overpayment_amount = 4024880.0;
    double error = 0.2;

    // Act
    calculator_result result = MortgageCalculator::mortgage_calculator(amount,
        period, interest);

    // Assert
    EXPECT_NEAR(right_overpayment_amount, result.overpayment_amount,
        error * period);
}
