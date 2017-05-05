// Copyright 2017 Nesterov Alexander

#include "../include/lab_space.h"

#include <stdint.h>
#include <string>
#include <algorithm>

void LABSpace::swap(LABSpace &lab_space) {
    std::swap(lightness, lab_space.lightness);
    std::swap(a, lab_space.a);
    std::swap(b, lab_space.b);
}

LABSpace::LABSpace(const int lightness_,
                   const int a_,
                   const int b_) {
    if ((lightness_ < 0) || (lightness_ > 100)) {
        throw std::string("The index of lightness isn't in the range 0-100");
    } else if ((a_ < 0) || (a_ > 128)) {
        throw std::string("The index of a color isn't in the range 0-128");
    } else if ((b_ < 0) || (b_ > 128)) {
        throw std::string("The index of b color isn't in the range 0-128");
    } else {
        lightness = (uint8_t) lightness_;
        a = (uint8_t) a_;
        b = (uint8_t) b_;
    }
}

LABSpace::LABSpace(const LABSpace &lab_space) {
    lightness = lab_space.lightness;
    a = lab_space.a;
    b = lab_space.b;
}

LABSpace& LABSpace::operator=(const LABSpace &lab_space) {
    if (this != &lab_space) {
        LABSpace(lab_space).swap(*this);
    }
    return *this;
}

uint8_t LABSpace::GetLightness() const {
    return lightness;
}

uint8_t LABSpace::GetA() const {
    return a;
}

uint8_t LABSpace::GetB() const {
    return b;
}

void LABSpace::SetLightness(const int lightness_) {
    if ((lightness_ < 0) || (lightness_ > 100)) {
        throw std::string("The index of lightness isn't in the range 0-100");
    } else {
        lightness = (uint8_t) lightness_;
    }
}

void LABSpace::SetA(const int a_) {
    if ((a_ < 0) || (a_ > 128)) {
        throw std::string("The index of a color isn't in the range 0-128");
    }  else {
        a = (uint8_t) a_;
    }
}

void LABSpace::SetB(const int b_) {
    if ((b_ < 0) || (b_ > 128)) {
        throw std::string("The index of b color isn't in the range 0-128");
    } else {
        b = (uint8_t) b_;
    }
}

bool operator==(const LABSpace &lab_space_left,
                const LABSpace &lab_space_right) {
    if (&lab_space_left == &lab_space_right) {
        return true;
    } else {
        return ((lab_space_left.lightness == lab_space_right.lightness) &&
            (lab_space_left.a == lab_space_right.a) &&
            (lab_space_left.b == lab_space_right.b));
    }
}

bool operator!=(const LABSpace &lab_space_left,
                const LABSpace &lab_space_right) {
    return !(lab_space_left == lab_space_right);
}
