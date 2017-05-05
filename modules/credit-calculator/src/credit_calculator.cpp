// Copyright 2017 Simonyan Vaginak

#include "include/credit_calculator.h"
#include <math.h>
#include <stdexcept>

CreditCalculator::CreditCalculator() {}

bool CreditCalculator::check_data(int amount, int period,
    double interest, unsigned int month_pas) {
        return (amount > 0 && period > 0 && period <= 60 && interest > 0 &&
            interest < 100 && month_pas <= (unsigned)period);
}

bool CreditCalculator::check_data(int amount, int period,
    double interest) {
        return (amount > 0 && period > 0 && period <= 60 &&
            interest > 0 && interest < 100);
}

double CreditCalculator::monthly_payment(int amount, int period,
    double interest) {
    if (!check_data(amount, period, interest))
        throw std::runtime_error("The entered data is incorrect");
    double month_inter = interest / 100 / 12;
    if(!(1 - pow(1 + month_inter, -period)))
        throw std::runtime_error("You have entered an interest rate too low");
    return (amount*(month_inter / (1 - pow(1 + month_inter, -period))));
}

double CreditCalculator::total_payout(int amount, int period,
    double interest) {
    if (!check_data(amount, period, interest))
        throw std::runtime_error("The entered data is incorrect");
    return monthly_payment(amount, period, interest)*period;
}

double CreditCalculator::overpayment_amount(int amount, int period,
    double interest) {
    if (!check_data(amount, period, interest))
        throw std::runtime_error("The entered data is incorrect");
    return total_payout(amount, period, interest) - amount;
}

double CreditCalculator::check_balance(int amount, int period,
    double interest, int month_pas) {
    if (!check_data(amount, period, interest, month_pas))
        throw std::runtime_error("The entered data is incorrect");
    double paid_out;
    paid_out = monthly_payment(amount, period, interest)*month_pas;
    return total_payout(amount, period, interest) - paid_out;
}
