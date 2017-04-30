// Copyright 2017 Grechukhin Nikita

#include "include/integration_methods.h"
#include <string>

void IntegrationMethod::change_variable_to_value(std::string input,
    double value) {
    int size = input.size();
    for (int i = 0; i < size; i++) {
        if (input.at(i) == 'x' || input.at(i) == 'X')
            input.replace(i, 1, std::to_string(value));
    }
}

IntegrationMethod::IntegrationMethod() {}
