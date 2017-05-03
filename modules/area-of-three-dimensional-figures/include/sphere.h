// Copyright 2017 Kulygina Julia

#ifndef MODULES_AREA_OF_THREE_DIMENSIONAL_FIGURES_INCLUDE_SPHERE_H_
#define MODULES_AREA_OF_THREE_DIMENSIONAL_FIGURES_INCLUDE_SPHERE_H_
#define _USE_MATH_DEFINES

#include <cmath>
#include <string>

class Sphere {
 public:
     explicit Sphere(double _R);
     double CalculateS();
     Sphere(const Sphere& z);

     double getR() const;
     double getS() const;
     void setR(const double _R);
     void setS(const double _S);

     bool operator == (const Sphere& z) const;
     bool operator != (const Sphere& z) const;

 private:
     double R;
     double S;
};

#endif  // MODULES_AREA_OF_THREE_DIMENSIONAL_FIGURES_INCLUDE_SPHERE_H_
