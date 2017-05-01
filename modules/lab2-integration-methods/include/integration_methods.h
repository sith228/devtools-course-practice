// Copyright 2017 Grechukhin Nikita

#ifndef MODULES_LAB2_INTEGRATION_METHODS_INCLUDE_INTEGRATION_METHODS_H_
#define MODULES_LAB2_INTEGRATION_METHODS_INCLUDE_INTEGRATION_METHODS_H_

#include <string>

class IntegrationMethod {
 public:
    IntegrationMethod();
    double rectangle_method(std::string input, double low_limit,
        double upper_limit, int quantity_of_steps);
    double trapezoid_method(std::string input, double low_limit,
        double upper_limit, int quantity_of_steps);
    double simpson_method(std::string input, double low_limit,
        double upper_limit, double eps);
 private:
    std::string change_variable_to_value(std::string input, double value);
    double calculate_function(std::string input);
};

#endif  // MODULES_LAB2_INTEGRATION_METHODS_INCLUDE_INTEGRATION_METHODS_H_
