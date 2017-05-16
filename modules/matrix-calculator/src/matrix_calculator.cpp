// Copyright 2017 Israfilov Marat

#include "include/matrix_calculator.h"
#include <iostream>

bool MatrixCalculator::operator ==(const MatrixCalculator& p) const {
    return this->matrix_ == p.matrix_;
}

bool MatrixCalculator::size_comp(const MatrixCalculator& p) const {
    bool result = false;

    if (this->matrix_.size() == p.matrix_.size()) {
        result = true;

        for (size_t i = 0; i < matrix_.size(); ++i) {
            if (this->matrix_[i].size() != p.matrix_[i].size()) {
                result = false;
                break;
            }
        }
    }

    return result;
}

MatrixCalculator::MatrixCalculator(int rows, int columns) {
    if (rows < 0 || columns < 0) {
        throw INVALID_ARGS;
    }

    matrix_ = std::vector<std::vector<double > >(rows, 
              std::vector<double>(columns, 0.0));
}

MatrixCalculator::MatrixCalculator(const MatrixCalculator& p) {
    matrix_ = p.matrix_;
}

MatrixCalculator::~MatrixCalculator() {
    matrix_.clear();
}

MatrixCalculator& MatrixCalculator::operator =(const MatrixCalculator& p) {
    if (!(*this == p)) {
        matrix_ = p.matrix_;
    }

    return *this;
}

MatrixCalculator MatrixCalculator::operator +(const MatrixCalculator& p) const {
    MatrixCalculator result(*this);

    if (!size_comp(p)) {
        throw INVALID_SIZES;
    }

    for (size_t i = 0; i < this->matrix_.size(); ++i) {
        for (size_t j = 0; j < this->matrix_[i].size(); ++j) {
            result.matrix_[i][j] = this->matrix_[i][j] + p.matrix_[i][j];
        }
    }

    return result;
}

MatrixCalculator MatrixCalculator::operator -(const MatrixCalculator& p) const {
    MatrixCalculator result(*this);

    if (!size_comp(p)) {
        throw INVALID_SIZES;
    }

    for (size_t i = 0; i < this->matrix_.size(); ++i) {
        for (size_t j = 0; j < this->matrix_[i].size(); ++j) {
            result.matrix_[i][j] = this->matrix_[i][j] - p.matrix_[i][j];
        }
    }

    return result;
}

MatrixCalculator MatrixCalculator::operator *(const MatrixCalculator& p) const {
    if (this->matrix_[0].size() != p.matrix_.size()) {
        throw INVALID_SIZES;
    }

    MatrixCalculator result(this->matrix_.size(), p.matrix_[0].size());

    for (size_t i = 0; i < result.matrix_.size(); ++i) {
        for (size_t j = 0; j < result.matrix_[i].size(); ++j) {
            for (size_t k = 0; k < p.matrix_.size(); ++k) {
                result.matrix_[i][j] += this->matrix_[i][k] * p.matrix_[k][j];
            }
        }
    }

    return result;
}

double MatrixCalculator::Determinant() const {
    return 0.0;
}

void MatrixCalculator::SetMat(std::vector<std::vector<double>> &input_matrix) {
    for (size_t i = 1; i < input_matrix.size(); ++i) {
        if (input_matrix[i - 1].size() != input_matrix[i].size()) {
            throw INVALID_MATRIX;
        }
    }

    if (this->matrix_ != input_matrix) {
        matrix_ = input_matrix;
    }
}
