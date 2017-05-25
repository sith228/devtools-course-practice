// Copyright 2017 Maxim Doronin

#include <cmath>

#include "include/functions.h"

Function::Function(std::vector<float> koefs) {
    this->koefs = koefs;
}

/*
==================== polinomial of 2 degree ====================
*/
float Polynomial2Degree::f(float x) const {
    if (koefs.size() != 3) {
        throw "Polynomial2Degree: Mismatch in the number of arguments";
    }
    return koefs.at(0)*pow(x, 2) + koefs.at(1)*x + koefs.at(2);
}

float Polynomial2Degree::df(float x) const {
    if (koefs.size() != 3) {
        throw "Polynomial2Degree: Mismatch in the number of arguments";
    }
    return 2*koefs.at(0)*x + koefs.at(1);
}

float Polynomial2Degree::d2f(float x) const {
    if (koefs.size() != 3) {
        throw "Polynomial2Degree: Mismatch in the number of arguments";
    }
    return 2*koefs.at(0);
}

/*
==================== polinomial of 3 degree ====================
*/
float Polynomial3Degree::f(float x) const {
    if (koefs.size() != 4) {
        throw "Polynomial3Degree: Mismatch in the number of arguments";
    }
    return koefs.at(0)*pow(x, 3) + koefs.at(1)*pow(x, 2) + koefs.at(2)*x
    + koefs.at(3);
}

float Polynomial3Degree::df(float x) const {
    if (koefs.size() != 4) {
        throw "Polynomial3Degree: Mismatch in the number of arguments";
    }
    return 3*koefs.at(0)*pow(x, 2) + 2*koefs.at(1)*x + koefs.at(2);
}

float Polynomial3Degree::d2f(float x) const {
    if (koefs.size() != 4) {
        throw "Polynomial3Degree: Mismatch in the number of arguments";
    }
    return 6*koefs.at(0)*x + 2*koefs.at(1);
}

/*
==================== polinomial of 4 degree ====================
*/
float Polynomial4Degree::f(float x) const {
    if (koefs.size() != 5) {
        throw "Polynomial4Degree: Mismatch in the number of arguments";
    }
    return koefs.at(0)*pow(x, 4) + koefs.at(1)*pow(x, 3)
    + koefs.at(2)*pow(x, 2) + koefs.at(3)*x + koefs.at(4);
}

float Polynomial4Degree::df(float x) const {
    if (koefs.size() != 5) {
        throw "Polynomial4Degree: Mismatch in the number of arguments";
    }
    return 4*koefs.at(0)*pow(x, 3) + 3*koefs.at(1)*pow(x, 2)
    + 2*koefs.at(2)*x + koefs.at(3);
}

float Polynomial4Degree::d2f(float x) const {
    if (koefs.size() != 5) {
        throw "Polynomial4Degree: Mismatch in the number of arguments";
    }
    return 12*koefs.at(0)*pow(x, 2) + 6*koefs.at(1)*x + 2*koefs.at(2);
}

/*
==================== Exponent a*exp(b*x) + c ====================
*/
float Exponent::f(float x) const {
    if (koefs.size() != 3) {
        throw "Exponent: Mismatch in the number of arguments";
    }
    return koefs.at(0) * exp(koefs.at(1) * x) + koefs.at(2);
}

float Exponent::df(float x) const {
    if (koefs.size() != 3) {
        throw "Exponent: Mismatch in the number of arguments";
    }
    return koefs.at(0) * koefs.at(1) * exp(koefs.at(1) * x);
}

float Exponent::d2f(float x) const {
    if (koefs.size() != 3) {
        throw "Exponent: Mismatch in the number of arguments";
    }
    return koefs.at(0) * pow(koefs.at(1), 2) * exp(koefs.at(1) * x);
}
