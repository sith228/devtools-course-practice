// Copyright 2017 Simonyan Vaginak

#include "include/credit_calculator.h"
#include <math.h>

CreditCalculator::CreditCalculator() {}

bool CreditCalculator::check_data(int amount, int period,
    double interest, int month_pas) {
        return (amount > 0 && period > 0 && period <= 60 && interest > 0 &&
            interest < 100 && month_pas >= 0 && month_pas <= period);
}

bool CreditCalculator::check_data(int amount, int period,
    double interest) {
        return (amount > 0 && period > 0 && period <= 60 &&
            interest > 0 && interest < 100);
}

double CreditCalculator::monthly_payment(int amount, int period,
    double interest) {
    if (!check_data(amount, period, interest))
        return -1;
    double month_inter = interest / 100 / 12;
    return (amount*(month_inter / (1 - pow(1 + month_inter, -period))));
}

double CreditCalculator::total_payout(int amount, int period,
    double interest) {
    if (!check_data(amount, period, interest))
        return -1;
    CreditCalculator creditCalc;
    return creditCalc.monthly_payment(amount, period, interest)*period;
}

double CreditCalculator::overpayment_amount(int amount, int period,
    double interest) {
    if (!check_data(amount, period, interest))
        return -1;
    CreditCalculator creditCalc;
    return creditCalc.total_payout(amount, period, interest) - amount;
}

double CreditCalculator::check_balance(int amount, int period,
    double interest, int month_pas) {
    if (!check_data(amount, period, interest, month_pas))
        return -1;
    CreditCalculator creditCalc;
    double paid_out;
    paid_out = creditCalc.monthly_payment(amount, period, interest)*month_pas;
    return creditCalc.total_payout(amount, period, interest) - paid_out;
}
