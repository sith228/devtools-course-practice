
#include "include/area_converter.h"

AreaConverter::AreaConverter(double from, double to)
    : ratio_(Square(from / to)) {}

double AreaConverter::operator()(double x) {
    if (x < 0) {
        throw "It is impossible to work with negative area";
    }

    return x * ratio_;
}
