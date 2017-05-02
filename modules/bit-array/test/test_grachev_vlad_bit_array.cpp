// Copyright 2017 Grachev Vlad

#include <gtest/gtest.h>

#include "include/bit_array.h"
#include <string>

TEST(BitArrayTest, Can_Create_Bit_Array_With_Positive_Size) {
    ASSERT_NO_THROW(BitArray bitArray(8));
}

TEST(BitArrayTest,  Cant_Create_Bit_Array_With_Size_Zero) {
    ASSERT_ANY_THROW(BitArray bitArray(0));
}

TEST(BitArrayTest,  Cant_Create_Bit_Array_With_Negative_Size) {
    ASSERT_ANY_THROW(BitArray bitArray(0));
}

TEST(BitArrayTest,  Can_Get_Size) {
    BitArray bitArray(8);

    EXPECT_EQ(bitArray.getSize(), 8);
}

TEST(BitArrayTest,  Bits_Sum_Of_New_Array_Is_Zero) {
    BitArray bitArray(64);
    int sum = 0;

    for (unsigned int i = 0; i < bitArray.getSize(); i++)
        sum += bitArray.getBit(i);

    EXPECT_EQ(sum, 0);
}

TEST(BitArrayTest,  Cant_Get_Bit_With_Negative_Index) {
    BitArray bitArray(8);

    ASSERT_ANY_THROW(bitArray.getBit(-1));
}

TEST(BitArrayTest,  Cant_Get_Bit_With_Too_Large_Index) {
    BitArray bitArray(8);

    ASSERT_ANY_THROW(bitArray.getBit(8));
}

TEST(BitArrayTest,  Can_Set_Bit) {
    BitArray bitArray(8);

    bitArray.setBit(4);

    EXPECT_EQ(bitArray.getBit(4), 1);
}

TEST(BitArrayTest,  Cant_Set_Bit_With_Negative_Index) {
    BitArray bitArray(8);

    ASSERT_ANY_THROW(bitArray.setBit(-1));
}

TEST(BitArrayTest,  Cant_Set_Bit_With_Too_Large_Index) {
    BitArray bitArray(8);

    ASSERT_ANY_THROW(bitArray.setBit(8));
}

TEST(BitArrayTest,  Can_Clear_Bit) {
    BitArray bitArray(8);
    int bitValueAftrerSet, bitValueAfterClear;

    bitArray.setBit(5);
    bitValueAftrerSet = bitArray.getBit(5);
    bitArray.clearBit(5);
    bitValueAfterClear = bitArray.getBit(5);

    EXPECT_NE(bitValueAftrerSet, bitValueAfterClear);
}

TEST(BitArrayTest,  Can_Clear_Bit_With_Zero_Value) {
    BitArray bitArray(8);

    ASSERT_NO_THROW(bitArray.clearBit(5));
}

TEST(BitArrayTest,  Cant_Clear_Bit_With_Negative_Index) {
    BitArray bitArray(8);

    ASSERT_ANY_THROW(bitArray.clearBit(-1));
}

TEST(BitArrayTest,  Cant_Clear_Bit_With_Too_Large_Index) {
    BitArray bitArray(8);

    ASSERT_ANY_THROW(bitArray.clearBit(8));
}

TEST(BitArrayTest,  Can_Assign_Bit_Arrays_With_Equal_Size) {
    BitArray bitArray1(4), bitArray2(4);
    bool equalityOfBitArrays;

    for (unsigned int i = 0; i < bitArray1.getSize(); i++)
        bitArray1.setBit(i);
    bitArray2 = bitArray1;
    equalityOfBitArrays = true;
    for (unsigned int i = 0; i < bitArray1.getSize(); i++) {
        if (bitArray1.getBit(i) != bitArray2.getBit(i))
            equalityOfBitArrays = false;
    }

    ASSERT_TRUE(equalityOfBitArrays);
}

TEST(BitArrayTest,  Assing_Operator_Changes_Bit_Array_Size) {
    BitArray bitArray1(16), bitArray2(4);

    bitArray2 = bitArray1;

    EXPECT_EQ(bitArray2.getSize(), 16);
}

