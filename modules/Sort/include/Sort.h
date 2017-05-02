// Copyright 2017 Mitrokhin Nikita

#ifndef MODULES_SORT_INCLUDE_SORT_H_
#define MODULES_SORT_INCLUDE_SORT_H_

#include <stdio.h>
#include <iostream>
#include <iomanip>

class Sort {
 public:
    Sort(const int Array_[], int Length);
    ~Sort();
    Sort(const Sort&) = delete;
    int operator[] (int i) const {return Array_[i]; }
    bool operator== (const Sort& z) const;
 private:
    int* Array_;
    int Length_;
};

#endif  // MODULES_SORT_INCLUDE_SORT_H_
