// Copyright 2017 Korniakov Kirill

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Igor_Fedorov_ComplexNumberTest, Cant_divide_by_Zero) {
	double r = 15.023;
	double i = 97.193;
	ComplexNumber a(r, i);
	ComplexNumber b(r, i);
	ComplexNumber c = a - b;
	ComplexNumber d;
	EXPECT_ANY_THROW(d = c / d);
}
TEST(Igor_Fedorov_ComplexNumberTest, Cant_divide_by_Zero) {
	double r = 123;
	double i = 123;
	ComplexNumber a(1, 0);
	ComplexNumber b(r, i);
	ComplexNumber c = a / b;
	ComplexNumber d(r / (r*r +i*i ),-i/(r*r+i*i));
	EXPECT_EQ(c,d);
}