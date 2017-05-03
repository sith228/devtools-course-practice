// Copyright 2017 Kulygina Julia

#include "include/pyramid.h"
#include <string>

Pyramid::Pyramid(double _a, double _b, double _l) {
    if ((_a > 0) && (_b > 0) && (_l > 0)) {
        a = _a;
        b = _b;
        l = _l;
    } else {
        throw std::string("a <= 0 ~~ b <= 0 ~~ l <= 0");
    }
    S = 0;
}

double Pyramid::get_a() const {
    return a;
}

double Pyramid::get_b() const {
    return b;
}

double Pyramid::get_l() const {
    return l;
}

double Pyramid::getS() const {
    return S;
}

void Pyramid::set_a(const double _a) {
    if (_a > 0) {
        a = _a;
    } else {
        throw std::string("a <= 0");
    }
}

void Pyramid::set_b(const double _b) {
    if (_b > 0) {
        b = _b;
    } else {
        throw std::string("b <= 0");
    }
}

void Pyramid::set_l(const double _l) {
    if (_l > 0) {
        l = _l;
    } else {
        throw std::string("l <= 0");
    }
}

void Pyramid::setS(const double _S) {
    if (_S >= 0) {
        S = _S;
    } else {
        throw std::string("S < 0");
    }
}

double Pyramid::CalculateS() {
    double _a = this->get_a();
    double _b = this->get_b();
    double _l = this->get_l();

    double p1 = (2 * l + _a) / 2;
    double heron_al = sqrt(p1 * (p1 - _a) * (p1 - _l) * (p1 - _l));

    double p2 = (2 * l + _b) / 2;
    double heron_bl = sqrt(p2 * (p2 - _b) * (p2 - _l) * (p2 - _l));

    this->setS(_a*_b + 2 * heron_al + 2 * heron_bl);
    return this->getS();
}

Pyramid::Pyramid(const Pyramid& z) {
    this->set_a(z.get_a());
    this->set_b(z.get_b());
    this->set_l(z.get_l());
    this->setS(z.getS());
}

bool Pyramid::operator == (const Pyramid& z) const {
    bool flag1 = (this->get_a() == z.get_a());
    bool flag2 = (this->get_b() == z.get_b());
    bool flag3 = (this->get_l() == z.get_l());
    if ((flag1) && (flag2) && (flag3))
        return true;
    else
        return false;
}

bool Pyramid::operator != (const Pyramid& z) const {
    return !(*this == z);
}
