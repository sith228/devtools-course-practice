// Copyright 2017 Kulygina Julia

#define _USE_MATH_DEFINES
#include "include/three-dimensional-figures.h"
#include <cmath>

Parallelepiped::Parallelepiped(double _a, double _b, double _c) {
    if ((_a > 0) && (_b > 0) && (_c > 0)) {
        a = _a;
        b = _b;
        c = _c;
    }
    else {
        throw std::string("a <= 0 ~~ b <= 0 ~~ c <= 0");
    }
    S = 0;
}

double Parallelepiped::get_a() const {
    return a;
}

double Parallelepiped::get_b() const {
    return b;
}

double Parallelepiped::get_c() const {
    return c;
}

double Parallelepiped::getS() const {
    return S;
}

void Parallelepiped::set_a(const double _a) {
    if (_a > 0) {
        a = _a;
    }
    else {
        throw std::string("a <= 0");
    }
}

void Parallelepiped::set_b(const double _b) {
    if (_b > 0) {
        b = _b;
    }
    else {
        throw std::string("b <= 0");
    }
}

void Parallelepiped::set_c(const double _c) {
    if (_c > 0) {
        c = _c;
    }
    else {
        throw std::string("c <= 0");
    }
}

void Parallelepiped::setS(const double _S) {
    if (_S >= 0) {
        S = _S;
    }
    else {
        throw std::string("S < 0");
    }
}

double Parallelepiped::CalculateS() {
    double _a = this->get_a();
    double _b = this->get_b();
    double _c = this->get_c();
    this->setS(2 * (_a*_b + _b*_c + _a*_c));
    return this->getS();
}

Parallelepiped::Parallelepiped(const Parallelepiped& z) {
    this->set_a(z.get_a());
    this->set_b(z.get_b());
    this->set_c(z.get_c());
    this->setS(z.getS());
}

bool Parallelepiped::operator == (const Parallelepiped& z) const {
    if ((this->get_a() == z.get_a()) && (this->get_b() == z.get_b()) && (this->get_c() == z.get_c()))
        return true;
    else return false;
}

bool Parallelepiped::operator != (const Parallelepiped& z) const {
    return !(*this == z);
}
