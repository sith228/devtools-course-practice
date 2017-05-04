// Copyright 2017 Nesterov Alexander

#ifndef MODULES_COLOR_SPACES_INCLUDE_HSB_HSV_SPACE_H_
#define MODULES_COLOR_SPACES_INCLUDE_HSB_HSV_SPACE_H_

#include <sys/types.h>
#include <algorithm>

class HSBHSVSpace {
 private:
    __uint16_t hue;
    __uint16_t saturation;
    __uint16_t value_brightnes;
    void swap(HSBHSVSpace &hsb_hsv_space);

 public:
    HSBHSVSpace(): hue(0), saturation(0), value_brightnes(0) {}
    HSBHSVSpace(const int hue_, const int saturation_,
                const int value_brightnes_);
    HSBHSVSpace(const HSBHSVSpace &hsb_hsv_space);

    HSBHSVSpace& operator=(const HSBHSVSpace &hsb_hsv_space);

    __uint16_t GetHue() const;
    __uint16_t GetSaturation() const;
    __uint16_t GetValueBrightnes() const;
    void SetHue(const int hue_);
    void SetSaturation(const int saturation_);
    void SetValueBrightnes(const int value_brightnes_);

    friend bool operator==(const HSBHSVSpace &hsb_hsv_space_left,
                           const HSBHSVSpace &hsb_hsv_space_right);
    friend bool operator!=(const HSBHSVSpace &hsb_hsv_space_left,
                           const HSBHSVSpace &hsb_hsv_space_right);
};

#endif  // MODULES_COLOR_SPACES_INCLUDE_HSB_HSV_SPACE_H_
