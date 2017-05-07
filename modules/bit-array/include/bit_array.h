// Copyright 2017 Grachev Vlad

#ifndef MODULES_BIT_ARRAY_INCLUDE_BIT_ARRAY_H_
#define MODULES_BIT_ARRAY_INCLUDE_BIT_ARRAY_H_

#include <string>

typedef unsigned int MemoryBlock;

class BitArray {
 public:
    explicit BitArray(const int size);
    BitArray(const BitArray& bitArray);
    ~BitArray();

    BitArray& operator = (const BitArray& bitArray);

    unsigned int GetSize() const;
    void SetBit(const unsigned int bitNumber);
    void ClearBit(const unsigned int bitNumber);
    int GetBit(const unsigned int bitNumber) const;

    BitArray operator & (const BitArray& bitArray) const;
    BitArray operator | (const BitArray& bitArray) const;
    BitArray operator ^ (const BitArray& bitArray) const;
    BitArray operator ~() const;

    bool operator == (const BitArray& bitArray) const;
    bool operator != (const BitArray& bitArray) const;

    std::string ToString() const;

 private:
    unsigned int GetBlockNumber(const unsigned int globalBitNumber) const;
    unsigned int GetLocalBitNumber(const unsigned int globalBitNumber) const;
    MemoryBlock GetMask(const unsigned int globalBitNumber) const;

    unsigned int size_;

    unsigned int nBlocks_;
    MemoryBlock* memoryBlocks_;
    const int blockSize_ = sizeof(MemoryBlock) * 8;
};

#endif  // MODULES_BIT_ARRAY_INCLUDE_BIT_ARRAY_H_
