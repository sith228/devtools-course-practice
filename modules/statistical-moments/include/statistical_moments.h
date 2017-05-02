// Copyright 2017 Olga Kiseleva

#ifndef MODULES_STATISTICAL_MOMENTS_INCLUDE_STATISTICAL_MOMENTS_H_
#define MODULES_STATISTICAL_MOMENTS_INCLUDE_STATISTICAL_MOMENTS_H_

#include <vector>
#include <string>

class statisticalMoments {
private:
    std::vector<double> values;
    std::vector<double> chanced;
public:
    statisticalMoments();
    statisticalMoments(std::vector<double> values, std::vector<double> chanced);
    ~statisticalMoments();
    double getMoment(unsigned int order);
};
#endif  // MODULES_STATISTICAL_MOMENTS_INCLUDE_STATISTICAL_MOMENTS_H_
