// Copyright 2017 Grechukhin Nikita

#ifndef MODULES_NIKITA_GRECHUKHIN_LAB2_INTEGRATION_METHODS_INCLUDE_INTEGRATION_METHODS_H_
#define MODULES_NIKITA_GRECHUKHIN_LAB2_INTEGRATION_METHODS_INCLUDE_INTEGRATION_METHODS_H_

class IntegrationMethod {
 public:
    IntegrationMethod();
    IntegrationMethod(double upperLimit, double lowerLimit);

    double getUpperLimit() const;
    void setUpperLimit(double upperLimit);

    double getLowerLimit() const;
    void setLowerLimit(double lowerLimit);

 private:
    double upperLimit;
    double lowerLimit;

};

#endif  // MODULES_NIKITA_GRECHUKHIN_LAB2_INTEGRATION_METHODS_INCLUDE_INTEGRATION_METHODS_H_
