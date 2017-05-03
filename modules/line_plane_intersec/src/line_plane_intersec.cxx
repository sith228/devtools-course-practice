// Copyright 2017 Lapin Artem

#include "include/line_plane_intersec.h"
#include <string.h>
#include <string>
#include <vector>

Intersection::Intersection() {
    linex0_ = 1.0;
    liney0_ = 1.0;
    linez0_ = 1.0;
    linem_ = 1.0;
    linen_ = 1.0;
    linep_ = 1.0;
    planeA_ = 1.0;
    planeB_ = 1.0;
    planeC_ = 1.0;
    planeD_ = 1.0;
}

void Intersection::SetLine(double x0, double y0, double z0,
double m, double n, double p) {
    linex0_ = x0;
    liney0_ = y0;
    linez0_ = z0;
    linem_ = m;
    linen_ = n;
    linep_ = p;
}

std::vector<double> Intersection::GetLine() {
    std::vector<double> result(6);
    result[0] = linex0_;
    result[1] = liney0_;
    result[2] = linez0_;
    result[3] = linem_;
    result[4] = linen_;
    result[5] = linep_;
    return result;
}

std::vector<double> Intersection::GetPlane() {
    std::vector<double> result(4);
    result[0] = planeA_;
    result[1] = planeB_;
    result[2] = planeC_;
    result[3] = planeD_;
    return result;
}

void Intersection::SetPlane(double A, double B, double C, double D) {
    planeA_ = A;
    planeB_ = B;
    planeC_ = C;
    planeD_ = D;
}

Intersection::Intersection(double x0, double y0, double z0, double m,
double n, double p, double A, double B, double C, double D) {
    linex0_ = x0;
    liney0_ = y0;
    linez0_ = z0;
    linem_ = m;
    linen_ = n;
    linep_ = p;
    planeA_ = A;
    planeB_ = B;
    planeC_ = C;
    planeD_ = D;
}

std::vector<double> Intersection::CalculateIntersection() {
    double temp;
    temp = planeA_*linem_ + planeB_*linen_ + planeC_*linep_;
    std::vector<double> result(3);
    if (temp == 0) {
        throw std::string("Line and plane are parallel or line lies in plane");
    } else {
        temp = (-1 * (planeA_*linex0_ + planeB_*liney0_ + planeC_*linez0_ + planeD_))
        / temp;
        result[0] = linex0_ + linem_*temp;
        result[1] = liney0_ + linen_*temp;
        result[2] = linez0_ + linep_*temp;
    }
    return result;
}


