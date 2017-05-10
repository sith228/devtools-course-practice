// Copyright 2017 Bilkovsky Alexander

#ifndef  MODULES_SALARY_CALCULATION_INCLUDE_SALARY_CACULATIONL_H_
#define  MODULES_SALARY_CALCULATION_INCLUDE_SALARY_CACULATIONL_H_

class Salary {
 public:
     Salary(int salary_per_hour = 20, int needed_hours = 200,
            int work_hours = 200, int workday = 9);
     void SetAdminRest(int val);
     void SetOvertimeBonus(int val);
     void SetSalaryPerHour(int val);
     void SetNeededHours(int val);
     void SetWorkHours(int val);
     void SetWorkDay(int val);
     void SetPenalty(int val);
     void CalculateSalary();
     int GetSalary() { return salary_; }
     int GetAdminRest() { return admin_rest_; }
     int GetOvertimeBonus() { return overtime_bonus_; }
     int GetSalaryPerHour() { return salary_per_hour_; }
     int GetNeededHours() { return needed_hours_; }
     int GetWorkHours() { return work_hours_; }
     int GetWorkDay() { return workday_; }
     int GetPenalty() { return penalty_; }

 private:
     int salary_;  // Месячная зарплата
     int salary_per_hour_;  // Почасовой оклад
     int work_hours_;  // Отработанные часы
     int overtime_bonus_;  // Сверхурочные
     int admin_rest_;  // Дни административного отпуска
     int needed_hours_;  // Часы которые нужно отработать по плану
     int penalty_;  // Штраф за недоработку
     int workday_;  // Норма рабочего дня
};

#endif  // MODULES_SALARY_CALCULATION_INCLUDE_SALARY_CACULATIONL_H_
