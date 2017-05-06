
#include "include/area_converter.h"

AreaConverter::AreaConverter(double from, double to)
    : ratio_(Square(from / to)) {}

double AreaConverter::operator()(double x) {
    return x * ratio_;
}
