// Copyright 2017 Vinogradova Ekaterina

#include "include/deque.h"

Deque::Deque(int size) : Front(-1), Back(0) {
    DataCount = 0;
    MemSize = size;
    if (size < 0)
        throw "DataErr";
    else if (size == 0)
        pMem = nullptr;
    else
        pMem = new TElem[MemSize];
}

Deque::~Deque() {
    delete[] pMem;
    pMem = nullptr;
}

int Deque::GetNextFrontIndex(int index) {
    return ++index % MemSize;
}

int Deque::GetNextBackIndex(int index) {
    return (index == 0) ? MemSize - 1 : --index;
}

void Deque::InsFront(TElem element) {
    if (pMem == nullptr)
        throw "DataNoMem";
    else if (IsFull())
        throw "DataFull";
    else
    {
        Front = GetNextFrontIndex(Front);
        pMem[Front] = element;
        DataCount++;
    }
}

void Deque::InsBack(TElem element) {
    if (pMem == nullptr)
        throw "DataNoMem";
    else if (IsFull())
        throw "DataFull";
    else
    {
        Back = GetNextBackIndex(Back);
        pMem[Back] = element;
        DataCount++;
    }
}

TElem Deque::GetFront() {
    if (pMem == nullptr)
        throw "DataNoMem";
    else if (IsEmpty())
        throw "DataEmpty";
    else
    {
        DataCount--;
        TData tmp = pMem[Front];
        Front = GetNextBackIndex(Front);
        return tmp;
    }
}

TElem Deque::GetBack() {
    if (pMem == nullptr)
        throw "DataNoMem";
    else if (IsEmpty())
        throw "DataEmpty";
    else
    {
        DataCount--;
        TData tmp = pMem[Back];
        Back = GetNextFrontIndex(Back);
        return tmp;
    }
}

bool Deque::IsEmpty(void) const {
    return DataCount == 0;
}

bool Deque::IsFull(void) const {
    return DataCount == MemSize;
}
