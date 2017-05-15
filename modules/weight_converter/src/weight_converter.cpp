// Copyright 2017 Buldakov Vladislav

#include "include/weight_converter.h"

const double WeightConverter::kRatio_[] = {
    1.0,
    0.000001,
    0.001,
    0.00006479891,
    0.00177185,
    0.0283495,
    0.453592,
    0.0002
};  // Weight/Kilogram ratio

WeightConverter::WeightConverter(double weight, Weights type) {
    setWeight(weight, type);
}

void WeightConverter::setWeight(double weight, Weights type) {
    Weight_ = weight * kRatio_[type];
}

double WeightConverter::getWeight() {
    return Weight_;
}

double WeightConverter::Convert(Weights to) {
    return Weight_ / kRatio_[to];
}

double WeightConverter::Convert(double weight, Weights from, Weights to) {
    return kRatio_[from] / kRatio_[to] * weight;
}
