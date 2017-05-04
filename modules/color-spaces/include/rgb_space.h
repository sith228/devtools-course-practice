// Copyright 2017 Nesterov Alexander
#ifndef MODULES_COLOR_SPACES_INCLUDE_RGB_SPACE_H_
#define MODULES_COLOR_SPACES_INCLUDE_RGB_SPACE_H_
#include <sys/types.h>
#include <algorithm>


class RGBSpace {
 private:
    __uint8_t red;
    __uint8_t green;
    __uint8_t blue;
    void swap(RGBSpace &rgb_space);

 public:
    RGBSpace(): red(0), green(0), blue(0) {}
    RGBSpace(const int red_, const int green_, const int blue_);
    RGBSpace(const RGBSpace &rgb_space);

    RGBSpace& operator=(const RGBSpace &rgb_space);

    __uint8_t GetRed() const;
    __uint8_t GetGreen() const;
    __uint8_t GetBlue() const;
    void SetRed(const int red_);
    void SetGreen(const int green_);
    void SetBlue(const int blue_);

    friend bool operator==(const RGBSpace &rgb_space_left,
                           const RGBSpace &rgb_space_right);
    friend bool operator!=(const RGBSpace &rgb_space_left,
                           const RGBSpace &rgb_space_right);
};

#endif  // MODULES_COLOR_SPACES_INCLUDE_RGB_SPACE_H_
