// Copyright 2017 Nesterov Alexander

#ifndef MODULES_COLOR_SPACES_INCLUDE_LAB_SPACE_H_
#define MODULES_COLOR_SPACES_INCLUDE_LAB_SPACE_H_
#include <stdint.h>
#include <algorithm>

class LABSpace {
 public:
    LABSpace(): lightness_(0), a_(0), b_(0) {}
    LABSpace(const int lightness, const int a, const int b);
    LABSpace(const LABSpace &lab_space);

    LABSpace& operator=(const LABSpace &lab_space);

    uint8_t getLightness() const;
    uint8_t getA() const;
    uint8_t getB() const;
    void setLightness(const int lightness);
    void setA(const int a);
    void setB(const int b);

    friend bool operator==(const LABSpace &lab_space_left,
                           const LABSpace &lab_space_right);
    friend bool operator!=(const LABSpace &lab_space_left,
                           const LABSpace &lab_space_right);

 private:
    uint8_t lightness_;
    uint8_t a_;
    uint8_t b_;
    void swap(LABSpace &lab_space);
};

#endif  // MODULES_COLOR_SPACES_INCLUDE_LAB_SPACE_H_
