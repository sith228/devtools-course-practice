// Copyright 2017 Nesterov Alexander

#ifndef MODULES_COLOR_SPACES_INCLUDE_XYZ_SPACE_H_
#define MODULES_COLOR_SPACES_INCLUDE_XYZ_SPACE_H_
#include <stdint.h>
#include <algorithm>
#include "../include/lab_space.h"

class XYZSpace {
 private:
    uint8_t x;
    uint8_t y;
    uint8_t z;
    void swap(XYZSpace &xyz_space);
    LABSpace ToLABSpace() const;

 public:
    XYZSpace(): x(0), y(0), z(0) {}
    XYZSpace(const int x_, const int y_, const int z_);
    XYZSpace(const XYZSpace &xyz_space);
    explicit XYZSpace(const LABSpace &lab_space);

    XYZSpace& operator=(const XYZSpace &xyz_space);

    uint8_t GetX() const;
    uint8_t GetY() const;
    uint8_t GetZ() const;
    void SetX(const int x_);
    void SetY(const int y_);
    void SetZ(const int z_);

    friend bool operator==(const XYZSpace &xyz_space_left,
                           const XYZSpace &xyz_space_right);
    friend bool operator!=(const XYZSpace &xyz_space_left,
                           const XYZSpace &xyz_space_right);

    operator LABSpace() const { return ToLABSpace(); }
};
#endif  // MODULES_COLOR_SPACES_INCLUDE_XYZ_SPACE_H_
