// Copyright 2017 Olga Kiseleva

#ifndef MODULES_STATISTICAL_MOMENTS_INCLUDE_STATISTICAL_MOMENTS_H_
#define MODULES_STATISTICAL_MOMENTS_INCLUDE_STATISTICAL_MOMENTS_H_

#include <vector>
#include <string>

static class StatisticalMoments {
 public:
   double getCustomMoment(const std::vector<double>& values,
        const std::vector<double>& chances,unsigned int order,
        unsigned int offset);
   double getExpectancy(const std::vector<double>& values,
        const std::vector<double>& chances);
   double getDispersion(const std::vector<double>& values,
        const std::vector<double>& chances);
 private:
    void checkingInputDate(const std::vector<double>& values,
        const std::vector<double>& chances);
    bool isChanceValid(const std::vector<double>& values,
        const std::vector<double>& chances);
    bool isChancesDistributionRow(const std::vector<double>& values,
        const std::vector<double>& chances);
};
#endif  // MODULES_STATISTICAL_MOMENTS_INCLUDE_STATISTICAL_MOMENTS_H_
