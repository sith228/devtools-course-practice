// Copyright 2017 Fedorov Igor

#include "include/newton-method.h"

#include <algorithm>
#include <iostream>
#include <cmath>

bool newton_method::IsMonotone(float(*fun)(float)) {
    if (A > B) {
        std::swap(A, B);
    }
    if (fun(A) > fun(B)) {
        float i = A;
        float temp_i = i;
        while (temp_i < B) {
            if (fun(i) < fun(temp_i))
                return false;
            i = temp_i;
            temp_i += Acc;
            }
    } else if (fun(A) < fun(B)) {
        float i = A;
        float temp_i = i;
        while (temp_i < B) {
            if (fun(i) > fun(temp_i))
                return false;
            i = temp_i;
            temp_i += Acc;
        }
    }
    if (A == B) {
        return false;
    }
    if (fun(A) == fun(B)) {
        return false;
    }
    return true;
}

float newton_method::FindRoot(float(*fun)(float),
    float(*deriv_fun)(float), float(*deriv2_fun)(float)) {
    if (IsMonotone(fun)) {
        float xn = fun(A)*deriv2_fun(A) > 0 ? A : B;
        float x1 = xn - fun(xn) / deriv_fun(xn);
        float x0 = xn;
        float xsum = std::abs(x0 - x1);
        while (xsum > Acc) {
            if (x1 < A || x1 > B)
                throw("segment have not desidion");
            x0 = x1;
            x1 = x1 - fun(x1) / deriv_fun(x1);
            xsum = std::abs(x0 - x1);
        }
        return x1;
    } else
        throw("function isnot monotone or its point");
}
