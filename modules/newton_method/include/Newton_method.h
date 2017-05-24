// Copyright 2017 Dryakhlov Dmitry

#ifndef MODULES_NEWTON_METHOD_INCLUDE_NEWTON_METHOD_H_
#define MODULES_NEWTON_METHOD_INCLUDE_NEWTON_METHOD_H_

class NewtonMethod {
 public:
    static double newton_method_polinom(double eps, int size,
                                                    double *polinom_coef);
    static double newton_method_function(double eps);
    static void geneate_random_polinom(int size, double *polinom_coef);

 private:
    static void calculate_derivative_polinom(int size,
                const double *polinom_coef, double *polinom_derivative_coef);
    static double polinom_value(int size, int x, const  double* coef);
    static double function_value(double x);
    static double first_derivative_finction_value(double x);
};

#endif  // MODULES_NEWTON_METHOD_INCLUDE_NEWTON_METHOD_H_
