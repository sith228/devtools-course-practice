// Copyright 2017 Nesterov Alexander
#ifndef MODULES_COLOR_SPACES_INCLUDE_RGB_SPACE_H_
#define MODULES_COLOR_SPACES_INCLUDE_RGB_SPACE_H_
#include <stdint.h>
#include <algorithm>
#include "../include/hsb_hsv_space.h"
#include "../include/xyz_space.h"


class RGBSpace {
 public:
    RGBSpace(): red_(0), green_(0), blue_(0) {}
    RGBSpace(const int red, const int green, const int blue);
    RGBSpace(const RGBSpace &rgb_space);
    explicit RGBSpace(const HSBHSVSpace &hsbhsv_space);
    explicit RGBSpace(const XYZSpace &xyz_space);

    RGBSpace& operator=(const RGBSpace &rgb_space);

    uint8_t getRed() const;
    uint8_t getGreen() const;
    uint8_t getBlue() const;
    void setRed(const int red_);
    void setGreen(const int green_);
    void setBlue(const int blue_);

    friend bool operator==(const RGBSpace &rgb_space_left,
                           const RGBSpace &rgb_space_right);
    friend bool operator!=(const RGBSpace &rgb_space_left,
                           const RGBSpace &rgb_space_right);

    operator HSBHSVSpace() const { return ToHSBHSVSpace(); }
    operator XYZSpace() const { return ToXYZSpace(); }

 private:
    uint8_t red_;
    uint8_t green_;
    uint8_t blue_;
    void swap(RGBSpace &rgb_space);
    HSBHSVSpace ToHSBHSVSpace() const;
    XYZSpace ToXYZSpace() const;
};

#endif  // MODULES_COLOR_SPACES_INCLUDE_RGB_SPACE_H_
