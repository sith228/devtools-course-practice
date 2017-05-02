// Copyright 2017 Nesterov Alexander

#include "../include/rgb_space.h"
#include <string>
#include <algorithm>

void RGBSpace::swap(RGBSpace &rgb_space) {
    std::swap(red, rgb_space.red);
    std::swap(green, rgb_space.green);
    std::swap(blue, rgb_space.blue);
}

RGBSpace::RGBSpace(const uint8_t red_,
                   const uint8_t green_,
                   const uint8_t blue_) {
    if ((red_ < 0) && (red_ > 255)) {
        throw std::string("The index of red color isn't in the range 0-255");
    } else if ((green_ < 0) && (green_ > 255)) {
        throw std::string("The index of red color isn't in the range 0-255");
    } else if ((blue_ < 0) && (blue_ > 255)) {
        throw std::string("The index of red color isn't in the range 0-255");
    } else {
        red = red_;
        green = green_;
        blue = blue_;
    }
}

RGBSpace::RGBSpace(const RGBSpace &rgb_space) {
    if (&rgb_space == nullptr) {
        throw std::string("Copying object is nullptr");
    } else {
        red = rgb_space.red;
        green = rgb_space.green;
        blue = rgb_space.blue;
    }
}

RGBSpace& RGBSpace::operator=(const RGBSpace &rgb_space) {
    if ((&rgb_space != nullptr) && (this != &rgb_space)) {
        RGBSpace(RGBSpace).swap(*this);
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

void RGBSpace::SetRed(const uint8_t red_) {
    red = red_;
}

void RGBSpace::SetGreen(const uint8_t green_) {
    green = green_;
}

void RGBSpace::SetBlue(const uint8_t blue_) {
    blue = blue_;
}

bool operator==(const RGBSpace &rgb_space_left,
                const RGBSpace &rgb_space_right) const {
    return ((rgb_space_left.red == rgb_space_right.red) &&
            (rgb_space_left.green == rgb_space_right.green) &&
            (rgb_space_left.blue == rgb_space_right.blue));
}

bool operator!=(const RGBSpace &rgb_space_left,
                const RGBSpace &rgb_space_right) const {
    return !(rgb_space_left == rgb_space_right);
}
