// Copyright 2017 Kulygina Julia

#ifndef MODULES_AREA_OF_THREE_DIMENSIONAL_FIGURES_INCLUDE_CYLINDER_H_
#define MODULES_AREA_OF_THREE_DIMENSIONAL_FIGURES_INCLUDE_CYLINDER_H_
#define _USE_MATH_DEFINES

#include <cmath>
#include <string>

class Cylinder {
 public:
     Cylinder(double _r, double _h);
     double CalculateS();
     Cylinder(const Cylinder& z);

     double getr() const;
     double getl() const;
     double getS() const;
     void setr(const double _r);
     void setl(const double _l);
     void setS(const double _S);

     bool operator == (const Cylinder& z) const;
     bool operator != (const Cylinder& z) const;

 private:
     double r;
     double l;
     double S;
};

#endif  // MODULES_AREA_OF_THREE_DIMENSIONAL_FIGURES_INCLUDE_CYLINDER_H_
