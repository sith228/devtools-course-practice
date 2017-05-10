#pragma once
#ifndef MODULES_MATRIX_CALCULATOR_INCLUDE_MATRIX_CALCULATOR_H_
#define MODULES_MATRIX_CALCULATOR_INCLUDE_MATRIX_CALCULATOR_H_

class MatrixCalculator {
private:
    double **matrix;
    int rows, columns;

public:    
    MatrixCalculator(int _rows = 0, int _columns = 0);
    ~MatrixCalculator();

    MatrixCalculator& operator =(const MatrixCalculator&);
    MatrixCalculator operator +(const MatrixCalculator&) const;
    MatrixCalculator operator -(const MatrixCalculator&) const;
    MatrixCalculator operator *(const MatrixCalculator&) const;

    double determinant() const;
    void set_array(double, double);

    bool operator ==(const Matrix&) const;
};

#endif // MODULES_MATRIX_CALCULATOR_INCLUDE_MATRIX_CALCULATOR_H_
