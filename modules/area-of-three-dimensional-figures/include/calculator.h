// Copyright 2017 Kulygina Julia

#ifndef MODULES_AREA_OF_THREE_DIMENSIONAL_FIGURES_INCLUDE_CALCULATOR_H_
#define MODULES_AREA_OF_THREE_DIMENSIONAL_FIGURES_INCLUDE_CALCULATOR_H_
#define _USE_MATH_DEFINES

#include <cmath>
#include <string>

class Calculator {
 public:
     Calculator();

     double Calculate_Sphere(double _r);
     double Calculate_Cone(double _r, double _l);
     double Calculate_Conoid(double _r1, double _r2, double _l);
     double Calculate_Cube(double _h);
     double Calculate_Cylinder(double _r, double _h);
     double Calculate_Parallelepiped(double _a, double _b, double _c);
     double Calculate_Prism(double _a, double _b, double _c, double _h);
     double Calculate_Pyramid(double _a, double _b, double _l);
     double Calc_Tetra(double _a, double _b, double _c, double _l);

 private:
     double S;

     bool Is_positive_parameter(double _a);
     bool Check_for_Heron(double _a, double _b, double _c);
     bool Check_positives(double massive_parameters[], int massive_size);
     double Calc_Heron(double _a, double _b, double _c);
};

#endif  // MODULES_AREA_OF_THREE_DIMENSIONAL_FIGURES_INCLUDE_CALCULATOR_H_
