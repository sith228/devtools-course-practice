// Copyright 2017 Fedorov Igor

#ifndef MODULES_ROOT_FINDER_INCLUDE_NEWTON_METHOD_H_
#define MODULES_ROOT_FINDER_INCLUDE_NEWTON_METHOD_H_

class newton_method {
public:
	void setAB(float a,float b) {
		A = a;
		B = b;
	};
	void setAccuracy(float acc) {
		Acc = acc;
	};

	float FindRoot(float(*fun)(float), float(*deriv_fun)(float), float(*deriv2_fun)(float));

private:
	float A;
	float B;
	float Acc;
	bool IsMonotone(float(*fun)(float));
};
#endif  // MODULES_ARITHMETIC_PARSER_INCLUDE_ARITHMETIC_PARSER_H_
