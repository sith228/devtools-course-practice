// Copyright 2017 Dmitry Dryakhlov

#include <math.h>
#include <stdexcept>
#include "include/Newton_method.h"

double NewtonMethod::newton_method_polinom(double eps, int size,
                                           double *polinom_coef) {
    if (size <= 0)
        throw "size < 0";
    double x = 0, x1 = 1;
    double *polinom_derivative_coef = new double[size - 1];
    calculate_derivative_polinom(size - 1, polinom_coef,
                                        polinom_derivative_coef);
    while (fabs(x1 - x) >= eps) {
        x = x1;
        double fx = polinom_value(size, x, polinom_coef);
        double fx1 = polinom_value(size - 1, x, polinom_derivative_coef);
        x1 = x - (fx / fx1);
    }

    delete[]polinom_derivative_coef;
    return x;
}

double NewtonMethod::newton_method_function(double eps) {
    double x = 0.0, x1 = 1.0;

    while (fabs(x1 - x) >= eps) {
       x = x1;
       double fx = function_value(x);
       double fx1 = first_derivative_finction_value(x);
        x1 = x - (fx / fx1);
    }
    return x;
}

void NewtonMethod::geneate_random_polinom(int size, double *polinom_coef) {
    if (size <= 0)
        throw "size < 0";
    for (int i = 0; i < size; i++) {
        polinom_coef[i] = static_cast<double>(i)*7.0;
    }
}

double NewtonMethod::polinom_value(int size, int x, const double * coef) {
    if (size <= 0)
        throw "size < 0";
    double sum = 0.0;
    for (int k = 0; k < size; k++) {
        sum = sum + (coef[k] * pow(x, k));
    }
    return sum;
}

void NewtonMethod::calculate_derivative_polinom(int size,
     const double * polinom_coef, double * polinom_derivative_coef) {
    if (size <= 0)
        throw "size < 0";
    for (int i = 0; i < size; i++) {
        polinom_derivative_coef[i] = (i + 1) * polinom_coef[i + 1];
    }
}

double NewtonMethod::function_value(double x) {
    return 3.0*x + sin(x) - pow(2.71828, x);
}

double NewtonMethod::first_derivative_finction_value(double x) {
    return 3.0 - cos(x) - pow(2.71828, x);
}
