// Copyright 2017 Kulygina Julia

#ifndef MODULES_AREA_OF_THREE_DIMENSIONAL_FIGURES_INCLUDE_PARALLELEPIPED_H_
#define MODULES_AREA_OF_THREE_DIMENSIONAL_FIGURES_INCLUDE_PARALLELEPIPED_H_
#define _USE_MATH_DEFINES

#include <cmath>
#include <string>

class Parallelepiped {
 public:
     Parallelepiped(double _a, double _b, double _c);
     double CalculateS();
     Parallelepiped(const Parallelepiped& z);

     double get_a() const;
     double get_b() const;
     double get_c() const;
     double getS() const;
     void set_a(const double _a);
     void set_b(const double _b);
     void set_c(const double _c);
     void setS(const double _S);

     bool operator == (const Parallelepiped& z) const;
     bool operator != (const Parallelepiped& z) const;

 private:
     double a;
     double b;
     double c;
     double S;
};

#endif  // MODULES_AREA_OF_THREE_DIMENSIONAL_FIGURES_INCLUDE_PARALLELEPIPED_H_
