// Copyright 2017 Kulygina Julia

#ifndef MODULES_AREA_OF_THREE_DIMENSIONAL_FIGURES_INCLUDE_CONOID_H_
#define MODULES_AREA_OF_THREE_DIMENSIONAL_FIGURES_INCLUDE_CONOID_H_
#define _USE_MATH_DEFINES

#include <cmath>
#include <string>

class Conoid {
 public:
     Conoid(double _r1, double _r2, double _l);
     double CalculateS();
     Conoid(const Conoid& z);

     double getr1() const;
     double getr2() const;
     double getl() const;
     double getS() const;
     void setr1(const double _r1);
     void setr2(const double _r2);
     void setl(const double _l);
     void setS(const double _S);

     bool operator == (const Conoid& z) const;
     bool operator != (const Conoid& z) const;

 private:
     double r1;
     double r2;
     double l;
     double S;
};

#endif  // MODULES_AREA_OF_THREE_DIMENSIONAL_FIGURES_INCLUDE_CONOID_H_
