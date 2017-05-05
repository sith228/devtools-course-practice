// Copyright 2017 Olga Kiseleva

#ifndef MODULES_STATISTICAL_MOMENTS_INCLUDE_STATISTICAL_MOMENTS_H_
#define MODULES_STATISTICAL_MOMENTS_INCLUDE_STATISTICAL_MOMENTS_H_

#include <vector>
#include <string>

class StatisticalMoments {
 public:
    StatisticalMoments(const std::vector<double>& values,const std::vector<double>& chances);
    double getMoment(unsigned int order);
 private:
    std::vector<double> values;
    std::vector<double> chances;
    bool isChanceValid();
    bool isChancesDistributionRow();
};
#endif  // MODULES_STATISTICAL_MOMENTS_INCLUDE_STATISTICAL_MOMENTS_H_
