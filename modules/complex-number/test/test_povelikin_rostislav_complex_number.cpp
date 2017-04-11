// Copyright 2017 Povelikin Rostislav

#include <gtest/gtest.h>
#include "include/complex_number.h"

class Povelikin_Rostislav_ComplexNumberTestFixture : public ::testing::Test {
protected:
    double im = 2132.421;
    double re = -3213.153141;
    ComplexNumber complexNumber;

    void SetUp() {
        complexNumber.setIm(im);
        complexNumber.setRe(re);
    }

    void TearDown() {};
};

TEST_F(Povelikin_Rostislav_ComplexNumberTestFixture, square_number) {
    complexNumber = complexNumber * complexNumber;

    EXPECT_EQ(re * re - im * im, complexNumber.getRe());
    EXPECT_EQ(re * im + re * im, complexNumber.getIm());
}

TEST_F(Povelikin_Rostislav_ComplexNumberTestFixture, sum_with_zero) {
    complexNumber = complexNumber + ComplexNumber();

    EXPECT_EQ(re, complexNumber.getRe());
    EXPECT_EQ(im, complexNumber.getIm());
}

TEST_F(Povelikin_Rostislav_ComplexNumberTestFixture, sum_of_conjugate_is_0) {
    ComplexNumber conjucate(complexNumber);
    conjucate.setIm(complexNumber.getIm()*(-1));

    EXPECT_EQ(0, (complexNumber + conjucate).getIm());
}

TEST(Povelikin_Rostislav_ComplexNumber, contructor_with_casted_long) {
    long double re = 0.0;
    long double im = 0.0;

    ASSERT_NO_THROW(ComplexNumber complexNumber(
        static_cast<double>(re),
        static_cast<double>(im)));
}

TEST(Povelikin_Rostislav_ComplexNumber, contructor_with_casted_float) {
    float re = 0.0;
    float im = 0.0;

    ASSERT_NO_THROW(ComplexNumber complexNumber(
        static_cast<double>(re),
        static_cast<double>(im)));
}

TEST(Povelikin_Rostislav_ComplexNumber, contructor_with_casted_int) {
    int re = 0.0;
    int im = 0.0;

    ASSERT_NO_THROW(ComplexNumber complexNumber(
        static_cast<double>(re),
        static_cast<double>(im)));
}

TEST(Povelikin_Rostislav_ComplexNumber, contructor_with_casted_char) {
    char re = 0.0;
    char im = 0.0;

    ASSERT_NO_THROW(ComplexNumber complexNumber(
        static_cast<double>(re),
        static_cast<double>(im)));
}
