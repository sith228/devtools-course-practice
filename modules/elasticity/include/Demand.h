// Copyright 2017 Zemlyanskiy Nikita

#ifndef MODULES_ELASTICITY_INCLUDE_DEMAND_H_
#define MODULES_ELASTICITY_INCLUDE_DEMAND_H_

enum Elasticity{Elastic, UnitElastic, NoElastic};

class Demand {
 protected:
    double coeffofdemand;
    double oldprice, newprice;
    double olddemand, newdemand;
    double deltaprice;
    double deltademand;
    double revenue;
    int elasticity;
 public:
    Demand(double _oldprice, double _newprice,
           double _olddemand, double _newdemand);
    int checkforelasticity();
    double revenuechange(double revenue);
};
#endif  // MODULES_ELASTICITY_INCLUDE_DEMAND_H_
