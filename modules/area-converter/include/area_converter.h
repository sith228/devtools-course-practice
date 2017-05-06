// Copyright 2017 Kuchkov Ivan

#ifndef MODULES_AREA_CONVERTER_INCLUDE_AREA_CONVERTER_H_
#define MODULES_AREA_CONVERTER_INCLUDE_AREA_CONVERTER_H_

class AreaConverter {
 public:
    static constexpr double centimeter = 0.01;
    static constexpr double decimeter = 0.1;
    static constexpr double meter = 1.0;
    static constexpr double yard = 0.9144;
    static constexpr double inch = 0.0254;
    static constexpr double acr = 63.6149072341;
    static constexpr double hectare = 100;

    AreaConverter(double, double);
    double operator()(double);

 private:
    double ratio_;
    static double Square(double x) { return x * x; }
};

#endif  // MODULES_AREA_CONVERTER_INCLUDE_AREA_CONVERTER_H_
