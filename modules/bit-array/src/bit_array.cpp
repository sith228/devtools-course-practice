// Copyright 2017 Grachev Vlad

#include <string>
#include "include/bit_array.h"

BitArray::BitArray(const int size) {
    if (size > 0) {
        size_ = size;
        nBlocks_ = size / blockSize_;
        nBlocks_++;
        if (size % blockSize_ == 0)
            nBlocks_--;
        memoryBlocks_ = new MemoryBlock[nBlocks_];
        for (unsigned int i = 0; i < nBlocks_; i++)
            memoryBlocks_[i] = 0;
    } else {
        throw std::string("Incorrect array size");
    }
}



BitArray::BitArray(const BitArray& bitArray) {
    size_ = bitArray.size_;
    nBlocks_ = bitArray.nBlocks_;
    memoryBlocks_ = new MemoryBlock[nBlocks_];
    for (unsigned int i = 0; i < nBlocks_; i++)
        memoryBlocks_[i] = bitArray.memoryBlocks_[i];
}



BitArray::~BitArray() {
    delete [] memoryBlocks_;
    memoryBlocks_ = nullptr;
}



BitArray& BitArray::operator = (const BitArray& bitArray) {
    if (this != &bitArray) {
        delete[] memoryBlocks_;
        size_ = bitArray.size_;
        nBlocks_ = bitArray.nBlocks_;
        memoryBlocks_ = new MemoryBlock[nBlocks_];
        for (unsigned int i = 0; i < nBlocks_; i++)
            memoryBlocks_[i] = bitArray.memoryBlocks_[i];
    }
    return *this;
}



unsigned int BitArray::GetSize() const {
    return size_;
}



unsigned int BitArray::GetBlockNumber
                       (const unsigned int globalBitNumber) const {
    return globalBitNumber / blockSize_;
}



unsigned int BitArray::GetLocalBitNumber
                       (const unsigned int globalBitNumber) const {
    return globalBitNumber % blockSize_;
}



MemoryBlock BitArray::GetMask
                      (const unsigned int globalBitNumber) const {
    MemoryBlock mask = 1;
    mask <<= GetLocalBitNumber(globalBitNumber);
    return mask;
}

void BitArray::SetBit(const unsigned int bitNumber) {
    if (bitNumber < size_) {
        memoryBlocks_[GetBlockNumber(bitNumber)] |= GetMask(bitNumber);
    } else {
        throw std::string("Incorrect index");
    }
}



void BitArray::ClearBit(const unsigned int bitNumber) {
    if (bitNumber < size_) {
        memoryBlocks_[GetBlockNumber(bitNumber)] &= ~GetMask(bitNumber);
    } else {
        throw std::string("Incorrect index");
    }
}


int BitArray::GetBit(const unsigned int bitNumber) const {
    if (bitNumber < size_) {
        int bitValue;
        int blockNumber = GetBlockNumber(bitNumber);
        bitValue = memoryBlocks_[blockNumber] & GetMask(bitNumber);
        if (bitValue > 0)
            bitValue = 1;
        return bitValue;
    } else {
        throw std::string("Incorrect index");
    }
}



BitArray BitArray::operator & (const BitArray& bitArray) const {
    int size = size_;
    if (size_ < bitArray.size_)
        size = bitArray.size_;
    BitArray tempBitArray(size);

    for (unsigned int i = 0; i < nBlocks_; i++)
        tempBitArray.memoryBlocks_[i] = memoryBlocks_[i];
    for (unsigned int i = 0; i < tempBitArray.nBlocks_; i++)
        tempBitArray.memoryBlocks_[i] &= bitArray.memoryBlocks_[i];

    return tempBitArray;
}



BitArray BitArray::operator | (const BitArray& bitArray) const {
    int size = size_;
    if (size_ < bitArray.size_)
        size = bitArray.size_;
    BitArray tempBitArray(size);

    for (unsigned int i = 0; i < nBlocks_; i++)
        tempBitArray.memoryBlocks_[i] = memoryBlocks_[i];
    for (unsigned int i = 0; i < tempBitArray.nBlocks_; i++)
        tempBitArray.memoryBlocks_[i] |= bitArray.memoryBlocks_[i];

    return tempBitArray;
}



BitArray BitArray::operator ^ (const BitArray& bitArray) const {
    int size = size_;
    if (size_ < bitArray.size_)
        size = bitArray.size_;
    BitArray tempBitArray(size);

    for (unsigned int i = 0; i < nBlocks_; i++)
        tempBitArray.memoryBlocks_[i] = memoryBlocks_[i];
    for (unsigned int i = 0; i < tempBitArray.nBlocks_; i++)
        tempBitArray.memoryBlocks_[i] ^= bitArray.memoryBlocks_[i];

    return tempBitArray;
}



BitArray BitArray::operator ~() const {
    BitArray tempBitArray(*this);

    for (unsigned int i = 0; i < tempBitArray.size_; i++) {
        if (GetBit(i) == 0) {
            tempBitArray.SetBit(i);
        } else {
            tempBitArray.ClearBit(i);
        }
    }

    return tempBitArray;
}



bool BitArray::operator == (const BitArray& bitArray) const {
    if (size_ == bitArray.size_) {
        for (unsigned int i = 0; i < nBlocks_; i++)
        if (memoryBlocks_[i] != bitArray.memoryBlocks_[i])
            return false;
        return true;
    }
    return false;
}



bool BitArray::operator != (const BitArray& bitArray) const {
    return !(*this == bitArray);
}



std::string BitArray::ToString() const {
    std::string outputString;
    for (int i = size_ - 1; i >= 0; i--)
    if (GetBit(i) == 1)
        outputString+= '1';
    else
        outputString += '0';
    return outputString;
}

