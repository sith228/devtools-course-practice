// Copyright 2017 Fedorov Igor

#ifndef MODULES_COMPLEX_NUMBER_INCLUDE_COMPLEX_CALCULATOR_H_
#define MODULES_COMPLEX_NUMBER_INCLUDE_COMPLEX_CALCULATOR_H_

#include<iostream>
#include"../include/field.h"

class Saper {
 public:
	Saper(int wth = 10, int hght = 10, int countbomb = 10);
	void Print();
	bool TouchResult(int x_, int y_);
	void MarkCell(int x,int y);
	void NewLVL();
	bool IsWin();
 private:
	Field *field_;
	int DeactivatedBomb_;
};

#endif  // MODULES_COMPLEX_NUMBER_INCLUDE_COMPLEX_CALCULATOR_H_
