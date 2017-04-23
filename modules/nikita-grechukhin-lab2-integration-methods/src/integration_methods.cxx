// Copyright 2017 Nikita Grechukhin

#include "include/integration_methods.h"

IntegrationMethod::IntegrationMethod() {
    this->upperLimit = 1.0;
    this->lowerLimit = 0.0;
}

IntegrationMethod::IntegrationMethod(double upperLimit, double lowerLimit) {
    this->upperLimit = upperLimit;
    this->lowerLimit = lowerLimit;
}

double IntegrationMethod::getUpperLimit() const {
    return upperLimit;
}

void IntegrationMethod::setUpperLimit(double upperLimit) {
    this->upperLimit = upperLimit;
}

double IntegrationMethod::getLowerLimit() const {
    return lowerLimit;
}

void IntegrationMethod::setLowerLimit(double lowerLimit) {
    this->lowerLimit = lowerLimit;
}
