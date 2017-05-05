// Copyright 2017 Pletnev Nikita

#ifndef MODULES_QUADRATIC_EQUATION_INCLUDE_QUADRATIC_EQUATION_H_
#define MODULES_QUADRATIC_EQUATION_INCLUDE_QUADRATIC_EQUATION_H_

class QuadraticEquation {
 private:
    double coefA_;
    double coefB_;
    double coefC_;

    double discriminant();

 public:
    QuadraticEquation();
    QuadraticEquation(
        const double coefA, const double coefB, const double coefC);

    void setCoefA(const double coefA);
    void setCoefB(const double coefB);
    void setCoefC(const double coefC);
    void setCoefficients(
        const double coefA, const double coefB, const double coefC);

    double getCoefA(void);
    double getCoefB(void);
    double getCoefC(void);

    int numOfSolutions(void);
    double getX1(void);
    double getX2(void);
};

#endif  // MODULES_QUADRATIC_EQUATION_INCLUDE_QUADRATIC_EQUATION_H_
