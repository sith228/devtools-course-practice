// Copyright 2017 Nikita Grechukhin

#ifndef MODULES_NIKITA_GRECHUKHIN_LAB2_INTEGRATION_METHODS_INCLUDE_INTEGRATION_METHODS_H_
#define MODULES_NIKITA_GRECHUKHIN_LAB2_INTEGRATION_METHODS_INCLUDE_INTEGRATION_METHODS_H_

class IntegrationMethod {

private:
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

#endif  // MODULES_NIKITA_GRECHUKHIN_LAB2_INTEGRATION_METHODS_INCLUDE_INTEGRATION_METHODS_H_
