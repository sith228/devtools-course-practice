// Copyright 2017 Simonyan Vaginak

#ifndef MODULES_CREDIT_CALCULATOR_INCLUDE_CREDIT_CALCULATOR_H_
#define MODULES_CREDIT_CALCULATOR_INCLUDE_CREDIT_CALCULATOR_H_

class CreditCalculator {
 public:
  CreditCalculator();
  static double overpayment_amount(int amount, int period, double interest);
  static double monthly_payment(int amount, int period, double interest);
  static double total_payout(int amount, int period, double interest);
  static double check_balance(int amount, int period, double interest, int month_pas);

 private:
  static bool check_data(int amount, int period, double interest);
  static bool check_data(int amount, int period, double interest, unsigned int month_pas);
};

#endif  // MODULES_CREDIT_CALCULATOR_INCLUDE_CREDIT_CALCULATOR_H_
