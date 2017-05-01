// Copyright 2017 Gvozdeva Viktoria

#include <include/queue.h>
template <class valType>
Queue <valType> :: Queue( int _maxSize)
{
    if ( _maxSize > 0) {
        maxSize = _maxSize;
        queuePtr = new valType [maxSize];
        length = 0;
        head = 0;
        tail = -1;
    }
    else throw "Size is incorrect!";
}
template <class valType>
Queue <valType> :: ~Queue()
{
    delete[] queuePtr;
}
template <class valType>
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
template <class valType>
bool Queue <valType> :: IsFull() const
{
    return (length == maxSize);
}
template <class valType>
bool Queue <valType> :: IsEmpty() const
{
    return  ( length  == 0);
}
template <class valType>
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
template <class valType>
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
