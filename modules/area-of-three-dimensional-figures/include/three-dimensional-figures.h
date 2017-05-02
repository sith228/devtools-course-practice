// Copyright 2017 Kulygina Julia

#ifndef MODULES_AREA_OF_THREE_DIMENSIONAL_FIGURES_INCLUDE_THREE_DIMENSIONAL_FIGURES_H_
#define MODULES_AREA_OF_THREE_DIMENSIONAL_FIGURES_INCLUDE_THREE_DIMENSIONAL_FIGURES_H_
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

 private:
    double R;
    double S;
};

class Cube {
 public:
     explicit Cube(double _h);
     double CalculateS();
     Cube(const Cube& z);

     double geth() const;
     double getS() const;
     void seth(const double _h);
     void setS(const double _S);
 private:
     double h;
     double S;
};

class Cone {
 public:
     Cone(double _r, double _l);
     double CalculateS();
     Cone(const Cone& z);

     double getr() const;
	 double getl() const;
     double getS() const;
     void setr(const double _r);
     void setl(const double _l);
     void setS(const double _S);
 private:
     double r;
     double l;
     double S;
};

#endif  // MODULES_COMPLEX_NUMBER_INCLUDE_COMPLEX_CALCULATOR_H_
