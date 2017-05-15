// Copyright 2017 Buldakov Vladislav

#include "include/weight_converter.h"

const std::map<Weights, double> WeightsMap::kWeights_ratio = WeightsMap::CreateMap();

WeightConverter::WeightConverter(double weight, Weights type) {
    setWeight(weight, type);
}

void WeightConverter::setWeight(double weight, Weights type) {
    Weight_ = weight * WeightsMap::kWeights_ratio.at(type);
}

double WeightConverter::getWeight() {
    return Weight_;
}

double WeightConverter::Convert(Weights to) {
    return Weight_ / WeightsMap::kWeights_ratio.at(to);
}

double WeightConverter::Convert(double weight, Weights from, Weights to) {
    return WeightsMap::kWeights_ratio.at(from) / WeightsMap::kWeights_ratio.at(to) * weight;
}
