// Copyright 2017 Yashkov Vladislav

#ifndef MODULES_INTERPOLATION_SEARCH_INCLUDE_INTERPOLATION_SEARCH_H_
#define MODULES_INTERPOLATION_SEARCH_INCLUDE_INTERPOLATION_SEARCH_H_

class InterpolationSearch {
 public:
    int Search(int toFind, int * sortedArray, int length);

 private:
    bool isArrayValid_(int * sortedArray, int length);
};

#endif  // MODULES_INTERPOLATION_SEARCH_INCLUDE_INTERPOLATION_SEARCH_H_
