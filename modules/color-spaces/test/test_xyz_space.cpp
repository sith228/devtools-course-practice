// Copyright 2017 Nesterov Alexander
#include <gtest/gtest.h>
#include "../include/xyz_space.h"

TEST(XYZSpaceTest, Can_Initiliaze_Variable_With_The_Default_Constructor) {
    // Arrange
    int sum = 0;
    // Act
    XYZSpace space;
    sum += space.getX();
    sum += space.getY();
    sum += space.getZ();
    // Assert
    EXPECT_EQ(0, sum);
}

TEST(XYZSpaceTest, Can_Enter_X_Not_Correct_Data_In_The_Constructor) {
    // Arrange
    int x = 110;
    int y = 99;
    int z = 107;
    // Act & Assert
    EXPECT_ANY_THROW({ XYZSpace space(x, y, z); });
}

TEST(XYZSpaceTest, Can_Enter_Y_Not_Correct_Data_In_The_Constructor) {
    // Arrange
    int x = 85;
    int y = -256;
    int z = 100;
    // Act & Assert
    EXPECT_ANY_THROW({ XYZSpace space(x, y, z); });
}

TEST(XYZSpaceTest, Can_Enter_Z_Not_Correct_Data_In_The_Constructor) {
    // Arrange
    int x = 0;
    int y = 0;
    int z = -1;
    // Act & Assert
    EXPECT_ANY_THROW({ XYZSpace space(x, y, z); });
}

TEST(XYZSpaceTest, Can_Enter_Data_Without_Throw_In_The_Constructor) {
    // Arrange
    int x = 95;
    int y = 100;
    int z = 108;
    // Act & Assert
    EXPECT_NO_THROW({ XYZSpace space(x, y, z); });
}

TEST(XYZSpaceTest, Can_Enter_X_Correct_Data_In_The_Constructor) {
    // Arrange
    int x = 90;
    int y = 95;
    int z = 100;
    // Act
    XYZSpace space(x, y, z);
    // Assert
    EXPECT_EQ(x, space.getX());
}

TEST(XYZSpaceTest, Can_Enter_Y_Correct_Data_In_The_Constructor) {
    // Arrange
    int x = 90;
    int y = 95;
    int z = 100;
    // Act
    XYZSpace space(x, y, z);
    // Assert
    EXPECT_EQ(y, space.getY());
}

TEST(XYZSpaceTest, Can_Enter_Z_Correct_Data_In_The_Constructor) {
    // Arrange
    int x = 90;
    int y = 95;
    int z = 100;
    // Act
    XYZSpace space(x, y, z);
    // Assert
    EXPECT_EQ(z, space.getZ());
}

TEST(XYZSpaceTest, Can_Use_The_Copying_Constructor) {
    // Arrange
    XYZSpace space(70, 80, 90);
    // Act
    XYZSpace copy_space(space);
    // Assert
    EXPECT_EQ(space, copy_space);
}

TEST(XYZSpaceTest, Can_Use_Assignment_Operator) {
    // Arrange
    XYZSpace space(72, 82, 92);
    // Act
    XYZSpace assigment_space = space;
    // Assert
    EXPECT_EQ(space, assigment_space);
}

TEST(XYZSpaceTest, Can_Set_Field_X) {
    // Arrange
    int x = 77;
    // Act
    XYZSpace space;
    space.setX(x);
    // Assert
    EXPECT_EQ(x, space.getX());
}

TEST(XYZSpaceTest, Can_Set_Field_Y) {
    // Arrange
    int y = 88;
    // Act
    XYZSpace space;
    space.setY(y);
    // Assert
    EXPECT_EQ(y, space.getY());
}

TEST(XYZSpaceTest, Can_Set_Field_Z) {
    // Arrange
    int z = 99;
    // Act
    XYZSpace space;
    space.setZ(z);
    // Assert
    EXPECT_EQ(z, space.getZ());
}

