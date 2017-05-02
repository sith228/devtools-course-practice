// Copyright 2017 Mitrokhin Nikita

#include "include/Sort.h"

Sort::Sort(const int Array[], int Length) {
    Array_ = new int[Length];
    Length_ = Length;
    for (int i = 0; i < Length_; i++)
       Array_[i] = Array[i];
}

Sort::~Sort() {
    delete[] Array_;
}

bool Sort::operator==(const Sort & z) const {
        bool result = true;
        if (z.Length_ != Length_) {
           result = false;
        } else {
           for (int i = 0; i < Length_; i++) {
                 if (Array_[i] != z.Array_[i])
                    result = false;
            }
        }
        return result;
}
