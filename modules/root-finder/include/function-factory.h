// Copyright 2017 Maxim Doronin

#ifndef MODULES_ROOT_FINDER_INCLUDE_FUNCTION_FACTORY_H_
#define MODULES_ROOT_FINDER_INCLUDE_FUNCTION_FACTORY_H_

#include "include/functions.h"

enum FunctionID
{
	POLINOMIAL_2_DEGREE,
	POLINOMIAL_3_DEGREE,
    POLINOMIAL_4_DEGREE,
    EXPONENT
};

class FunctionFactory {
 public:
	static Function* createFunction (FunctionID fid)
	{
		Function *function;

		switch (fid) {
		case 0: function = new Polynomial2Degree(); break;
		case 1: function = new Polynomial3Degree(); break;
		case 2: function = new Polynomial4Degree(); break;
        case 3: function = new Exponent(); break;
		}
		return function;
	}
};



#endif  // MODULES_ROOT_FINDER_INCLUDE_FUNCTION_FACTORY_H_
