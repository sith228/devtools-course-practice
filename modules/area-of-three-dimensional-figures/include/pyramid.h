// Copyright 2017 Kulygina Julia

#ifndef MODULES_AREA_OF_THREE_DIMENSIONAL_FIGURES_INCLUDE_PYRAMID_H_
#define MODULES_AREA_OF_THREE_DIMENSIONAL_FIGURES_INCLUDE_PYRAMID_H_
#define _USE_MATH_DEFINES

#include <cmath>
#include <string>

class Pyramid {
 public:
     Pyramid(double _a, double _b, double _l);
     double CalculateS();
     Pyramid(const Pyramid& z);

     double get_a() const;
     double get_b() const;
     double get_l() const;
     double getS() const;
     void set_a(const double _a);
     void set_b(const double _b);
     void set_l(const double _l);
     void setS(const double _S);

     bool operator == (const Pyramid& z) const;
     bool operator != (const Pyramid& z) const;

 private:
     double a;
     double b;
     double l;
     double S;
};

#endif  // MODULES_AREA_OF_THREE_DIMENSIONAL_FIGURES_INCLUDE_PYRAMID_H_
