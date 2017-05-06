// Copyright 2017 Anna Mironova

#ifndef MODULES_STACK_INCLUDE_STACK_H_
#define MODULES_STACK_INCLUDE_STACK_H_

const int MAX_STACK_SIZE = 100000000;

template <class ValType>
class TStack {
 public:
    explicit TStack(int _size = MAX_STACK_SIZE);
    TStack(const TStack &v);
    ~TStack();

    int GetStackSize()const;
    int GetStackTop() const;
    void Push(const ValType elem);
    ValType Pop();
    ValType StTop();
    bool CheckFull() const;
    bool CheckEmpty() const;

    TStack<ValType>& TStack<ValType>::operator=(const TStack& s);

 private:
    ValType *pVector_;
    int Size_;
    int Top_;
};

template <class ValType>
TStack<ValType>::TStack(int _size) {
    if (_size < 0) {
        throw "Negative size";
    } else if (_size > MAX_STACK_SIZE) {
        throw "Size more than MAX_VECTOR_SIZE";
    } else {
        Top_ = -1;
        Size_ = _size;
        pVector_ = new ValType[Size_];
    }
}

template <class ValType>
TStack<ValType>::TStack(const TStack<ValType > &v) {
    Size_ = v.GetStackSize();
    Top_ = v.GetStackTop();
    pVector_ = new ValType[Size_];
    for (int i = 0; i < Top_; i++)
        pVector_[i] = v.pVector_[i];
}

template <class ValType>
TStack<ValType>::~TStack() {
    if (pVector_ != NULL) {
        delete[]pVector_;
    }
}

template <class ValType>
int TStack<ValType>::GetStackSize()const {
    return Size_;
}

template <class ValType>
int TStack<ValType>::GetStackTop()const {
    return Top_;
}

template <class ValType>
void TStack<ValType>::Push(const ValType elem) {
    if (this->CheckFull()) {
        throw "Full stack";
    } else {
        Top_++;
        pVector_[Top_] = elem;
    }
}

template <class ValType>
ValType TStack<ValType>::Pop() {
    if (this->CheckEmpty()) {
        throw "Empty stack";
    } else {
        ValType res;
        res = pVector_[Top_];
        Top_--;
        return res;
    }
}

template <class ValType>
ValType TStack<ValType>::StTop() {
    if (this->CheckEmpty()) {
        throw "Empty stack";
    } else {
        return pVector_[Top_];
    }
}

template <class ValType>
bool TStack<ValType>::CheckFull() const {
    if (Top_ == Size_ - 1) {
        return true;
    } else {
        return false;
    }
}

template <class ValType>
bool TStack<ValType>::CheckEmpty() const {
    if (Top_ == (-1)) {
        return true;
    } else {
        return false;
    }
}

template <class ValType>
TStack<ValType>& TStack<ValType>::operator=(const TStack& s) {
    if (pVector_ == s.pVector_) {
        return *this;
    }
    Size_ = s.Size_;
    Top_ = s.Top_;
    delete[]pVector_;
    pVector_ = new ValType[Size_];
    for (int i = 0; i < Size_; i++) {
        pVector_[i] = s.pVector_[i];
    }
    return *this;
}
#endif  //  MODULES_STACK_INCLUDE_STACK_H_
