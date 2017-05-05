// Copyright 2017 Nesterov Alexander

#include "../include/xyz_space.h"
#include <stdint.h>
#include <string>
#include <algorithm>

void XYZSpace::swap(XYZSpace &xyz_space) {
    std::swap(x, xyz_space.x);
    std::swap(y, xyz_space.y);
    std::swap(z, xyz_space.z);
}

XYZSpace::XYZSpace(const int x_,
                   const int y_,
                   const int z_) {
    if ((x_ < 0) || (x_ > 95)) {
        throw std::string("The index of x isn't in the range 0-95");
    } else if ((y_ < 0) || (y_ > 100)) {
        throw std::string("The index of y isn't in the range 0-100");
    } else if ((z_ < 0) || (z_ > 108)) {
        throw std::string("The index of z isn't in the range 0-108");
    } else {
        x = (uint8_t) x_;
        y = (uint8_t) y_;
        z = (uint8_t) z_;
    }
}

XYZSpace::XYZSpace(const XYZSpace &xyz_space) {
    x = xyz_space.x;
    y = xyz_space.y;
    z = xyz_space.z;
}

XYZSpace& XYZSpace::operator=(const XYZSpace &xyz_space) {
    if (this != &xyz_space) {
        XYZSpace(xyz_space).swap(*this);
    }
    return *this;
}

uint8_t XYZSpace::GetX() const {
    return x;
}

uint8_t XYZSpace::GetY() const {
    return y;
}

uint8_t XYZSpace::GetZ() const {
    return z;
}

void XYZSpace::SetX(const int x_) {
    if ((x_ < 0) || (x_ > 95)) {
        throw std::string("The index of x isn't in the range 0-95");
    } else {
        x = (uint8_t) x_;
    }
}

void XYZSpace::SetY(const int y_) {
    if ((y_ < 0) || (y_ > 100)) {
        throw std::string("The index of y isn't in the range 0-100");
    }  else {
        y = (uint8_t) y_;
    }
}

void XYZSpace::SetZ(const int z_) {
    if ((z_ < 0) || (z_ > 108)) {
        throw std::string("The index of z isn't in the range 0-108");
    } else {
        z = (uint8_t) z_;
    }
}

bool operator==(const XYZSpace &xyz_space_left,
                const XYZSpace &xyz_space_right) {
    if (&xyz_space_left == &xyz_space_right) {
        return true;
    } else {
        return ((xyz_space_left.x == xyz_space_right.x) &&
            (xyz_space_left.y == xyz_space_right.y) &&
            (xyz_space_left.z == xyz_space_right.z));
    }
}

bool operator!=(const XYZSpace &xyz_space_left,
                const XYZSpace &xyz_space_right) {
    return !(xyz_space_left == xyz_space_right);
}
