// Copyright 2017 Karev Boris

#ifndef MODULES_TRIANGLE_INCLUDE_TRIANGLE_H_
#define MODULES_TRIANGLE_INCLUDE_TRIANGLE_H_

class Triangle {
 public:
    Triangle();
    Triangle(const double point1_coordx, const double point1_coordy,
        const double point2_coordx, const double point2_coordy,
        const double point3_coordx, const double point3_coordy);
    Triangle(const Triangle& t);

    bool operator == (const Triangle& t) const;
    bool operator != (const Triangle& t) const;

    double GetCoordxPoint(const int number_point) const;
    double GetCoordyPoint(const int number_point) const;

    void SetCoordxPoint(const double x, const int number_point);
    void SetCoordyPoint(const double y, const int number_point);

    double CalculateSide(const int number_side) const;
    double CalculateCorner(const int number_corner) const;

    double CalculatePerimeter() const;
    double CalculateSquare() const;

    double GetCoordxMedian() const;
    double GetCoordyMedian() const;

 private:
    bool isTriangle() const;
    double point1_coordx_;
    double point1_coordy_;
    double point2_coordx_;
    double point2_coordy_;
    double point3_coordx_;
    double point3_coordy_;
};

#endif  // MODULES_TRIANGLE_INCLUDE_TRIANGLE_H_
