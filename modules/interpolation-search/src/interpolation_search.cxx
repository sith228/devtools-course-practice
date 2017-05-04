// Copyright 2017 Yashkov Vladislav

#include "include/interpolation_search.h"

InterpolationSearch::InterpolationSearch(int * sortedArray, int length) {
  SetArray(sortedArray, length);
}

void InterpolationSearch::SetArray(int * sortedArray, int length) {
  if (isArraySorted(sortedArray, length)) {
    sortedArray_ = sortedArray;
    length_ = length;
  } else {
    throw "Array isn't sorted";
  }
}

bool InterpolationSearch::isArraySorted(int * sortedArray, int length) {
  if (sortedArray == nullptr) {
    throw "Array is null";
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

int InterpolationSearch::Search(int toFind) {
  if (isArraySorted(sortedArray_, length_)) {
    // Returns the index of an element with a value of toFind or -1,
    // if there is no such element
    int low_ = 0;
    int high_ = length_ - 1;
    while (sortedArray_[low_] < toFind && sortedArray_[high_] > toFind) {
      int mid_ = low_ + ((toFind - sortedArray_[low_]) *
        (high_ - low_)) / (sortedArray_[high_] - sortedArray_[low_]);
      if (sortedArray_[mid_] < toFind)
        low_ = mid_ + 1;
      else if (sortedArray_[mid_] > toFind)
        high_ = mid_ - 1;
      else
        return mid_;
    }
    if (sortedArray_[low_] == toFind) {
      return low_;
    } else {
      if (sortedArray_[high_] == toFind)
        return high_;
      else
        return -1;
    }
  } else {
    throw "Array isn't valid";
    return -1;
  }
}
