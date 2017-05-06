// Copyright 2017 Simonyan Vaginak

#include <gtest/gtest.h>

#include "include/credit_calculator.h"

TEST(Simonyan_Vaginak_CreditCalculator, get_monthly_payment) {
    // Arrange
    int amount = 300000;
    int period = 12;
    double inter = 22;
    double result;
    double moth_pay = 28078;
    double month_error = 0.2;

    // Act
    result = CreditCalculator::monthly_payment(amount, period, inter);

    // Assert
    EXPECT_NEAR(moth_pay, result, period*month_error);
}

TEST(Simonyan_Vaginak_CreditCalculator,
    get_month_payment_with_incorrect_param) {
    // Arrange
    int amount = -300000;
    int period = 12;
    double inter = 150;

    // Act+Assert
    ASSERT_ANY_THROW(CreditCalculator::monthly_payment(amount, period, inter));
}

TEST(Simonyan_Vaginak_CreditCalculator,
    get_month_payment_with_low_inter) {
    // Arrange
    int amount = 300000;
    int period = 12;
    double inter = 1e-15;

    // Act+Assert
    ASSERT_ANY_THROW(CreditCalculator::monthly_payment(amount, period, inter));
}

TEST(Simonyan_Vaginak_CreditCalculator, get_total_payout) {
    // Arrange
    int amount = 300000;
    int period = 12;
    double inter = 22;
    double result;
    double payout = 336940;
    double month_error = 0.2;

    // Act
    result = CreditCalculator::total_payout(amount, period, inter);

    // Assert
    EXPECT_NEAR(payout, result, period*month_error);
}

TEST(Simonyan_Vaginak_CreditCalculator,
    get_total_payout_with_incorrect_parameters) {
    // Arrange
    int amount = 300000;
    int period = -12;
    double inter = 22;

    // Act+Assert
    ASSERT_ANY_THROW(CreditCalculator::total_payout(amount, period, inter));
}

TEST(Simonyan_Vaginak_CreditCalculator, get_overpayment_amount) {
    // Arrange
    int amount = 300000;
    int period = 12;
    double inter = 22;
    double result;
    double overpay = 36940;
    double month_error = 0.2;

    // Act
    result = CreditCalculator::overpayment_amount(amount, period, inter);

    // Assert
    EXPECT_NEAR(overpay, result, period*month_error);
}

TEST(Simonyan_Vaginak_CreditCalculator,
    get_overpayment_amount_with_incorrect_parameters) {
    // Arrange
    int amount = 300000;
    int period = -12;
    double inter = 22;

    // Act+Assert
    ASSERT_ANY_THROW(CreditCalculator::overpayment_amount(amount,
        period, inter));
}

TEST(Simonyan_Vaginak_CreditCalculator, check_balance) {
    // Arrange
    int amount = 300000;
    int period = 12;
    int month_pas = 5;
    double inter = 22;
    double result;
    double balance = 196550;
    double month_error = 0.2;

    // Act
    result = CreditCalculator::check_balance(amount, period, inter, month_pas);

    // Assert
    EXPECT_NEAR(balance, result, period*month_error);
}

TEST(Simonyan_Vaginak_CreditCalculator,
    check_balance_with_incorrect_parameters) {
    // Arrange
    int amount = 300000;
    int period = 12;
    int month_pas = 15;
    double inter = 22;

    // Act+Assert
    ASSERT_ANY_THROW(CreditCalculator::check_balance(amount, period,
        inter, month_pas));
}
