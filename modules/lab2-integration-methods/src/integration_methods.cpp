// Copyright 2017 Grechukhin Nikita

#include "include/integration_methods.h"
#include <string>
#include <cmath>
#include "include/function_parser.h"

std::string IntegrationMethod::change_variable_to_value(std::string input,
    double value) {
    int size = (input).size();
    for (int i = 0; i < size; i++) {
        if ((input).at(i) == 'x' || (input).at(i) == 'X') {
            (input).replace(i, 1, std::to_string(value));
            size = (input).size();
        }
    }
    return input;
}

IntegrationMethod::IntegrationMethod() {}

double IntegrationMethod::calculate_function(std::string input) {
    Parser parser(input.c_str());
    return eval(parser.parse());
}

double IntegrationMethod::rectangle_method(std::string input, double low_limit,
    double upper_limit, int quantity_of_steps) {
    std::string func_in_low_limit = change_variable_to_value(input, low_limit);
    std::string func_in_upper_limit =
        change_variable_to_value(input, upper_limit);

    double s = calculate_function(func_in_low_limit) +
        calculate_function(func_in_upper_limit);
    s /=2;

    double h = (upper_limit - low_limit) / quantity_of_steps;
    for (int i=1; i < quantity_of_steps; i++) {
        double x = low_limit + i*h;
        std::string func = change_variable_to_value(input, x);
        s+=calculate_function(func);
    }

    double result = s*h;
    return result;
}

double IntegrationMethod::trapezoid_method(std::string input, double low_limit,
    double upper_limit, int quantity_of_steps) {
        double result = 0;
        if (quantity_of_steps > 1) {
            double y, dy;
            dy = (upper_limit - low_limit)/quantity_of_steps;
            std::string func_in_low_limit =
                change_variable_to_value(input, low_limit);
            std::string func_in_upper_limit =
                change_variable_to_value(input, upper_limit);
            y = calculate_function(func_in_low_limit) +
                calculate_function(func_in_upper_limit);

            for (int i=1; i < quantity_of_steps; i++) {
                double x = low_limit + dy*i;
                std::string func = change_variable_to_value(input, x);
                y+=2*calculate_function(func);
            }
            result = (upper_limit - low_limit) / (2*quantity_of_steps)*y;
        }
        return result;
}

double IntegrationMethod::simpson_method(std::string input, double low_limit,
    double upper_limit, double eps) {
        double integral = eps + 1;
        double integral1 = 0;
        for (int n=2; (n <= 4) || (fabs(integral1-integral) > eps); n*=2) {
            double h, sum2 = 0, sum4 = 0, sum = 0;
            h = (upper_limit - low_limit)/(2*n);
            for (int i=1; i <= 2*n-1; i+=2) {
                double x1 = low_limit + h*i;
                double x2 = low_limit + h*(i+1);
                std::string func1 = change_variable_to_value(input, x1);
                std::string func2 = change_variable_to_value(input, x2);

                sum4+=calculate_function(func1);
                sum2+=calculate_function(func2);
            }
            std::string func_with_lower_limit =
                change_variable_to_value(input, low_limit);
            std::string func_with_upper_limit =
                change_variable_to_value(input, upper_limit);
            sum = calculate_function(func_with_lower_limit) + 4*sum4 + 2*sum2-
                calculate_function(func_with_upper_limit);
            integral = integral1;
            integral1 = (h/3)*sum;
        }
    return integral1;
}
