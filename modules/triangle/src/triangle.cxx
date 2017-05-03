// Copyright 2017 Karev Boris

#include "include/triangle.h"
#include <string>
#include <cmath>

Triangle::Triangle() : point1_coordx_(0), point1_coordy_(0),
point2_coordx_(0), point2_coordy_(1), point3_coordx_(1), point3_coordy_(0) {}

Triangle::Triangle(const double point1_coordx, const double point1_coordy,
    const double point2_coordx, const double point2_coordy,
    const double point3_coordx, const double point3_coordy)
    : point1_coordx_(point1_coordx), point1_coordy_(point1_coordy),
    point2_coordx_(point2_coordx), point2_coordy_(point2_coordy),
    point3_coordx_(point3_coordx), point3_coordy_(point3_coordy) {
    if (!isTriangle(*this)) {
        throw std::string("These coordinates do not form a triangle");
    }
}

Triangle::Triangle(const Triangle& t) :
point1_coordx_(t.Get_coordX_point(1)), point1_coordy_(t.Get_coordY_point(1)),
point2_coordx_(t.Get_coordX_point(2)), point2_coordy_(t.Get_coordY_point(2)),
point3_coordx_(t.Get_coordX_point(3)), point3_coordy_(t.Get_coordY_point(3)) {}

double Triangle::Get_coordX_point(const int number_point) const {
    if (number_point == 1) return point1_coordx_;
    if (number_point == 2) return point2_coordx_;
    if (number_point == 3) return point3_coordx_;
    throw std::string("Unknown number of point");
}

double Triangle::Get_coordY_point(const int number_point) const {
    if (number_point == 1) return point1_coordy_;
    if (number_point == 2) return point2_coordy_;
    if (number_point == 3) return point3_coordy_;
    throw std::string("Unknown number of point");
}

void Triangle::Set_coordX_point(const double x, const int number_point) {
    if (number_point == 1) point1_coordx_ = x;
    if (number_point == 2) point2_coordx_ = x;
    if (number_point == 3) point3_coordx_ = x;
    if ((number_point != 1) && (number_point != 2) && (number_point != 3))
        throw std::string("Unknown number of point");
    if (!isTriangle(*this)) {
        throw std::string("New coordinates do not form a triangle.");
    }
}

void Triangle::Set_coordY_point(const double y, const int number_point) {
    if (number_point == 1) point1_coordy_ = y;
    if (number_point == 2) point2_coordy_ = y;
    if (number_point == 3) point3_coordy_ = y;
    if ((number_point != 1) && (number_point != 2) && (number_point != 3))
        throw std::string("Unknown number of point");
    if (!isTriangle(*this)) {
        throw std::string("New coordinates do not form a triangle.");
    }
}

bool Triangle::isTriangle(const Triangle& t) const {
    double side1, side2, side3;
    side1 = sqrt(pow(point1_coordx_ - point2_coordx_, 2)
        + pow(point1_coordy_ - point2_coordy_, 2));
    side2 = sqrt(pow(point3_coordx_ - point2_coordx_, 2)
        + pow(point3_coordy_ - point2_coordy_, 2));
    side3 = sqrt(pow(point1_coordx_ - point3_coordx_, 2)
        + pow(point1_coordy_ - point3_coordy_, 2));
    return ((side1 < side2 + side3) &&
        (side2 < side1 + side3) && (side3 < side1 + side2));
}

bool Triangle::operator == (const Triangle& t) const {
    return ((point1_coordx_ == t.Get_coordX_point(1)) &&
        (point1_coordy_ == t.Get_coordY_point(1))
        && (point2_coordx_ == t.Get_coordX_point(2)) &&
        (point2_coordy_ == t.Get_coordY_point(2))
        && (point3_coordx_ == t.Get_coordX_point(3)) &&
        (point3_coordy_ == t.Get_coordY_point(3)));
}

bool Triangle::operator != (const Triangle& t) const {
    return !(*this == t);
}

double Triangle::Calculate_side(const int number_side) const {
    if (number_side == 1)
        return sqrt(pow(point3_coordx_ - point2_coordx_, 2)
        + pow(point3_coordy_ - point2_coordy_, 2));
    if (number_side == 2)
        return sqrt(pow(point1_coordx_ - point3_coordx_, 2)
        + pow(point1_coordy_ - point3_coordy_, 2));
    if (number_side == 3)
        return sqrt(pow(point1_coordx_ - point2_coordx_, 2)
        + pow(point1_coordy_ - point2_coordy_, 2));
    throw std::string("Unknown number of side");
}

double Triangle::Calculate_corner(const int number_corner) const {
    double s1, s2, s3;
    s1 = sqrt(pow(point1_coordx_ - point2_coordx_, 2)
        + pow(point1_coordy_ - point2_coordy_, 2));
    s2 = sqrt(pow(point3_coordx_ - point2_coordx_, 2)
        + pow(point3_coordy_ - point2_coordy_, 2));
    s3 = sqrt(pow(point1_coordx_ - point3_coordx_, 2)
        + pow(point1_coordy_ - point3_coordy_, 2));
    if (number_corner == 1)
        return acos((s1*s1 + s3*s3 - s2*s2) / (2 * s1*s3));
    if (number_corner == 2)
        return acos((s1*s1 + s2*s2 - s3*s3) / (2 * s1*s2));
    if (number_corner == 3)
        return acos((s2*s2 + s3*s3 - s1*s1) / (2 * s2*s3));
    throw std::string("Unknown number of corner");
}

double Triangle::Calculate_perimeter() const {
    double side1, side2, side3;
    side1 = sqrt(pow(point1_coordx_ - point2_coordx_, 2)
        + pow(point1_coordy_ - point2_coordy_, 2));
    side2 = sqrt(pow(point3_coordx_ - point2_coordx_, 2)
        + pow(point3_coordy_ - point2_coordy_, 2));
    side3 = sqrt(pow(point1_coordx_ - point3_coordx_, 2)
        + pow(point1_coordy_ - point3_coordy_, 2));
    return side1 + side2 + side3;
}

double Triangle::Calculate_square() const {
    double side1, side2, side3, per;
    side1 = sqrt(pow(point1_coordx_ - point2_coordx_, 2)
        + pow(point1_coordy_ - point2_coordy_, 2));
    side2 = sqrt(pow(point3_coordx_ - point2_coordx_, 2)
        + pow(point3_coordy_ - point2_coordy_, 2));
    side3 = sqrt(pow(point1_coordx_ - point3_coordx_, 2)
        + pow(point1_coordy_ - point3_coordy_, 2));
    per = (side1 + side2 + side3) / 2;
    return sqrt(per * (per - side1) * (per - side2) * (per - side3));
}

double Triangle::Get_coordX_median() const {
    return (point1_coordx_ + point2_coordx_ + point3_coordx_) / 3;
}

double Triangle::Get_coordY_median() const {
    return (point1_coordy_ + point2_coordy_ + point3_coordy_) / 3;
}
