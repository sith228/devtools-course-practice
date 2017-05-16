// Copyright 2017 Israfilov Marat

#pragma once
#ifndef MODULES_MATRIX_CALCULATOR_INCLUDE_MATRIX_CALCULATOR_H_
#define MODULES_MATRIX_CALCULATOR_INCLUDE_MATRIX_CALCULATOR_H_

#include <vector>
#define INVALID_ARGS -1
#define INVALID_SIZES -2
#define INVALID_MATRIX -3
#define DIV_BY_ZERO -4

class MatrixCalculator {
 public:
    MatrixCalculator(int, int);
    MatrixCalculator(const MatrixCalculator&);
    ~MatrixCalculator();

    MatrixCalculator& operator =(const MatrixCalculator&);
    MatrixCalculator operator +(const MatrixCalculator&) const;
    MatrixCalculator operator -(const MatrixCalculator&) const;
    MatrixCalculator operator *(const MatrixCalculator&) const;

    double Determinant() const;
    void SetMatrix(std::vector<std::vector<double>> &);

 protected:
    bool operator ==(const MatrixCalculator&) const;
    bool size_comp(const MatrixCalculator&) const;

 private:
    std::vector<std::vector<double > > matrix_;
};

#endif  // MODULES_MATRIX_CALCULATOR_INCLUDE_MATRIX_CALCULATOR_H_
