// Copyright 2017 Grachev Vlad

#include <gtest/gtest.h>

#include <string>
#include "include/bit_array.h"

TEST(BitArrayTest, Can_Create_Bit_Array_With_Positive_Size) {
    // Assert
    ASSERT_NO_THROW(BitArray bitArray(8));
}

TEST(BitArrayTest, Cant_Create_Bit_Array_With_Size_Zero) {
    // Assert
    ASSERT_ANY_THROW(BitArray bitArray(0));
}

TEST(BitArrayTest, Cant_Create_Bit_Array_With_Negative_Size) {
    // Assert
    ASSERT_ANY_THROW(BitArray bitArray(0));
}

TEST(BitArrayTest, Can_Get_Size) {
    // Arrange
    BitArray bitArray(8);
    unsigned int expectedArraySize = 8, realArraySize;

    // Act
    realArraySize = bitArray.GetSize();

    // Assert
    EXPECT_EQ(expectedArraySize, realArraySize);
}

TEST(BitArrayTest, Bits_Sum_Of_New_Array_Is_Zero) {
    // Arrange
    BitArray bitArray(64);
    int sum = 0;

    // Act
    for (unsigned int i = 0; i < bitArray.GetSize(); i++)
        sum += bitArray.GetBit(i);

    // Assert
    EXPECT_EQ(sum, 0);
}

TEST(BitArrayTest, Cant_Get_Bit_With_Negative_Index) {
    // Arrange
    BitArray bitArray(8);

    // Assert
    ASSERT_ANY_THROW(bitArray.GetBit(-1));
}

TEST(BitArrayTest, Cant_Get_Bit_With_Too_Large_Index) {
    // Arrange
    BitArray bitArray(8);

    // Assert
    ASSERT_ANY_THROW(bitArray.GetBit(8));
}

TEST(BitArrayTest, Can_Set_Bit) {
    // Arrange
    BitArray bitArray(8);

    // Act
    bitArray.SetBit(4);

    // Assert
    EXPECT_EQ(bitArray.GetBit(4), 1);
}

TEST(BitArrayTest, Cant_Set_Bit_With_Negative_Index) {
    // Arrange
    BitArray bitArray(8);

    // Assert
    ASSERT_ANY_THROW(bitArray.SetBit(-1));
}

TEST(BitArrayTest, Cant_Set_Bit_With_Too_Large_Index) {
    // Arrange
    BitArray bitArray(8);

    // Assert
    ASSERT_ANY_THROW(bitArray.SetBit(8));
}

TEST(BitArrayTest, Can_Clear_Bit) {
    // Arrange
    BitArray bitArray(8);
    int bitValueAftrerSet, bitValueAfterClear;

    // Act
    bitArray.SetBit(5);
    bitValueAftrerSet = bitArray.GetBit(5);
    bitArray.ClearBit(5);
    bitValueAfterClear = bitArray.GetBit(5);

    // Assert
    EXPECT_NE(bitValueAftrerSet, bitValueAfterClear);
}

TEST(BitArrayTest, Can_Clear_Bit_With_Zero_Value) {
    // Arrange
    BitArray bitArray(8);

    // Assert
    ASSERT_NO_THROW(bitArray.ClearBit(5));
}

TEST(BitArrayTest, Cant_Clear_Bit_With_Negative_Index) {
    // Arrange
    BitArray bitArray(8);

    // Assert
    ASSERT_ANY_THROW(bitArray.ClearBit(-1));
}

TEST(BitArrayTest, Cant_Clear_Bit_With_Too_Large_Index) {
    // Arrange
    BitArray bitArray(8);

    // Assert
    ASSERT_ANY_THROW(bitArray.ClearBit(8));
}

TEST(BitArrayTest, Can_Assign_Bit_Arrays_With_Equal_Size) {
    // Arrange
    BitArray bitArray1(4), bitArray2(4);
    bool equalityOfBitArrays;

    // Act
    for (unsigned int i = 0; i < bitArray1.GetSize(); i++)
        bitArray1.SetBit(i);
    bitArray2 = bitArray1;
    equalityOfBitArrays = true;
    for (unsigned int i = 0; i < bitArray1.GetSize(); i++) {
        if (bitArray1.GetBit(i) != bitArray2.GetBit(i))
            equalityOfBitArrays = false;
    }

    // Assert
    ASSERT_TRUE(equalityOfBitArrays);
}

