// Copyright 2017 Nesterov Alexander

#ifndef MODULES_COLOR_SPACES_INCLUDE_XYZ_SPACE_H_
#define MODULES_COLOR_SPACES_INCLUDE_XYZ_SPACE_H_
#include <stdint.h>
#include <algorithm>
#include "../include/lab_space.h"

class XYZSpace {
 public:
    XYZSpace();
    XYZSpace(const int x, const int y, const int z);
    XYZSpace(const XYZSpace &xyz_space);
    explicit XYZSpace(const LABSpace &lab_space);

    XYZSpace& operator=(const XYZSpace &xyz_space);

    uint8_t getX() const;
    uint8_t getY() const;
    uint8_t getZ() const;
    void setX(const int x);
    void setY(const int y);
    void setZ(const int z);

    friend bool operator==(const XYZSpace &xyz_space_left,
                           const XYZSpace &xyz_space_right);
    friend bool operator!=(const XYZSpace &xyz_space_left,
                           const XYZSpace &xyz_space_right);

    operator LABSpace() const { return ToLABSpace(); }

 private:
    uint8_t x_;
    uint8_t y_;
    uint8_t z_;
    void swap(XYZSpace &xyz_space);
    LABSpace ToLABSpace() const;
};
#endif  // MODULES_COLOR_SPACES_INCLUDE_XYZ_SPACE_H_
