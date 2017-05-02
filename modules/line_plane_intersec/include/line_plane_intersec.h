// Copyright 2017 Lapin Artem

#ifndef MODULES_LINE_PLANE_INTERSEC_INCLUDE_LINE_PLANE_INTERSEC_H_
#define MODULES_LINE_PLANE_INTERSEC_INCLUDE_LINE_PLANE_INTERSEC_H_
#include <vector>
using namespace std;

class Intersection {
private:
    double linex0;
    double liney0;
    double linez0;
    double linem;
    double linen;
    double linep;
    double planeA;
    double planeB;
    double planeC;
    double planeD;

public:
    Intersection();
    void SetLine(double linex0, double liney0, double linez0, double linem, double linen, double linep);
    void SetPlane(double planeA, double planeB, double planeC, double planeD);
    vector <double> GetLine(void);
    vector <double> GetPlane(void);
    Intersection(double x0, double y0, double z0, double m, double n, double p, double A, double B, double C, double D);
    vector <double> CalculateIntersection(void);

};

#endif  // MODULES_LINE_PLANE_INTERSEC_INCLUDE_LINE_PLANE_INTERSEC_H_