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

void Sort::ChoiceSort(void) {
    for (int i = 0; i < Length_; i++) {
        int temp = Array_[0];
        for (int j = i + 1; j < Length_; j++) {
            if (Array_[i] > Array_[j]) {
                temp = Array_[i];
                Array_[i] = Array_[j];
                Array_[j] = temp;
            }
        }
    }
}

void Sort::Merge(int first, int last) {
  int mi, st, e, j;
  int *mas = new int[100];
  mi = (first + last) / 2;
  st = first;
  e = mi + 1;
  for (j = first; j <= last; j++)
    if ((st <= mi) && ((e > last) || (Array_[st] < Array_[e]))) {
        mas[j] = Array_[st];
        st++;
    } else {
        mas[j] = Array_[e];
        e++;
    }
  for (j = first; j <= last; j++) Array_[j] = mas[j];
  delete[]mas;
}

void Sort::MergeSort(int first, int last) {
     if (first < last) {
         MergeSort(first, (first + last) / 2);
         MergeSort((first + last) / 2 + 1, last);
         Merge(first, last);
     }
}
