// Copyright 2017 Karev Boris

#ifndef MODULES_KAREV_BORIS_TRIANGLE_INCLUDE_TRIANGLE_H_
#define MODULES_KAREV_BORIS_TRIANGLE_INCLUDE_TRIANGLE_H_

class Triangle {
public:
    Triangle();
    Triangle(const double x1, const double y1, const double x2, const double y2, const double x3, const double y3);
    Triangle(const Triangle& t);

    Triangle& operator=(const Triangle& t);

    double getX1() const;
    double getX2() const;
    double getX3() const;
    double getY1() const;
    double getY2() const;
    double getY3() const;

    void setX1(const double x);
    void setX2(const double x);
    void setX3(const double x);
    void setY1(const double y);
    void setY2(const double y);
    void setY3(const double y);

    bool operator == (const Triangle& t) const;
    bool operator != (const Triangle& t) const;

    double comp_side1() const;
    double comp_side2() const;
    double comp_side3() const;

    double comp_corner1() const;
    double comp_corner2() const;
    double comp_corner3() const;

    double perimeter() const;
    double square() const;

    double medianX() const;
    double medianY() const;

    bool isSimilar(const Triangle& t) const;

private:
    bool isTriangle(const Triangle& t) const;
    double x1;
    double y1;
    double x2;
    double y2;
    double x3;
    double y3;
};

#endif  // MODULES_KAREV_BORIS_TRIANGLE_INCLUDE_TRIANGLE_H_
