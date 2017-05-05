// Copyright 2017 Simonyan Vaginak

#include <gtest/gtest.h>

#include "include/credit_calculator.h"

TEST(Simonyan_Vaginak_CreditCalculator, get_monthly_payment) {
    // Arrange
    int amount = 300000;
    int period = 12;
    double interest = 22;
    double result;
    double moth_pay = 28078;
    double month_error = 0.2;

    // Act
    result = CreditCalculator::monthly_payment(amount, period, interest);

    // Assert
    EXPECT_NEAR(moth_pay, result, period*month_error);
}

TEST(Simonyan_Vaginak_CreditCalculator,
    get_month_payment_with_incorrect_param) {
    // Arrange
    int amount = -300000;
    int period = 12;
    double interest = 150;

    // Act+Assert
    ASSERT_ANY_THROW(CreditCalculator::monthly_payment(amount, period, interest));
}

TEST(Simonyan_Vaginak_CreditCalculator, get_total_payout) {
    // Arrange
    int amount = 300000;
    int period = 12;
    double interest = 22;
    double result;
    double payout = 336940;
    double month_error = 0.2;

    // Act
    result = CreditCalculator::total_payout(amount, period, interest);

    // Assert
    EXPECT_NEAR(payout, result, period*month_error);
}

TEST(Simonyan_Vaginak_CreditCalculator,
    get_total_payout_with_incorrect_parameters) {
    // Arrange
    int amount = 300000;
    int period = -12;
    double interest = 22;

    // Act+Assert
    ASSERT_ANY_THROW(CreditCalculator::total_payout(amount, period, interest));
}

TEST(Simonyan_Vaginak_CreditCalculator, get_overpayment_amount) {
    // Arrange
    int amount = 300000;
    int period = 12;
    double interest = 22;
    double result;
    double overpay = 36940;
    double month_error = 0.2;

    // Act
    result = CreditCalculator::overpayment_amount(amount, period, interest);

    // Assert
    EXPECT_NEAR(overpay, result, period*month_error);
}

TEST(Simonyan_Vaginak_CreditCalculator,
    get_overpayment_amount_with_incorrect_parameters) {
    // Arrange
    int amount = 300000;
    int period = -12;
    double interest = 22;

    // Act+Assert
    ASSERT_ANY_THROW(CreditCalculator::overpayment_amount(amount, period, interest));
}

TEST(Simonyan_Vaginak_CreditCalculator, check_balance) {
    // Arrange
    int amount = 300000;
    int period = 12;
    int month_passed = 5;
    double interest = 22;
    double result;
    double balance = 196550;
    double month_error = 0.2;

    // Act
    result = CreditCalculator::check_balance(amount, period, interest, month_passed);

    // Assert
    EXPECT_NEAR(balance, result, period*month_error);
}

TEST(Simonyan_Vaginak_CreditCalculator,
    check_balance_with_incorrect_parameters) {
    // Arrange
    int amount = -300000;
    int period = 12;
    int month_passed = 5;
    double interest = 22;

    // Act+Assert
    ASSERT_ANY_THROW(CreditCalculator::check_balance(amount, period, interest, month_passed));
}
