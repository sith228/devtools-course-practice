#pragma once

using namespace std;

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
    double Convert(Weights from, Weights to, double val);
private:
    double Weight; // kg   
    static const double ratio[END];
};