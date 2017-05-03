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

    double Get_coordX_point(const int number_point) const;
    double Get_coordY_point(const int number_point) const;

    void Set_coordX_point(const double x, const int number_point);
    void Set_coordY_point(const double y, const int number_point);

    double Calculate_side(const int number_side) const;
    double Calculate_corner(const int number_corner) const;

    double Calculate_perimeter() const;
    double Calculate_square() const;

    double Get_coordX_median() const;
    double Get_coordY_median() const;

 private:
    bool isTriangle(const Triangle& t) const;
    double point1_coordx_;
    double point1_coordy_;
    double point2_coordx_;
    double point2_coordy_;
    double point3_coordx_;
    double point3_coordy_;
};

#endif  // MODULES_TRIANGLE_INCLUDE_TRIANGLE_H_