TEST(BitArrayTest,  Can_Assign_Bit_Arrays_With_Different_Size) {
    BitArray bitArray1(16), bitArray2(4);
    bool equalityOfBitArrays;

    for (unsigned int i = 0; i < bitArray1.getSize(); i++)
        bitArray1.setBit(i);
    bitArray2 = bitArray1;
    equalityOfBitArrays = true;
    for (unsigned int i = 0; i < bitArray1.getSize(); i++) {
        if (bitArray1.getBit(i) != bitArray2.getBit(i))
            equalityOfBitArrays = false;
    }

    ASSERT_TRUE(equalityOfBitArrays);
}

TEST(BitArrayTest, Assigned_Bit_Array_Has_Its_Own_Memory) {
    BitArray bitArray1(5), bitArray2(8);
    bool equalityOfBitArrays;

    bitArray1.setBit(2);
    bitArray1.setBit(4);

    bitArray2 = bitArray1;
    bitArray1.clearBit(4);
    bitArray1.setBit(0);

    for (unsigned int i = 0; i < bitArray1.getSize(); i++) {
        if (bitArray1.getBit(i) != bitArray2.getBit(i))
            equalityOfBitArrays = false;
    }

    ASSERT_FALSE(equalityOfBitArrays);
}

TEST(BitArrayTest, Equal_Bit_Arrays_Are_Equal) {
    BitArray bitArray1(8), bitArray2(8);

    for (unsigned int i = 0; i < bitArray1.getSize(); i++) {
        if (i % 2 == 0) {
            bitArray1.setBit(i);
            bitArray2.setBit(i);
        }
    }

    ASSERT_TRUE(bitArray1 == bitArray2);
}

TEST(BitArrayTest,  Bit_Arrays_Witn_Different_Size_Are_Not_Equal) {
    BitArray bitArray1(8), bitArray2(16);
    bool equalityOfBitArrays;

    equalityOfBitArrays = !(bitArray1 == bitArray2) && (bitArray1 != bitArray2);

    ASSERT_TRUE(equalityOfBitArrays);
}

TEST(BitArrayTest,  Not_Equal_Bit_Arrays_Are_Not_Equal) {
    BitArray bitArray1(8), bitArray2(8);
    bool equalityOfBitArrays;

    for (unsigned int i = 0; i < bitArray1.getSize(); i++) {
        if (i % 2 == 0)
            bitArray1.setBit(i);
        else
            bitArray2.setBit(i);
    }
    equalityOfBitArrays = !(bitArray1 == bitArray2) || (bitArray1 != bitArray2);

    ASSERT_TRUE(equalityOfBitArrays);
}

TEST(BitArrayTest, Can_Copy_Bit_Array) {
    BitArray bitArray1(8);

    ASSERT_NO_THROW(BitArray bitArray2(bitArray1));
}

TEST(BitArrayTest, Copied_Bit_Array_Is_Equal_Original) {
    BitArray bitArray1(8);

    for (unsigned int i = 0; i < bitArray1.getSize(); i++) {
        if (i % 2 == 0)
            bitArray1.setBit(i);
    }
    BitArray bitArray2(bitArray1);

    EXPECT_EQ(bitArray1, bitArray2);
}

TEST(BitArrayTest, Copied_Bit_Array_Has_Its_Own_Memory) {
    BitArray bitArray1(5);

    bitArray1.setBit(2);
    bitArray1.setBit(4);

    BitArray bitArray2(bitArray1);
    bitArray1.clearBit(4);
    bitArray1.setBit(0);

    EXPECT_NE(bitArray1, bitArray2);
}

TEST(BitArrayTest, AND_Operator_Applied_To_Bit_Arrays_Of_Equal_Size) {
    BitArray bitArray1(4), bitArray2(4), expectedBitArray(4);

    bitArray1.setBit(2);
    bitArray1.setBit(3);

    bitArray2.setBit(1);
    bitArray2.setBit(3);

    expectedBitArray.setBit(3);

    EXPECT_EQ(expectedBitArray, bitArray1 & bitArray2);
}

