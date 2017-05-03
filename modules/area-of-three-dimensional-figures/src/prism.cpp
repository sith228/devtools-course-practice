// Copyright 2017 Kulygina Julia

#define _USE_MATH_DEFINES
#include "include/three-dimensional-figures.h"
#include <cmath>
#include <string>

Prism::Prism(double _a, double _b, double _c, double _h) {
    if ((_a > 0) && (_b > 0) && (_c > 0) && (_h > 0)) {
        a = _a;
        b = _b;
        c = _c;
        h = _h;
    } else {
        throw std::string("a <= 0 ~~ b <= 0 ~~ c <= 0 ~~ h <= 0");
    }
    S = 0;
}

double Prism::get_a() const {
    return a;
}

double Prism::get_b() const {
    return b;
}

double Prism::get_c() const {
    return c;
}

double Prism::get_h() const {
    return h;
}

double Prism::getS() const {
    return S;
}

void Prism::set_a(const double _a) {
    if (_a > 0) {
        a = _a;
    } else {
        throw std::string("a <= 0");
    }
}

void Prism::set_b(const double _b) {
    if (_b > 0) {
        b = _b;
    } else {
        throw std::string("b <= 0");
    }
}

void Prism::set_c(const double _c) {
    if (_c > 0) {
        c = _c;
    } else {
        throw std::string("c <= 0");
    }
}

void Prism::set_h(const double _h) {
    if (_h > 0) {
        h = _h;
    } else {
        throw std::string("h <= 0");
    }
}

void Prism::setS(const double _S) {
    if (_S >= 0) {
        S = _S;
    } else {
        throw std::string("S < 0");
    }
}

double Prism::CalculateS() {
    double _a = this->get_a();
    double _b = this->get_b();
    double _c = this->get_c();
    double _h = this->get_h();

    double p = (_a + _b + _c) / 2;
    double heron_abc = sqrt(p* (p - _a)*(p - _b)*(p - _c));
    this->setS(2 * heron_abc + _a*_h + _b*_h + _a*_h);
    return this->getS();
}

Prism::Prism(const Prism& z) {
    this->set_a(z.get_a());
    this->set_b(z.get_b());
    this->set_c(z.get_c());
    this->set_h(z.get_h());
    this->setS(z.getS());
}

bool Prism::operator == (const Prism& z) const {
    bool flag1 = (this->get_a() == z.get_a());
    bool flag2 = (this->get_b() == z.get_b());
    bool flag3 = (this->get_c() == z.get_c());
    bool flag4 = (this->get_h() == z.get_h());
    if ((flag1) && (flag2) && (flag3) && (flag4))
        return true;
    else
        return false;
}

bool Prism::operator != (const Prism& z) const {
    return !(*this == z);
}
