// Copyright 2017 Grachev Vlad

#include "include/bit_array.h"
#include <string>

BitArray::BitArray(const int size) {
    if (size > 0) {
        size_ = size;
        nBlocks_ = size / (sizeof(MemoryBlock) * 8);
        nBlocks_++;
        if (size % (sizeof(MemoryBlock) * 8) == 0)
            nBlocks_--;
        memoryBlocks = new MemoryBlock[nBlocks_];
        if (memoryBlocks != nullptr) {
            for (unsigned int i = 0; i < nBlocks_; i++)
                memoryBlocks[i] = 0;
        } else {
            throw std::string("Data has no memory");
        }
    } else {
        throw std::string("Incorrect array size");
    }
}



BitArray::BitArray(const BitArray& bitArray) {
    size_ = bitArray.size_;
    nBlocks_ = bitArray.nBlocks_;
    memoryBlocks = new MemoryBlock[nBlocks_];
    if (memoryBlocks != nullptr) {
        for (unsigned int i = 0; i < nBlocks_; i++)
            memoryBlocks[i] = bitArray.memoryBlocks[i];
    } else {
        throw std::string("Data has no memory");
    }
}



BitArray::~BitArray() {
    delete [] memoryBlocks;
    memoryBlocks = nullptr;
}



BitArray& BitArray::operator = (const BitArray& bitArray) {
    if (this != &bitArray) {
        delete[] memoryBlocks;
        size_ = bitArray.size_;
        nBlocks_ = bitArray.nBlocks_;
        memoryBlocks = new MemoryBlock[nBlocks_];
        if (memoryBlocks != nullptr) {
            for (unsigned int i = 0; i < nBlocks_; i++)
                memoryBlocks[i] = bitArray.memoryBlocks[i];
        } else {
            throw std::string("Data has no memory");
        }
    }
    return *this;
}



unsigned int BitArray::getSize() const {
    return size_;
}



unsigned int BitArray::getBlockNumber
                       (const unsigned int globalBitNumber) const {
    if (globalBitNumber < size_) {
        return globalBitNumber / (sizeof(MemoryBlock) * 8);
    } else {
        throw std::string("Incorrect index");
    }
}



unsigned int BitArray::getLocalBitNumber
(const unsigned int globalBitNumber) const {
    if (globalBitNumber < size_) {
        return globalBitNumber % (sizeof(MemoryBlock)* 8);
    } else {
        throw std::string("Incorrect index");
    }
}



MemoryBlock BitArray::getMask
                      (const unsigned int globalBitNumber) const {
    if (globalBitNumber < size_) {
        MemoryBlock mask = 1;
        mask <<= getLocalBitNumber(globalBitNumber);
        return mask;
    } else {
        throw std::string("Incorrect index");
    }
}

void BitArray::setBit(const unsigned int bitNumber) {
    if (bitNumber < size_) {
        memoryBlocks[getBlockNumber(bitNumber)] |= getMask(bitNumber);
    } else {
        throw std::string("Incorrect index");
    }
}



void BitArray::clearBit(const unsigned int bitNumber) {
    if (bitNumber < size_) {
        memoryBlocks[getBlockNumber(bitNumber)] &= ~getMask(bitNumber);
    } else {
        throw std::string("Incorrect index");
    }
}


int BitArray::getBit(const unsigned int bitNumber) const {
    if (bitNumber < size_) {
        int bitValue;
        bitValue = memoryBlocks[getBlockNumber(bitNumber)] & getMask(bitNumber);
        if (bitValue > 0)
            bitValue = 1;
        return bitValue;
    } else {
        throw std::string("Incorrect index");
    }
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



BitArray BitArray::operator ~() {
    BitArray tempBitArray(*this);

    for (unsigned int i = 0; i < tempBitArray.nBlocks_; i++) {
        if (getBit(i) == 0) {
            tempBitArray.setBit(i);
        } else {
            tempBitArray.clearBit(i);
        }
    }

    return tempBitArray;
}



bool BitArray::operator == (const BitArray& bitArray) const {
    if (nBlocks_ == bitArray.nBlocks_) {
        for (unsigned int i = 0; i < nBlocks_; i++)
        if (memoryBlocks[i] != bitArray.memoryBlocks[i])
            return false;
        return true;
    } else {
        return false;
    }
}



bool BitArray::operator != (const BitArray& bitArray) const {
    return !(*this == bitArray);
}



std::string BitArray::ToString() {
    std::string outputString;
    for (int i = size_ - 1; i >= 0; i--)
    if (getBit(i) == 1)
        outputString+= '1';
    else
        outputString += '0';
    return outputString;
}



std::istream& operator >> (std::istream& istr, BitArray& bitArray) {
    char symbol;
    unsigned int i = 0;
    istr >> symbol;
    while ((i < bitArray.nBlocks_) && ((symbol == '0') || (symbol == '1'))) {
        if (symbol == '0')
            bitArray.clearBit(i);
        else
            bitArray.setBit(i);
        istr >> symbol;
        i++;
    }
    return istr;
}
