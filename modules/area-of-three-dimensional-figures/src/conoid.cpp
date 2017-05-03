// Copyright 2017 Kulygina Julia

#define _USE_MATH_DEFINES
#include "include/three-dimensional-figures.h"
#include <string>

Conoid::Conoid(double _r1, double _r2, double _l) {
    if ((_r1 > 0) && (_l > 0) && (_r2 > 0)) {
        r1 = _r1;
        r2 = _r2;
        l = _l;
    } else {
        throw std::string("r <= 0 ~~ l <= 0");
    }
    S = 0;
}

double Conoid::getr1() const {
    return r1;
}

double Conoid::getr2() const {
    return r2;
}

double Conoid::getl() const {
    return l;
}

double Conoid::getS() const {
    return S;
}

void Conoid::setr1(const double _r1) {
    if (_r1 > 0) {
        r1 = _r1;
    } else {
        throw std::string("r1 <= 0");
    }
}

void Conoid::setr2(const double _r2) {
    if (_r2 > 0) {
        r2 = _r2;
    } else {
        throw std::string("r2 <= 0");
    }
}

void Conoid::setl(const double _l) {
    if (_l > 0) {
        l = _l;
    } else {
        throw std::string("l <= 0");
    }
}

void Conoid::setS(const double _S) {
    if (_S >= 0) {
        S = _S;
    } else {
        throw std::string("S < 0");
    }
}

double Conoid::CalculateS() {
    double _r1 = this->getr1();
    double _r2 = this->getr2();
    double _l = this->getl();
    this->setS(M_PI * (_r1 + _r2)*_l);
    return this->getS();
}

Conoid::Conoid(const Conoid& z) {
    this->setr1(z.getr1());
    this->setr2(z.getr2());
    this->setl(z.getl());
    this->setS(z.getS());
}

bool Conoid::operator == (const Conoid& z) const {
    bool flag1 = (this->getr1() == z.getr1());
    bool flag2 = (this->getr2() == z.getr2());
    bool flag3 = (this->getl() == z.getl());
    if ((flag1) && (flag2) && (flag3))
        return true;
    else
        return false;
}

bool Conoid::operator != (const Conoid& z) const {
    return !(*this == z);
}
