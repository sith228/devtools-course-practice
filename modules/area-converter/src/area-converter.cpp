
#include "include\area-converter.h"

double area_converter::operator()(double x)
{
    return x * area_converter::ratio;
}
