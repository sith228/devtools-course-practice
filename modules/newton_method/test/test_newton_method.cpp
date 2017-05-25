// Copyright 2017 Dmitry Dryakhlov

#include <gtest/gtest.h>

#include "include/Newton_method.h"

const double eps = 0.01;
const size_t polynom_size = 10;

TEST(test_newton_method, can_generate_random_polynom) {
    // Arrange
    NewtonMethod nm;
    double *polynom_coef = new double[polynom_size];
    // Act & Assert
    ASSERT_NO_THROW(nm.GeneateRandomPolynom(polynom_size, polynom_coef));
    delete[]polynom_coef;
}

TEST(test_newton_method, random_polynom_whith_zero_size) {
    // Arrange
    size_t zero_size = 0;
    double *polynom_coef = new double[zero_size];
    NewtonMethod nm;
    // Act & Assert
    ASSERT_NO_THROW(nm.GeneateRandomPolynom(zero_size, polynom_coef););
    delete[]polynom_coef;
}


TEST(test_newton_method, work_with_const_function) {
    // Arrange
    NewtonMethod nm;
    // Act & Assert
    ASSERT_NO_THROW(nm.NewtonMethodFunction(eps));
}

TEST(test_newton_method, work_with_const_function_negative_eps) {
    // Arrange
    NewtonMethod nm;
    // Act & Assert
    ASSERT_ANY_THROW(nm.NewtonMethodFunction(-0.01));
}

TEST(test_newton_method, work_with_random_polynom) {
    // Arrange
    NewtonMethod nm;
    double *polynom_coef = new double[polynom_size];
    nm.GeneateRandomPolynom(polynom_size, polynom_coef);
    // Act & Assert
    ASSERT_NO_THROW(nm.NewtonMethodPolynom(eps, polynom_size, polynom_coef));
    delete[]polynom_coef;
}

TEST(test_newton_method, work_with_random_polynom_zero_size) {
    // Arrange
    NewtonMethod nm;
    size_t zero_size = 0;
    double *polynom_coef = new double[polynom_size];
    nm.GeneateRandomPolynom(zero_size, polynom_coef);
    // Act & Assert
    ASSERT_ANY_THROW(nm.NewtonMethodPolynom(eps, zero_size, polynom_coef));
    delete[]polynom_coef;
}

TEST(test_newton_method, work_with_random_polynom_negative_eps) {
    // Arrange
    NewtonMethod nm;
    double *polynom_coef = new double[polynom_size];
    nm.GeneateRandomPolynom(polynom_size, polynom_coef);
    // Act & Assert
    ASSERT_ANY_THROW(nm.NewtonMethodPolynom(-0.1, polynom_size,
                                                                polynom_coef));
    delete[]polynom_coef;
}

TEST(test_newton_method, check_result_function) {
    // Arrange
    NewtonMethod nm;
    // Act & Assert
    ASSERT_TRUE(nm.CheckRootFunction(nm.NewtonMethodFunction(eps), eps));
}

TEST(test_newton_method, check_result_polynom) {
    // Arrange
    double *polynom_coef = new double[polynom_size];
    NewtonMethod nm;	
    nm.GeneateRandomPolynom(polynom_size, polynom_coef);
    double root = nm.NewtonMethodPolynom(eps, polynom_size, polynom_coef);
    // Act & Assert
    ASSERT_TRUE(nm.CheckRootPolynom(root, eps*100, polynom_size, polynom_coef) );
    delete[]polynom_coef;
}
