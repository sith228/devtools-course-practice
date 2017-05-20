// Copyright 2017 Lobanov Andrey

#ifndef MODULES_INTERSECTTWOLINE_INCLUDE_LINESEGMENT_H_
#define MODULES_INTERSECTTWOLINE_INCLUDE_LINESEGMENT_H_

#include <string>
#include <sstream>

using std::string;

class LineSegment2D {
 public:
  LineSegment2D(double X1, double Y1, double X2, double Y2) {
    if (X1 == X2 && Y1 == Y2) {
      throw "Error, points can not coincide";
    } else if (X1 > X2) {
      X1_ = X2;
      Y1_ = Y2;
      X2_ = X1;
      Y2_ = Y1;
    } else {
      X1_ = X1;
      Y1_ = Y1;
      X2_ = X2;
      Y2_ = Y2;
    }
  }
  LineSegment2D() {
    X1_ = 0;
    Y1_ = 0;
    X2_ = 0;
    Y2_ = 0;
  }
  void Set_X1(double X) {
    X1_ = X;
  }
  void Set_X2(double X) {
    X2_ = X;
  }
  void Set_Y1(double Y) {
    Y1_ = Y;
  }
  void Set_Y2(double Y) {
    Y2_ = Y;
  }

  double Get_Coord(int count);

  double Get_Coeff(int count);

  string ÑheckIntersection(LineSegment2D lineSegment);
  bool BelongingToSegment(LineSegment2D segment);

 protected:
  double X1_;
  double X2_;
  double Y1_;
  double Y2_;
};
#endif  // MODULES_INTERSECTTWOLINE_INCLUDE_LINESEGMENT_H_
