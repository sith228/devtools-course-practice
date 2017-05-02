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
    int size = size_;
    if (size_ < bitArray.size_)
        size = bitArray.size_;
    BitArray tempBitArray(size);

    for (unsigned int i = 0; i < nBlocks_; i++)
        tempBitArray.memoryBlocks[i] = memoryBlocks[i];
    for (unsigned int i = 0; i < tempBitArray.nBlocks_; i++)
        tempBitArray.memoryBlocks[i] &= bitArray.memoryBlocks[i];

    return tempBitArray;
}



BitArray BitArray::operator | (const BitArray& bitArray) {
    int size = size_;
    if (size_ < bitArray.size_)
        size = bitArray.size_;
    BitArray tempBitArray(size);

    for (unsigned int i = 0; i < nBlocks_; i++)
        tempBitArray.memoryBlocks[i] = memoryBlocks[i];
    for (unsigned int i = 0; i < tempBitArray.nBlocks_; i++)
        tempBitArray.memoryBlocks[i] |= bitArray.memoryBlocks[i];

    return tempBitArray;
}



BitArray BitArray::operator ^ (const BitArray& bitArray) {
    int size = size_;
    if (size_ < bitArray.size_)
        size = bitArray.size_;
    BitArray tempBitArray(size);

    for (unsigned int i = 0; i < nBlocks_; i++)
        tempBitArray.memoryBlocks[i] = memoryBlocks[i];
    for (unsigned int i = 0; i < tempBitArray.nBlocks_; i++)
        tempBitArray.memoryBlocks[i] ^= bitArray.memoryBlocks[i];

    return tempBitArray;
}



BitArray BitArray::operator ~() {
    BitArray tempBitArray(*this);

    for (unsigned int i = 0; i < tempBitArray.size_; i++) {
        if (getBit(i) == 0) {
            tempBitArray.setBit(i);
        } else {
            tempBitArray.clearBit(i);
        }
    }

    return tempBitArray;
}



bool BitArray::operator == (const BitArray& bitArray) const {
    if (size_ == bitArray.size_) {
        for (unsigned int i = 0; i < nBlocks_; i++)
        if (memoryBlocks[i] != bitArray.memoryBlocks[i])
            return false;
        return true;
    }
    return false;
}



bool BitArray::operator != (const BitArray& bitArray) const {
    return !(*this == bitArray);
}



std::string BitArray::toString() {
    std::string outputString;
    for (int i = size_ - 1; i >= 0; i--)
    if (getBit(i) == 1)
        outputString+= '1';
    else
        outputString += '0';
    return outputString;
}

