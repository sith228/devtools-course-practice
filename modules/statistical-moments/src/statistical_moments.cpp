// Copyright 2017 Olga Kiseleva

#include "include/statistical_moments.h"
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <vector>

bool StatisticalMoments::isChanceValid(const std::vector<double>& values,
    const std::vector<double>& chances) {
    for (unsigned int i = 0; i < chances.size(); i++) {
        if ((chances[i] < 0) || (chances[i] > 1))
            return false;
    }
    return true;
}

bool StatisticalMoments::isChancesDistributionRow(
    const std::vector<double>& values, const std::vector<double>& chances) {
    double tmp_sum = 0;
    for (unsigned int i = 0; i < chances.size(); i++) {
        tmp_sum += chances[i];
    }
    return (tmp_sum == 1);
}

void StatisticalMoments::checkingInputDate(const std::vector<double>& values,
    const std::vector<double>& chances) {
    if (values.empty() && chances.empty()) {
        throw std::runtime_error("Both vectors are empty");
    }
    if (values.empty()) {
        throw std::runtime_error("vector \"values\" is empty");
    }
    if (chances.empty()) {
        throw std::runtime_error("vector \"chances\" is empty");
    }
    if (chances.size() != values.size()) {
        throw std::runtime_error("values and chances must have equals size");
    }
    if (!isChanceValid(values, chances)) {
        throw std::runtime_error("One of chances is out in range [0,1]");
    }
    if (!isChancesDistributionRow(values, chances)) {
        throw std::runtime_error("sum of chances isn't equals 1");
    }
}

double StatisticalMoments::getCustomMoment(const std::vector<double>& values,
    const std::vector<double>& chances, unsigned int order, 
    unsigned int offset) {
    double result = 0;
    if (order == 0) {
        throw new std::runtime_error("Order must be more than zero");
    }
    for (unsigned int i = 0; i < chances.size(); i++) {
        result += pow(values[i] - offset, order)*chances[i];
    }
    return result;
}
double StatisticalMoments::getExpectancy(const std::vector<double>& values,
    const std::vector<double>& chances) {
    double result = 0;
    for (unsigned int i = 0; i < chances.size(); i++) {
        result += values[i]*chances[i];
    }
    return result;
}
double StatisticalMoments::getDispersion(const std::vector<double>& values,
    const std::vector<double>& chances) {
    double expectansy = StatisticalMoments::getExpectancy(values,chances);
    double dispersion = 0;
    for (unsigned int i = 0; i < chances.size(); i++) {
        dispersion += pow(values[i] - expectansy, 2)*chances[i];
    }
    return dispersion;

}

