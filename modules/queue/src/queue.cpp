// Copyright 2017 Gvozdeva Viktoria

#include <include/queue.h>

Queue <valType> :: Queue( int _maxSize)
{
    if ( _maxSize > 0) {
        maxSize = _maxSize;
        queuePtr = new valType [maxSize];
        len = 0;
        begin = 0;
        end = -1;
    }
    else throw "Size is incorrect!";
}

Queue <valType> :: ~Queue()
{
    delete[] queuePtr;
}

Queue <valType> :: Queue( const Queue & Q)
{
    maxSize = Q.maxSize;
    begin = Q.begin;
    end = Q.end;
    len = Q.len;
    queuePtr = new ValType [maxSize];
    for (int i=0; i<= len; i++)
    queuePtr[i] = Q.queuePtr[i]; 
}

bool Queue <valType> :: IsFull() const
{
    return (len == maxSize);
}

bool Queue <valType> :: IsEmpty() const
{
    return  ( len  == 0);
}

void Queue <valType> :: Push(const valType &elem)
{
    if ( IsFull() ) throw "Queue is full!";
    else 
        if (tail == maxSize - 1) tail = 0;
        else 
            {
               tail++;
               queuePtr[tail] = elem;
               length++;
            }
}

valType Queue <valType> :: Pop()
{
    if ( IsEmpty() ) throw "Queue is empty!";
    else
    {
        valType elem = queuePtr[head];
        if ( head == maxSize - 1 ) head = 0;
        else 
            head--;
        length--;
        return elem;
    }
}
