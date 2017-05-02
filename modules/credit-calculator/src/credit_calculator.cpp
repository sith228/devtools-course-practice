// Copyright 2017 Simonyan Vaginak

#include "include/credit_calculator.h"


CreditCalculator::CreditCalculator() {}

bool CreditCalculator::check_data(int amount, int period,
    double interest, int month_pas) {
    if (amount > 0 && period > 0 && period <= 60 && interest > 0 &&
        interest < 100 && month_pas >= 0 && month_pas <= period)
        return true;
    else
        return false;
}

bool CreditCalculator::check_data(int amount, int period,
    double interest) {
    if (amount > 0 && period > 0 && period <= 60 && 
        interest > 0 && interest < 100)
        return true;
    else
        return false;
}

double CreditCalculator::monthly_payment(int amount, int period,
    double interest) {
    if (!check_data(amount, period, interest))
        return -1;
    double month_pay;
    double month_inter = interest / 100 / 12;
    month_pay = amount*(month_inter / (1 - pow(1 + month_inter, -period)));
    return month_pay;
}

double CreditCalculator::total_payout(int amount, int period,
    double interest) {
    if (!check_data(amount, period, interest))
        return -1;
    CreditCalculator tmp;
    return tmp.monthly_payment(amount, period, interest)*period;
}

double CreditCalculator::overpayment_amount(int amount, int period,
    double interest) {
    if (!check_data(amount, period, interest))
        return -1;
    CreditCalculator tmp;
    return tmp.total_payout(amount, period, interest) - amount;
}

double CreditCalculator::check_balance(int amount, int period,
    double interest, int month_pas) {
    if (!check_data(amount, period, interest, month_pas))
        return -1;
    CreditCalculator tmp;
    double paid_out;
    paid_out = tmp.monthly_payment(amount, period, interest)*month_pas;
    return tmp.total_payout(amount, period, interest) - paid_out;
}
