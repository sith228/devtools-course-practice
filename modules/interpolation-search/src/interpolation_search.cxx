// Copyright 2017 Yashkov Vladislav

#include "include/interpolation_search.h"

bool InterpolationSearch::IsArrayValid_(int * sorted_array, int length) {
  if (sorted_array == nullptr) {
    throw "Array is null";
  } else {
    if (length < 1) {
      throw "length is null or negative";
    } else {
      for (int i = 1; i < length; i++)
        if (sorted_array[i] < sorted_array[i - 1])
          return false;
      return true;
    }
  }
  return false;
}

int InterpolationSearch::Search(int to_find, int * sorted_array, int length) {
  if (IsArrayValid_(sorted_array, length)) {
    // Returns the index of an element with a value of toFind or -1,
    // if there is no such element
    int low = 0;
    int high = length - 1;
    while (sorted_array[low] < to_find && sorted_array[high] > to_find) {
      int mid = low + ((to_find - sorted_array[low]) *
        (high - low)) / (sorted_array[high] - sorted_array[low]);
      if (sorted_array[mid] < to_find)
        low = mid + 1;
      else if (sorted_array[mid] > to_find)
        high = mid - 1;
      else
        return mid;
    }
    if (sorted_array[low] == to_find) {
      return low;
    } else {
      if (sorted_array[high] == to_find)
        return high;
      else
        return -1;  // Not found
    }
  } else {
    throw "Array isn't valid";
  }
}
