// Copyright 2017 Tarasov Oleg

#include "include/length_converter.h"

/* Коэффициенты перевода единицы измерения в см */


Length::Length(LENGTH_TYPE type, double value) {
    SetValue(type, value);
}

void Length::SetValue(LENGTH_TYPE type, double value) {
    length_cm_ = value * GetConvertCoef(type);
}

double Length::GetConvertCoef(LENGTH_TYPE type) const {
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

double Length::ConvertTo(LENGTH_TYPE type) const {
    return length_cm_ / GetConvertCoef(type);
}
