// Copyright 2017 Dmitry Dryakhlov

#include <gtest/gtest.h>

#include "include/Newton_method.h"

const double eps = 0.1;
const int polinom_size = 10;

TEST(test_newton_method, can_generate_random_polinom) {
    // Arrange
    NewtonMethod NM;
    double *polinom_coef = new double[polinom_size];
    // Act & Assert
    ASSERT_NO_THROW(NM.geneate_random_polinom(polinom_size, polinom_coef));
    delete[]polinom_coef;
}

TEST(test_newton_method, work_with_const_function) {
    // Arrange
    NewtonMethod NM;
    // Act & Assert
    ASSERT_NO_THROW(NM.newton_method_function(eps));
}

TEST(test_newton_method, polinome_size_is_zero) {
    // Arrange
    NewtonMethod NM;
    double *polinom_coef = new double[polinom_size];
    // Act & Assert
    ASSERT_NO_THROW(NM.geneate_random_polinom(10, polinom_coef));
    delete[]polinom_coef;
}

TEST(test_newton_method, work_with_random_polinom) {
    // Arrange
    NewtonMethod NM;
    double *polinom_coef = new double[polinom_size];
    NM.geneate_random_polinom(polinom_size, polinom_coef);
    // Act & Assert
    ASSERT_NO_THROW(NM.newton_method_polinom(eps, polinom_size, polinom_coef));
    delete[]polinom_coef;
}



