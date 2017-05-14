#include "include/weight_converter.h"

const double WeightConverter::ratio[] = {
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
    Weight = weight * ratio[type];
}

double WeightConverter::getWeight() {
    return Weight;
}

double WeightConverter::Convert(Weights to){
    return Weight / ratio[to];
}

double WeightConverter::Convert(Weights from, Weights to, double val){
    return ratio[to]/ratio[from] * val;
}
