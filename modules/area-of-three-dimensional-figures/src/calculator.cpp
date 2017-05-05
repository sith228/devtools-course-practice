// Copyright 2017 Kulygina Julia

#define _USE_MATH_DEFINES
#include "include/calculator.h"
#include <cmath>
#include <string>

Calculator::Calculator() {
    S = 0;
}

bool Calculator::Is_positive_parameter(double _a) {
    if (_a <= 0)
        return false;
    else
        return true;
}

bool Calculator::Check_positive(double massive_parameters[], int size) {
    for (int i = 0; i < size; i++) {
        if (!(Is_positive_parameter(massive_parameters[i]))) {
            throw std::string("parameters are negative");
            return false;
        }
    }

    return true;
}

bool Calculator::Check_for_Heron(double _a, double _b, double _c) {
    if ((_a + _b >= _c) && (_b + _c >= _a) && (_a + _c >= _b))
        return true;
    else
        return false;
}

double Calculator::Calc_Heron(double _a, double _b, double _c) {
    double heron_abc;
    if (Check_for_Heron(_a, _b, _c)) {
        double p = (_a + _b + _c) / 2;
        heron_abc = sqrt(p* (p - _a)*(p - _b)*(p - _c));
    } else {
        throw std::string("Triangle is not calc");
    }
    return heron_abc;
}

double Calculator::Calculate_Sphere(double _r) {
    if (Is_positive_parameter(_r))
        S = 4 * M_PI * _r * _r;
    else
        throw std::string("r <== 0");
    return S;
}

double Calculator::Calculate_Cone(double _r, double _l) {
    double *parameters_rl = new double[2];
    parameters_rl[0] = _r;
    parameters_rl[1] = _l;
    if (Check_positives(parameters_rl, 2))
        S = M_PI * _r * _l;

    return S;
}

double Calculator::Calculate_Conoid(double _r1, double _r2, double _l) {
    double *parameters_rlr = new double[3];
    parameters_rlr[0] = _r1;
    parameters_rlr[1] = _r2;
    parameters_rlr[2] = _l;
    if (Check_positives(parameters_rlr, 3))
        S = M_PI * (_r1 + _r2) * _l;

    return S;
}

double Calculator::Calculate_Cube(double _h) {
    if (Is_positive_parameter(_h))
        S = 6 * _h * _h;
    else
        throw std::string("h <= 0");
    return S;
}

double Calculator::Calculate_Cylinder(double _r, double _h) {
    double *parameters_rh = new double[2];
    parameters_rh[0] = _r;
    parameters_rh[1] = _h;
    if (Check_positives(parameters_rh, 2))
        S = 2 * M_PI * _r * _h;

    return S;
}

double Calculator::Calculate_Parallelepiped(double _a, double _b, double _c) {
    double *parameters_abc = new double[3];
    parameters_abc[0] = _a;
    parameters_abc[1] = _b;
    parameters_abc[2] = _c;
    if (Check_positives(parameters_abc, 3))
        S = 2 * (_a * _b + _b * _c + _a * _c);

    return S;
}

double Calculator::Calculate_Prism(double _a, double _b, double _c, double _h) {
    double *parameters_abch = new double[4];
    parameters_abch[0] = _a;
    parameters_abch[1] = _b;
    parameters_abch[2] = _c;
    parameters_abch[3] = _h;

    if (Check_positives(parameters_abch, 4)) {
        double heron_abc = Calc_Heron(_a, _b, _c);
        S = 2 * heron_abc + _a*_h + _b*_h + _a*_h;
    }

    return S;
}

double Calculator::Calculate_Pyramid(double _a, double _b, double _l) {
    double *parameters_abl = new double[3];
    parameters_abl[0] = _a;
    parameters_abl[1] = _b;
    parameters_abl[2] = _l;

    if (Check_positives(parameters_abl, 3)) {
        double heron_al = Calc_Heron(_a, _l, _l);
        double heron_bl = Calc_Heron(_b, _l, _l);
        S = _a*_b + 2 * heron_al + 2 * heron_bl;
    }

    return S;
}

double Calculator::Calc_Tetra(double _a, double _b, double _c, double _l) {
    double *parameters_abcl = new double[4];
    parameters_abcl[0] = _a;
    parameters_abcl[1] = _b;
    parameters_abcl[2] = _c;
    parameters_abcl[3] = _l;

    if (Check_positives(parameters_abcl, 4)) {
        double heron_al = Calc_Heron(_a, _l, _l);
        double heron_bl = Calc_Heron(_b, _l, _l);
        double heron_abc = Calc_Heron(_a, _b, _c);
        double heron_cl = Calc_Heron(_c, _l, _l);

        S = heron_abc + heron_al + heron_bl + heron_cl;
    }

    return S;
}
