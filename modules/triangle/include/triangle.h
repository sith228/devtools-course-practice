// Copyright 2017 Karev Boris

#ifndef MODULES_TRIANGLE_INCLUDE_TRIANGLE_H_
#define MODULES_TRIANGLE_INCLUDE_TRIANGLE_H_

class Triangle {
public:
    Triangle();
    Triangle(const double point1_coordx, const double point1_coordy, const double point2_coordx, const double point2_coordy, const double point3_coordx, const double point3_coordy);
    Triangle(const Triangle& t);

    Triangle& operator = (const Triangle& t);
    bool operator == (const Triangle& t) const;
    bool operator != (const Triangle& t) const;

    double Get_coordx_point1() const;
    double Get_coordy_point1() const;
    double Get_coordx_point2() const;
    double Get_coordy_point2() const;
    double Get_coordx_point3() const;
    double Get_coordy_point3() const;

    void Set_coordx_point1(const double x);
    void Set_coordy_point1(const double x);
    void Set_coordx_point2(const double x);
    void Set_coordy_point2(const double y);
    void Set_coordx_point3(const double y);
    void Set_coordy_point3(const double y);

    double Calculate_side1() const;
    double Calculate_side2() const;
    double Calculate_side3() const;

    double Calculate_corner1() const;
    double Calculate_corner2() const;
    double Calculate_corner3() const;

    double Calculate_perimeter() const;
    double Calculate_square() const;

    double Get_coordx_median() const;
    double Get_coordy_median() const;

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
