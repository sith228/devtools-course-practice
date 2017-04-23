// Copyright 2016 Nikita Grechukhin

#include "include/integration_methods.h"

IntegrationMethod::IntegrationMethod(double upperLimit, double lowerLimit)
{
    this->upperLimit = upperLimit;
    this->lowerLimit = lowerLimit;
}

double IntegrationMethod::upper_limit() const
{
    return upperLimit;
}

void IntegrationMethod::set_upper_limit(double upper_limit)
{
    upperLimit = upper_limit;
}

double IntegrationMethod::lower_limit() const
{
    return lowerLimit;
}

void IntegrationMethod::set_lower_limit(double lower_limit)
{
    lowerLimit = lower_limit;
}
