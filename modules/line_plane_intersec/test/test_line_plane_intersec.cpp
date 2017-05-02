// Copyright 2017 Lapin Artem

#include <gtest/gtest.h>

#include <string>
#include <stdexcept>
#include <vector>

#include "include/line_plane_intersec.h"

TEST(Lapin_Artem_Line_Plane_Intersec_Test, Do_Throw_When_Line_Parallel_Plane) {
    // Arrange
    Intersection Intersec(1, 1, 1, 0, 0, 0, 1, 1, 1, 0);
    // Act & Assert
    EXPECT_THROW(Intersec.CalculateIntersection(), std::string);
}

TEST(Lapin_Artem_Line_Plane_Intersec_Test, Calculate_Return_Is_Correct) {
    // Arrange
    Intersection Intersec(-1, -2, 3, -3, 2, -2, 1, 3, -5, 9);
    std::vector<double> expected(3);
    expected[0] = -4;
    expected[1] = 0;
    expected[2] = 1;
    // Act & Assert
    EXPECT_EQ(Intersec.CalculateIntersection(), expected);
}

TEST(Lapin_Artem_Line_Plane_Intersec_Test, GetLine_And_SetLine_Works_Correct) {
    // Arrange
    Intersection Intersec;
    std::vector<double> expected(6);
    expected[0] = 6;
    expected[1] = 5;
    expected[2] = 4;
    expected[3] = 3;
    expected[4] = 2;
    expected[5] = 1;
    // Act
    Intersec.SetLine(6, 5, 4, 3, 2, 1);
    // Assert
    EXPECT_EQ(Intersec.GetLine(), expected);
}

TEST(Lapin_Artem_Line_Plane_Intersec_Test, GetPlane_And_SetPlane_Correct) {
    // Arrange
    Intersection Intersec;
    std::vector<double> expected(4);
    expected[0] = 6;
    expected[1] = 5;
    expected[2] = 4;
    expected[3] = 3;
    // Act
    Intersec.SetPlane(6, 5, 4, 3);
    // Assert
    EXPECT_EQ(Intersec.GetPlane(), expected);
}

TEST(Lapin_Artem_Line_Plane_Intersec_Test, More_Test_For_Calculate) {
    // Arrange
    Intersection Intersec(-3, 0, -2, -1, -3, 3, 1, -2, -1, 3);
    std::vector<double> expected(3);
    expected[0] = -2;
    expected[1] = 3;
    expected[2] = -5;
    // Act & Assert
    EXPECT_EQ(Intersec.CalculateIntersection(), expected);
}
