// Copyright 2017 Vinogradova Ekaterina

#ifndef MODULES_DEQUE_INCLUDE_DEQUE_H_
#define MODULES_DEQUE_INCLUDE_DEQUE_H_

#include <iostream>

#define DefMemSize   25

typedef double    TElem;
typedef TElem*    PTElem;
typedef double    TData;

class Deque {
 protected:
    PTElem pMem;
    int Front;
    int Back;
    int MemSize;
    int DataCount;

    int GetNextFrontIndex(int index);
    int GetNextBackIndex(int index);
 public:
    explicit Deque(int size = DefMemSize);
    ~Deque();
    void InsFront(TElem element);
    void InsBack(TElem element);
    TElem GetFront();
    TElem GetBack();
    bool IsEmpty(void) const;
    bool IsFull(void) const;
};

#endif  // MODULES_DEQUE_INCLUDE_DEQUE_H_
