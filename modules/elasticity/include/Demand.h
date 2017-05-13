// Copyright 2017 Zemlyanskiy Nikita

#pragma once

#include <iostream>
using namespace std;

enum Elasticity{Elastic,UnitElastic,NoElastic};

class Demand {
   protected:
       double coeffofdemand;
       double oldprice,newprice;
       double olddemand,newdemand;
       double deltaprice;
       double deltademand;
       double revenue;
   public:
      Demand(double _oldprice, double _newprice, double _olddemand, double _newdemand);
      int checkforelasticity();
      double revenuechange(double revenue);
};
