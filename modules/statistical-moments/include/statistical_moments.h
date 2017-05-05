// Copyright 2017 Olga Kiseleva

#ifndef MODULES_STATISTICAL_MOMENTS_INCLUDE_STATISTICAL_MOMENTS_H_
#define MODULES_STATISTICAL_MOMENTS_INCLUDE_STATISTICAL_MOMENTS_H_

#include <vector>
#include <string>

class StatisticalMoments {
 public:
    static double getCustomMoment(const std::vector<double>& values,
        const std::vector<double>& chances, unsigned int order,
        unsigned int offset);
    static double getExpectancy(const std::vector<double>& values,
        const std::vector<double>& chances);
    static double getDispersion(const std::vector<double>& values,
        const std::vector<double>& chances);
 private:
    static void checkingInputDate(const std::vector<double>& values,
        const std::vector<double>& chances);
    static bool isChanceValid(const std::vector<double>& values,
        const std::vector<double>& chances);
    static bool isChancesDistributionRow(const std::vector<double>& values,
        const std::vector<double>& chances);
};
#endif  // MODULES_STATISTICAL_MOMENTS_INCLUDE_STATISTICAL_MOMENTS_H_
