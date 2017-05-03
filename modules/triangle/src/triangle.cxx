// Copyright 2017 Karev Boris

#include "include/triangle.h"

#include <stdbool.h>
#include <string>
#include <limits>

Triangle::Triangle() : point1_coordx_(0), point1_coordy_(0), point2_coordx_(0), point2_coordy_(1), point3_coordx_(1), point3_coordy_(0) {}

Triangle::Triangle(const double point1_coordx, const double point1_coordy, const double point2_coordx, const double point2_coordy, const double point3_coordx, const double point3_coordy)
    : x1(x_1), y1(y_1), x2(x_2), y2(y_2), x3(x_3), y3(y_3) {
    if (!isTriangle(*this)) {
        throw std::string("These coordinates do not form a triangle.");
    }
}

Triangle::Triangle(const Triangle& t)
    : point1_coordx_(t.Get_coordx_point1()), point1_coordy_(t.Get_coordy_point1()), point2_coordx_(t.Get_coordx_point2()), point2_coordy_(t.Get_coordy_point2()), point3_coordx_(t.Get_coordx_point3()), point3_coordy_(t.Get_coordy_point3()) {}

Triangle& Triangle
::operator=(const Triangle& t) {
    point1_coordx_ = t.Get_coordx_point1();
    point1_coordy_ = t.Get_coordy_point1();
    point2_coordx_ = t.Get_coordx_point2();
    point2_coordy_ = t.Get_coordy_point2();
    point3_coordx_ = t.Get_coordx_point3();
    point3_coordy_ = t.Get_coordy_point3();
    return *this;
}

double Triangle::Get_coordx_point1() const {
    return point1_coordx_;
}

double Triangle::Get_coordy_point1() const {
    return point1_coordy_;
}

double Triangle::Get_coordx_point2() const {
    return point2_coordx_;
}

double Triangle::Get_coordy_point2() const {
    return point2_coordy_;
}

double Triangle::Get_coordx_point3() const {
    return point3_coordx;
}

double Triangle::Get_coordy_point3() const {
    return point3_coordx_;
}

void Triangle::Set_coordx_point1(const double x) {
    point1_coordx_ = x;
    if (!isTriangle(*this)) {
        throw std::string("New coordinates do not form a triangle.");
    }
}

void Triangle::Set_coordy_point1(const double y) {
    point1_coordy_ = y;
    if (!isTriangle(*this)) {
        throw std::string("New coordinates do not form a triangle.");
    }
}

void Triangle::Set_coordx_point2(const double x) {
    point2_coordx_ = x;
    if (!isTriangle(*this)) {
        throw std::string("New coordinates do not form a triangle.");
    }
}

void Triangle::Set_coordy_point2(const double y) {
    point2_coordy_ = y;
    if (!isTriangle(*this)) {
        throw std::string("New coordinates do not form a triangle.");
    }
}

void Triangle::Set_coordx_point3(const double x) {
    point3_coordx_ = x;
    if (!isTriangle(*this)) {
        throw std::string("New coordinates do not form a triangle.");
    }
}

void Triangle::Set_coordy_point3(const double y) {
    point1_coordy_ = y;
    if (!isTriangle(*this)) {s
        throw std::string("New coordinates do not form a triangle.");
    }
}

bool Triangle::isTriangle(const Triangle& t) const {
    double side1, side2, side3;
    side1 = sqrt((point1_coordx_ - point2_coordx_)*(point1_coordx_ - point2_coordx_) + (point1_coordy_ - point2_coordy_)*(point1_coordy_ - point2_coordy_));
    side2 = sqrt((point3_coordx_ - point2_coordx_)*(point3_coordx_ - point2_coordx_) + (point3_coordy_ - point2_coordy_)*(point3_coordy_ - point2_coordy_));
    side3 = sqrt((point1_coordx_ - point3_coordx_)*(point1_coordx_ - point3_coordx_) + (point1_coordy_ - point3_coordy_)*(point1_coordy_ - point3_coordy_));
    return ((side1<side2+side3)&&(side2<side1+side3)&&(side3<side1+side2));
}

