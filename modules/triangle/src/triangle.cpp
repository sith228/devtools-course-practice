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
    if (!isTriangle()) {
        point1_coordx_ = 0;
        point1_coordy_ = 0;
        point2_coordx_ = 0;
        point2_coordy_ = 1;
        point3_coordx_ = 1;
        point3_coordy_ = 0;
        throw
          std::string(
          "These coordinates do not form a triangle.Created default triangle");
    }
}

Triangle::Triangle(const Triangle& t) :
point1_coordx_(t.GetCoordxPoint(1)), point1_coordy_(t.GetCoordyPoint(1)),
point2_coordx_(t.GetCoordxPoint(2)), point2_coordy_(t.GetCoordyPoint(2)),
point3_coordx_(t.GetCoordxPoint(3)), point3_coordy_(t.GetCoordyPoint(3)) {}

double Triangle::GetCoordxPoint(const int number_point) const {
    double result_coord = 0;
    if (number_point == 1) result_coord = point1_coordx_;
    if (number_point == 2) result_coord = point2_coordx_;
    if (number_point == 3) result_coord = point3_coordx_;
    if ((number_point != 1) && (number_point != 2) && (number_point != 3))
        throw std::string("Unknown number of point");
    return result_coord;
}

double Triangle::GetCoordyPoint(const int number_point) const {
    double result_coord = 0;
    if (number_point == 1) result_coord = point1_coordy_;
    if (number_point == 2) result_coord = point2_coordy_;
    if (number_point == 3) result_coord = point3_coordy_;
    if ((number_point != 1) && (number_point != 2) && (number_point != 3))
        throw std::string("Unknown number of point");
    return result_coord;
}

void Triangle::SetCoordxPoint(const double x, const int number_point) {
    double copy_coord = 0;
    if (number_point == 1) {
        copy_coord = point1_coordx_;
        point1_coordx_ = x;
    }
    if (number_point == 2) {
        copy_coord = point2_coordx_;
        point2_coordx_ = x;
    }
    if (number_point == 3) {
        copy_coord = point3_coordx_;
        point3_coordx_ = x;
    }
    if ((number_point != 1) && (number_point != 2) && (number_point != 3))
        throw std::string("Unknown number of point");
    if (!isTriangle()) {
        SetCoordxPoint(copy_coord, number_point);
        throw std::string("New coordinates do not form a triangle.");
    }
}

void Triangle::SetCoordyPoint(const double y, const int number_point) {
    double copy_coord = 0;
    if (number_point == 1) {
        copy_coord = point1_coordy_;
        point1_coordy_ = y;
    }
    if (number_point == 2) {
        copy_coord = point2_coordy_;
        point2_coordy_ = y;
    }
    if (number_point == 3) {
        copy_coord = point3_coordy_;
        point3_coordy_ = y;
    }
    if ((number_point != 1) && (number_point != 2) && (number_point != 3))
        throw std::string("Unknown number of point");
    if (!isTriangle()) {
        SetCoordyPoint(copy_coord, number_point);
        throw std::string("New coordinates do not form a triangle.");
    }
}

bool Triangle::isTriangle() const {
    double side1, side2, side3;
    side1 = CalculateSide(1);
    side2 = CalculateSide(2);
    side3 = CalculateSide(3);
    return ((side1 < side2 + side3) &&
        (side2 < side1 + side3) && (side3 < side1 + side2));
}

bool Triangle::operator == (const Triangle& t) const {
    return ((point1_coordx_ == t.GetCoordxPoint(1)) &&
        (point1_coordy_ == t.GetCoordyPoint(1))
        && (point2_coordx_ == t.GetCoordxPoint(2)) &&
        (point2_coordy_ == t.GetCoordyPoint(2))
        && (point3_coordx_ == t.GetCoordxPoint(3)) &&
        (point3_coordy_ == t.GetCoordyPoint(3)));
}

bool Triangle::operator != (const Triangle& t) const {
    return !(*this == t);
}

double Triangle::CalculateSide(const int number_side) const {
    double result_side = 0;
    if (number_side == 1)
        result_side = sqrt(pow(point3_coordx_ - point2_coordx_, 2)
        + pow(point3_coordy_ - point2_coordy_, 2));
    if (number_side == 2)
        result_side = sqrt(pow(point1_coordx_ - point3_coordx_, 2)
        + pow(point1_coordy_ - point3_coordy_, 2));
    if (number_side == 3)
        result_side = sqrt(pow(point1_coordx_ - point2_coordx_, 2)
        + pow(point1_coordy_ - point2_coordy_, 2));
    if ((number_side != 1) && (number_side != 2) && (number_side != 3))
        throw std::string("Unknown number of side");
    return result_side;
}

double Triangle::CalculateCorner(const int number_corner) const {
    double result_corner = 0;
    double side1, side2, side3;
    side1 = CalculateSide(1);
    side2 = CalculateSide(2);
    side3 = CalculateSide(3);
    if (number_corner == 1)
        result_corner =
        acos((side2*side2 + side3*side3 - side1*side1) / (2 * side2*side3));
    if (number_corner == 2)
        result_corner =
        acos((side1*side1 + side3*side3 - side2*side2) / (2 * side1*side3));
    if (number_corner == 3)
        result_corner =
        acos((side2*side2 + side1*side1 - side3*side3) / (2 * side2*side1));
    if ((number_corner != 1) && (number_corner != 2) && (number_corner != 3))
        throw std::string("Unknown number of corner");
    return result_corner;
}

double Triangle::CalculatePerimeter() const {
    double side1, side2, side3;
    side1 = CalculateSide(1);
    side2 = CalculateSide(2);
    side3 = CalculateSide(3);
    return side1 + side2 + side3;
}

double Triangle::CalculateSquare() const {
    double side1, side2, side3, per;
    side1 = CalculateSide(1);
    side2 = CalculateSide(2);
    side3 = CalculateSide(3);
    per = (side1 + side2 + side3) / 2;
    return sqrt(per * (per - side1) * (per - side2) * (per - side3));
}

double Triangle::GetCoordxMedian() const {
    return (point1_coordx_ + point2_coordx_ + point3_coordx_) / 3;
}

double Triangle::GetCoordyMedian() const {
    return (point1_coordy_ + point2_coordy_ + point3_coordy_) / 3;
}
