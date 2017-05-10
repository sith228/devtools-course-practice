// Copyright 2017 Bakalin Andrey

#include "include/mortgage_calculator.h"
#include <stdexcept>
#include <cmath>

calculator_result MortgageCalculator::mortgage_calculator(double amount,
    int period, double interest) {
    if (amount <= 0) {
        throw std::invalid_argument("Amount was entered incorrectly");
    }
    if (period <= 0 || period > 600) {
        throw std::invalid_argument("Period was entered incorrectly");
    }
    if (interest <= 0 || interest >= 100) {
        throw std::invalid_argument("Interest was entered incorrectly");
    }
    if ((1 - pow(1 + interest, -period)) == 0) {
        throw std::invalid_argument("Interest can't be so low");
    }

    calculator_result result;
    double month_interest = interest / (100 * 12);

    result.monthly_payment = amount * month_interest /
        (1 - pow(1 + month_interest, -period));
    result.total_payout = (result.monthly_payment * period);
    result.overpayment_amount = result.total_payout - amount;

    return result;
}