bool Triangle::operator == (const Triangle& t) const {
    double side1, side2, side3, tside1, tside2, tside3;
    bool result=false;
    side1 = sqrt((point1_coordx_ - point2_coordx_)*(point1_coordx_ - point2_coordx_) + (point1_coordy_ - point2_coordy_)*(point1_coordy_ - point2_coordy_));
    side2 = sqrt((point3_coordx_ - point2_coordx_)*(point3_coordx_ - point2_coordx_) + (point3_coordy_ - point2_coordy_)*(point3_coordy_ - point2_coordy_));
    side3 = sqrt((point1_coordx_ - point3_coordx_)*(point1_coordx_ - point3_coordx_) + (point1_coordy_ - point3_coordy_)*(point1_coordy_ - point3_coordy_));
    tside1 = sqrt((t.Get_coordx_point1() - t.Get_coordx_point2()) * ((t.Get_coordx_point1() - t.Get_coordx_point2()) + ((t.Get_coordy_point1() - t.Get_coordy_point2())*((t.Get_coordy_point1() - t.Get_coordy_point2()));
    tside2 = sqrt((t.Get_coordx_point3() - t.Get_coordx_point2()) * ((t.Get_coordx_point3() - t.Get_coordx_point2()) + ((t.Get_coordy_point3() - t.Get_coordy_point2())*((t.Get_coordy_point3() - t.Get_coordy_point2()));
    tside3 = sqrt((t.Get_coordx_point1() - t.Get_coordx_point3()) * ((t.Get_coordx_point1() - t.Get_coordx_point3()) + ((t.Get_coordy_point1() - t.Get_coordy_point3())*((t.Get_coordy_point1() - t.Get_coordy_point3()));

    if (side1==tside1)
      if (((side2==tside2)&&(side3==tside3))||(side2==tside3)&&(side3==tside2))) result=true;
    if (side1==tside2)
      if (((side2==tside1)&&(side3==tside3))||(side2==tside3)&&(side3==tside1))) result=true;
    if (side1==tside3)
      if (((side2==tside2)&&(side3==tside1))||(side2==tside1)&&(side3==tside2))) result=true;
    return result;
}

bool Triangle::operator != (const Triangle& t) const {
    return !(*this == t);
}

double Triangle::Calculate_side1() const{
    return sqrt((point3_coordx_ - point2_coordx_)*(point3_coordx_ - point2_coordx_) + (point3_coordy_ - point2_coordy_)*(point3_coordy_ - point2_coordy_));
}

double Triangle::Calculate_side2() const{
    return sqrt((point1_coordx_ - point3_coordx_)*(point1_coordx_ - point3_coordx_) + (point1_coordy_ - point3_coordy_)*(point1_coordy_ - point3_coordy_));
}

double Triangle::Calculate_side3() const{
    return sqrt((point1_coordx_ - point2_coordx_)*(point1_coordx_ - point2_coordx_) + (point1_coordy_ - point2_coordy_)*(point1_coordy_ - point2_coordy_));
}

double Triangle::Calculate_corner1() const{
    double side1, side2, side3;
    side1 = sqrt((point1_coordx_ - point2_coordx_)*(point1_coordx_ - point2_coordx_) + (point1_coordy_ - point2_coordy_)*(point1_coordy_ - point2_coordy_));
    side2 = sqrt((point3_coordx_ - point2_coordx_)*(point3_coordx_ - point2_coordx_) + (point3_coordy_ - point2_coordy_)*(point3_coordy_ - point2_coordy_));
    side3 = sqrt((point1_coordx_ - point3_coordx_)*(point1_coordx_ - point3_coordx_) + (point1_coordy_ - point3_coordy_)*(point1_coordy_ - point3_coordy_));
    return acos((side1*side1+side3*side3-side2*side2)/(2*side1*side3));
}

double Triangle::Calculate_corner2() const{
    double side1, side2, side3;
    side1 = sqrt((point1_coordx_ - point2_coordx_)*(point1_coordx_ - point2_coordx_) + (point1_coordy_ - point2_coordy_)*(point1_coordy_ - point2_coordy_));
    side2 = sqrt((point3_coordx_ - point2_coordx_)*(point3_coordx_ - point2_coordx_) + (point3_coordy_ - point2_coordy_)*(point3_coordy_ - point2_coordy_));
    side3 = sqrt((point1_coordx_ - point3_coordx_)*(point1_coordx_ - point3_coordx_) + (point1_coordy_ - point3_coordy_)*(point1_coordy_ - point3_coordy_));
    return acos((side1*side1 + side2*s2 - side3*side3) / (2 * side1*side2));
}

double Triangle::Calculate_corner3() const{
    double side1, side2, side3;
    side1 = sqrt((point1_coordx_ - point2_coordx_)*(point1_coordx_ - point2_coordx_) + (point1_coordy_ - point2_coordy_)*(point1_coordy_ - point2_coordy_));
    side2 = sqrt((point3_coordx_ - point2_coordx_)*(point3_coordx_ - point2_coordx_) + (point3_coordy_ - point2_coordy_)*(point3_coordy_ - point2_coordy_));
    side3 = sqrt((point1_coordx_ - point3_coordx_)*(point1_coordx_ - point3_coordx_) + (point1_coordy_ - point3_coordy_)*(point1_coordy_ - point3_coordy_));
    return acos((side2*side2 + side3*side3 - side1*side1) / (2 * side2*side3));
}

double Triangle::Calculate_perimeter() const{
    double side1, side2, side3;
    side1 = sqrt((point1_coordx_ - point2_coordx_)*(point1_coordx_ - point2_coordx_) + (point1_coordy_ - point2_coordy_)*(point1_coordy_ - point2_coordy_));
    side2 = sqrt((point3_coordx_ - point2_coordx_)*(point3_coordx_ - point2_coordx_) + (point3_coordy_ - point2_coordy_)*(point3_coordy_ - point2_coordy_));
    side3 = sqrt((point1_coordx_ - point3_coordx_)*(point1_coordx_ - point3_coordx_) + (point1_coordy_ - point3_coordy_)*(point1_coordy_ - point3_coordy_));
    return side1+side2+side3;
}

double Triangle::Calculate_square() const{
    double side1, side2, side3, per;
    side1 = sqrt((point1_coordx_ - point2_coordx_)*(point1_coordx_ - point2_coordx_) + (point1_coordy_ - point2_coordy_)*(point1_coordy_ - point2_coordy_));
    side2 = sqrt((point3_coordx_ - point2_coordx_)*(point3_coordx_ - point2_coordx_) + (point3_coordy_ - point2_coordy_)*(point3_coordy_ - point2_coordy_));
    side3 = sqrt((point1_coordx_ - point3_coordx_)*(point1_coordx_ - point3_coordx_) + (point1_coordy_ - point3_coordy_)*(point1_coordy_ - point3_coordy_));
    per = (side1 + side2 + side3) / 2;
    return sqrt(per * (per - side1) * (per - side2) * (per - side3));
}

double Triangle::Get_coordx_median() const{
    return (point1_coordx_ + point2_coordx_ + point3_coordx_) / 3;
}

double Triangle::Get_coordy_median() const{
    return (point1_coordy_ + point2_coordy_ + point3_coordy_) / 3;
}
