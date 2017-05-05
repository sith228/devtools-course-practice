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
    SetValue(type, value);
}

void Length::SetValue(LENGTH_TYPE type, double value) {
    length_cm = value * GetConvertCoef(type);
}

double Length::GetConvertCoef(LENGTH_TYPE type) const {
    switch (type) {
    case MICROMETRE:
        return MICROMETRE_TO_CM;
    case MILLIMETRE:
        return MILLIMETRE_TO_CM;
    case DECIMETRE:
        return DECIMETRE_TO_CM;
    case METRE:
        return METRE_TO_CM;
    case KILOMETRE:
        return KILOMETRE_TO_CM;
    case INCH:
        return INCH_TO_CM;
    case HAND:
        return HAND_TO_CM;
    case LINK:
        return LINK_TO_CM;
    case FOOT:
        return FOOT_TO_CM;
    case YARD:
        return YARD_TO_CM;
    case ROD:
        return ROD_TO_CM;
    case CHAIN:
        return CHAIN_TO_CM;
    case FURHLONG:
        return FURHLONG_TO_CM;
    case MILE:
        return MILE_TO_CM;
    case LEAGUE:
        return LEAGUE_TO_CM;
    default:
        return CENTIMETRE_TO_CM;
    }
}

double Length::ConvertTo(LENGTH_TYPE type) const {
    return length_cm / GetConvertCoef(type);
}
