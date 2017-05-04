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

int InterpolationSearch::Search(int search_elem) {
  if (isArraySorted(sortedArray_, length_)) {
    // Returns the index of an element with a value of toFind or -1,
    // if there is no such element
    int top = length_ - 1;
    int low = 0;
	while (search_elem > sortedArray_[low] && search_elem < sortedArray_[top]) {
      int middle = low + ((search_elem - sortedArray_[low]) *
        (top - low)) / (sortedArray_[top] - sortedArray_[low]);
	  if (search_elem > sortedArray_[middle])
        low = middle + 1;
	  else if (search_elem < sortedArray_[middle])
        top = middle - 1;
      else
        return middle;
    }
    if (sortedArray_[low] == search_elem) {
      return low;
    } else {
      if (sortedArray_[top] == search_elem)
        return top;
      else
        return -1;
    }
  } else {
    throw "Array isn't valid";
    return -1;
  }
}
