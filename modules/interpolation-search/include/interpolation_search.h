// Copyright 2017 Yashkov Vladislav

#ifndef MODULES_INTERPOLATION_SEARCH_INCLUDE_INTERPOLATION_SEARCH_H_
#define MODULES_INTERPOLATION_SEARCH_INCLUDE_INTERPOLATION_SEARCH_H_

class InterpolationSearch {
 public:
    InterpolationSearch(int * sortedArray, int length);
    void SetArray(int * sortedArray, int length);
    int Search(int toFind);

 private:
    int * sortedArray_;
    unsigned int length_;
    bool isArraySorted(int * sortedArray, int length);
};

#endif  // MODULES_INTERPOLATION_SEARCH_INCLUDE_INTERPOLATION_SEARCH_H_
