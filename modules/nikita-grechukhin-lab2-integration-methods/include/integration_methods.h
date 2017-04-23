// Copyright 2017 Nikita Grechukhin

#ifndef MODULES_INTEGRATION_INCLUDE_INTEGRATION_METHOD_H_
#define MODULES_INTEGRATION_INCLUDE_INTEGRATION_METHOD_H_

#include <string>

enum method {
    Rectangles,
    Trapezium,
    Simpson
};

class IntegrationMethod {

private:
    double result;
    double upperLimit;
    double lowerLimit;

public:
    IntegrationMethod();
    IntegrationMethod(double upperLimit, double lowerLimit);

    double getUpperLimit() const;
    void setUpperLimit(double upperLimit);

    double getLowerLimit() const;
    void setLowerLimit(double lowerLimit);
};

#endif  // MODULES_INTEGRATION_METHOD_INCLUDE_INTEGRATION_METHOD_H_