TEST(BitArrayTest, AND_Operator_Applied_To_Bit_Arrays_Of_Non_Equal_Size) {
    BitArray bitArray1(4), bitArray2(5), expectedBitArray(5);

    bitArray1.setBit(2);
    bitArray1.setBit(3);

    bitArray2.setBit(1);
    bitArray2.setBit(3);

    expectedBitArray.setBit(1);
    expectedBitArray.setBit(2);
    expectedBitArray.setBit(3);

    EXPECT_EQ(expectedBitArray, bitArray1 | bitArray2);
}

TEST(BitArrayTest,  OR_Operator_Applied_To_Bit_Arrays_Of_Equal_Size) {
    BitArray bitArray1(4), bitArray2(4), expectedBitArray(4);

    bitArray1.setBit(2);
    bitArray1.setBit(3);

    bitArray2.setBit(1);
    bitArray2.setBit(3);

    expectedBitArray.setBit(1);
    expectedBitArray.setBit(2);
    expectedBitArray.setBit(3);

    EXPECT_EQ(expectedBitArray, bitArray1 | bitArray2);
}

TEST(BitArrayTest,  OR_Operator_Applied_To_Bit_Arrays_Of_Non_Equal_Size) {
    BitArray bitArray1(4), bitArray2(5), expectedBitArray(5);

    bitArray1.setBit(2);
    bitArray1.setBit(3);

    bitArray2.setBit(1);
    bitArray2.setBit(3);

    expectedBitArray.setBit(1);
    expectedBitArray.setBit(2);
    expectedBitArray.setBit(3);

    EXPECT_EQ(expectedBitArray, bitArray1 | bitArray2);
}

TEST(BitArrayTest, XOR_Operator_Applied_To_Bit_Arrays_Of_Equal_Size) {
    BitArray bitArray1(4), bitArray2(4), expectedBitArray(4);

    bitArray1.setBit(2);
    bitArray1.setBit(3);

    bitArray2.setBit(1);
    bitArray2.setBit(3);

    expectedBitArray.setBit(1);
    expectedBitArray.setBit(2);

    EXPECT_EQ(expectedBitArray, bitArray1 ^ bitArray2);
}

TEST(BitArrayTest, XOR_Operator_Applied_To_Bit_Arrays_Of_Non_Equal_Size) {
    BitArray bitArray1(4), bitArray2(5), expectedBitArray(5);

    bitArray1.setBit(2);
    bitArray1.setBit(3);

    bitArray2.setBit(1);
    bitArray2.setBit(3);

    expectedBitArray.setBit(1);
    expectedBitArray.setBit(2);

    EXPECT_EQ(expectedBitArray, bitArray1 ^ bitArray2);
}

TEST(BitArrayTest,  Can_Invert_Bit_Array)
{
    BitArray bf(2), negativeBitArray(2), expectedBitArray(2);

    bf.setBit(1);
    negativeBitArray = ~bf;

    expectedBitArray.setBit(0);

    EXPECT_EQ(expectedBitArray, negativeBitArray);
}

TEST(BitArrayTest,  Can_Invert_Large_Bit_Array)
{
    const int size = 38;
    BitArray bf(size), negativeBitArray(size), expectedBitArray(size);
    bf.setBit(35);
    negativeBitArray = ~bf;

    for (int i = 0; i < size; i++)
        expectedBitArray.setBit(i);
    expectedBitArray.clearBit(35);

    EXPECT_EQ(expectedBitArray, negativeBitArray);
}

TEST(BitArrayTest, Can_Invert_Large_BitArray)
{
    BitArray bitArray(128), negativeBitArray(128), expectedBitArray(128);

    for (unsigned int i = 0; i < bitArray.getSize(); i++) {
        if (i % 2 == 0)
            bitArray.setBit(i);
        else
            expectedBitArray.setBit(i);
    }
    negativeBitArray = ~bitArray;

    EXPECT_EQ(expectedBitArray, negativeBitArray);
}

TEST(BitArrayTest, Can_Transform_Bit_Array_Into_Strign) {
    BitArray bitArray(8);
    std::string resultString, expectedStrign = "00011010";

    bitArray.setBit(1);
    bitArray.setBit(3);
    bitArray.setBit(4);
    resultString = bitArray.toString();

    EXPECT_EQ(expectedStrign, resultString);
}
