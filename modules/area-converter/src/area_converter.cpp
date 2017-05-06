
#include "include/area_converter.h"

area_converter::area_converter(double from, double to)
{
    area_converter::ratio = square(from / to);
}

double area_converter::operator()(double x)
{
    return x * area_converter::ratio;
}
