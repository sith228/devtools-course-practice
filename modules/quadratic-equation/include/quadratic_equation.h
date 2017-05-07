// Copyright 2017 Pletnev Nikita

#ifndef MODULES_QUADRATIC_EQUATION_INCLUDE_QUADRATIC_EQUATION_H_
#define MODULES_QUADRATIC_EQUATION_INCLUDE_QUADRATIC_EQUATION_H_

#include <vector>

class QuadraticEquation {
 public:
    QuadraticEquation();
    QuadraticEquation(
        const double coef_a, const double coef_b, const double coef_c);

    void set_coef_a(const double coef_a);
    void set_coef_b(const double coef_b);
    void set_coef_c(const double coef_c);
    void set_coefficients(
        const double coef_a, const double coef_b, const double coef_c);

    double get_coef_a(void) const;
    double get_coef_b(void) const;
    double get_coef_c(void) const;
    std::vector<double> get_coefficients(void) const;

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
