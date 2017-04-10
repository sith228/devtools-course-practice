// Copyright 2016 Nesterov Alexander

#include <gtest/gtest.h>
#include <functional>

#include "include/complex_number.h"

TEST(Nesterov_Alexander_ComplexNumberTest,
     Can_Use_Repeated_Enclosure_Constructors) {
// Arrange
    double re = 3.68;
    double im = 2.09;

// Act
    ComplexNumber z(re, im);
    std::function<ComplexNumber(int, ComplexNumber)> foo
        = [&foo](int k, ComplexNumber y) {
            if (k != 1) {
                ComplexNumber temp(foo(k - 1, y));
                y = temp;
            }
            return y;
        };
    ComplexNumber res(foo(10000, z));

// Assert
    EXPECT_EQ(re, res.getRe());
    EXPECT_EQ(im, res.getIm());
}
