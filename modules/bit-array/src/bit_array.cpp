// Copyright 2017 Grachev Vlad

#include "include/bit_array.h"
#include <string>

BitArray::BitArray(const unsigned int size = 1) : size_(size){
    if (size > 0) {
        nBlocks_ = size / sizeof(MemoryBlock);
        nBlocks_++;
        if (size % (sizeof(MemoryBlock) * 8) == 0)
            nBlocks_--;
        memoryBlocks = new MemoryBlock[nBlocks_];
        if (memoryBlocks != nullptr)
        for (unsigned int i = 0; i < size; i++)
            memoryBlocks[i] = 0;
        else
            throw string("Data has no memory");
    }
    else
        throw string("Incorrect array size");
}



BitArray::BitArray(const BitArray& bitArray) {
    size_ = bitArray.size_;
    nBlocks_ = bitArray.nBlocks_;
    memoryBlocks = new MemoryBlock[nBlocks_];
    if (memoryBlocks != nullptr)
    for (unsigned int i = 0; i < size_; i++)
        memoryBlocks[i] = bitArray.memoryBlocks[i];
    else
        throw string("Data has no memory");
}



BitArray::~BitArray() {
    delete [] memoryBlocks;
    memoryBlocks = nullptr;
}



BitArray& BitArray::operator = (const BitArray& bitArray) {
    if (this != &bitArray)
    {
        delete[] memoryBlocks;
        size_ = bitArray.size_;
        nBlocks_ = bitArray.nBlocks_;
        memoryBlocks = new MemoryBlock[nBlocks_];
        if (memoryBlocks != nullptr)
        for (unsigned int i = 0; i < size_; i++)
            memoryBlocks[i] = bitArray.memoryBlocks[i];
        else
            throw string("Data has no memory");
    }
    return *this;
}



unsigned int BitArray::getSize() const {
    return size_;
}



unsigned int BitArray::getBlockNumber(const unsigned int globalBitNumber) const {
    if (globalBitNumber < size_)
    {
        return globalBitNumber / sizeof(MemoryBlock);
    }
    else
        throw string("Incorrect index");
}



unsigned int BitArray::getLocalBitNumber(const unsigned int globalBitNumber) const {
    if (globalBitNumber < size_)
    {
        return globalBitNumber % (sizeof(MemoryBlock) * 8);
    }
    else
        throw string("Incorrect index");
}



MemoryBlock BitArray::getMask(const unsigned int globalBitNumber) const {
    if (globalBitNumber < size_)
    {
        MemoryBlock mask = 1;
        mask <<= getLocalBitNumber(globalBitNumber);
        return mask;
    }
    else
        throw string("Incorrect index");
}

void BitArray::setBit(const unsigned int bitNumber) {
    if ((bitNumber >= 0) && (bitNumber < size_)) {
        memoryBlocks[getBlockNumber(bitNumber)] |= getMask(bitNumber);
    }
    else
        throw string("Incorrect index");
}



void BitArray::clearBit(const unsigned int bitNumber) {
    if ((bitNumber >= 0) && (bitNumber < size_)) {
        memoryBlocks[getBlockNumber(bitNumber)] &= ~getMask(bitNumber);
    }
    else
        throw string("Incorrect index");
}



int BitArray::getBit(const unsigned int bitNumber) const {
    if ((bitNumber >= 0) && (bitNumber < size_)) {
        int bitValue;
        bitValue = (memoryBlocks[getBlockNumber(bitNumber)] & getMask(bitNumber)) > 0 ? 1 : 0;
        return bitValue;
    }
    else
        throw string("Incorrect index");
}



BitArray BitArray::operator & (const BitArray& bitArray) {
    BitArray tempBitArray(*this);
    if (nBlocks_ < bitArray.nBlocks_)
        tempBitArray = bitArray;

    for (unsigned int i = 0; i < tempBitArray.nBlocks_; i++)
        tempBitArray.memoryBlocks[i] &= bitArray.memoryBlocks[i];

    return tempBitArray;
}



BitArray BitArray::operator | (const BitArray& bitArray) {
    BitArray tempBitArray(*this);
    if (nBlocks_ < bitArray.nBlocks_)
        tempBitArray = bitArray;

    for (unsigned int i = 0; i < tempBitArray.nBlocks_; i++)
        tempBitArray.memoryBlocks[i] |= bitArray.memoryBlocks[i];

    return tempBitArray;
}



BitArray BitArray::operator ^ (const BitArray& bitArray) {
    BitArray tempBitArray(*this);
    if (nBlocks_ < bitArray.nBlocks_)
        tempBitArray = bitArray;

    for (unsigned int i = 0; i < tempBitArray.nBlocks_; i++)
        tempBitArray.memoryBlocks[i] ^= bitArray.memoryBlocks[i];

    return tempBitArray;
}



BitArray BitArray::operator ~ () {
    BitArray tempBitArray(*this);

    for (unsigned int i = 0; i < tempBitArray.nBlocks_; i++) {
        if (getBit(i) == 0)
            tempBitArray.setBit(i);
        else
            tempBitArray.clearBit(i);
    }

    return tempBitArray;
}



bool BitArray::operator == (const BitArray& bitArray) const {
    if (nBlocks_ == bitArray.nBlocks_) {
        for (unsigned int i = 0; i < nBlocks_; i++)
            if (memoryBlocks[i] != bitArray.memoryBlocks[i])
                return false;
      return true;
    }
    else
        return false;
}



bool BitArray::operator != (const BitArray& bitArray) const {
    return !(*this == bitArray);
}



istream& operator >> (istream& istr, BitArray& bitArray) {
    char symbol;
    unsigned int i = 0;
    istr >> symbol;
    while ((i < bitArray.nBlocks_) && ((symbol == '0') || (symbol == '1')))
    {
        if (symbol == '0')
            bitArray.clearBit(i);
        else
            bitArray.setBit(i);
        istr >> symbol;
        i++;
    }
    return istr;
}



ostream& operator << (ostream& ostr, const BitArray& bitArray) {
    for (int i = bitArray.size_ - 1; i >= 0; i--)
    if (bitArray.getBit(i))
        ostr << 1;
    else
        ostr << 0;
    ostr << endl;
    return ostr;
}
