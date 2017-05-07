// Copyright 2017 Pletnev Nikita

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "include/quadratic_equation.h"


TEST(Pletnev_Nikita_QuadraticEquationTest, Can_Create_Quadratic_Equation) {
    QuadraticEquation e;

    EXPECT_EQ(1, e.get_coef_a());
    EXPECT_EQ(0, e.get_coef_b());
    EXPECT_EQ(0, e.get_coef_c());
}

TEST(Pletnev_Nikita_QuadraticEquationTest, Create_Equat_With_Coefficients) {
    QuadraticEquation e(2.1, 0.0, 4.8);

    EXPECT_DOUBLE_EQ(2.1, e.get_coef_a());
    EXPECT_DOUBLE_EQ(0.0, e.get_coef_b());
    EXPECT_DOUBLE_EQ(4.8, e.get_coef_c());
}

TEST(Pletnev_Nikita_QuadraticEquationTest, Cant_Create_Coef_A_As_0) {
    EXPECT_THROW(QuadraticEquation e(0.0, 0.0, 4.8), std::string);
}

TEST(Pletnev_Nikita_QuadraticEquationTest, Cant_Set_Coef_A_As_0) {
    QuadraticEquation e(2.1, 0.0, 4.8);

    EXPECT_THROW(e.set_coef_a(0), std::string);
}

TEST(Pletnev_Nikita_QuadraticEquationTest, Can_Set_Coefficients) {
    QuadraticEquation e(2.1, 0.0, 4.8);

    e.set_coefficients(3, 7, 1);

    EXPECT_DOUBLE_EQ(3, e.get_coef_a());
    EXPECT_DOUBLE_EQ(7, e.get_coef_b());
    EXPECT_DOUBLE_EQ(1, e.get_coef_c());
}

TEST(Pletnev_Nikita_QuadraticEquationTest, Can_Get_Coefficients) {
    QuadraticEquation e(2.1, 0.0, 4.8);

    std::vector<double> coefs(e.get_coefficients());

    EXPECT_DOUBLE_EQ(coefs[0], e.get_coef_a());
    EXPECT_DOUBLE_EQ(coefs[1], e.get_coef_b());
    EXPECT_DOUBLE_EQ(coefs[2], e.get_coef_c());
}

TEST(Pletnev_Nikita_QuadraticEquationTest, Number_Of_Solutions_Is_1) {
    QuadraticEquation e(2.1, 0, 0);

    EXPECT_EQ(1, e.NumOfSolutions());
}

TEST(Pletnev_Nikita_QuadraticEquationTest, Number_Of_Solutions_Is_0) {
    QuadraticEquation e(20.5, 1, 3);

    EXPECT_EQ(0, e.NumOfSolutions());
}

TEST(Pletnev_Nikita_QuadraticEquationTest, Number_Of_Solutions_Is_2) {
    QuadraticEquation e(2, 10.53, 3);

    EXPECT_EQ(2, e.NumOfSolutions());
}

TEST(Pletnev_Nikita_QuadraticEquationTest, Can_Get_1_Solution) {
    QuadraticEquation e(1, 4, 4);

    EXPECT_DOUBLE_EQ(-2, e.GetX2());
    EXPECT_DOUBLE_EQ(e.GetX1(), e.GetX2());
}

TEST(Pletnev_Nikita_QuadraticEquationTest, Can_Get_2_Solutions) {
    QuadraticEquation e(1, 0.7, -2.94);

    EXPECT_DOUBLE_EQ(1.4, e.GetX1());
    EXPECT_DOUBLE_EQ(-2.1, e.GetX2());
}

TEST(Pletnev_Nikita_QuadraticEquationTest, Can_Get_0_Solutions) {
    QuadraticEquation e(20.5, 1, 3);

    EXPECT_DOUBLE_EQ(0, e.GetX1());
    EXPECT_DOUBLE_EQ(e.GetX1(), e.GetX2());
}
