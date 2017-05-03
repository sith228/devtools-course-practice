// Copyright 2017 Kulygina Julia

#define _USE_MATH_DEFINES
#include "include/three-dimensional-figures.h"
#include <cmath>

Sphere::Sphere(double _R) {
    if (_R > 0) {
        R = _R;
    }
    else {
        throw std::string("R <= 0");
    }
    S = 0;
}

double Sphere::getR() const {
    return R;
}

double Sphere::getS() const {
    return S;
}

void Sphere::setR(const double _R) {
    if (_R > 0) {
        R = _R;
    }
    else {
        throw std::string("R <= 0");
    }
}

void Sphere::setS(const double _S) {
    if (_S >= 0) {
        S = _S;
    }
    else {
        throw std::string("S < 0");
    }
}

double Sphere::CalculateS() {
    double _R = this->getR();
    this->setS(4 * M_PI * _R *_R);
    return this->getS();
}

Sphere::Sphere(const Sphere& z) {
    this->setR(z.getR());
    this->setS(z.getS());
}

bool Sphere::operator == (const Sphere& z) const {
    if (this->getR() == z.getR())
        return true;
    else return false;
}

bool Sphere::operator != (const Sphere& z) const {
    return !(*this == z);
}
