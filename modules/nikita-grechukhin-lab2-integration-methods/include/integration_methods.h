// Copyright 2017 Nikita Grechukhin

#ifndef MODULES_INTEGRATION_INCLUDE_INTEGRATION_METHOD_H_
#define MODULES_INTEGRATION_INCLUDE_INTEGRATION_METHOD_H_

#include <string>

enum method
{
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

    IntegrationMethod(double upperLimit, double lowerLimit);
    ~IntegrationMethod(){}

    double upper_limit() const;
    void set_upper_limit(double upper_limit);

    double lower_limit() const;
    void set_lower_limit(double lower_limit);
};

#endif  // MODULES_INTEGRATION_METHOD_INCLUDE_INTEGRATION_METHOD_H_
