// Copyright 2017 Yashkov Vladislav

#include <gtest/gtest.h>

#include "include/interpolation_search.h"

TEST(InterpolationSearch, Can_Create_Search) {
  const int length = 3;
  int * sortedArray = new int[length] {1, 2, 3};
  ASSERT_NO_THROW(InterpolationSearch interpolationSearch(sortedArray, length));
}

TEST(InterpolationSearch, Throws_When_Array_Unsorted) {
  const int len = 3;
  int * unSortedArr = new int[len] {3, 2, 1};
  ASSERT_ANY_THROW(InterpolationSearch interpolationSearch(unSortedArr, len));
}

TEST(InterpolationSearch, No_Throws_When_Array_Sorted) {
  const int len = 3;
  int * sortedArr = new int[len] {1, 2, 3};
  ASSERT_NO_THROW(InterpolationSearch interpolationSearch(sortedArr, len));
}
