// Copyright 2017 Gvozdeva Viktoriia

#ifndef MODULES_QUEUE_INCLUDE_QUEUE_H_
#define MODULES_QUEUE_INCLUDE_QUEUE_H_

const int MAX_SIZE = 1000000;

template <typename valType>
class Queue {

public:
    explicit Queue(int _maxSize = 10);
    ~Queue();
    Queue(const Queue &);
    bool IsFull() const;
    bool operator==(const Queue<valType>&) const;
    Queue<valType>& operator=(const Queue<valType>&);
    bool IsEmpty() const;
    void Push(const valType&);
    valType Pop();
	valType Top();

private:
    int head_, tail_, len_, maxSize_;
    valType *queuePtr_;
};

template <class valType>
Queue <valType> ::Queue(int _maxSize) {
    if (_maxSize > 0) {
        maxSize_ = _maxSize;
    } else if (_maxSize > MAX_SIZE) {
        maxSize_ = MAX_SIZE;
    } else {
        throw "Size is incorrect!";
    }
    queuePtr_ = new valType[maxSize_];
    if (queuePtr_ == nullptr) throw "Memory was not allocated";
    len_ = 0;
    head_ = 0;
    tail_ = -1;
}

template <class valType>
Queue <valType> ::Queue(const Queue& Q) {
    maxSize_ = Q.maxSize_;
    head_ = Q.head_;
    tail_ = Q.tail_;
    len_ = Q.len_;
    queuePtr_ = new valType[maxSize_];
    if (queuePtr_ == nullptr) throw "Memory was not allocated";
    for (int i = 0; i <= len_; i++)
        queuePtr_[i] = Q.queuePtr_[i];
}

template <class valType>
Queue<valType> :: ~Queue() {
    delete[] queuePtr_;
    queuePtr_ = nullptr;
}
template <class valType>
bool Queue<valType> :: operator==(const Queue<valType>& Q) const {
    if (this == &Q) return true;
    if (len_ != Q.len_) return false;
    for (int i = 0; i < len_; i++) {
        if (queuePtr_[i] != Q.queuePtr_[i])
            return false;
    }
    return true;
}

template <class valType>
Queue<valType>& Queue<valType> :: operator=(const Queue<valType>& Q) {
    if (maxSize_ != Q.maxSize_) {
        delete[] queuePtr_;
        queuePtr_ = new valType[Q.maxSize_];
    }
    maxSize_ = Q.maxSize_;
    head_ = Q.head_;
    tail_ = Q.tail_;
    len_ = Q.len_;
    for (int i = 0; i <= len_; i++)
        queuePtr_[i] = Q.queuePtr_[i];
    return *this;
}

template <class valType>
bool Queue <valType> ::IsFull() const {
    return (len_ == maxSize_);
}

template <class valType>
bool Queue <valType> ::IsEmpty() const {
    return  (len_ == 0);
}

template <class valType>
void Queue <valType> ::Push(const valType &elem) {
    if (queuePtr_ == nullptr) throw "Queue was deleted!";
    if (IsFull()) {
        throw "Queue is full!";
    } else {
        if (tail_ == maxSize_ - 1) {
            tail_ = 0;
        } else {
            tail_++;
            queuePtr_[tail_] = elem;
            len_++;
      }
    }
}

template <class valType>
valType Queue <valType> ::Pop() {
    if (queuePtr_ == nullptr) throw "Queue was deleted!";
    if (IsEmpty()) {
        throw "Queue is empty!";
    } else {
        valType elem = queuePtr_[head_];
        if (head_ == maxSize_ - 1) {
            head_ = 0;
        } else {
            head_--;
        }
        len_--;
        return elem;
    }
}

template <class valType>
valType Queue <valType> ::Top() {
    if (queuePtr_ == nullptr) throw "Queue was deleted!";
    if (IsEmpty()) {
        throw "Queue is empty!";
    } else {
        return queuePtr_[head_];
    }
}
#endif  // MODULES_QUEUE_INCLUDE_QUEUE_H_