TEST(BitArrayTest, Assing_Operator_Changes_Bit_Array_Size) {
    // Arrange
    BitArray bitArray1(16), bitArray2(4);
    unsigned int expectedArraySize = 16, realArraylSize;

    // Act
    bitArray2 = bitArray1;
    realArraylSize = bitArray2.GetSize();

    // Assert
    EXPECT_EQ(realArraylSize, expectedArraySize);
}

TEST(BitArrayTest, Can_Assign_Bit_Arrays_With_Different_Size) {
    // Arrange
    BitArray bitArray1(16), bitArray2(4);
    bool equalityOfBitArrays;

    // Act
    for (unsigned int i = 0; i < bitArray1.GetSize(); i++)
        bitArray1.SetBit(i);
    bitArray2 = bitArray1;
    equalityOfBitArrays = true;
    for (unsigned int i = 0; i < bitArray1.GetSize(); i++) {
        if (bitArray1.GetBit(i) != bitArray2.GetBit(i))
            equalityOfBitArrays = false;
    }

    // Assert
    ASSERT_TRUE(equalityOfBitArrays);
}

TEST(BitArrayTest, Assigned_Bit_Array_Has_Its_Own_Memory) {
    // Arrange
    BitArray bitArray1(5), bitArray2(8);
    bool equalityOfBitArrays;

    // Act
    bitArray1.SetBit(2);
    bitArray1.SetBit(4);

    bitArray2 = bitArray1;
    bitArray1.ClearBit(4);
    bitArray1.SetBit(0);

    for (unsigned int i = 0; i < bitArray1.GetSize(); i++) {
        if (bitArray1.GetBit(i) != bitArray2.GetBit(i))
            equalityOfBitArrays = false;
    }

    // Assert
    ASSERT_FALSE(equalityOfBitArrays);
}

TEST(BitArrayTest, Equal_Bit_Arrays_Are_Equal) {
    // Arrange
    BitArray bitArray1(8), bitArray2(8);

    // Act
    for (unsigned int i = 0; i < bitArray1.GetSize(); i++) {
        if (i % 2 == 0) {
            bitArray1.SetBit(i);
            bitArray2.SetBit(i);
        }
    }

    // Assert
    ASSERT_TRUE(bitArray1 == bitArray2);
}

TEST(BitArrayTest, Bit_Arrays_Witn_Different_Size_Are_Not_Equal) {
    // Arrange
    BitArray bitArray1(8), bitArray2(16);
    bool equalityOfBitArrays;

    // Act
    equalityOfBitArrays = !(bitArray1 == bitArray2) && (bitArray1 != bitArray2);

    // Assert
    ASSERT_TRUE(equalityOfBitArrays);
}

TEST(BitArrayTest, Not_Equal_Bit_Arrays_Are_Not_Equal) {
    // Arrange
    BitArray bitArray1(8), bitArray2(8);
    bool equalityOfBitArrays;

    // Act
    for (unsigned int i = 0; i < bitArray1.GetSize(); i++) {
        if (i % 2 == 0)
            bitArray1.SetBit(i);
        else
            bitArray2.SetBit(i);
    }
    equalityOfBitArrays = !(bitArray1 == bitArray2) || (bitArray1 != bitArray2);

    // Assert
    ASSERT_TRUE(equalityOfBitArrays);
}

TEST(BitArrayTest, Can_Copy_Bit_Array) {
    // Arrange
    BitArray bitArray1(8);

    // Assert
    ASSERT_NO_THROW(BitArray bitArray2(bitArray1));
}

TEST(BitArrayTest, Copied_Bit_Array_Is_Equal_Original) {
    // Arrange
    BitArray bitArray1(8);

    // Act
    for (unsigned int i = 0; i < bitArray1.GetSize(); i++) {
        if (i % 2 == 0)
            bitArray1.SetBit(i);
    }
    BitArray bitArray2(bitArray1);

    // Assert
    EXPECT_EQ(bitArray1, bitArray2);
}

TEST(BitArrayTest, Copied_Bit_Array_Has_Its_Own_Memory) {
    // Arrange
    BitArray bitArray1(5);

    // Act
    bitArray1.SetBit(2);
    bitArray1.SetBit(4);

    BitArray bitArray2(bitArray1);
    bitArray1.ClearBit(4);
    bitArray1.SetBit(0);

    // Assert
    EXPECT_NE(bitArray1, bitArray2);
}

