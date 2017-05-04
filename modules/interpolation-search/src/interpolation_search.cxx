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
    int mid;
    int low = 0;
    int high = length_ - 1;
    while (sortedArray_[low] < toFind && sortedArray_[high] > toFind) {
      mid = low + ((toFind - sortedArray_[low]) *
        (high - low)) / (sortedArray_[high] - sortedArray_[low]);
      if (sortedArray_[mid] < toFind)
        low = mid + 1;
      else if (sortedArray_[mid] > toFind)
        high = mid - 1;
      else
        return mid;
    }
    if (sortedArray_[low] == toFind) {
      return low;
    } else {
      if (sortedArray_[high] == toFind)
        return high;
      else
        return -1;  // Not found
    }
  } else {
    throw "Array isn't valid";
    return -1;
  }
}
