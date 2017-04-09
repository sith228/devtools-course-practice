// Copyright 2017 Alexander Gaivanuk

#include <gtest\gtest.h>
#include "include\complex_number.h"

TEST(Gaivanuk_Alexander_ComplexNumberTest, Check_default_ctor) {
	ComplexNumber z(0.0, 0.0);

	EXPECT_EQ(0.0, z.getRe());
	EXPECT_EQ(0.0, z.getIm());
}

TEST(Gaivanuk_Alexander_ComplexNumberTest, Can_create_with_im_and_re_parts) {
	double re = 234.23;
	double im = 324432.243;
	ComplexNumber z(re, im);

	EXPECT_EQ(re, z.getRe());
	EXPECT_EQ(im, z.getIm());
}

TEST(Gaivanuk_Alexander_ComplexNumberTest, Can_create_via_copy_ctor) {
	ComplexNumber z(34.23, -12.44);

	ComplexNumber z2(z);

	EXPECT_EQ(z, z2);
}

TEST(Gaivanuk_Alexander_ComplexNumberTest, Check_assign_operator) {
	ComplexNumber z(12.543, -23.44);

	ComplexNumber z2;
	z = z2;

	EXPECT_EQ(z, z2);
}

TEST(Gaivanuk_Alexander_ComplexNumberTest, Check_assign_operator_applying_to_itself) {
	double re = -24.435;
	double im = 54.34;
	ComplexNumber z(re, im);
	
	z = z;
	EXPECT_EQ(z.getRe(), re);
	EXPECT_EQ(z.getIm(), im);
}

TEST(Gaivanuk_Alexander_ComplexNumberTest, Can_set_re) {
	
	ComplexNumber z(-35.23, 56.0);

	double re2 = 45.223;
	double im2 = -5.344;

	z.setRe(re2);
	z.setIm(im2);

	EXPECT_EQ(z.getRe(), re2);
	EXPECT_EQ(z.getIm(), im2);
}

TEST(Gaivanuk_Alexander_ComplexNumberTest, Check_number_is_equal_to_itself) {
	ComplexNumber z(-3.23, 12.0);

	EXPECT_EQ(z, z);
}