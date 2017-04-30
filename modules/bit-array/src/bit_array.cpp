// Copyright 2017 Grachev Vlad

#include "include/bit_array.h"
#include <string>

BitArray::BitArray(const unsigned int size = 1){
    if (size > 0) {
        size_ = size;
        nBlocks_ = size / sizeof(memoryBlock);
        nBlocks_++;
        if (size % (sizeof(memoryBlock) * 8) == 0)
            nBlocks_--;
        memoryBlocks = new MemoryBlock[nBlocks_];
        if (memoryBlocks != nullptr)
        for (int i = 0; i < size; i++)
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
    for (int i = 0; i < size; i++)
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
        for (int i = 0; i < size; i++)
            memoryBlocks[i] = bitArray.memoryBlocks[i];
        else
            throw string("Data has no memory");
    }
    return *this;
}



unsigned int BitArray::getSize() const {
    return size_;
}



unsigned int getBlockNumber(const unsigned int globalBitNumber) {
    if (globalBitNumber < size_)
    {
        return size / sizeof(memoryBlock);
    }
    else
        throw string("Incorrect index");
}



unsigned int getLocalBitNumber(const unsigned int globalBitNumber) {
    if (globalBitNumber < size_)
    {
        return size % sizeof(memoryBlock);
    }
    else
        throw string("Incorrect index");
}



MemoryBlock getMask(const unsigned int globalBitNumber) {
    if (globalBitNumber < size_)
    {
        MemoryBlock mask = 1;
        mask <<= getLocalBitNumber(globalBitNumber);
        return mask;
    }
    else
        throw string("Incorrect index");
}

void BitArray::setBit(unsigned int bitNumber) {
    if ((bitNumber >= 0) && (bitNumver < size_)) {
        memoryBlocks[getBlockNumber(bitNumber)] |= getMask(bitNumber);
    }
    else
        throw string("Incorrect index");
}



void BitArray::clearBit(unsigned int bitNumber) {
    if ((bitNumber >= 0) && (bitNumver < size_)) {
        memoryBlocks[getBlockNumber(bitNumber)] &= ~getMask(bitNumber);
    }
    else
        throw string("Incorrect index");
}



int BitArray::getBit(unsigned int bitNumber) {
    if ((bitNumber >= 0) && (bitNumver < size_)) {
        int bitValue;
        bitValue = (memoryBlocks[getBlockNumber(bitNumber)] & getMask(bitNumber)) > 0 ? 1 : 0;
        return bitValue;
    }
    else
        throw string("Incorrect index");
}



BitArray BitArray::operator & (const BitArray& bitArray) {
    if (nBlocks_ > bitArray.nBlocks_)
        BitArray tempBitArray(*this);
    else
        BitArray tempBitArray(bitArray);

    for (int i = 0; i < tempBitArray.nBlocks_; i++)
        tempBitArray.memoryBlocks[i] &= bitArray.memoryBlocks[i];

    return temp;
}



BitArray BitArray::operator | (const BitArray& bitArray) {
    if (nBlocks_ > bitArray.nBlocks_)
        BitArray tempBitArray(*this);
    else
        BitArray tempBitArray(bitArray);

    for (int i = 0; i < tempBitArray.nBlocks_; i++)
        tempBitArray.memoryBlocks[i] |= bitArray.memoryBlocks[i];

    return temp;
}



BitArray BitArray::operator ^ (const BitArray& bitArray) {
    if (nBlocks_ > bitArray.nBlocks_)
        BitArray tempBitArray(*this);
    else
        BitArray tempBitArray(bitArray);

    for (int i = 0; i < tempBitArray.nBlocks_; i++)
        tempBitArray.memoryBlocks[i] ^= bitArray.memoryBlocks[i];

    return temp;
}



BitArray BitArray::operator ~ () {
    BitArray tempBitArray(*this);

    for (int i = 0; i < tempBitArray.nBlocks_; i++) {
        if (GetBit(i) == 0)
            tempBitArray.SetBit(i);
        else
            tempBitArray.ClearBit(i);
    }

    return temp;
}



bool BitArray::operator == (const BitArray& bitArray) {
    if (nBlocks_ == bitArray.nBlocks_)
        for (int i = 0; i < nBlocks_; i++)
            if (memoryBlocks[i] != bitArray.MemoryBlocks[i])
                return false;
      return true;
    }
    else
        return false;
}



bool BitArray::operator != (const BitArray& bitArray) {
    return !(*this == bitArray);
}



istream& operator >> (istream& istr, BitArray& bitArray) {
    char symbol;
    int i = 0;
    istr >> symbol;
    while ((i < bitArray.nBlocks_) && ((symbol == '0') || (symbol == '1')))
    {
        if (sign == '0')
            bitArray.ClearBit(i);
        else
            bitArray.SetBit(i);
        istr >> sign;
        i++;
    }
    return istr;
}



ostream& operator << (ostream& ostr, const BitArray& bitArray) {
    for (int i = bitArray.length_ - 1; i >= 0; i--)
    if (bitArray.GetBit(i))
        ostr << 1;
    else
        ostr << 0;
    ostr << endl;
    return ostr;
}
