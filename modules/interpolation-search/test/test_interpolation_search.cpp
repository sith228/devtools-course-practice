// Copyright 2017 Yashkov Vladislav

#include <gtest/gtest.h>

#include "include/interpolation_search.h"

TEST(InterpolationSearch, Can_Create_Search) {
  const int length = 3;
  int * sortedArray = new int[length] {1, 2, 3};
  ASSERT_NO_THROW(InterpolationSearch interpolationSearch(sortedArray, length));
}
