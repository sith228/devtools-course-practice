// Copyright 2017 Kulygina Julia

#define _USE_MATH_DEFINES
#include "include/three-dimensional-figures.h"
#include <cmath>

Cone::Cone(double _r, double _l) {
    if ((_r > 0) && (_l > 0)) {
        r = _r;
        l = _l;
    } else {
        throw std::string("r <= 0 ~~ l <= 0");
    }
    S = 0;
}

double Cone::getr() const {
    return r;
}

double Cone::getl() const {
    return l;
}

double Cone::getS() const {
    return S;
}

void Cone::setr(const double _r) {
    if (_r > 0) {
        r = _r;
    } else {
        throw std::string("r <= 0");
    }
}

void Cone::setl(const double _l) {
    if (_l > 0) {
        l = _l;
    } else {
        throw std::string("l <= 0");
    }
}

void Cone::setS(const double _S) {
    if (_S >= 0) {
        S = _S;
    } else {
        throw std::string("S < 0");
    }
}

double Cone::CalculateS() {
    double _r = this->getr();
    double _l = this->getl();
    this->setS(M_PI * _r *_l);
    return this->getS();
}

Cone::Cone(const Cone& z) {
    this->setr(z.getr());
    this->setl(z.getl());
    this->setS(z.getS());
}

bool Cone::operator == (const Cone& z) const {
    if ((this->getr() == z.getr()) && (this->getl() == z.getl()))
        return true;
    else return false;
}

bool Cone::operator != (const Cone& z) const {
    return !(*this == z);
}
