// Copyright 2017 Zemlyanskiy Nikita

#include "../include/Demand.h"

Demand::Demand(double _oldprice, double _newprice, double _olddemand, double _newdemand) {
   if((_oldprice>=0)&&(_newprice>=0)&&(_olddemand>=0)&&(_newdemand>=0)){
      oldprice=_oldprice;
      olddemand=_olddemand;
      newprice=_newprice;
      newdemand=_newdemand;
      deltaprice = newprice - oldprice;
      deltademand = newdemand - olddemand;
      coeffofdemand = deltademand/deltaprice;
    }
    else
      throw "Error";
}

int Demand::ñheckforelasticity() {
    if(coeffofdemand==1.0){
        cout<<"Coefficient of unit elasticity"<<endl;
        return UnitElastic;
     }
    else if(coeffofdemand>1.0){
          cout<<"Demand is elastic"<<endl;
          return Elastic;
     }
    else if(coeffofdemand<1.0){
          cout<<"Demand is not elastic"<<endl;
          return NoElastic;
    }
    cout << coeffofdemand << endl;
}

double Demand::revenuechange(double revenue) {
    cout<<revenue<<endl;
    if(coeffofdemand>=1.0){
        for (int time = 0;time < 30; time++){
        //30 days of work
            if(newprice>oldprice)
               revenue--;
            else if(newprice<oldprice)
               revenue++;
            else
               revenue;
        }
    }
    if(coeffofdemand<1.0){
        for(int time=0;time<30;time++){
            if (newprice>oldprice)
                revenue--;
            else if (newprice<oldprice)
                revenue++;
            else
                revenue;
        }
    }
    cout << revenue << endl;
    return revenue;
}
