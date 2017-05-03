// Copyright 2017 Lapin Artem

#ifndef MODULES_LINE_PLANE_INTERSEC_INCLUDE_LINE_PLANE_INTERSEC_H_
#define MODULES_LINE_PLANE_INTERSEC_INCLUDE_LINE_PLANE_INTERSEC_H_
#include <vector>

class Intersection {
 private:
    double linex0_;
    double liney0_;
    double linez0_;
    double linem_;
    double linen_;
    double linep_;
    double planeA_;
    double planeB_;
    double planeC_;
    double planeD_;

 public:
    Intersection();
    void SetLine(double linex0_, double liney0_, double linez0_,
    double linem_, double linen_, double linep_);
    void SetPlane(double planeA_, double planeB_, double planeC_, double planeD_);
    std::vector <double> GetLine(void);
    std::vector <double> GetPlane(void);
    Intersection(double x0, double y0, double z0,
    double m, double n, double p, double A, double B, double C, double D);
    std::vector <double> CalculateIntersection(void);
};

#endif  // MODULES_LINE_PLANE_INTERSEC_INCLUDE_LINE_PLANE_INTERSEC_H_
