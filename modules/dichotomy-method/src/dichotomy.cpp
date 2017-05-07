// Copyright Kildishev Maxim 2017

#include <include/dichotomy.h>
#include <cmath>
#include <iostream>

void Dichotomy::EnteredCorrectly(int a_factor, double left_border,
     double right_border, double eps) {
         if (right_border < left_border)
             throw "Incorrect borders";
         if (std::abs(right_border-left_border) < 0.0001)
             throw "Too close values";
         if (a_factor == 0)
             throw "Function is not unimodal";
         if (eps <=0)
             throw "Eps must be higher then zero";
}

double Dichotomy::FindMin(int a_factor, int b_factor, int c_factor,
     double left_border, double right_border, double eps) {
    EnteredCorrectly(a_factor, left_border, right_border, eps);
    double middle = (left_border + right_border)/2;
    double func_value_middle = a_factor*(middle+b_factor)
    *(middle+b_factor) + c_factor;
    while (right_border - left_border > eps) {
        double x = (left_border + middle)/2;
        double func_value_x = a_factor*(x+b_factor)*(x+b_factor) + c_factor;
        double y = (middle + right_border)/2;
        double func_value_y = a_factor*(y+b_factor)*(y+b_factor) + c_factor;
        if ((func_value_x < func_value_y) && (func_value_x < func_value_middle)) {
                right_border = middle;
                middle = x;
                func_value_middle = func_value_x;
            } else if ( (func_value_middle < func_value_x)
            && (func_value_middle < func_value_y) ) {
                left_border = x;
                right_border = y;
            } else {
                left_border = middle;
                middle = y;
                func_value_middle = func_value_y;
            }
        //Поскольку метод дихотомии должен вернуть отрезок, на котором
        //должен находиться минимум, возьмём за оценку решения его середину
    }
    return (left_border + right_border) / 2;
}
