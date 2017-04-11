//Copyright 2017 Kulygina Julia
#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kulygina_Julia_ComplexNumberTest, Can_create_complex_number) 
{
    double re = 1.0;
    double im = -1.0;
    ComplexNumber z(re, im);
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}
TEST(Kulygina_Julia_ComplexNumberTest, Can_set_complex_number)
{
    ComplexNumber z(10.0, 10.0);
    z.setRe(6.0);
    z.setIm(-1.0);
    EXPECT_EQ(6.0, z.getRe());
    EXPECT_EQ(-1.0, z.getIm());
}
TEST(Kulygina_Julia_ComplexNumberTest, Correct_add_operation)
{
    ComplexNumber z1(1.0, 2.0);
    ComplexNumber z2(1.0, 0.0);
    EXPECT_EQ((z2+z1).getRe, 2.0);
    EXPECT_EQ((z2+z1).getIm, 2.0);
}
TEST(Kulygina_Julia_ComplexNumberTest, Correct_definition_operation)
{
    ComplexNumber z(1.0, 2.0);
    ComplexNumber zres(0.0, 0.0);
    zres = z;
    EXPECT_EQ(zres.getRe, 1.0);
    EXPECT_EQ(zres.getIm, 2.0);
}
TEST(Kulygina_Julia_ComplexNumberTest, Correct_divided_zero)
{
    ComplexNumber z1(1.0, 2.0);
    ComplexNumber z2(0.0, 0.0);
    ASSERT_ANY_THROW(z1/z2);
}
TEST(Kulygina_Julia_ComplexNumberTest, Correct_divide_operation)
{
    ComplexNumber z1(1.0, 2.0);
    ComplexNumber z2(1.0, 0.0);
    ASSERT_NO_THROW(z1/z2);
    EXPECT_EQ((z1/z2).getRe, 1.0);
    EXPECT_EQ((z1/z2).getIm, 2.0);
}