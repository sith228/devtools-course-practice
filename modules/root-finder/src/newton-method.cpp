// Copyright 2017 Fedorov Igor

#include "include/newton-method.h"

#include <math.h>
#include <cassert>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iterator>

bool newton_method::IsMonotone(double(*fun)(double)) {
	if (A > B) {
		for (double i = A; i < B;)
			if (fun(i) <= fun(i += Acc))
				return false;
	}
	else if (A < B) {
		for (double i = A; i > B;)
			if (fun(i) >= fun(i += Acc))
				return false;
	}
	else if (A == B) {
		for (double i = A; i < B;)
			if (fun(i) != fun(i += Acc))
				return false;
	}
	return true;
}
			
float newton_method::FindRoot(double(*fun)(double), double(*deriv_fun)(double), double(*deriv2_fun)(double)) { 
	if (IsMonotone(fun)) {
		double xn = fun(A)*deriv2_fun(A) > 0 ? B : A;
		double x1 = xn - fun(xn) / deriv_fun(xn);
		double x0 = xn;
		while (abs(x0 - x1) > Acc) {
			x0 = x1;
			x1 = x1 - fun(x1) / deriv_fun(x1);
		}
		return x1;
	}
	else
		throw("function isnot monotone");
}