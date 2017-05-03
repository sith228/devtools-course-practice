// Copyright 2017 Kulygina Julia

#define _USE_MATH_DEFINES
#include "include/three-dimensional-figures.h"
#include <string>

Cylinder::Cylinder(double _r, double _l) {
    if ((_r > 0) && (_l > 0)) {
        r = _r;
        l = _l;
    } else {
        throw std::string("r <= 0 ~~ l <= 0");
    }
    S = 0;
}

double Cylinder::getr() const {
    return r;
}

double Cylinder::getl() const {
    return l;
}

double Cylinder::getS() const {
    return S;
}

void Cylinder::setr(const double _r) {
    if (_r > 0) {
        r = _r;
    } else {
        throw std::string("r <= 0");
    }
}

void Cylinder::setl(const double _l) {
    if (_l > 0) {
        l = _l;
    } else {
        throw std::string("l <= 0");
    }
}

void Cylinder::setS(const double _S) {
    if (_S >= 0) {
        S = _S;
    } else {
        throw std::string("S < 0");
    }
}

double Cylinder::CalculateS() {
    double _r = this->getr();
    double _l = this->getl();
    this->setS(2 * M_PI * _r *_l);
    return this->getS();
}

Cylinder::Cylinder(const Cylinder& z) {
    this->setr(z.getr());
    this->setl(z.getl());
    this->setS(z.getS());
}

bool Cylinder::operator == (const Cylinder& z) const {
    if ((this->getr() == z.getr()) && (this->getl() == z.getl()))
        return true;
    else return false;
}

bool Cylinder::operator != (const Cylinder& z) const {
    return !(*this == z);
}
