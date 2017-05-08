// Copyright 2017 Zorina Ekaterina

#ifndef __VECTOR3D_H__
#define __VECTOR3D_H__

#include <iostream>
#include <cmath>
using namespace std;

// Вектор в трёхмерном пространстве
class Vector3D {
protected:
    double x;
    double y;
    double z;
public:
    Vector3D(double _x = 0.0, double _y = 0.0, double _z = 0.0);
    Vector3D(const Vector3D &v);                // конструктор копирования
    double GetX() const { return x; };            // доступ
    double GetY() const { return y; };
    double GetZ() const { return z; };

    bool operator==(const Vector3D &v) const;  // сравнение
    bool operator!=(const Vector3D &v) const;  // сравнение
    bool IsCloseTo(const Vector3D &v) const;    // приближённое сравнение
                                                // для проверки вычислений
    Vector3D& operator=(const Vector3D &v);     // присваивание

                                              // векторные операции
    Vector3D  operator+(const Vector3D &v);     // сложение
    Vector3D  operator-(const Vector3D &v);     // вычитание
    double Norm();                        // норма вектора
    Vector3D Normalize();                // нормализация вектора
    double  operator*(const Vector3D &v);     // скалярное произведение
    Vector3D  operator^(const Vector3D &v);    // векторное произв-е v(v1, v2)

                                              // ввод-вывод
    friend istream& operator>>(istream &in, Vector3D &v) {
        in >> v.x >> v.y >> v.z;

        return in;
    }
    friend ostream& operator<<(ostream &out, const Vector3D &v) {
        out << "(" << v.x << ", " << v.y << ", " << v.z << ")" << endl;

        return out;
    }
};


#endif
