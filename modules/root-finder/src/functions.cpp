// Copyright 2017 Maxim Doronin

#include <cmath>
#include <string>
#include <vector>
#include "include/functions.h"

Function::Function(std::vector<float> koefs) {
    this->koefs = koefs;
}

void Function::generateThrow(std::string type) const {
    std::string throws = "";
    if (!type.compare("mismatch")) {
        throws += "Mismatch in the number of arguments\n";
    } else if (!type.compare("zero")) {
        throws += "First coefficient can't be zero\n";
    }
    throw std::string(throws);
}

void Function::checkKoefs(unsigned int neededNumberOfKoefs) const {
    if (koefs.size() != neededNumberOfKoefs) {
        generateThrow("mismatch");
    } else if (koefs.at(0) == 0) {
        generateThrow("zero");
    }
}

/*
==================== polinomial of 2 degree ====================
*/
float Polynomial2Degree::f(float x) const {
    checkKoefs(3);
    return koefs.at(0)*pow(x, 2) + koefs.at(1)*x + koefs.at(2);
}

float Polynomial2Degree::df(float x) const {
    checkKoefs(3);
    return 2 * koefs.at(0)*x + koefs.at(1);
}

float Polynomial2Degree::d2f(float x) const {
    checkKoefs(3);
    return 2 * koefs.at(0);
}

/*
==================== polinomial of 3 degree ====================
*/
float Polynomial3Degree::f(float x) const {
    checkKoefs(4);
    return koefs.at(0)*pow(x, 3) + koefs.at(1)*pow(x, 2) + koefs.at(2)*x
        + koefs.at(3);
}

float Polynomial3Degree::df(float x) const {
    checkKoefs(4);
    return 3 * koefs.at(0)*pow(x, 2) + 2 * koefs.at(1)*x + koefs.at(2);
}

float Polynomial3Degree::d2f(float x) const {
    checkKoefs(4);
    return 6 * koefs.at(0)*x + 2 * koefs.at(1);
}

/*
==================== polinomial of 4 degree ====================
*/
float Polynomial4Degree::f(float x) const {
    checkKoefs(5);
    return koefs.at(0)*pow(x, 4) + koefs.at(1)*pow(x, 3)
        + koefs.at(2)*pow(x, 2) + koefs.at(3)*x + koefs.at(4);
}

float Polynomial4Degree::df(float x) const {
    checkKoefs(5);
    return 4 * koefs.at(0)*pow(x, 3) + 3 * koefs.at(1)*pow(x, 2)
        + 2 * koefs.at(2)*x + koefs.at(3);
}

float Polynomial4Degree::d2f(float x) const {
    checkKoefs(5);
    return 12 * koefs.at(0)*pow(x, 2) + 6 * koefs.at(1)*x + 2 * koefs.at(2);
}

/*
==================== Exponent a*exp(b*x) + c ====================
*/
float Exponent::f(float x) const {
    checkKoefs(3);
    return koefs.at(0) * exp(koefs.at(1) * x) + koefs.at(2);
}

float Exponent::df(float x) const {
    checkKoefs(3);
    return koefs.at(0) * koefs.at(1) * exp(koefs.at(1) * x);
}

float Exponent::d2f(float x) const {
    checkKoefs(3);
    return koefs.at(0) * pow(koefs.at(1), 2) * exp(koefs.at(1) * x);
}
