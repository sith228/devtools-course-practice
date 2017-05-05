// Copyright 2017 Gvozdeva Viktoriia

#ifndef MODULES_QUEUE_INCLUDE_QUEUE_H_
#define MODULES_QUEUE_INCLUDE_QUEUE_H_

const int MAX_SIZE = 1000000;

template <typename valType>
class Queue {
 private:
    int head, tail, len, maxSize;
    valType *queuePtr;

 public:
    explicit Queue(int _maxSize);
    ~Queue();
    Queue(const Queue &);
    bool IsFull() const;
    bool operator==(const Queue<valType>&) const;
    Queue<valType>& operator=(const Queue<valType>&);
    bool IsEmpty() const;
    void Push(const valType&);
    valType Pop();
};

template <class valType>
Queue <valType> ::Queue(int _maxSize = 10) {
    if (_maxSize > 0) {
        maxSize = _maxSize;
    } else if (_maxSize > MAX_SIZE) {
        maxSize = MAX_SIZE;
    } else {
        throw "Size is incorrect!";
    }
    queuePtr = new valType[maxSize];
    if (queuePtr == nullptr) throw "Memory was not allocated";
    len = 0;
    head = 0;
    tail = -1;
}

template <class valType>
Queue <valType> ::Queue(const Queue& Q) {
    maxSize = Q.maxSize;
    head = Q.head;
    tail = Q.tail;
    len = Q.len;
    queuePtr = new valType[maxSize];
    if (queuePtr == nullptr) throw "Memory was not allocated";
    for (int i = 0; i <= len; i++)
        queuePtr[i] = Q.queuePtr[i];
}

template <class valType>
Queue<valType> :: ~Queue() {
    delete[] queuePtr;
    queuePtr = nullptr;
}
template <class valType>
bool Queue<valType> :: operator==(const Queue<valType>& Q) const {
    if (this == &Q) return true;
    if (len != Q.len) return false;
    for (int i = 0; i < len; i++) {
        if (queuePtr[i] != Q.queuePtr[i])
            return false;
    }
    return true;
}

template <class valType>
Queue<valType>& Queue<valType> :: operator=(const Queue<valType>& Q) {
    if (maxSize != Q.maxSize) {
        delete[] queuePtr;
        queuePtr = new valType[Q.maxSize];
    }
    maxSize = Q.maxSize;
    head = Q.head;
    tail = Q.tail;
    len = Q.len;
    for (int i = 0; i <= len; i++)
        queuePtr[i] = Q.queuePtr[i];
    return *this;
}

template <class valType>
bool Queue <valType> ::IsFull() const {
    return (len == maxSize);
}

template <class valType>
bool Queue <valType> ::IsEmpty() const {
    return  (len == 0);
}

template <class valType>
void Queue <valType> ::Push(const valType &elem) {
    if (queuePtr == nullptr) throw "Queue was deleted!";
    if (IsFull()) {
        throw "Queue is full!";
    } else {
        if (tail == maxSize - 1) {
            tail = 0;
        } else {
            tail++;
            queuePtr[tail] = elem;
            len++;
      }
    }
}

template <class valType>
valType Queue <valType> ::Pop() {
    if (queuePtr == nullptr) throw "Queue was deleted!";
    if (IsEmpty()) {
        throw "Queue is empty!";
    } else {
        valType elem = queuePtr[head];
        if (head == maxSize - 1) {
            head = 0;
        } else {
            head--;
        }
        len--;
        return elem;
    }
}
#endif  // MODULES_QUEUE_INCLUDE_QUEUE_H_
