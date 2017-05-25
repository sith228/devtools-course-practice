// Copyright 2017 Dryakhlov Dmitry

#ifndef MODULES_NEWTON_METHOD_INCLUDE_NEWTON_METHOD_H_
#define MODULES_NEWTON_METHOD_INCLUDE_NEWTON_METHOD_H_

class NewtonMethod {
public:
    static double NewtonMethodPolynom(double eps, size_t size,
        double *polynom_coef);
    static double NewtonMethodFunction(double eps);
    static void GeneateRandomPolynom(size_t size, double *polynom_coef);
    static bool CheckRootPolynom(double x, double eps, size_t size,
        const double *polynom_coef);
    static bool CheckRootFunction(double x, double eps);
private:
    static void CalculateDerivativePolynom(size_t size,
        const double *polynom_coef, double *polynom_derivative_coef);
    static double PolynomValue(size_t size, double x, const double* coef);
    static double FunctionValue(double x);
    static double FirstDerivativeFunctionValue(double x);
};

#endif  // MODULES_NEWTON_METHOD_INCLUDE_NEWTON_METHOD_H_
