// Copyright 2017 Pletnev Nikita

#include <gtest/gtest.h>

#include "include/quadratic_equation.h"


TEST(Pletnev_Nikita_QuadraticEquationTest, Can_Create_Quadratic_Equation) {
    QuadraticEquation e;

    EXPECT_EQ(1, e.getCoefA());
    EXPECT_EQ(0, e.getCoefB());
    EXPECT_EQ(0, e.getCoefC());
}

TEST(Pletnev_Nikita_QuadraticEquationTest, Create_Equat_With_Coefficients) {
    QuadraticEquation e(2.1, 0.0, 4.8);

    EXPECT_DOUBLE_EQ(2.1, e.getCoefA());
    EXPECT_DOUBLE_EQ(0.0, e.getCoefB());
    EXPECT_DOUBLE_EQ(4.8, e.getCoefC());
}

TEST(Pletnev_Nikita_QuadraticEquationTest, CoefA_Is_1_When_Create_As_0) {
    QuadraticEquation e(0.0, 0.0, 4.8);

    EXPECT_DOUBLE_EQ(1.0, e.getCoefA());
}

TEST(Pletnev_Nikita_QuadraticEquationTest, CoefA_Is_1_When_Set_As_0) {
    QuadraticEquation e(2.1, 0.0, 4.8);

    e.setCoefA(0);

    EXPECT_DOUBLE_EQ(1.0, e.getCoefA());
}

TEST(Pletnev_Nikita_QuadraticEquationTest, Number_Of_Solutions_Is_1) {
    QuadraticEquation e(2.1, 0, 0);

    EXPECT_EQ(1, e.numOfSolutions());
}

TEST(Pletnev_Nikita_QuadraticEquationTest, Number_Of_Solutions_Is_0) {
    QuadraticEquation e(20.5, 1, 3);

    EXPECT_EQ(0, e.numOfSolutions());
}

TEST(Pletnev_Nikita_QuadraticEquationTest, Number_Of_Solutions_Is_2) {
    QuadraticEquation e(2, 10.53, 3);

    EXPECT_EQ(2, e.numOfSolutions());
}

TEST(Pletnev_Nikita_QuadraticEquationTest, Can_Get_1_Solution) {
    QuadraticEquation e(1, 4, 4);

    EXPECT_DOUBLE_EQ(-2, e.getX2());
    EXPECT_DOUBLE_EQ(e.getX1(), e.getX2());
}

TEST(Pletnev_Nikita_QuadraticEquationTest, Can_Get_2_Solutions) {
    QuadraticEquation e(1, 0.7, -2.94);

    EXPECT_DOUBLE_EQ(1.4, e.getX1());
    EXPECT_DOUBLE_EQ(-2.1, e.getX2());
}

TEST(Pletnev_Nikita_QuadraticEquationTest, Can_Get_0_Solutions) {
    QuadraticEquation e(20.5, 1, 3);

    EXPECT_DOUBLE_EQ(0, e.getX1());
    EXPECT_DOUBLE_EQ(e.getX1(), e.getX2());
}
