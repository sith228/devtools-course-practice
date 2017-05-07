// Copyright 2017 Kildishev Maxim

#ifndef MODULES_DICHOTOMY_METHOD_INCLUDE_DICHOTOMY_H_
#define MODULES_DICHOTOMY_METHOD_INCLUDE_DICHOTOMY_H_

//За унимодальную функцию примем y = a_factor*(x+b_factor)^2 + c_factor
class Dichotomy{
 public:
   double FindMin(int a_factor, int b_factor, int c_factor,
       double left_border, double right_border, double eps);
 private:
    void EnteredCorrectly(int a_factor, double left_border,
         double right_border, double eps);
};

#endif  // MODULES_DICHOTOMY_METHOD_INCLUDE_DICHOTOMY_H_
