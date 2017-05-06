// Copyright 2017 Simonyan Vaginak

#include "include/credit_calculator.h"
#include <math.h>
#include <stdexcept>


bool CreditCalculator::check_data(int amount, int period,
    double interest, int month_pas) {
    check_data(amount, period, interest);
    if (month_pas > period) {
        throw std::runtime_error("Entered month_pas is incorrect");
    }
}

bool CreditCalculator::check_data(int amount, int period,
    double interest) {
    if (amount <= 0) {
        throw std::runtime_error("Entered amount is incorrect");
    }
    if (period <= 0 || period > 60) {
        throw std::runtime_error("Entered period is incorrect");
    }
    if (interest <= 0 || interest > 100) {
        throw std::runtime_error("Entered interest is incorrect");
    }
}

double CreditCalculator::monthly_payment(int amount, int period,
    double interest) {
    check_data(amount, period, interest);
    double month_inter = interest / 100 / 12;
    double denominator = (1 - pow(1 + month_inter, -period));
    if (denominator == 0.0) {
        throw std::runtime_error("You have entered an interest rate too low");
    }
    return (amount*(month_inter / denominator));
}

double CreditCalculator::total_payout(int amount, int period,
    double interest) {
    check_data(amount, period, interest);
    return monthly_payment(amount, period, interest)*period;
}

double CreditCalculator::overpayment_amount(int amount, int period,
    double interest) {
    check_data(amount, period, interest);
    return total_payout(amount, period, interest) - amount;
}

double CreditCalculator::check_balance(int amount, int period,
    double interest, int month_pas) {
    check_data(amount, period, interest, month_pas);
    double paid_out = monthly_payment(amount, period, interest)*month_pas;
    return total_payout(amount, period, interest) - paid_out;
}
