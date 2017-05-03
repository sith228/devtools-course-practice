// Copyright 2017 Kulygina Julia

#ifndef MODULES_AREA_OF_THREE_DIMENSIONAL_FIGURES_INCLUDE_CUBE_H_
#define MODULES_AREA_OF_THREE_DIMENSIONAL_FIGURES_INCLUDE_CUBE_H_
#define _USE_MATH_DEFINES

#include <cmath>
#include <string>

class Cube {
 public:
     explicit Cube(double _h);
     double CalculateS();
     Cube(const Cube& z);

     double geth() const;
     double getS() const;
     void seth(const double _h);
     void setS(const double _S);

     bool operator == (const Cube& z) const;
     bool operator != (const Cube& z) const;

 private:
     double h;
     double S;
};

#endif  // MODULES_AREA_OF_THREE_DIMENSIONAL_FIGURES_INCLUDE_CUBE_H_
