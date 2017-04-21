// Copyright 2017 Karev Boris

#include "include/triangle.h"

#include <stdbool.h>
#include <string>
#include <limits>

Triangle::Triangle() : x1(0), y1(0), x2(0), y2(1), x3(1), y3(0) {}

Triangle::Triangle(const double x_1, const double y_1, const double x_2, const double y_2, const double x_3, const double y_3)
    : x1(x_1), y1(y_1), x2(x_2), y2(y_2), x3(x_3), y3(y_3) {
    if (!isTriangle(*this)) {
        x1 = 0;
        y1 = 0;
        x2 = 0;
        y2 = 1;
        x3 = 1;
        y3 = 0;
        throw std::string("These coordinates do not form a triangle. Created a default triangle");
    }
}

Triangle::Triangle(const Triangle& t)
    : x1(t.getX1()), y1(t.getY1()), x2(t.getX2()), y2(t.getY2()), x3(t.getX3()), y3(t.getY3()) {}

Triangle& Triangle
::operator=(const Triangle& t) {
    x1 = t.getX1();
    y1 = t.getY1();
    x2 = t.getX2();
    y2 = t.getY2();
    x3 = t.getX3();
    y3 = t.getY3();
    return *this;
}

double Triangle::getX1() const {
    return x1;
}

double Triangle::getX2() const {
    return x2;
}

double Triangle::getX3() const {
    return x3;
}

double Triangle::getY1() const {
    return y1;
}

double Triangle::getY2() const {
    return y2;
}

double Triangle::getY3() const {
    return y3;
}

void Triangle::setX1(const double x) {
    double copyX1 = x1;
    x1 = x;
    if (!isTriangle(*this)) {
        x1 = copyX1;
        throw std::string("New coordinates do not form a triangle.");
    }
}

void Triangle::setX2(const double x) {
    double copyX2 = x2;
    x2 = x;
    if (!isTriangle(*this)) {
        x2 = copyX2;
        throw std::string("New coordinates do not form a triangle.");
    }
}

void Triangle::setX3(const double x) {
    double copyX3 = x3;
    x3 = x;
    if (!isTriangle(*this)) {
        x3 = copyX3;
        throw std::string("New coordinates do not form a triangle.");
    }
}

void Triangle::setY1(const double y) {
    double copyY1 = y1;
    y1 = y;
    if (!isTriangle(*this)) {
        y1 = copyY1;
        throw std::string("New coordinates do not form a triangle.");
    }
}

void Triangle::setY2(const double y) {
    double copyY2 = y2;
    y2 = y;
    if (!isTriangle(*this)) {
        y2 = copyY2;
        throw std::string("New coordinates do not form a triangle.");
    }
}

void Triangle::setY3(const double y) {
    double copyY3 = y3;
    y3 = y;
    if (!isTriangle(*this)) {
        y3 = copyY3;
        throw std::string("New coordinates do not form a triangle.");
    }
}

bool Triangle::isTriangle(const Triangle& t) const {
    double s1, s2, s3;
    s1 = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
    s2 = sqrt((x3 - x2)*(x3 - x2) + (y3 - y2)*(y3 - y2));
    s3 = sqrt((x1 - x3)*(x1 - x3) + (y1 - y3)*(y1 - y3));
    return ((s1<s2+s3)&&(s2<s1+s3)&&(s3<s1+s2));
}

bool Triangle::operator == (const Triangle& t) const {
    double s1, s2, s3, ts1, ts2, ts3;
    s1 = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
    s2 = sqrt((x3 - x2)*(x3 - x2) + (y3 - y2)*(y3 - y2));
    s3 = sqrt((x1 - x3)*(x1 - x3) + (y1 - y3)*(y1 - y3));
    ts1 = sqrt((t.x1 - t.x2)*(t.x1 - t.x2) + (t.y1 - t.y2)*(t.y1 - t.y2));
    ts2 = sqrt((t.x3 - t.x2)*(t.x3 - t.x2) + (t.y3 - t.y2)*(t.y3 - t.y2));
    ts3 = sqrt((t.x1 - t.x3)*(t.x1 - t.x3) + (t.y1 - t.y3)*(t.y1 - t.y3));
    return ((s1 == ts1) && (s2 == ts2) && (s3 == ts3));
}

bool Triangle::operator != (const Triangle& t) const {
    return !(*this == t);
}

double Triangle::comp_side1() const{
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

double Triangle::comp_side2() const{
    return sqrt((x3 - x2)*(x3 - x2) + (y3 - y2)*(y3 - y2));
}

double Triangle::comp_side3() const{
    return sqrt((x1 - x3)*(x1 - x3) + (y1 - y3)*(y1 - y3));
}

double Triangle::comp_corner1() const{
    double s1, s2, s3;
    s1 = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
    s2 = sqrt((x3 - x2)*(x3 - x2) + (y3 - y2)*(y3 - y2));
    s3 = sqrt((x1 - x3)*(x1 - x3) + (y1 - y3)*(y1 - y3));
    return acos((s1*s1+s3*s3-s2*s2)/(2*s1*s3));
}

double Triangle::comp_corner2() const{
    double s1, s2, s3;
    s1 = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
    s2 = sqrt((x3 - x2)*(x3 - x2) + (y3 - y2)*(y3 - y2));
    s3 = sqrt((x1 - x3)*(x1 - x3) + (y1 - y3)*(y1 - y3));
    return acos((s1*s1 + s2*s2 - s3*s3) / (2 * s1*s2));
}

double Triangle::comp_corner3() const{
    double s1, s2, s3;
    s1 = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
    s2 = sqrt((x3 - x2)*(x3 - x2) + (y3 - y2)*(y3 - y2));
    s3 = sqrt((x1 - x3)*(x1 - x3) + (y1 - y3)*(y1 - y3));
    return acos((s2*s2 + s3*s3 - s1*s1) / (2 * s2*s3));
}

double Triangle::perimeter() const{
    double s1, s2, s3;
    s1 = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
    s2 = sqrt((x3 - x2)*(x3 - x2) + (y3 - y2)*(y3 - y2));
    s3 = sqrt((x1 - x3)*(x1 - x3) + (y1 - y3)*(y1 - y3));
    return s1+s2+s3;
}

double Triangle::square() const{
    double s1, s2, s3, p;
    s1 = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
    s2 = sqrt((x3 - x2)*(x3 - x2) + (y3 - y2)*(y3 - y2));
    s3 = sqrt((x1 - x3)*(x1 - x3) + (y1 - y3)*(y1 - y3));
    p = (s1 + s2 + s3) / 2;
    return sqrt(p * (p - s1) * (p - s2) * (p - s3));
}

double Triangle::medianX() const{
    return (x1 + x2 + x3) / 3;
}

double Triangle::medianY() const{
    return (y1 + y2 + y3) / 3;
}
