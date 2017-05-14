// Copyright 2017 Buldakov Vladislav

#ifndef MODULES_WEIGHT_CONVERTER_INCLUDE_WEIGHT_CONVERTER_H_
#define MODULES_WEIGHT_CONVERTER_INCLUDE_WEIGHT_CONVERTER_H_

enum Weights{
    KG,    // kilogram
    MG,    // milligram
    G,     // gram
    GR,    // grain
    DR,    // dram
    OZ,    // ounce
    LB,    // pound
    CR,    // carat

    END
};

class WeightConverter{
 public:
    WeightConverter(double weight = 0.0, Weights type = KG);
    void setWeight(double weight, Weights type);
    double getWeight();

    double Convert(Weights to);
    double Convert(double weight, Weights from, Weights to);
 private:
    double Weight;    // kg
    static const double ratio[END];
};

#endif  // MODULES_WEIGHT_CONVERTER_INCLUDE_WEIGHT_CONVERTER_H_
