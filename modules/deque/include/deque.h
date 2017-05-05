// Copyright 2017 Vinogradova Ekaterina

#ifndef DEQUE_H_
#define DEQUE_H_

#include <iostream>

using namespace std;

#define DefMemSize   25     // размер памяти по умолчанию

typedef double    TElem;    // тип элемента
typedef TElem*    PTElem;
typedef double    TData;    // тип значений

class Deque
{
protected:
    PTElem pMem;      // память для СД
    int Front;
    int Back;
    int MemSize;      // размер памяти для СД
    int DataCount;    // количество элементов в СД

    int GetNextFrontIndex(int index);
    int GetNextBackIndex(int index);
public:
    Deque(int size = DefMemSize);
    ~Deque();
    void InsFront(TElem element);
    void InsBack(TElem element);
    TElem GetFront();
    TElem GetBack();
    bool IsEmpty(void) const;
    bool IsFull(void) const;
};

#endif  // DEQUE_H_
