// Copyright 2017 Buldakov Vladislav

#include "include/weight_converter.h"

const std::map<Weights, double> WeightsMap::kWeights_ratio = 
    WeightsMap::CreateMap();

WeightConverter::WeightConverter(double weight, Weights type) {
    SetWeight(weight, type);
}

void WeightConverter::SetWeight(double weight, Weights type) {
    Weight_ = weight * WeightsMap::kWeights_ratio.at(type);
}

double WeightConverter::GetWeight() {
    return Weight_;
}

double WeightConverter::Convert(Weights to) {
    return Weight_ / WeightsMap::kWeights_ratio.at(to);
}

double WeightConverter::Convert(double weight, Weights from, Weights to) {
    return WeightsMap::kWeights_ratio.at(from) / 
        WeightsMap::kWeights_ratio.at(to) * weight;
}
