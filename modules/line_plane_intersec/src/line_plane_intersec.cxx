// Copyright 2017 Lapin Artem

#include "include/line_plane_intersec.h"
#include <string.h>
#include <string>
#include <vector>

Intersection::Intersection() {
    linex0 = 1.0;
    liney0 = 1.0;
    linez0 = 1.0;
    linem = 1.0;
    linen = 1.0;
    linep = 1.0;
    planeA = 1.0;
    planeB = 1.0;
    planeC = 1.0;
    planeD = 1.0;
}

void Intersection::SetLine(double x0, double y0, double z0,
double m, double n, double p) {
    linex0 = x0;
    liney0 = y0;
    linez0 = z0;
    linem = m;
    linen = n;
    linep = p;
}

std::vector<double> Intersection::GetLine() {
    std::vector<double> result(6);
    result[0] = linex0;
    result[1] = liney0;
    result[2] = linez0;
    result[3] = linem;
    result[4] = linen;
    result[5] = linep;
    return result;
}

std::vector<double> Intersection::GetPlane() {
    std::vector<double> result(4);
    result[0] = planeA;
    result[1] = planeB;
    result[2] = planeC;
    result[3] = planeD;
    return result;
}

void Intersection::SetPlane(double A, double B, double C, double D) {
    planeA = A;
    planeB = B;
    planeC = C;
    planeD = D;
}

Intersection::Intersection(double x0, double y0, double z0, double m,
double n, double p, double A, double B, double C, double D) {
    linex0 = x0;
    liney0 = y0;
    linez0 = z0;
    linem = m;
    linen = n;
    linep = p;
    planeA = A;
    planeB = B;
    planeC = C;
    planeD = D;
}

std::vector<double> Intersection::CalculateIntersection() {
    double temp;
    temp = planeA*linem + planeB*linen + planeC*linep;
    std::vector<double> result(3);
    if (temp == 0) {
        throw std::string("Line and plane are parallel or line lies in plane");
    } else {
        temp = (-1 * (planeA*linex0 + planeB*liney0 + planeC*linez0 + planeD))
		/ temp;
        result[0] = linex0 + linem*temp;
        result[1] = liney0 + linen*temp;
        result[2] = linez0 + linep*temp;
    }
    return result;
}


