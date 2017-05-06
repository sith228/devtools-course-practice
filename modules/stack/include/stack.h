// Copyright 2017 Anna Mironova

#ifndef MODULES_STACK_INCLUDE_STACK_H_
#define MODULES_STACK_INCLUDE_STACK_H_

const int MAX_STACK_SIZE = 100000000;

template <class ValType>
class TStack {
 public:
    explicit TStack(int _size = MAX_STACK_SIZE );
    TStack(const TStack &v);
    ~TStack();

    int GetStackSize()const;
    int GetStackTop() const;
    void Push(const ValType elem);
    ValType Pop();
    ValType stTop();
    bool CheckFull() const;
    bool CheckEmpty() const;

 private:
    ValType *pVector;
    int Size;
    int Top;
};

template <class ValType>
TStack<ValType>::TStack(int _size) {
    if (_size < 0) {
        throw "Negative size";
    } else if (_size > = MAX_STACK_SIZE) {
        throw "Size more than MAX_VECTOR_SIZE";
    } else {
        Top = -1;
        Size = _size;
        pVector = new ValType[Size];
    }
}

template <class ValType>
TStack<ValType>::TStack(const TStack<ValType > &v) {
    Size = v.GetStackSize();
    Top = v.GetStackTop();
    pVector = new ValType[Size];
    for (int i = 0; i < Top; i++)
        pVector[i] = v.pVector[i];
}

template <class ValType>
TStack<ValType>::~TStack() {
    if (pVector != NULL) {
        delete[]pVector;
    }
}

template <class ValType>
int TStack<ValType>::GetStackSize()const {
    return Size;
}

template <class ValType>
int TStack<ValType>::GetStackTop()const {
    return Top;
}

template <class ValType>
void TStack<ValType>::Push(const ValType elem) {
    if (this->CheckFull()) {
        throw "Full stack";
    } else {
        Top++;
        pVector[Top] = elem;
    }
}

template <class ValType>
ValType TStack<ValType>::Pop() {
    if (this->CheckEmpty()) {
        throw "Empty stack";
    } else {
        ValType res;
        res = pVector[Top];
        Top--;
        return res;
    }
}

template <class ValType>
ValType TStack<ValType>::stTop() {
    if (this->CheckEmpty()) {
        throw "Empty stack";
    } else {
        return pVector[Top];
    }
}

template <class ValType>
bool TStack<ValType>::CheckFull() const {
    if (Top == Size - 1) {
        return true;
    } else {
        return false;
    }
}

template <class ValType>
bool TStack<ValType>::CheckEmpty() const {
    if (Top == (-1)) {
        return true;
    } else {
        return false;
    }
}
#endif  //  MODULES_STACK_INCLUDE_STACK_H_
