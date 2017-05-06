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
    realArraySize = bitArray.getSize();

    // Assert
    EXPECT_EQ(realArraySize, expectedArraySize);
}

TEST(BitArrayTest, Bits_Sum_Of_New_Array_Is_Zero) {
    // Arrange
    BitArray bitArray(64);
    int sum = 0;

    // Act
    for (unsigned int i = 0; i < bitArray.getSize(); i++)
        sum += bitArray.getBit(i);

    // Assert
    EXPECT_EQ(sum, 0);
}

TEST(BitArrayTest, Cant_Get_Bit_With_Negative_Index) {
    // Arrange
    BitArray bitArray(8);

    // Assert
    ASSERT_ANY_THROW(bitArray.getBit(-1));
}

TEST(BitArrayTest, Cant_Get_Bit_With_Too_Large_Index) {
    // Arrange
    BitArray bitArray(8);

    // Assert
    ASSERT_ANY_THROW(bitArray.getBit(8));
}

TEST(BitArrayTest, Can_Set_Bit) {
    // Arrange
    BitArray bitArray(8);

    // Act
    bitArray.setBit(4);

    // Assert
    EXPECT_EQ(bitArray.getBit(4), 1);
}

TEST(BitArrayTest, Cant_Set_Bit_With_Negative_Index) {
    // Arrange
    BitArray bitArray(8);

    // Assert
    ASSERT_ANY_THROW(bitArray.setBit(-1));
}

TEST(BitArrayTest, Cant_Set_Bit_With_Too_Large_Index) {
    // Arrange
    BitArray bitArray(8);

    // Assert
    ASSERT_ANY_THROW(bitArray.setBit(8));
}

TEST(BitArrayTest, Can_Clear_Bit) {
    // Arrange
    BitArray bitArray(8);
    int bitValueAftrerSet, bitValueAfterClear;

    // Act
    bitArray.setBit(5);
    bitValueAftrerSet = bitArray.getBit(5);
    bitArray.clearBit(5);
    bitValueAfterClear = bitArray.getBit(5);

    // Assert
    EXPECT_NE(bitValueAftrerSet, bitValueAfterClear);
}

TEST(BitArrayTest, Can_Clear_Bit_With_Zero_Value) {
    // Arrange
    BitArray bitArray(8);

    // Assert
    ASSERT_NO_THROW(bitArray.clearBit(5));
}

TEST(BitArrayTest, Cant_Clear_Bit_With_Negative_Index) {
    // Arrange
    BitArray bitArray(8);

    // Assert
    ASSERT_ANY_THROW(bitArray.clearBit(-1));
}

TEST(BitArrayTest, Cant_Clear_Bit_With_Too_Large_Index) {
    // Arrange
    BitArray bitArray(8);

    // Assert
    ASSERT_ANY_THROW(bitArray.clearBit(8));
}

