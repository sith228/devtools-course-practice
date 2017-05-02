// Copyright 2017 Kulygina Julia

#include "include/three-dimensional-figures.h"

Cube::Cube(double _h) {
    if (_h > 0)
        h = _h;
    else 
        throw std::string("h <= 0");
    S = 0;
}

double Cube::geth() const {
    return h;
}

double Cube::getS() const {
    return S;
}

void Cube::seth(const double _h) {
    if (_h > 0)
        h = _h;
    else
        throw std::string("h <= 0");
}

void Cube::setS(const double _S) {
    if (_S >= 0)
        S = _S;
    else
        throw std::string("S < 0");
}

double Cube::CalculateS() {
    double _h = this->geth();
    this->setS(6 * _h * _h);
    return this->getS();
}

Cube::Cube(const Cube& z) {
    this->seth(z.geth());
    this->setS(z.getS());
}
