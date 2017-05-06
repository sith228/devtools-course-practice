// Copyright 2017 Lobanov Andrey

#ifndef MODULES_LINESEGMENT_INCLUDE_LINESEGMENT_H_
#define MODULES_LINESEGMENT_INCLUDE_LINESEGMENT_H_

#include <string>
#include <sstream>

using namespace std;

class LineSegment2D {
protected:
    string str;
    double coeff_A;
    double coeff_B;
    double coeff_C;
    double Corrections(double value);
public:
    LineSegment2D(double A, double B, double C) {
        coeff_A = A;
        coeff_B = B;
        coeff_C = C;
    }
    void Set_Coeff_A(double new_A) {
        coeff_A = new_A;
    }
    void Set_Coeff_B(double new_B) {
        coeff_B = new_B;
    }
    void Set_Coeff_C(double new_C) {
        coeff_C = new_C;
    }
    double Get_Coeff_A() {
        return coeff_A;
    }
    double Get_Coeff_B() {
        return coeff_B;
    }
	double Get_Coeff_C() {
        return coeff_C;
    }
    string checkIntersection(LineSegment2D lineSegment);
};
#endif