TEST(BitArrayTest, AND_Operator_Applied_To_Bit_Arrays_Of_Equal_Size) {
    // Arrange
    BitArray bitArray1(4), bitArray2(4), expectedBitArray(4);

    // Act
    bitArray1.SetBit(2);
    bitArray1.SetBit(3);

    bitArray2.SetBit(1);
    bitArray2.SetBit(3);

    expectedBitArray.SetBit(3);

    // Assert
    EXPECT_EQ(expectedBitArray, bitArray1 & bitArray2);
}

TEST(BitArrayTest, AND_Operator_Applied_To_Bit_Arrays_Of_Non_Equal_Size) {
    // Arrange
    BitArray bitArray1(4), bitArray2(5), expectedBitArray(5);

    // Act
    bitArray1.SetBit(2);
    bitArray1.SetBit(3);

    bitArray2.SetBit(1);
    bitArray2.SetBit(3);

    expectedBitArray.SetBit(3);

    // Assert
    EXPECT_EQ(expectedBitArray, bitArray1 & bitArray2);
}

TEST(BitArrayTest, OR_Operator_Applied_To_Bit_Arrays_Of_Equal_Size) {
    // Arrange
    BitArray bitArray1(4), bitArray2(4), expectedBitArray(4);

    // Act
    bitArray1.SetBit(2);
    bitArray1.SetBit(3);

    bitArray2.SetBit(1);
    bitArray2.SetBit(3);

    expectedBitArray.SetBit(1);
    expectedBitArray.SetBit(2);
    expectedBitArray.SetBit(3);

    // Assert
    EXPECT_EQ(expectedBitArray, bitArray1 | bitArray2);
}

TEST(BitArrayTest, OR_Operator_Applied_To_Bit_Arrays_Of_Non_Equal_Size) {
    // Arrange
    BitArray bitArray1(4), bitArray2(5), expectedBitArray(5);

    // Act
    bitArray1.SetBit(2);
    bitArray1.SetBit(3);

    bitArray2.SetBit(1);
    bitArray2.SetBit(3);

    expectedBitArray.SetBit(1);
    expectedBitArray.SetBit(2);
    expectedBitArray.SetBit(3);

    // Assert
    EXPECT_EQ(expectedBitArray, bitArray1 | bitArray2);
}

TEST(BitArrayTest, XOR_Operator_Applied_To_Bit_Arrays_Of_Equal_Size) {
    // Arrange
    BitArray bitArray1(4), bitArray2(4), expectedBitArray(4);

    // Act
    bitArray1.SetBit(2);
    bitArray1.SetBit(3);

    bitArray2.SetBit(1);
    bitArray2.SetBit(3);

    expectedBitArray.SetBit(1);
    expectedBitArray.SetBit(2);

    // Assert
    EXPECT_EQ(expectedBitArray, bitArray1 ^ bitArray2);
}

TEST(BitArrayTest, XOR_Operator_Applied_To_Bit_Arrays_Of_Non_Equal_Size) {
    // Arrange
    BitArray bitArray1(4), bitArray2(5), expectedBitArray(5);

    // Act
    bitArray1.SetBit(2);
    bitArray1.SetBit(3);

    bitArray2.SetBit(1);
    bitArray2.SetBit(3);

    expectedBitArray.SetBit(1);
    expectedBitArray.SetBit(2);

    // Assert
    EXPECT_EQ(expectedBitArray, bitArray1 ^ bitArray2);
}

TEST(BitArrayTest, Can_Invert_Bit_Array) {
    // Arrange
    BitArray bf(2), negativeBitArray(2), expectedBitArray(2);

    // Act
    bf.SetBit(1);
    negativeBitArray = ~bf;

    expectedBitArray.SetBit(0);

    // Assert
    EXPECT_EQ(expectedBitArray, negativeBitArray);
}

TEST(BitArrayTest, Can_Invert_Large_BitArray) {
    // Arrange
    BitArray bitArray(128), negativeBitArray(128), expectedBitArray(128);

    // Act
    for (unsigned int i = 0; i < bitArray.GetSize(); i++) {
        if (i % 2 == 0)
            bitArray.SetBit(i);
        else
            expectedBitArray.SetBit(i);
    }
    negativeBitArray = ~bitArray;

    // Assert
    EXPECT_EQ(expectedBitArray, negativeBitArray);
}

TEST(BitArrayTest, Can_Transform_Bit_Array_Into_Strign) {
    // Arrange
    BitArray bitArray(8);
    std::string resultString, expectedStrign = "00011010";

    // Act
    bitArray.SetBit(1);
    bitArray.SetBit(3);
    bitArray.SetBit(4);
    resultString = bitArray.ToString();

    // Assert
    EXPECT_EQ(expectedStrign, resultString);
}
