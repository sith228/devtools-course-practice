// Copyright 2017 Nesterov Alexander

#ifndef MODULES_COLOR_SPACES_INCLUDE_LAB_SPACE_H_
#define MODULES_COLOR_SPACES_INCLUDE_LAB_SPACE_H_
#include <stdint.h>
#include <algorithm>

class LABSpace {
 private:
    uint8_t lightness;
    uint8_t a;
    uint8_t b;
    void swap(LABSpace &lab_space);

 public:
    LABSpace(): lightness(0), a(0), b(0) {}
    LABSpace(const int lightness_, const int a_, const int b_);
    LABSpace(const LABSpace &lab_space);

    LABSpace& operator=(const LABSpace &lab_space);

    uint8_t GetLightness() const;
    uint8_t GetA() const;
    uint8_t GetB() const;
    void SetLightness(const int lightness_);
    void SetA(const int a_);
    void SetB(const int b_);

    friend bool operator==(const LABSpace &lab_space_left,
                           const LABSpace &lab_space_right);
    friend bool operator!=(const LABSpace &lab_space_left,
                           const LABSpace &lab_space_right);
};

#endif  // MODULES_COLOR_SPACES_INCLUDE_LAB_SPACE_H_
