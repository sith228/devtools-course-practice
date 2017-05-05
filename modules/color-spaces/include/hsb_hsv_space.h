// Copyright 2017 Nesterov Alexander

#ifndef MODULES_COLOR_SPACES_INCLUDE_HSB_HSV_SPACE_H_
#define MODULES_COLOR_SPACES_INCLUDE_HSB_HSV_SPACE_H_

#include <stdint.h>
#include <algorithm>

class HSBHSVSpace {
 public:
    HSBHSVSpace(): hue_(0), saturation_(0), value_brightnes_(0) {}
    HSBHSVSpace(const int hue, const int saturation,
                const int value_brightnes);
    HSBHSVSpace(const HSBHSVSpace &hsb_hsv_space);

    HSBHSVSpace& operator=(const HSBHSVSpace &hsb_hsv_space);

    uint16_t getHue() const;
    uint16_t getSaturation() const;
    uint16_t getValueBrightnes() const;
    void setHue(const int hue);
    void setSaturation(const int saturation);
    void setValueBrightnes(const int value_brightnes);

    friend bool operator==(const HSBHSVSpace &hsb_hsv_space_left,
                           const HSBHSVSpace &hsb_hsv_space_right);
    friend bool operator!=(const HSBHSVSpace &hsb_hsv_space_left,
                           const HSBHSVSpace &hsb_hsv_space_right);

 private:
    uint16_t hue_;
    uint16_t saturation_;
    uint16_t value_brightnes_;
    void swap(HSBHSVSpace &hsb_hsv_space);
};

#endif  // MODULES_COLOR_SPACES_INCLUDE_HSB_HSV_SPACE_H_
