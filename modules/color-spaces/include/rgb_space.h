// Copyright 2017 Nesterov Alexander
#ifndef MODULES_COLOR_SPACES_INCLUDE_RGB_SPACE_H_
#define MODULES_COLOR_SPACES_INCLUDE_RGB_SPACE_H_
#include <stdint.h>
#include <algorithm>
#include "../include/lab_space.h"
#include "../include/hsb_hsv_space.h"
#include "../include/xyz_space.h"


class RGBSpace {
 private:
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    void swap(RGBSpace &rgb_space);
    HSBHSVSpace ToHSBHSVSpace() const;
    XYZSpace ToXYZSpace() const;
    LABSpace ToLABSpace() const;


 public:
    RGBSpace(): red(0), green(0), blue(0) {}
    RGBSpace(const int red_, const int green_, const int blue_);
    RGBSpace(const RGBSpace &rgb_space);

    RGBSpace& operator=(const RGBSpace &rgb_space);

    uint8_t GetRed() const;
    uint8_t GetGreen() const;
    uint8_t GetBlue() const;
    void SetRed(const int red_);
    void SetGreen(const int green_);
    void SetBlue(const int blue_);

    friend bool operator==(const RGBSpace &rgb_space_left,
                           const RGBSpace &rgb_space_right);
    friend bool operator!=(const RGBSpace &rgb_space_left,
                           const RGBSpace &rgb_space_right);

    operator HSBHSVSpace() const { return ToHSBHSVSpace(); }
    operator XYZSpace() const { return ToXYZSpace(); }
    operator LABSpace() const { return ToLABSpace(); }
};

#endif  // MODULES_COLOR_SPACES_INCLUDE_RGB_SPACE_H_
