#ifndef MODULES_AREA_CONVERTER_INCLUDE_AREA_CONVERTER_H_
#define MODULES_AREA_CONVERTER_INCLUDE_AREA_CONVERTER_H_

class area_converter
{
    const double ratio;
    static double square(double x) { return x * x; }

public:
    static constexpr double centimeter = 0.01;
    static constexpr double decimeter = 0.1;
    static constexpr double meter = 1.0;

    area_converter(double, double);
    double operator()(double);
};

#endif  // MODULES_AREA_CONVERTER_INCLUDE_AREA_CONVERTER_H_
