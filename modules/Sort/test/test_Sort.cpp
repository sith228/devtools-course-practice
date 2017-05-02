// Copyright 2017 Mitrokhin Nikita

#include <gtest/gtest.h>
#include <include/Sort.h>

TEST(Sort, Can_Compare_Result) {
    // Arrange
    const int N = 6;
    const int Array[N] = { 5, 2, 1, 4, 3, 6 };
    Sort Array1(Array, N);
    Sort Array2(Array, N);

    // Act
    const bool expected_true = Array1 == Array2;

    // Assert
    EXPECT_TRUE(expected_true);
}

TEST(Sort, Can_Compare_Result_False) {
    // Arrange
    const int N = 10;
    const int M = 5;
    const int Arr1[N] = { 3457, 7, 5, 12, 56, 4, 1, 33, 27, 1040 };
    const int Arr2[M] = { 5, 2, 1, 4, 3 };
    Sort Array1(Arr1, N);
    Sort Array2(Arr2, M);

    // Act
    const bool expected_false = Array1 == Array2;

    // Assert
    EXPECT_FALSE(expected_false);
}
