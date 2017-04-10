// Copyright 2016 Nesterov Alexander

#include <gtest/gtest.h>
#include <functional>

#include "include/complex_number.h"

typedef std::function<ComplexNumber(int, ComplexNumber)> functor;

TEST(Nesterov_Alexander_ComplexNumberTest,
     DISABLED_Check_Property_Conjugacy) {
    // Arrange
    double re = 1.00001;
    double im = 0.00001;
    ComplexNumber z(re, im);
    ComplexNumber conjugate_z(re, -im);

    // Act & Assert
    ComplexNumber res1(1.0, 0.0);
    ComplexNumber res2(1.0, 0.0);

    for (int i = 0; i < 1000; i++) {
        res1 = res1 * conjugate_z;
        res2 = res2 * z;
    }
    res2.setIm(-res2.getIm());

    EXPECT_EQ(res1, res2);
}

TEST(Nesterov_Alexander_ComplexNumberTest,
     /*DISABLED*/_Will_Be_Result_Is_Real_Number) {
    // Arrange
    double re = 0.0;
    double im = 2.0;
    ComplexNumber z(re, im);
    ComplexNumber conjugate_z(re, -im);

    // Act
    ComplexNumber res(1.0, 0.0);
    for (int i = 0; i < 1000; i++) {
        res = res * (z +  z * conjugate_z + conjugate_z);
    }

    // Assert
    EXPECT_DOUBLE_EQ(0.0, res.getIm());
}

TEST(Nesterov_Alexander_ComplexNumberTest,
     Can_Use_Repeated_Enclosure_Constructors) {
    // Arrange
    double re = 3.68;
    double im = 2.09;
    ComplexNumber z(re, im);

    // Act
    functor foo = [&foo](int k, ComplexNumber y) -> ComplexNumber {
        if (k != 1) {
            ComplexNumber temp(foo(k - 1, y));
            return temp;
        }
        return y;
    };
    ComplexNumber res(foo(10000, z));

    // Assert
    EXPECT_DOUBLE_EQ(re, res.getRe());
    EXPECT_DOUBLE_EQ(im, res.getIm());
}
