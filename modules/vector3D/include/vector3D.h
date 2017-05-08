// Copyright 2017 Zorina Ekaterina

#ifndef __VECTOR3D_H__
#define __VECTOR3D_H__

#include <iostream>
#include <cmath>


// Вектор в трёхмерном пространстве
class Vector3D {
protected: 
    double x;
    double y;
    double z;
public: 
    Vector3D(double _x = 0.0, double _y = 0.0, double _z = 0.0);
    Vector3D(const Vector3D &v);                // copy constructor
    double GetX() const { return x; }            // access
    double GetY() const { return y; }
    double GetZ() const { return z; }

    bool operator==(const Vector3D &v) const;  // comparison
    bool operator!=(const Vector3D &v) const;  // comparison

    Vector3D& operator=(const Vector3D &v);     // assigment

                                              // vector operations
    Vector3D  operator+(const Vector3D &v);     // addition
    Vector3D  operator-(const Vector3D &v);     // subtraction
    double Norm();                        // vector norm
    Vector3D Normalize();                // normalization vector
    double  operator*(const Vector3D &v);     // scalar product
    Vector3D  operator^(const Vector3D &v);    // vector product v(v1, v2)
};


#endif // MODULES_VECTOR3D_INCLUDE_VECTOR3D_H_
