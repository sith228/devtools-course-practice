// Copyright 2017 Simonyan Vaginak

#ifndef MODULES_CREDIT_CALCULATOR_INCLUDE_CREDIT_CALCULATOR_H_
#define MODULES_CREDIT_CALCULATOR_INCLUDE_CREDIT_CALCULATOR_H_

#include <math.h>

class CreditCalculator {
public:
  CreditCalculator();
  bool check_data(int amount, int period, double interest);
  bool check_data(int amount, int period, double interest, int month_pas);
  double overpayment_amount(int amount, int period, double interest);
  double monthly_payment(int amount, int period, double interest);
  double total_payout(int amount, int period, double interest);
  double check_balance(int amount, int period, double interest, int month_pas);
};

#endif  // MODULES_CREDIT_CALCULATOR_INCLUDE_CREDIT_CALCULATOR_H_
