// Copyright 2017 Nesterov Alexander

#include "../include/rgb_space.h"
#include <math.h>
#include <string>
#include <algorithm>

void RGBSpace::swap(RGBSpace &rgb_space) {
    std::swap(red, rgb_space.red);
    std::swap(green, rgb_space.green);
    std::swap(blue, rgb_space.blue);
}

HSBHSVSpace RGBSpace::ToHSBHSVSpace() const {
    double red_quote = static_cast<double>(red) / 255;
    double green_quote = static_cast<double>(green) / 255;
    double blue_quote = static_cast<double>(blue) / 255;

    double_t min = std::min(red_quote, std::min(green_quote, blue_quote));
    double_t max = std::max(red_quote, std::max(green_quote, blue_quote));

    uint16_t h = 0, s, v;
    if (max == min) {
        h = 0;
    } else if ((max == red_quote) && (green_quote >= blue_quote)) {
        h = static_cast<uint16_t>(round(
            60 * ((green_quote - blue_quote)/(max - min))));
    } else if ((max == red_quote) && (green_quote < blue_quote)) {
        h = static_cast<uint16_t>(round(
            60 * ((green_quote - blue_quote)/(max - min)) + 360));
    } else if (max == green_quote) {
        h = static_cast<uint16_t>(round(
            60 * ((blue_quote - red_quote)/(max - min)) + 120));
    } else if (max == blue_quote) {
        h = static_cast<uint16_t>(round(
            60 * ((red_quote - green_quote)/(max - min)) + 240));
    }

    s = (uint16_t) round((max == 0) ? 0 : (1 - min/max)*100);

    v = (uint16_t) round(max * 100);

    HSBHSVSpace hsbhsv_space(h, s, v);

    return hsbhsv_space;
}

XYZSpace RGBSpace::ToXYZSpace() const {
    double_t red_quote = static_cast<double_t >(red) / 255;
    double_t green_quote = static_cast<double_t >(green) / 255;
    double_t blue_quote = static_cast<double_t >(blue) / 255;

    if (red_quote > 0.04045) {
        red_quote = pow((red_quote + 0.055) / 1.055, 2.4);
    } else {
        red_quote /= 12.92;
    }

    if (green_quote > 0.04045) {
        green_quote = pow((green_quote + 0.055) / 1.055, 2.4);
    } else {
        green_quote /= 12.92;
    }

    if (blue_quote > 0.04045) {
        blue_quote = pow((blue_quote + 0.055) / 1.055, 2.4);
    } else {
        blue_quote /= 12.92;
    }

    red_quote *= 100;
    green_quote *= 100;
    blue_quote *= 100;

    uint8_t x = static_cast<uint8_t>(round(
        red_quote *0.4124564 + green_quote*0.3575761 + blue_quote*0.1804375));
    uint8_t y = static_cast<uint8_t>(round(
        red_quote *0.2126729 + green_quote*0.7151522 + blue_quote*0.0721750));
    uint8_t z = static_cast<uint8_t>(round(
        red_quote *0.0193339 + green_quote*0.1191920 + blue_quote*0.9503041));

    XYZSpace xyz_space(x, y, z);
    return xyz_space;
}

LABSpace RGBSpace::ToLABSpace() const {
    LABSpace lab_space;
    return lab_space;
}

RGBSpace::RGBSpace(const int red_,
                   const int green_,
                   const int blue_) {
    if ((red_ < 0) || (red_ > 255)) {
        throw std::string("The index of red color isn't in the range 0-255");
    } else if ((green_ < 0) || (green_ > 255)) {
        throw std::string("The index of green color isn't in the range 0-255");
    } else if ((blue_ < 0) || (blue_ > 255)) {
        throw std::string("The index of blue color isn't in the range 0-255");
    } else {
        red = static_cast<uint8_t>(red_);
        green = static_cast<uint8_t>(green_);
        blue = static_cast<uint8_t>(blue_);
    }
}

RGBSpace::RGBSpace(const RGBSpace &rgb_space) {
    red = rgb_space.red;
    green = rgb_space.green;
    blue = rgb_space.blue;
}

RGBSpace& RGBSpace::operator=(const RGBSpace &rgb_space) {
    if (this != &rgb_space) {
        RGBSpace(rgb_space).swap(*this);
    }
    return *this;
}

uint8_t RGBSpace::GetRed() const {
    return red;
}

uint8_t RGBSpace::GetGreen() const {
    return green;
}

uint8_t RGBSpace::GetBlue() const {
    return blue;
}

void RGBSpace::SetRed(const int red_) {
    if ((red_ < 0) || (red_ > 255)) {
        throw std::string("The index of red color isn't in the range 0-255");
    } else {
        red = static_cast<uint8_t>(red_);
    }
}

void RGBSpace::SetGreen(const int green_) {
    if ((green_ < 0) || (green_ > 255)) {
        throw std::string("The index of green color isn't in the range 0-255");
    }  else {
        green = static_cast<uint8_t>(green_);
    }
}

void RGBSpace::SetBlue(const int blue_) {
    if ((blue_ < 0) || (blue_ > 255)) {
        throw std::string("The index of blue color isn't in the range 0-255");
    } else {
        blue = static_cast<uint8_t>(blue_);
    }
}

bool operator==(const RGBSpace &rgb_space_left,
                const RGBSpace &rgb_space_right) {
    if (&rgb_space_left == &rgb_space_right) {
        return true;
    } else {
        return ((rgb_space_left.red == rgb_space_right.red) &&
            (rgb_space_left.green == rgb_space_right.green) &&
            (rgb_space_left.blue == rgb_space_right.blue));
    }
}

bool operator!=(const RGBSpace &rgb_space_left,
                const RGBSpace &rgb_space_right) {
    return !(rgb_space_left == rgb_space_right);
}
