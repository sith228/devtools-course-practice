// Copyright 2017 Kulygina Julia

#define _USE_MATH_DEFINES
#include "include/calculator.h"
#include <cmath>
#include <string>

Calculator::Calculator() {
    S = 0;
}

bool Calculator::Is_positive_parametr(double _a) {
    if (_a <= 0)
        return false;
    else
        return true;
}

double Calculator::Calculate_Sphere(double _r) {
    if (Is_positive_parametr(_r))
        S = 4 * M_PI * _r * _r;
    else
        throw std::string("r <== 0");
    return S;
}

double Calculator::Calculate_Cone(double _r, double _l) {
    if (Is_positive_parametr(_r) && Is_positive_parametr(_l))
        S = M_PI * _r * _l;
    else
        throw std::string("r <= 0 ~~ l <= 0");
    return S;
}

double Calculator::Calculate_Conoid(double _r1, double _r2, double _l) {
    bool flag1 = Is_positive_parametr(_r1);
    bool flag2 = Is_positive_parametr(_r2);
    bool flag3 = Is_positive_parametr(_l);
    if ((flag1) && (flag2) && (flag3))
        S = M_PI * (_r1 + _r2) * _l;
    else
        throw std::string("r1 <= 0 ~~ r2 <= 0 ~~ l <= 0");
    return S;
}

double Calculator::Calculate_Cube(double _h) {
    if (Is_positive_parametr(_h))
        S = 6 * _h * _h;
    else
        throw std::string("h <= 0");
    return S;
}

double Calculator::Calculate_Cylinder(double _r, double _h) {
    if (Is_positive_parametr(_r) && Is_positive_parametr(_h))
        S = 2 * M_PI * _r * _h;
    else
        throw std::string("r <= 0 ~~ h <= 0");
    return S;
}

double Calculator::Calculate_Parallelepiped(double _a, double _b, double _c) {
    bool flag1 = Is_positive_parametr(_a);
    bool flag2 = Is_positive_parametr(_b);
    bool flag3 = Is_positive_parametr(_c);
    if ((flag1) && (flag2) && (flag3))
        S = 2 * (_a * _b + _b * _c + _a * _c);
    else
        throw std::string("a <= 0 ~~ b <= 0 ~~ c <= 0");
    return S;
}

double Calculator::Calculate_Prism(double _a, double _b, double _c, double _h) {
    bool flag1 = Is_positive_parametr(_a);
    bool flag2 = Is_positive_parametr(_b);
    bool flag3 = Is_positive_parametr(_c);
    bool flag4 = Is_positive_parametr(_h);
    if ((flag1) && (flag2) && (flag3) && (flag4)) {
        double p = (_a + _b + _c) / 2;
        double heron_abc = sqrt(p* (p - _a)*(p - _b)*(p - _c));
        S = 2 * heron_abc + _a*_h + _b*_h + _a*_h;
    } else {
        throw std::string("a <= 0 ~~ b <= 0 ~~ c <= 0 ~~ h <= 0");
    }
    return S;
}

double Calculator::Calculate_Pyramid(double _a, double _b, double _l) {
    bool flag1 = Is_positive_parametr(_a);
    bool flag2 = Is_positive_parametr(_b);
    bool flag3 = Is_positive_parametr(_l);
    if ((flag1) && (flag2) && (flag3)) {
        double p1 = (2 * _l + _a) / 2;
        double heron_al = sqrt(p1 * (p1 - _a) * (p1 - _l) * (p1 - _l));

        double p2 = (2 * _l + _b) / 2;
        double heron_bl = sqrt(p2 * (p2 - _b) * (p2 - _l) * (p2 - _l));

        S = _a*_b + 2 * heron_al + 2 * heron_bl;
    } else {
        throw std::string("a <= 0 ~~ b <= 0 ~~ l <= 0");
    }
    return S;
}

double Calculator::Calc_Tetra(double _a, double _b, double _c, double _l) {
    bool flag1 = Is_positive_parametr(_a);
    bool flag2 = Is_positive_parametr(_b);
    bool flag3 = Is_positive_parametr(_c);
    bool flag4 = Is_positive_parametr(_l);
    if ((flag1) && (flag2) && (flag3) && (flag4)) {
        double p = (_a + _b + _c) / 2;
        double heron_abc = sqrt(p* (p - _a)*(p - _b)*(p - _c));

        double p_al = (_a + 2 * _l) / 2;
        double heron_al = sqrt(p_al* (p_al - _a)*(p_al - _l) * (p_al - _l));

        double p_bl = (_b + 2 * _l) / 2;
        double heron_bl = sqrt(p_bl * (p_bl - _b) * (p_bl - _l) * (p_bl - _l));

        double p_cl = (_c + 2 * _l) / 2;
        double heron_cl = sqrt(p_cl * (p_cl - _c) * (p_cl - _l) * (p_cl - _l));

        S = heron_abc + heron_al + heron_bl + heron_cl;
    } else {
        throw std::string("a <= 0 ~~ b <= 0 ~~ c <= 0 ~~ l <= 0");
    }
    return S;
}
