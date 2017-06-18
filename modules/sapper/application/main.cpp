// Copyright 2017 Fedorov Igor

#include "./include/saper.h"

int main(){
	Saper a;
	a.IsWin();
	a.MarkCell(0, 0);
	a.NewLVL();
	a.Print();
	a.TouchResult(0, 0);
	return 0;
}