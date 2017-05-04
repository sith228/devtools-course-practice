// Copyright 2017 Anna Mironova

#include <gtest/gtest.h>

#include "include/stack.h"

// TESTS FOR INT

TEST(StackTest, Can_Create_Stack_With_Positive_Length_INT) {
    // Arrange & Act & Assert
    ASSERT_NO_THROW(TStack<int> v(5));
}

TEST(StackTest, Cant_Create_Too_Large_Stack_INT) {
    // Arrange & Act & Assert
    ASSERT_ANY_THROW(TStack<int> v(MAX_STACK_SIZE + 1));
}

TEST(StackTest, Cant_Create_Stack_With_Negative_Length_INT) {
    // Arrange & Act & Assert
    ASSERT_ANY_THROW(TStack<int> v(-5));
}

TEST(StackTest, Can_Create_Copied_Stack_INT) {
    // Arrange
    TStack <int> v(10);

    // Act & Assert
    ASSERT_NO_THROW(TStack <int> v1(v));
}

TEST(StackTest, Can_Get_Stack_Size_INT) {
    // Arrange
    TStack <int> v(10);

    // Act & Assert
    EXPECT_EQ(10, v.GetStackSize());
}

TEST(StackTest, Can_Get_Stack_Top_INT) {
    // Arrange
    TStack <int> v(10);
    v.Include(2);
    v.Include(15);

    // Act & Assert
    EXPECT_EQ(1, v.GetStackTop());
}


TEST(StackTest, Can_Include_New_Element_INT) {
    // Arrange
    TStack <int> v(2);

    // Act
    v.Include(5);

    // Assert
    EXPECT_EQ(5, v.Get());
}

TEST(StackTest, Cant_Include_Element_When_Stack_Is_Full_INT) {
    // Arrange
    TStack <int> v(2);
    v.Include(5);
    v.Include(7);

    // Act&Assert
    ASSERT_ANY_THROW(v.Include(9));
}

TEST(StackTest, Can_Exclude_Element_INT) {
    // Arrange
    TStack <int> v(2);
    v.Include(5);

    // Act&Assert
    EXPECT_EQ(5, v.Exclude());
}

TEST(StackTest, Top_Decreases_When_Exclude_Element_INT) {
    // Arrange
    TStack <int> v(2);
    v.Include(5);

    // Act & Assert
    EXPECT_EQ(5, v.Exclude());
    EXPECT_EQ(-1, v.GetStackTop());
}

TEST(StackTest, Can_Get_Element_INT) {
    // Arrange
    TStack <int> v(2);
    v.Include(5);

    // Act&Assert
    EXPECT_EQ(5, v.Get());
}

TEST(StackTest, Top_Does_Not_Change_When_Get_Element_INT) {
    // Arrange
    TStack <int> v(2);
    v.Include(5);

    // Act & Assert
    EXPECT_EQ(5, v.Get());
    EXPECT_EQ(0, v.GetStackTop());
}

TEST(StackTest, Cant_Get_Element_When_Stack_Is_Empty_INT) {
    // Arrange
    TStack <int> v(2);

    // Act & Assert
    ASSERT_ANY_THROW(v.Get());
}

TEST(StackTest, Cant_Exclude_Element_When_Stack_Is_Empty_INT) {
    // Arrange
    TStack <int> v(2);

    // Act & Assert
    ASSERT_ANY_THROW(v.Exclude());
}

TEST(StackTest, New_Stack_Is_Empty_INT) {
    // Arrange
    TStack<int> v(2);

    // Act & Assert
    EXPECT_TRUE(v.CheckEmpty());
}

TEST(StackTest, Can_Check_Full_Stack_INT) {
    // Arrange
    TStack<int> v(2);
    v.Include(5);
    v.Include(7);

    // Act & Assert
    EXPECT_TRUE(v.CheckFull());
}


