// Copyright 2017 Gvozdeva Viktoria

#ifndef MODULES_GVOZDEVA_VIKTORIA_QUEUE_INCLUDE_QUEUE_H_
#define MODULES_GVOZDEVA_VIKTORIA_QUEUE_INCLUDE_QUEUE_H_

#include <iostream>

template <class valType>

class Queue {
private:
    int head, tail, length, maxSize; ;
    valType *queuePtr;

public:
    //Queue();
    Queue(int _maxSize); 
    ~Queue();
    Queue (const Queue & Q);  
    bool IsFull() const; 
    bool IsEmpty() const; 
    void Push(const valType & ); 
    valType Pop(); 
};

#endif  // MODULES_GVOZDEVA_VIKTORIA_QUEUE_INCLUDE_QUEUE_H_