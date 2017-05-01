// Copyright 2017 Grachev Vlad

#include <gtest/gtest.h>

#include "include/bit_array.h"

TEST(BitArray, can_create_bit_array) {
    ASSERT_NO_THROW(BitArray bitArray(5));
}
