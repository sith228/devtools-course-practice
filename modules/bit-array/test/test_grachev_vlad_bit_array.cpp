// Copyright 2017 Grachev Vlad

#include <gtest/gtest.h>

#include "include/bit_array.h"

TEST(BitArray, can_create_bit_array_with_positive_size) {
    ASSERT_NO_THROW(BitArray bitArray(8));
}

TEST(BitArray, cant_create_bit_array_with_size_zero) {
    ASSERT_ANY_THROW(BitArray bitArray(0));
}

TEST(BitArray, cant_create_bit_array_with_negative_size) {
    ASSERT_ANY_THROW(BitArray bitArray(-10));
}

TEST(BitArray, can_get_size) {
    BitArray bitArray(8);

    EXPECT_EQ(bitArray.getSize(), 8);
}

TEST(BitArray, bits_sum_of_new_array_is_zero) {
    BitArray bitArray(64);
    int sum = 0;

    for (unsigned int i = 0; i < bitArray.getSize(); i++)
        sum += bitArray.getBit(i);

    EXPECT_EQ(sum, 0);
}

TEST(BitArray, cant_get_bit_with_negative_index) {
    BitArray bitArray(8);

    ASSERT_ANY_THROW(bitArray.getBit(-1));
}

TEST(BitArray, cant_get_bit_with_too_large_index) {
    BitArray bitArray(8);

    ASSERT_ANY_THROW(bitArray.getBit(8));
}

TEST(BitArray, can_set_bit) {
    BitArray bitArray(8);

    bitArray.setBit(4);

    EXPECT_EQ(bitArray.getBit(4), 1);
}

TEST(BitArray, cant_set_bit_with_negative_index) {
    BitArray bitArray(8);

    ASSERT_ANY_THROW(bitArray.setBit(-1));
}

TEST(BitArray, cant_set_bit_with_too_large_index) {
    BitArray bitArray(8);

    ASSERT_ANY_THROW(bitArray.setBit(8));
}

TEST(BitArray, can_clear_bit) {
    BitArray bitArray(8);
    int bitValueAftrerSet, bitValueAfterClear;

    bitArray.setBit(5);
    bitValueAftrerSet = bitArray.getBit(5);
    bitArray.clearBit(5);
    bitValueAfterClear = bitArray.getBit(5);

    EXPECT_NE(bitValueAftrerSet, bitValueAfterClear);
}

TEST(BitArray, can_clear_bit_with_zero_value) {
    BitArray bitArray(8);

    ASSERT_NO_THROW(bitArray.clearBit(5));
}

TEST(BitArray, cant_clear_bit_with_negative_index) {
    BitArray bitArray(8);

    ASSERT_ANY_THROW(bitArray.clearBit(-1));
}

TEST(BitArray, cant_clear_bit_with_too_large_index) {
    BitArray bitArray(8);

    ASSERT_ANY_THROW(bitArray.clearBit(8));
}

TEST(BitArray, can_assign_bit_arrays_with_equal_size) {
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

TEST(BitArray, assing_operator_changes_bit_array_size) {
    BitArray bitArray1(16), bitArray2(4);

    bitArray2 = bitArray1;

    EXPECT_EQ(bitArray2.getSize(), 16);
}

TEST(BitArray, can_assign_bit_arrays_with_non_equal_size) {
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

TEST(BitArray, or_operator_applied_to_bit_arrays_of_equal_size) {
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

TEST(BitArray, or_operator_applied_to_bit_arrays_of_non_equal_size) {
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

TEST(BitArray, and_operator_applied_to_bit_arrays_of_equal_size) {
    BitArray bitArray1(4), bitArray2(4), expectedBitArray(4);

    bitArray1.setBit(2);
    bitArray1.setBit(3);

    bitArray2.setBit(1);
    bitArray2.setBit(3);

    expectedBitArray.setBit(3);

    EXPECT_EQ(expectedBitArray, bitArray1 & bitArray2);
}

TEST(BitArray, and_operator_applied_to_bit_arrays_of_non_equal_size) {
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
