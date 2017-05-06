// Copyright 2017 Lobanov Andrey

#include "LineSegment.h"
#include <iostream>

using namespace std;

string LineSegment2D::checkIntersection(LineSegment2D lineSegment) {
    string str1, str2, str3;
    stringstream stream1, stream2;
    double coord_X, coord_Y;
    if ((lineSegment.Get_Coeff_A() / Get_Coeff_A() ==
        lineSegment.Get_Coeff_B() / Get_Coeff_B()) &&
        (lineSegment.Get_Coeff_A() / Get_Coeff_A() ==
        lineSegment.Get_Coeff_C() / Get_Coeff_C())) {
            str = "Lines are coincide";
    }
    else if (lineSegment.Get_Coeff_A() / Get_Coeff_A() ==
             lineSegment.Get_Coeff_B() / Get_Coeff_B()) {
                  str = "Lines are parallel";
    }
    else {
        coord_X = (-1) * (Get_Coeff_C() * lineSegment.Get_Coeff_B() -
                  lineSegment.Get_Coeff_C() * Get_Coeff_B()) /
                  (Get_Coeff_A() * lineSegment.Get_Coeff_B() -
                  Get_Coeff_B() * lineSegment.Get_Coeff_A());
        coord_Y = (-1) * (Get_Coeff_A() * lineSegment.Get_Coeff_C() -
                  lineSegment.Get_Coeff_A() * Get_Coeff_C()) /
                  (Get_Coeff_A() * lineSegment.Get_Coeff_B() -
                  lineSegment.Get_Coeff_A() * Get_Coeff_B());

        str1 = "Intersection point: (";
        stream1 << Corrections(coord_X);
        stream1 >> str2;
        str2 += "; ";
        stream2 << Corrections(coord_Y);
        stream2 >> str3;
        str3 += ")";
        str = str1 + str2 + str3;
    }
    cout << str << endl;;
    return str;
}

double LineSegment2D::Corrections(double value) {
    if (value == -0) {
        return -value;
    }
    else {
        return value;
    }
}
