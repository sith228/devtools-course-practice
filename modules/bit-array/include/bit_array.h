// Copyright 2017 Grachev Vlad

#ifndef MODULES_BIT_ARRAY_INCLUDE_BIT_ARRAY_H_
#define	MODULES_BIT_ARRAY_INCLUDE_BIT_ARRAY_H_

#include <iostream>

using namespace std

typedef unsigned int MemoryBlock;

class BitArray {
 public:
    BitArray(const unsigned int size);
    BitArray(const BitArray& bitArray);
    ~BitArray();

    BitArray& operator = (const BitArray& bitArray);

    unsigned int getSize() const;
    void setBit(unsigned int bitNumber);
    void clearBit(unsigned int bitNumber);
    int getBit(unsigned int bitNumber) const;

    BitArray operator & (const BitArray& bitArray);
    BitArray operator | (const BitArray& bitArray);
    BitArray operator ^ (const BitArray& bitArray);
    BitArray operator ~ ();

    bool operator == (const BitArray& bitArray) const;
    bool operator != (const BitArray& bitArray) const;

    friend istream& operator >> (istream& istr, BitArray& bitArray);
    friend ostream& operator << (ostream& ostr, const BitArray& bitArray);

 private:
    unsigned int getBlockNumber(const unsigned int globalBitNumber);
    unsigned int getLocalBitNumber(const unsigned int globalBitNumber);
    MemoryBlock getMask(const unsigned int localBitNumber);

    unsigned int size_;
    MemoryBlock* memoryBlocks;
    unsigned int nBlocks_;
};

#endif // MODULES_BIT_ARRAY_INCLUDE_BIT_ARRAY_H_
