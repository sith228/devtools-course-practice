// Copyright 2017 Nesterov Alexander
#include <gtest/gtest.h>
#include "../include/rgb_space.h"

TEST(RGBSpaceTest, Can_Initiliaze_Variable_With_The_Default_Constructor) {
    // Arrange
    int sum = 0;
    // Act
    RGBSpace space;
    sum += space.GetRed();
    sum += space.GetGreen();
    sum += space.GetBlue();
    // Assert
    EXPECT_EQ(0, sum);
}

TEST(RGBSpaceTest, Can_Enter_Red_Not_Correct_Data_In_The_Constructor) {
    // Arrange
    int red = 256;
    int green = 128;
    int blue = 128;
    // Act & Assert
    EXPECT_ANY_THROW({ RGBSpace space(red, green, blue);});
}

TEST(RGBSpaceTest, Can_Enter_Green_Not_Correct_Data_In_The_Constructor) {
    // Arrange
    int red = 128;
    int green = -256;
    int blue = 128;
    // Act & Assert
    EXPECT_ANY_THROW({ RGBSpace space(red, green, blue);});
}

TEST(RGBSpaceTest, Can_Enter_Blue_Not_Correct_Data_In_The_Constructor) {
    // Arrange
    int red = 0;
    int green = 0;
    int blue = -1;
    // Act & Assert
    EXPECT_ANY_THROW({ RGBSpace space(red, green, blue);});
}

TEST(RGBSpaceTest, Can_Enter_Data_Without_Throw_In_The_Constructor) {
    // Arrange
    int red = 127;
    int green = 236;
    int blue = 56;
    // Act & Assert
    EXPECT_NO_THROW({ RGBSpace space(red, green, blue);});
}

TEST(RGBSpaceTest, Can_Enter_Red_Correct_Data_In_The_Constructor) {
    // Arrange
    int red = 127;
    int green = 236;
    int blue = 56;
    // Act
    RGBSpace space(red, green, blue);
    // Assert
    EXPECT_EQ(red, space.GetRed());
}

TEST(RGBSpaceTest, Can_Enter_Green_Correct_Data_In_The_Constructor) {
    // Arrange
    int red = 127;
    int green = 236;
    int blue = 56;
    // Act
    RGBSpace space(red, green, blue);
    // Assert
    EXPECT_EQ(green, space.GetGreen());
}

TEST(RGBSpaceTest, Can_Enter_Blue_Correct_Data_In_The_Constructor) {
    // Arrange
    int red = 127;
    int green = 236;
    int blue = 56;
    // Act
    RGBSpace space(red, green, blue);
    // Assert
    EXPECT_EQ(blue, space.GetBlue());
}
