// Copyright 2017 Bakalin Andrey

#ifndef MODULES_MORTGAGE_CALCULATOR_INCLUDE_MORTGAGE_CALCULATOR_H_
#define MODULES_MORTGAGE_CALCULATOR_INCLUDE_MORTGAGE_CALCULATOR_H_

struct calculator_result {
    double monthly_payment;
    double overpayment_amount;
    double total_payout;
};

class MortgageCalculator {
 public:
     static calculator_result mortgage_calculator(double amount,
         int period, double interest);
};

#endif  // MODULES_MORTGAGE_CALCULATOR_INCLUDE_MORTGAGE_CALCULATOR_H_