TEST(BitArrayTest, Can_Assign_Bit_Arrays_With_Equal_Size) {
    // Arrange
    BitArray bitArray1(4), bitArray2(4);
    bool equalityOfBitArrays;

    // Act
    for (unsigned int i = 0; i < bitArray1.getSize(); i++)
        bitArray1.setBit(i);
    bitArray2 = bitArray1;
    equalityOfBitArrays = true;
    for (unsigned int i = 0; i < bitArray1.getSize(); i++) {
        if (bitArray1.getBit(i) != bitArray2.getBit(i))
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
    realArraylSize = bitArray2.getSize();

    // Assert
    EXPECT_EQ(realArraylSize, expectedArraySize);
}

TEST(BitArrayTest, Can_Assign_Bit_Arrays_With_Different_Size) {
    // Arrange
    BitArray bitArray1(16), bitArray2(4);
    bool equalityOfBitArrays;

    // Act
    for (unsigned int i = 0; i < bitArray1.getSize(); i++)
        bitArray1.setBit(i);
    bitArray2 = bitArray1;
    equalityOfBitArrays = true;
    for (unsigned int i = 0; i < bitArray1.getSize(); i++) {
        if (bitArray1.getBit(i) != bitArray2.getBit(i))
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
    bitArray1.setBit(2);
    bitArray1.setBit(4);

    bitArray2 = bitArray1;
    bitArray1.clearBit(4);
    bitArray1.setBit(0);

    for (unsigned int i = 0; i < bitArray1.getSize(); i++) {
        if (bitArray1.getBit(i) != bitArray2.getBit(i))
            equalityOfBitArrays = false;
    }

    // Assert
    ASSERT_FALSE(equalityOfBitArrays);
}

TEST(BitArrayTest, Equal_Bit_Arrays_Are_Equal) {
    //Arrange
    BitArray bitArray1(8), bitArray2(8);

    //Act
    for (unsigned int i = 0; i < bitArray1.getSize(); i++) {
        if (i % 2 == 0) {
            bitArray1.setBit(i);
            bitArray2.setBit(i);
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
    for (unsigned int i = 0; i < bitArray1.getSize(); i++) {
        if (i % 2 == 0)
            bitArray1.setBit(i);
        else
            bitArray2.setBit(i);
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
    for (unsigned int i = 0; i < bitArray1.getSize(); i++) {
        if (i % 2 == 0)
            bitArray1.setBit(i);
    }
    BitArray bitArray2(bitArray1);

    // Assert
    EXPECT_EQ(bitArray1, bitArray2);
}

TEST(BitArrayTest, Copied_Bit_Array_Has_Its_Own_Memory) {
    // Arrange
    BitArray bitArray1(5);

    // Act
    bitArray1.setBit(2);
    bitArray1.setBit(4);

    BitArray bitArray2(bitArray1);
    bitArray1.clearBit(4);
    bitArray1.setBit(0);

    // Assert
    EXPECT_NE(bitArray1, bitArray2);
}

TEST(BitArrayTest, AND_Operator_Applied_To_Bit_Arrays_Of_Equal_Size) {
    // Arrange
    BitArray bitArray1(4), bitArray2(4), expectedBitArray(4);

    // Act
    bitArray1.setBit(2);
    bitArray1.setBit(3);

    bitArray2.setBit(1);
    bitArray2.setBit(3);

    expectedBitArray.setBit(3);

    // Assert
    EXPECT_EQ(expectedBitArray, bitArray1 & bitArray2);
}

TEST(BitArrayTest, AND_Operator_Applied_To_Bit_Arrays_Of_Non_Equal_Size) {
    // Arrange
    BitArray bitArray1(4), bitArray2(5), expectedBitArray(5);

    // Act
    bitArray1.setBit(2);
    bitArray1.setBit(3);

    bitArray2.setBit(1);
    bitArray2.setBit(3);

    expectedBitArray.setBit(3);

    // Assert
    EXPECT_EQ(expectedBitArray, bitArray1 & bitArray2);
}

TEST(BitArrayTest, OR_Operator_Applied_To_Bit_Arrays_Of_Equal_Size) {
    // Arrange
    BitArray bitArray1(4), bitArray2(4), expectedBitArray(4);

    // Act
    bitArray1.setBit(2);
    bitArray1.setBit(3);

    bitArray2.setBit(1);
    bitArray2.setBit(3);

    expectedBitArray.setBit(1);
    expectedBitArray.setBit(2);
    expectedBitArray.setBit(3);

    // Assert
    EXPECT_EQ(expectedBitArray, bitArray1 | bitArray2);
}

TEST(BitArrayTest, OR_Operator_Applied_To_Bit_Arrays_Of_Non_Equal_Size) {
    // Arrange
    BitArray bitArray1(4), bitArray2(5), expectedBitArray(5);

    //Act
    bitArray1.setBit(2);
    bitArray1.setBit(3);

    bitArray2.setBit(1);
    bitArray2.setBit(3);

    expectedBitArray.setBit(1);
    expectedBitArray.setBit(2);
    expectedBitArray.setBit(3);

    // Assert
    EXPECT_EQ(expectedBitArray, bitArray1 | bitArray2);
}

TEST(BitArrayTest, XOR_Operator_Applied_To_Bit_Arrays_Of_Equal_Size) {
    // Arrange
    BitArray bitArray1(4), bitArray2(4), expectedBitArray(4);

    // Act
    bitArray1.setBit(2);
    bitArray1.setBit(3);

    bitArray2.setBit(1);
    bitArray2.setBit(3);

    expectedBitArray.setBit(1);
    expectedBitArray.setBit(2);

    // Assert
    EXPECT_EQ(expectedBitArray, bitArray1 ^ bitArray2);
}

TEST(BitArrayTest, XOR_Operator_Applied_To_Bit_Arrays_Of_Non_Equal_Size) {
    // Arrange
    BitArray bitArray1(4), bitArray2(5), expectedBitArray(5);

    // Act
    bitArray1.setBit(2);
    bitArray1.setBit(3);

    bitArray2.setBit(1);
    bitArray2.setBit(3);

    expectedBitArray.setBit(1);
    expectedBitArray.setBit(2);

    // Assert
    EXPECT_EQ(expectedBitArray, bitArray1 ^ bitArray2);
}

TEST(BitArrayTest, Can_Invert_Bit_Array) {
    // Arrange
    BitArray bf(2), negativeBitArray(2), expectedBitArray(2);

    // Act
    bf.setBit(1);
    negativeBitArray = ~bf;

    expectedBitArray.setBit(0);

    // Assert
    EXPECT_EQ(expectedBitArray, negativeBitArray);
}

TEST(BitArrayTest, Can_Invert_Large_BitArray) {
    // Arrange
    BitArray bitArray(128), negativeBitArray(128), expectedBitArray(128);

    // Act
    for (unsigned int i = 0; i < bitArray.getSize(); i++) {
        if (i % 2 == 0)
            bitArray.setBit(i);
        else
            expectedBitArray.setBit(i);
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
    bitArray.setBit(1);
    bitArray.setBit(3);
    bitArray.setBit(4);
    resultString = bitArray.toString();

    // Assert
    EXPECT_EQ(expectedStrign, resultString);
}
