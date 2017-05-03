// Copyright 2017 Kulygina Julia

#ifndef MODULES_AREA_OF_THREE_DIMENSIONAL_FIGURES_INCLUDE_TETRAHEDRON_H_
#define MODULES_AREA_OF_THREE_DIMENSIONAL_FIGURES_INCLUDE_TETRAHEDRON_H_
#define _USE_MATH_DEFINES

#include <cmath>
#include <string>

class Tetrahedron {
 public:
     Tetrahedron(double _a, double _b, double _c, double _l);
     double CalculateS();
     Tetrahedron(const Tetrahedron& z);

     double get_a() const;
     double get_b() const;
     double get_c() const;
     double get_l() const;
     double getS() const;
     void set_a(const double _a);
     void set_b(const double _b);
     void set_c(const double _c);
     void set_l(const double _l);
     void setS(const double _S);

     bool operator == (const Tetrahedron& z) const;
     bool operator != (const Tetrahedron& z) const;

 private:
     double a;
     double b;
     double c;
     double l;
     double S;
};

#endif  // MODULES_AREA_OF_THREE_DIMENSIONAL_FIGURES_INCLUDE_TETRAHEDRON_H_
