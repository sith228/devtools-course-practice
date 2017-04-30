// Copyright 2017 Tarasov Oleg

#include "include/length_converter.h"

/* Коэффициенты перевода единицы измерения в см */
#define MICROMETRE_TO_CM    0.0001
#define MILLIMETRE_TO_CM    0.1
#define CENTIMETRE_TO_CM    1.0
#define DECIMETRE_TO_CM     10.0
#define METRE_TO_CM         100.0
#define KILOMETRE_TO_CM     100000.0
#define INCH_TO_CM          2.54
#define HAND_TO_CM          10.16
#define LINK_TO_CM          20.1168
#define FOOT_TO_CM          30.48
#define YARD_TO_CM          91.44
#define ROD_TO_CM           502.92
#define CHAIN_TO_CM         2011.68
#define FURHLONG_TO_CM      20116.8
#define MILE_TO_CM          160934.4
#define LEAGUE_TO_CM        482803.2

Length::Length(LENGTH_TYPE type, double value) {
    length_sm = value * GetConvertCoef(type);
}

double Length::GetConvertCoef(LENGTH_TYPE type) const {
    if (type == MICROMETRE) return MICROMETRE_TO_CM;
    else if (type == MILLIMETRE) return MILLIMETRE_TO_CM;
    else if (type == DECIMETRE) return DECIMETRE_TO_CM;
    else if (type == METRE) return METRE_TO_CM;
    else if (type == KILOMETRE) return KILOMETRE_TO_CM;
    else if (type == INCH) return INCH_TO_CM;
    else if (type == HAND) return HAND_TO_CM;
    else if (type == LINK) return LINK_TO_CM;
    else if (type == FOOT) return FOOT_TO_CM;
    else if (type == YARD) return YARD_TO_CM;
    else if (type == ROD) return ROD_TO_CM;
    else if (type == CHAIN) return CHAIN_TO_CM;
    else if (type == FURHLONG) return FURHLONG_TO_CM;
    else if (type == MILE) return MILE_TO_CM;
    else if (type == LEAGUE) return LEAGUE_TO_CM;
    else return CENTIMETRE_TO_CM;
}

double Length::ConvertTo(LENGTH_TYPE type) const {
    return length_sm / GetConvertCoef(type);
}
