// Copyright 2017 Pletnev Nikita

#include "include/quadratic_equation.h"
#include <math.h>


QuadraticEquation::QuadraticEquation() : coefA_(1), coefB_(0), coefC_(0) {}

QuadraticEquation::QuadraticEquation(
    const double coefA, const double coefB, const double coefC) {
    setCoefA(coefA);
    setCoefB(coefB);
    setCoefC(coefC);
}

double QuadraticEquation::discriminant() {
    return coefB_*coefB_ - 4 * coefA_*coefC_;
}

void QuadraticEquation::setCoefA(const double coefA) {
    if (coefA != 0)
        coefA_ = coefA;
    else
        coefA_ = 1;
}

void QuadraticEquation::setCoefB(const double coefB) {
    coefB_ = coefB;
}

void QuadraticEquation::setCoefC(const double coefC) {
    coefC_ = coefC;
}

void QuadraticEquation::setCoefficients(
    const double coefA, const double coefB, const double coefC) {
    setCoefA(coefA);
    setCoefB(coefB);
    setCoefC(coefC);
}

double QuadraticEquation::getCoefA(void) {
    return coefA_;
}

double QuadraticEquation::getCoefB(void) {
    return coefB_;
}

double QuadraticEquation::getCoefC(void) {
    return coefC_;
}

int QuadraticEquation::numOfSolutions(void) {
    int result = 1;
    if (discriminant() < 0) result = 0;
    if (discriminant() > 0) result = 2;
    return result;
}

double QuadraticEquation::getX1(void) {
    double result = 0;
    if (numOfSolutions() > 0)
        result = (-coefB_ + sqrt(discriminant())) / 2 * coefA_;
    return result;
}

double QuadraticEquation::getX2(void) {
    double result = 0;
    if (numOfSolutions() < 2)
        result = getX1();
    else
        result = (-coefB_ - sqrt(discriminant())) / 2 * coefA_;
    return result;
}

