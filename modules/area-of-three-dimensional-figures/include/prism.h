// Copyright 2017 Kulygina Julia

#ifndef MODULES_AREA_OF_THREE_DIMENSIONAL_FIGURES_INCLUDE_PRISM_H_
#define MODULES_AREA_OF_THREE_DIMENSIONAL_FIGURES_INCLUDE_PRISM_H_
#define _USE_MATH_DEFINES

#include <cmath>
#include <string>

class Prism {
 public:
     Prism(double _a, double _b, double _c, double _h);
     double CalculateS();
     Prism(const Prism& z);

     double get_a() const;
     double get_b() const;
     double get_c() const;
     double get_h() const;
     double getS() const;
     void set_a(const double _a);
     void set_b(const double _b);
     void set_c(const double _c);
     void set_h(const double _h);
     void setS(const double _S);

     bool operator == (const Prism& z) const;
     bool operator != (const Prism& z) const;

 private:
     double a;
     double b;
     double c;
     double h;
     double S;
};

#endif  // MODULES_AREA_OF_THREE_DIMENSIONAL_FIGURES_INCLUDE_PRISM_H_
