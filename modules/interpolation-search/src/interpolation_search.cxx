// Copyright 2017 Yashkov Vladislav

#include "include/interpolation_search.h"

InterpolationSearch::InterpolationSearch(int * sortedArray, int length) {
  if (isArraySorted(sortedArray, length)) {
    sortedArray_ = sortedArray;
    length_ = length;
  } else {
    throw "array isn't sorted";
  }
}

bool InterpolationSearch::isArraySorted(int * sortedArray, int length) {
  if (sortedArray == nullptr) {
    throw "array is null";
  } else {
    if (length < 1) {
      throw "length is null or negative";
    } else {
      int i = 1;
      while (i < length) {
        if (sortedArray[i] < sortedArray[i - 1])
          return false;
        i++;
      }
      return true;
    }
  }
  return false;
}
