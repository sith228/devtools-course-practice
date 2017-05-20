// Copyright 2017 Lobanov Andrey

#include "include/LineSegment.h"
#include <iostream>
#include <string>

using std::string;
using std::stringstream;

double LineSegment2D::Get_Coord(int count) {
  switch (count) {
    case 1: return X1_;
    case 2: return Y1_;
    case 3: return X2_;
    case 4: return Y2_;
    default: throw "Invalid value";
  }
}

double LineSegment2D::Get_Coeff(int count) {
  switch (count) {
    case 1: return Y1_ - Y2_;
    case 2: return X2_ - X1_;
    case 3: return X1_ * Y2_ - X2_ * Y1_;
    default: throw "Invalid value";
  }
}

string LineSegment2D::CheckIntersection(LineSegment2D lineSegment) {
  string str, str1;
  double A1 = Get_Coeff(1);
  double A2 = lineSegment.Get_Coeff(1);
  double B1 = Get_Coeff(2);
  double B2 = lineSegment.Get_Coeff(2);
  double C1 = Get_Coeff(3);
  double C2 = lineSegment.Get_Coeff(3);
  stringstream stream;

  if (A1 * B2 == B1 * A2) {
    if (C2 / C1 == B2 / B1 || C2 / C1 == A2 / A1) {
      str = "The segments are on the same line";
      return str;
    } else {
      str = "Segments are parallel";
      return str;
    }
  } else {
    double coord_X = (-1) * (C1 * B2 - C2 * B1) / (A1 * B2 - B1 * A2);
    double coord_Y = (-1) * (A1 * C2 - A2 * C1) / (A1 * B2 - A2 * B1);

    if (BelongingToSegment(lineSegment)) {
      str = "Intersection point: (";
      stream << coord_X << ";" << coord_Y << ")";
      stream >> str1;
      str = str + str1;
    } else {
      str = "Segments do not intersect";
    }
    return str;
  }
}

bool LineSegment2D::BelongingToSegment(LineSegment2D segment) {
  if (Get_Coord(1) <= segment.Get_Coord(3) &&
	  segment.Get_Coord(3) <= Get_Coord(3))
    return true;
  if (Get_Coord(1) <= segment.Get_Coord(1) &&
	  segment.Get_Coord(1) <= Get_Coord(3))
    return true;
  return false;
}
