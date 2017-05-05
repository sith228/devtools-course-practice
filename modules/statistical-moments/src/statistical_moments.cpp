// Copyright 2017 Olga Kiseleva

#include "include/statistical_moments.h"
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <vector>

bool StatisticalMoments::isChanceValid() {
    for (unsigned int i = 0; i < StatisticalMoments::chances.size(); i++) {
        if ((StatisticalMoments::chances[i] < 0) ||
            (StatisticalMoments::chances[i] > 1))
            return false;
    }
    return true;
}

bool StatisticalMoments::isChancesDistributionRow() {
    double tmp_sum = 0;
    for (unsigned int i = 0; i < StatisticalMoments::chances.size(); i++) {
        tmp_sum += chances[i];
    }
    return (tmp_sum == 1);
}

StatisticalMoments::StatisticalMoments(const std::vector<double>& values,
    const std::vector<double>& chances) {
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

double StatisticalMoments::getMoment(unsigned int order) {
    double result = 0;
    if (order == 0) {
        throw new std::runtime_error("Order must be more than zero");
    }
    int a = 0;  // for start moments
    for (unsigned int i = 0; i < StatisticalMoments::chances.size(); i++) {
        result += pow(values[i] - a, order)*chances[i];
    }
    return result;
}
