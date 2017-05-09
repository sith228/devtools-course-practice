// Copyright 2017 Tarasov Oleg

#include "include/length_converter.h"

/* Коэффициенты перевода единицы измерения в см */
const double Length::micrometre_to_cm_ = 0.0001;
const double Length::millimetre_to_cm_ = 0.1;
const double Length::centimetre_to_cm_ = 1.0;
const double Length::decimetre_to_cm_ = 10.0;
const double Length::metre_to_cm_ = 100.0;
const double Length::kilometre_to_cm_ = 100000.0;
const double Length::inch_to_cm_ = 2.54;
const double Length::hand_to_cm_ = 10.16;
const double Length::link_to_cm_ = 20.1168;
const double Length::foot_to_cm_ = 30.48;
const double Length::yard_to_cm_ = 91.44;
const double Length::rod_to_cm_ = 502.92;
const double Length::chain_to_cm_ = 2011.68;
const double Length::furhlong_to_cm_ = 20116.8;
const double Length::mile_to_cm_ = 160934.4;
const double Length::league_to_cm_ = 482803.2;

Length::Length(LengthType type, double value) {
    SetValue(type, value);
}

void Length::SetValue(LengthType type, double value) {
    length_cm_ = value * GetConvertCoef(type);
}

double Length::GetConvertCoef(LengthType type) const {
    switch (type) {
    case MICROMETRE:
        return micrometre_to_cm_;
    case MILLIMETRE:
        return millimetre_to_cm_;
    case DECIMETRE:
        return decimetre_to_cm_;
    case METRE:
        return metre_to_cm_;
    case KILOMETRE:
        return kilometre_to_cm_;
    case INCH:
        return inch_to_cm_;
    case HAND:
        return hand_to_cm_;
    case LINK:
        return link_to_cm_;
    case FOOT:
        return foot_to_cm_;
    case YARD:
        return yard_to_cm_;
    case ROD:
        return rod_to_cm_;
    case CHAIN:
        return chain_to_cm_;
    case FURHLONG:
        return furhlong_to_cm_;
    case MILE:
        return mile_to_cm_;
    case LEAGUE:
        return league_to_cm_;
    default:
        return centimetre_to_cm_;
    }
}

double Length::ConvertTo(LengthType type) const {
    return length_cm_ / GetConvertCoef(type);
}
