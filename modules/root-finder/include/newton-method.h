// Copyright 2017 Fedorov Igor

#ifndef MODULES_ARITHMETIC_PARSER_INCLUDE_ARITHMETIC_PARSER_H_
#define MODULES_ARITHMETIC_PARSER_INCLUDE_ARITHMETIC_PARSER_H_

class newton_method {
public:
	void setA(float a) {
		A = a;
	};
	void setB(float b) {
		B = b;
	};
	void setAccuracy(float acc) {
		Acc = acc;
	};

	float FindRoot(double(*fun)(double), double(*deriv_fun)(double), double(*deriv2_fun)(double));

private:
	float A;
	float B;
	float Acc;
	bool IsMonotone(double(*fun)(double));
};
#endif  // MODULES_ARITHMETIC_PARSER_INCLUDE_ARITHMETIC_PARSER_H_
