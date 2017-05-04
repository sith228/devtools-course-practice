// Copyright 2017 Grechukhin Nikita

#ifndef MODULES_LAB2_INTEGRATION_METHODS_INCLUDE_INTEGRATION_METHODS_H_
#define MODULES_LAB2_INTEGRATION_METHODS_INCLUDE_INTEGRATION_METHODS_H_

#include <string>

class IntegrationMethod {
 public:
    double rectangle_method(const std::string &integrand, double low_limit,
        double upper_limit, unsigned quantity_of_steps);
    double trapezoid_method(const std::string &integrand, double low_limit,
        double upper_limit, unsigned quantity_of_steps);
    double simpson_method(const std::string &integrand, double low_limit,
        double upper_limit, double eps);
 private:
     std::string change_variable_to_value(const std::string &integrand,
        double value);
     double calculate_function(const std::string &integrand);
};

#endif  // MODULES_LAB2_INTEGRATION_METHODS_INCLUDE_INTEGRATION_METHODS_H_
