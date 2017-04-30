// Copyright 2017 Grachev Vlad

#ifndef MODULES_BIT_ARRAY_INCLUDE_BIT_ARRAY_H_
#define	MODULES_BIT_ARRAY_INCLUDE_BIT_ARRAY_H_

#include <iostream>

using namespace std

typedef unsigned int MemoryBlock;

enum ReturnCode {
     DATA_OK,
     DATA_ERROR,
     INCORRECT_INDEX
};

class BitArray {
 public:
    BitArray(const unsigned int length);
    BitArray(const BitArray& bitArray);
    ~BitArray();

    BitArray& operator = (const BitArray& bitArray);

    ReturnCode getReturnCode();

    unsigned int getLength() const;
    void setBit(unsigned int bitNumber);
    void clearBit(unsigned int bitNumber);
    int getBit(unsigned int bitNumber) const;

    BitArray operator & (const BitArray& bitArray);
    BitArray operator | (const BitArray& bitArray);
    BitArray operator ~ (const BitArray& bitArray);
    BitArray operator ^ (const BitArray& bitArray);

    bool operator == (const BitArray& bitArray) const;
    bool operator != (const BitArray& bitArray) const;

    friend istream &operator>>(istream &istr, BitArray& bitArray);
    friend ostream &operator<<(ostream &ostr, const BitArray& bitArray);

 private:
    getLocalBitNumber(const unsigned int globalBitNumber);
    getMask(const unsigned int localBitNumber);

    setReturnCode(ReturnCodes returnCode);

    unsigned int length_;
    MemoryBlock* memoryBlocks;
    unsigned int nBlocks_;

    ReturnCode returnCode_;
};

#endif // MODULES_BIT_ARRAY_INCLUDE_BIT_ARRAY_H_
