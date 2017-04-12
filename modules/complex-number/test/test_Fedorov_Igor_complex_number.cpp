// Copyright 2017 Korniakov Kirill

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Igor_Fedorov_ComplexNumberTest, Cant_divide_by_Zero) {
	double re = 234.23;
	double im = 324432.243;

	ComplexNumber z1(re, im);
	ComplexNumber z2(re, im);
	ComplexNumber z = z1 - z2;
	ComplexNumber c;
	EXPECT_ANY_THROW(c = z / c);
}
