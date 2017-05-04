// Copyright 2017 Nesterov Alexander

#include "../include/hsb_hsv_space.h"

#include <cstdint>
#include <string>
#include <algorithm>


void HSBHSVSpace::swap(HSBHSVSpace &hsb_hsv_space) {
    std::swap(hue, hsb_hsv_space.hue);
    std::swap(saturation, hsb_hsv_space.saturation);
    std::swap(value_brightnes, hsb_hsv_space.value_brightnes);
}

HSBHSVSpace::HSBHSVSpace(const int hue_,
                   const int saturation_,
                   const int value_brightnes_) {
    if ((hue_ < 0) || (hue_ > 360)) {
        throw std::string("The index of hue not in the range 0-360");
    } else if ((saturation_ < 0) || (saturation_ > 100)) {
        throw std::string("The index of saturation not in the range 0-100");
    } else if ((value_brightnes_ < 0) || (value_brightnes_ > 100)) {
        throw std::string("The index of brightnes not in the range 0-100");
    } else {
        hue = (uint16_t) hue_;
        saturation = (uint16_t) saturation_;
        value_brightnes = (uint16_t) value_brightnes_;
    }
}

HSBHSVSpace::HSBHSVSpace(const HSBHSVSpace &hsb_hsv_space) {
    if (&hsb_hsv_space == nullptr) {
        throw std::string("Copying object is nullptr");
    } else {
        hue = hsb_hsv_space.hue;
        saturation = hsb_hsv_space.saturation;
        value_brightnes = hsb_hsv_space.value_brightnes;
    }
}

HSBHSVSpace& HSBHSVSpace::operator=(const HSBHSVSpace &hsb_hsv_space) {
    if (this != &hsb_hsv_space) {
        HSBHSVSpace(hsb_hsv_space).swap(*this);
    }
    return *this;
}

uint16_t HSBHSVSpace::GetHue() const {
    return hue;
}

uint16_t HSBHSVSpace::GetSaturation() const {
    return saturation;
}

uint16_t HSBHSVSpace::GetValueBrightnes() const {
    return value_brightnes;
}

void HSBHSVSpace::SetHue(const int hue_) {
    if ((hue_ < 0) || (hue_ > 360)) {
        throw std::string("The index of hue isn't in the range 0-360");
    } else {
        hue = (uint16_t) hue_;
    }
}

void HSBHSVSpace::SetSaturation(const int saturation_) {
    if ((saturation_ < 0) || (saturation_ > 100)) {
        throw std::string("The index of saturation isn't in the range 0-100");
    }  else {
        saturation = (uint16_t) saturation_;
    }
}

void HSBHSVSpace::SetValueBrightnes(const int value_brightnes_) {
    if ((value_brightnes_ < 0) || (value_brightnes_ > 100)) {
        throw std::string("The index of brightnes isn't in the range 0-100");
    } else {
        value_brightnes = (uint16_t) value_brightnes_;
    }
}

bool operator==(const HSBHSVSpace &hsb_hsv_space_left,
                const HSBHSVSpace &hsb_hsv_space_right) {
    if (&hsb_hsv_space_left == &hsb_hsv_space_right) {
        return true;
    } else {
        return ((hsb_hsv_space_left.hue == hsb_hsv_space_right.hue) &&
            (hsb_hsv_space_left.saturation == hsb_hsv_space_right.saturation) &&
            (hsb_hsv_space_left.value_brightnes ==
                hsb_hsv_space_right.value_brightnes));
    }
}

bool operator!=(const HSBHSVSpace &hsb_hsv_space_left,
                const HSBHSVSpace &hsb_hsv_space_right) {
    return !(hsb_hsv_space_left == hsb_hsv_space_right);
}
