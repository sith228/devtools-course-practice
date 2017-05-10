// Copyright 2017 Pletnev Nikita

#ifndef MODULES_QUADRATIC_EQUATION_INCLUDE_QUADRATIC_EQUATION_H_
#define MODULES_QUADRATIC_EQUATION_INCLUDE_QUADRATIC_EQUATION_H_

#include <vector>

class QuadraticEquation {
 public:
    QuadraticEquation();
    QuadraticEquation(
        const double coef_a, const double coef_b, const double coef_c);

    void SetCoefA(const double coef_a);
    void SetCoefB(const double coef_b);
    void SetCoefC(const double coef_c);
    void SetCoefficients(
        const double coef_a, const double coef_b, const double coef_c);

    double GetCoefA(void) const;
    double GetCoefB(void) const;
    double GetCoefC(void) const;
    std::vector<double> GetCoefficients(void) const;

    int NumOfSolutions(void) const;
    double GetX1(void) const;
    double GetX2(void) const;

 private:
    double coef_a_;
    double coef_b_;
    double coef_c_;

    double Discriminant() const;
};

#endif  // MODULES_QUADRATIC_EQUATION_INCLUDE_QUADRATIC_EQUATION_H_