TEST(XYZSpaceTest, Can_Set_Not_Correct_Data_In_Field_X) {
    // Arrange
    int x = 257;
    // Act
    XYZSpace space;
    // Assert
    EXPECT_ANY_THROW({ space.setX(x); });
}

TEST(XYZSpaceTest, Can_Set_Not_Correct_Data_In_Field_Y) {
    // Arrange
    int y = -2;
    // Act
    XYZSpace space;
    // Assert
    EXPECT_ANY_THROW({ space.setY(y); });
}

TEST(XYZSpaceTest, Can_Set_Not_Correct_Data_In_Field_Z) {
    // Arrange
    int z = -258;
    // Act
    XYZSpace space;
    // Assert
    EXPECT_ANY_THROW({ space.setZ(z); });
}

TEST(XYZSpaceTest, Can_Use_Equals_In_XYZSpace) {
    // Arrange
    int x = 50, y = 66, z = 73;
    XYZSpace left_space(x, y, z);
    XYZSpace right_space(x, y, z);
    // Act & Assert
    EXPECT_TRUE(left_space == right_space);
}

TEST(XYZSpaceTest, Can_Use_Equals_With_As) {
    // Arrange
    int x = 50;
    int y = 66;
    int z = 73;
    // Act
    XYZSpace *space = new XYZSpace(x, y, z);
    XYZSpace *other_space = space;
    bool result = (space == other_space);
    delete space;
    // Assert
    EXPECT_TRUE(result);
}


TEST(XYZSpaceTest, Can_Use_Not_Equals_In_XYZSpace) {
    // Arrange
    int x = 50;
    int y = 66;
    int z = 73;
    // Act & Assert
    XYZSpace left_space(x, y, z);
    x++; y++; z++;
    XYZSpace right_space(x, y, z);
    EXPECT_TRUE(left_space != right_space);
}

TEST(XYZSpaceTest, Can_Convert_XYZ_To_LAB_Where_Var_Small) {
    // Arrange
    XYZSpace space(0, 0, 0);
    // Act
    LABSpace convert_space(space);
    // Assert
    LABSpace correct_space(0, 0, 0);
    EXPECT_EQ(correct_space, convert_space);
}

TEST(XYZSpaceTest, Can_Convert_Lab_To_XYZ_Where_Var_Small) {
    // Arrange
    LABSpace space(0, 0, 0);
    // Act
    XYZSpace convert_space(space);
    // Assert
    XYZSpace correct_space(0, 0, 0);
    EXPECT_EQ(correct_space, convert_space);
}

TEST(XYZSpaceTest, Can_Convert_XYZ_To_LAB_Where_Var_Big) {
    // Arrange
    XYZSpace space(35, 34, 12);
    // Act
    LABSpace convert_space(space);
    // Assert
    LABSpace correct_space(65, 9, 44);
    EXPECT_EQ(correct_space, convert_space);
}

TEST(XYZSpaceTest, Can_Convert_Lab_To_XYZ_Where_Var_Big) {
    // Arrange
    LABSpace space(6, 4, 2);
    // Act
    XYZSpace convert_space(space);
    // Assert
    XYZSpace correct_space(0, 0, 0);
    EXPECT_EQ(correct_space, convert_space);
}

TEST(XYZSpaceTest, Can_Convert_Lab_To_XYZ_Where_Var_Very_Big) {
    // Arrange
    LABSpace space(56, 6, 6);
    // Act
    XYZSpace convert_space(space);
    // Assert
    XYZSpace correct_space(1, 23, 22);
    EXPECT_EQ(correct_space, convert_space);
}

TEST(XYZSpaceTest, Can_Use_Swap_Method) {
    // Arrange
    XYZSpace space1(1, 2, 3);
    XYZSpace space2(3, 4, 5);
    // Act
    space1 = space2;
    // Assert
    EXPECT_EQ(space1, space2);
}

TEST(XYZSpaceTest, Can_Use_Compare_As) {
    // Arrange
    XYZSpace space(1, 2, 3);
    // Act & Assert
    EXPECT_TRUE(space == space);
}
