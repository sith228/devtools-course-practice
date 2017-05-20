// Copyright 2017 Yashkov Vladislav

#ifndef MODULES_INTERPOLATION_SEARCH_INCLUDE_INTERPOLATION_SEARCH_H_
#define MODULES_INTERPOLATION_SEARCH_INCLUDE_INTERPOLATION_SEARCH_H_

class InterpolationSearch {
 public:
    static int Search(int to_find, int * sorted_array, int length);

 private:
    static bool IsArrayValid_(int * sorted_array, int length);
};

#endif  // MODULES_INTERPOLATION_SEARCH_INCLUDE_INTERPOLATION_SEARCH_H_
