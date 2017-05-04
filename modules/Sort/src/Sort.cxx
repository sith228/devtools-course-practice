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

void Sort::QuickSort(int l, int m) {
    int x = Array_[l + (m - l) / 2];
    int temp;
    int i = l;
    int j = m;
    while (i <= j) {
        while (Array_[i] < x) i++;
        while (Array_[j] > x) j--;
        if (i <= j) {
            temp = Array_[i];
            Array_[i] = Array_[j];
            Array_[j] = temp;
            i++;
            j--;
        }
    }
    if (i < m)
       QuickSort(i, m);
    if (l < j)
       QuickSort(l, j);
}

void Sort::PasteSort(void) {
    int counter = 0;
    for (int i = 1; i < Length_; i++) {
        for (int j = i; j > 0 && Array_[j - 1] > Array_[j]; j--) {
            counter++;
            int tmp = Array_[j - 1];
            Array_[j - 1] = Array_[j];
            Array_[j] = tmp;
        }
    }
}
