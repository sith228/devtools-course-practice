// Copyright 2017 Olga Kiseleva

#include "include/statistical_moments.h"

#include <iostream>
#include <vector>

bool statisticalMoments::isChangeValid() {
    for (int i = 0;i < statisticalMoments::chances.size();i++) {
        if ((statisticalMoments::chances[i] < 0) || (statisticalMoments::chances[i]>1))
            return false;
    }
    return true;
}

bool statisticalMoments::isChangesDistributionRow() {
    double tmp_sum = 0;
    for (unsigned int i = 0;i < statisticalMoments::chances.size();i++) {
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
    if (this->values.empty()) {
        throw std::runtime_error("vector \"values\" are empty");
    }
    if (this->chances.empty()) {
        throw std::runtime_error("vector \"changes\" are empty");
    }
    if (!isChangeValid()) {
        throw std::runtime_error("One of changes is out if range [0,1] ");
    }
    if (!isChangesDistributionRow()) {
        throw std::runtime_error("sum of changes isn't equals 1");
    }
}


//проверить, чтобы сумма changes=1, иначе, беда
//}
statisticalMoments::~statisticalMoments() {
    //удалить вектора, если это нужно
}
double statisticalMoments::getMoment(unsigned int order) {
    //выдать момент порядка order, учитывая, что данные корректные
    return 0;
}