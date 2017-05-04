// Copyright 2017 Olga Kiseleva

#include "include/statistical_moments.h"
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <vector>

bool statisticalMoments::isChangeValid() {
    for (unsigned int i = 0; i < statisticalMoments::chances.size(); i++) {
        if ((statisticalMoments::chances[i] < 0) ||
            (statisticalMoments::chances[i] > 1))
            return false;
    }
    return true;
}

bool statisticalMoments::isChangesDistributionRow() {
    double tmp_sum = 0;
    for (unsigned int i = 0; i < statisticalMoments::chances.size(); i++) {
        tmp_sum += chances[i];
    }
    if (tmp_sum != 1) {
        return false;
    }
    return true;
}

statisticalMoments::statisticalMoments(std::vector<double> values,
    std::vector<double> changes) {
    this->values = values;
    this->chances = changes;
    if (this->values.empty() && this->chances.empty()) {
        throw std::runtime_error("Both vectors are empty");
    }
    if (this->values.empty()) {
        throw std::runtime_error("vector \"values\" is empty");
    }
    if (this->chances.empty()) {
        throw std::runtime_error("vector \"changes\" is empty");
    }
    if (this->chances.size() != this->values.size()) {
        throw std::runtime_error("values and changes must have equals size");
    }
    if (!isChangeValid()) {
        throw std::runtime_error("One of changes is out in range [0,1]");
    }
    if (!isChangesDistributionRow()) {
        throw std::runtime_error("sum of changes isn't equals 1");
    }
}

statisticalMoments::~statisticalMoments() {
    // delete vector if it nessesary
}
double statisticalMoments::getMoment(unsigned int order) {
    double result = 0;
    int a = 0;  // for start moments
    for (unsigned int i = 0; i < statisticalMoments::chances.size(); i++) {
        result += pow(values[i] - a, order)*chances[i];
    }
    return result;
}
