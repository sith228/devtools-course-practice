// Copyright 2017 Olga Kiseleva

#include "include/statistical_moments.h"
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <vector>

bool statisticalMoments::isChanceValid() {
    for (unsigned int i = 0; i < statisticalMoments::chances.size(); i++) {
        if ((statisticalMoments::chances[i] < 0) ||
            (statisticalMoments::chances[i] > 1))
            return false;
    }
    return true;
}

bool statisticalMoments::isChancesDistributionRow() {
    double tmp_sum = 0;
    for (unsigned int i = 0; i < statisticalMoments::chances.size(); i++) {
        tmp_sum += chances[i];
    }
    return (tmp_sum == 1);
}

statisticalMoments::statisticalMoments(std::vector<double> values,
    std::vector<double> chances) {
    this->values = values;
    this->chances = chances;
    if (this->values.empty() && this->chances.empty()) {
        throw std::runtime_error("Both vectors are empty");
    }
    if (this->values.empty()) {
        throw std::runtime_error("vector \"values\" is empty");
    }
    if (this->chances.empty()) {
        throw std::runtime_error("vector \"chances\" is empty");
    }
    if (this->chances.size() != this->values.size()) {
        throw std::runtime_error("values and chances must have equals size");
    }
    if (!isChanceValid()) {
        throw std::runtime_error("One of chances is out in range [0,1]");
    }
    if (!isChancesDistributionRow()) {
        throw std::runtime_error("sum of chances isn't equals 1");
    }
}

double statisticalMoments::getMoment(unsigned int order) {
    double result = 0;
    if (order == 0) {
        throw new std::runtime_error("Order must be more than zero");
    }
    int a = 0;  // for start moments
    for (unsigned int i = 0; i < statisticalMoments::chances.size(); i++) {
        result += pow(values[i] - a, order)*chances[i];
    }
    return result;
}
