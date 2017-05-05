// Copyright 2017 Nesterov Alexander

#include "../include/xyz_space.h"
#include <math.h>
#include <stdint.h>
#include <string>
#include <algorithm>


void XYZSpace::swap(XYZSpace &xyz_space) {
    std::swap(x, xyz_space.x);
    std::swap(y, xyz_space.y);
    std::swap(z, xyz_space.z);
}

LABSpace XYZSpace::ToLABSpace() const {
    double x_quote = static_cast<double>(x) / 95.05;
    double y_quote = static_cast<double>(y) / 100;
    double z_quote = static_cast<double>(z) / 108.9;

    if (x_quote > 0.008856) {
        x_quote = pow(x_quote, 1.0/3);
    } else {
        x_quote = (7.787 * x_quote) + (16.0/116);
    }

    if (y_quote > 0.008856) {
        y_quote = pow(y_quote, 1.0/3);
    } else {
        y_quote = (7.787 * y_quote) + (16.0/116);
    }

    if (z_quote > 0.008856) {
        z_quote = pow(z_quote, 1.0/3);
    } else {
        z_quote = (7.787 * z_quote) + (16.0/116);
    }

    uint8_t lightness = static_cast<uint8_t>(round((116.0*y_quote)-16.0));
    uint8_t a = static_cast<uint8_t>(round(500.0 * (x_quote - y_quote)));
    uint8_t b = static_cast<uint8_t>(round(200.0 * (y_quote - z_quote)));

    LABSpace lab_space(lightness, a, b);
    return lab_space;
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

XYZSpace::XYZSpace(const LABSpace &lab_space) {
    double y_quote =
        ((static_cast<double>(lab_space.GetLightness())) + 16.0) / 116.0;
    double x_quote =
        static_cast<double>(lab_space.GetA()) / 500 + y_quote;
    double z_quote =
        y_quote - static_cast<double>(lab_space.GetB()) / 200;

    if (pow(y_quote, 3.0) > 0.008856) {
        y_quote = pow(y_quote, 3.0);
    } else {
        y_quote = (y_quote - 16.0/116) / 7.787;
    }

    if (pow(x_quote, 3.0) > 0.008856) {
        x_quote = pow(y_quote, 3.0);
    } else {
        x_quote = (x_quote - 16.0/116) / 7.787;
    }

    if (pow(z_quote, 3.0) > 0.008856) {
        z_quote = pow(z_quote, 3.0);
    } else {
        z_quote = (z_quote - 16.0/116) / 7.787;
    }

    x = static_cast<uint8_t>((x_quote * 95.05));
    y = static_cast<uint8_t>((y_quote * 100));
    z = static_cast<uint8_t>((z_quote * 108.9));
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
