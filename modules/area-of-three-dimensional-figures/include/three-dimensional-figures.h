// Copyright 2017 Kulygina Julia

#ifndef MODULES_AREA_OF_THREE_DIMENSIONAL_FIGURES_INCLUDE_THREE_DIMENSIONAL_FIGURES_H_
#define MODULES_AREA_OF_THREE_DIMENSIONAL_FIGURES_INCLUDE_THREE_DIMENSIONAL_FIGURES_H_
#define _USE_MATH_DEFINES

#include <cmath>
#include <string>

class Sphere {
public:
    explicit Sphere(double _R);
    double CalculateS();
    Sphere(const Sphere& z);

    double getR() const;
    double getS() const;
    void setR(const double _R);
    void setS(const double _S);

    bool operator == (const Sphere& z) const;
    bool operator != (const Sphere& z) const;

private:
    double R;
    double S;
};

class Cube {
public:
    explicit Cube(double _h);
    double CalculateS();
    Cube(const Cube& z);

    double geth() const;
    double getS() const;
    void seth(const double _h);
    void setS(const double _S);

    bool operator == (const Cube& z) const;
    bool operator != (const Cube& z) const;

private:
    double h;
    double S;
};

class Cone {
public:
    Cone(double _r, double _l);
    double CalculateS();
    Cone(const Cone& z);

    double getr() const;
    double getl() const;
    double getS() const;
    void setr(const double _r);
    void setl(const double _l);
    void setS(const double _S);

    bool operator == (const Cone& z) const;
    bool operator != (const Cone& z) const;

private:
    double r;
    double l;
    double S;
};

class Cylinder {
public:
    Cylinder(double _r, double _h);
    double CalculateS();
    Cylinder(const Cylinder& z);

    double getr() const;
    double getl() const;
    double getS() const;
    void setr(const double _r);
    void setl(const double _l);
    void setS(const double _S);

    bool operator == (const Cylinder& z) const;
    bool operator != (const Cylinder& z) const;

private:
    double r;
    double l;
    double S;
};

class Conoid {
public:
    Conoid(double _r1, double _r2, double _l);
    double CalculateS();
    Conoid(const Conoid& z);

    double getr1() const;
    double getr2() const;
    double getl() const;
    double getS() const;
    void setr1(const double _r1);
    void setr2(const double _r2);
    void setl(const double _l);
    void setS(const double _S);

    bool operator == (const Conoid& z) const;
    bool operator != (const Conoid& z) const;

private:
    double r1;
    double r2;
    double l;
    double S;
};

class Parallelepiped {
public:
    Parallelepiped(double _a, double _b, double _c);
    double CalculateS();
    Parallelepiped(const Parallelepiped& z);

    double get_a() const;
    double get_b() const;
    double get_c() const;
    double getS() const;
    void set_a(const double _a);
    void set_b(const double _b);
    void set_c(const double _c);
    void setS(const double _S);

    bool operator == (const Parallelepiped& z) const;
    bool operator != (const Parallelepiped& z) const;

private:
    double a;
    double b;
    double c;
    double S;
};

class Pyramid {
public:
    Pyramid(double _a, double _b, double _l);
    double CalculateS();
    Pyramid(const Pyramid& z);

    double get_a() const;
    double get_b() const;
    double get_l() const;
    double getS() const;
    void set_a(const double _a);
    void set_b(const double _b);
    void set_l(const double _l);
    void setS(const double _S);

    bool operator == (const Pyramid& z) const;
    bool operator != (const Pyramid& z) const;

private:
    double a;
    double b;
    double l;
    double S;
};

class Prism {
public:
    Prism(double _a, double _b, double _c, double _h);
    double CalculateS();
    Prism(const Prism& z);

    double get_a() const;
    double get_b() const;
    double get_c() const;
    double get_h() const;
    double getS() const;
    void set_a(const double _a);
    void set_b(const double _b);
    void set_c(const double _c);
    void set_h(const double _h);
    void setS(const double _S);

    bool operator == (const Prism& z) const;
    bool operator != (const Prism& z) const;

private:
    double a;
    double b;
    double c;
    double h;
    double S;
};

class Tetrahedron {
public:
    Tetrahedron(double _a, double _b, double _c, double _l);
    double CalculateS();
    Tetrahedron(const Tetrahedron& z);

    double get_a() const;
    double get_b() const;
    double get_c() const;
    double get_l() const;
    double getS() const;
    void set_a(const double _a);
    void set_b(const double _b);
    void set_c(const double _c);
    void set_l(const double _l);
    void setS(const double _S);

    bool operator == (const Tetrahedron& z) const;
    bool operator != (const Tetrahedron& z) const;

private:
    double a;
    double b;
    double c;
    double l;
    double S;
};

#endif  // MODULES_AREA_OF_THREE_DIMENSIONAL_FIGURES_INCLUDE_THREE_DIMENSIONAL_FIGURES_H_
