// Copyright 2017 Kulygina Julia

#define _USE_MATH_DEFINES
#include "include/tetrahedron.h"
#include <cmath>
#include <string>

Tetrahedron::Tetrahedron(double _a, double _b, double _c, double _l) {
    if ((_a > 0) && (_b > 0) && (_c > 0) && (_l > 0)) {
        a = _a;
        b = _b;
        c = _c;
        l = _l;
    }
    else {
        throw std::string("a <= 0 ~~ b <= 0 ~~ c <= 0 ~~ l <= 0");
    }
    S = 0;
}

double Tetrahedron::get_a() const {
    return a;
}

double Tetrahedron::get_b() const {
    return b;
}

double Tetrahedron::get_c() const {
    return c;
}

double Tetrahedron::get_l() const {
    return l;
}

double Tetrahedron::getS() const {
    return S;
}

void Tetrahedron::set_a(const double _a) {
    if (_a > 0) {
        a = _a;
    } else {
        throw std::string("a <= 0");
    }
}

void Tetrahedron::set_b(const double _b) {
    if (_b > 0) {
        b = _b;
    } else {
        throw std::string("b <= 0");
    }
}

void Tetrahedron::set_c(const double _c) {
    if (_c > 0) {
        c = _c;
    } else {
        throw std::string("c <= 0");
    }
}

void Tetrahedron::set_l(const double _l) {
    if (_l > 0) {
        l = _l;
    } else {
        throw std::string("l <= 0");
    }
}

void Tetrahedron::setS(const double _S) {
    if (_S >= 0) {
        S = _S;
    } else {
        throw std::string("S < 0");
    }
}

double Tetrahedron::CalculateS() {
    double _a = this->get_a();
    double _b = this->get_b();
    double _c = this->get_c();
    double _l = this->get_l();

    double p = (_a + _b + _c) / 2;
    double heron_abc = sqrt(p* (p - _a)*(p - _b)*(p - _c));

    double p_al = (_a + 2 * _l) / 2;
    double heron_al = sqrt(p_al* (p_al - _a)*(p_al - _l) * (p_al - _l));

    double p_bl = (_b + 2 * _l) / 2;
    double heron_bl = sqrt(p_bl * (p_bl - _b) * (p_bl - _l) * (p_bl - _l));

    double p_cl = (_c + 2 * _l) / 2;
    double heron_cl = sqrt(p_cl * (p_cl - _c) * (p_cl - _l) * (p_cl - _l));

    this->setS(heron_abc + heron_al + heron_bl + heron_cl);
    return this->getS();
}

Tetrahedron::Tetrahedron(const Tetrahedron& z) {
    this->set_a(z.get_a());
    this->set_b(z.get_b());
    this->set_c(z.get_c());
    this->set_l(z.get_l());
    this->setS(z.getS());
}

bool Tetrahedron::operator == (const Tetrahedron& z) const {
    if ((this->get_a() == z.get_a()) && (this->get_b() == z.get_b()) && (this->get_c() == z.get_c()) && (this->get_l() == z.get_l()))
        return true;
    else return false;
}

bool Tetrahedron::operator != (const Tetrahedron& z) const {
    return !(*this == z);
}
