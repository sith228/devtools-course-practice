
#include <gtest/gtest.h>

#include "include/complex_number.h"

// сначала стандартная проверка всего функционала

TEST(Nazarov_Aleksandr_ComplexNumberTest, Can_Get_Rigt_Re) {

        ComplexNumber a(11, 11);

        EXPECT_EQ(a.getRe(), 11);
}

TEST(Nazarov_Aleksandr_ComplexNumberTest, Can_Set_Rigt_Im) {

        ComplexNumber a(11, 11);

        a.setIm(12);

        EXPECT_EQ(a.getIm(), 12);
}

TEST(Nazarov_Aleksandr_ComplexNumberTest, Can_Set_Rigt_Re) {

        ComplexNumber a(11, 11);

        a.setRe(12);

        EXPECT_EQ(a.getRe(), 12);

}

TEST(Nazarov_Aleksandr_ComplexNumberTest, Can_Get_Rigt_Im) {

        ComplexNumber a(11, 11);

        EXPECT_EQ(a.getIm(), 11);

}

TEST(Nazarov_Aleksandr_ComplexNumberTest, Can_Get_Right_Sum) {

        double ar = 13.77, ai = 19.86;
        double br = 4.20, bi = 14.00;
        double cr = ar + br, ci = ai + bi;

        ComplexNumber a(ar, ai);
        ComplexNumber b(br, bi);
        ComplexNumber c(0.00, 0.00);

        ASSERT_NO_THROW(c = a + b);

        EXPECT_EQ(c.getRe(), cr);
        EXPECT_EQ(c.getIm(), ci);
}

TEST(Nazarov_Aleksandr_ComplexNumberTest, Can_Get_Right_Subtract) {

        double ar = 13.77, ai = 19.86;
        double br = 4.20, bi = 14.00;
        double cr = ar - br, ci = ai - bi;

        ComplexNumber a(ar, ai);
        ComplexNumber b(br, bi);
        ComplexNumber c(0.00, 0.00);

        ASSERT_NO_THROW(c = a - b);

        EXPECT_EQ(c.getRe(), cr);
        EXPECT_EQ(c.getIm(), ci);
}

TEST(Nazarov_Aleksandr_ComplexNumberTest, Can_Get_Right_Multiplication) {

        double ar = 10, ai = 10;
        double br = 2, bi = 2;
        double cr = 0, ci = 40;

        ComplexNumber a(ar, ai);
        ComplexNumber b(br, bi);
        ComplexNumber c(0.00, 0.00);

        ASSERT_NO_THROW(c = a * b);

        EXPECT_EQ(c.getRe(), cr);
        EXPECT_EQ(c.getIm(), ci);
}

TEST(Nazarov_Aleksandr_ComplexNumberTest, Can_Get_Right_Division) {

        double ar = 10, ai = 10;
        double br = 4, bi = 2;
        double cr = 3, ci = 1;

        ComplexNumber a(ar, ai);
        ComplexNumber b(br, bi);
        ComplexNumber c(0.00, 0.00);

        ASSERT_NO_THROW(c = a / b);

        EXPECT_EQ(c.getRe(), cr);
        EXPECT_EQ(c.getIm(), ci);
}

TEST(Nazarov_Aleksandr_ComplexNumberTest, Can_Get_Right_Equal) {

        double ar = 13.77, ai = 19.86;
        double br = 4.20, bi = 14.00;

        ComplexNumber a(ar, ai);
        ComplexNumber b(br, bi);
        ComplexNumber c(0.00, 0.00);

        ASSERT_NO_THROW(c = a);

        EXPECT_EQ(c, a);
        EXPECT_NE(c, b);
        EXPECT_EQ(1, c == a);
        EXPECT_EQ(0, a == b);
}

TEST(Nazarov_Aleksandr_ComplexNumberTest, Can_Get_Right_Not_Equal) {

        double ar = 13.77, ai = 19.86;
        double br = 4.20, bi = 14.00;

        ComplexNumber a(ar, ai);
        ComplexNumber b(br, bi);
        ComplexNumber c(0.00, 0.00);

        ASSERT_NO_THROW(c = a);

        EXPECT_EQ(c, a);
        EXPECT_NE(c, b);
        EXPECT_EQ(0, c != a);
        EXPECT_EQ(1, a != b);
}

// что нибудь необычное

TEST(Nazarov_Aleksandr_ComplexNumberTest, Can_Equate_To_Itself) {

        double ar = 13.77, ai = 19.86;

        ComplexNumber a(ar, ai);

        ASSERT_NO_THROW(a = a);

        EXPECT_EQ(a.getIm(), ai);
        EXPECT_EQ(a.getRe(), ar);
}

TEST(Nazarov_Aleksandr_ComplexNumberTest, Cant_Division_To_Zero) {

        double ar = 13.77, ai = 19.86;

        ComplexNumber a(ar, ai);
        ComplexNumber b(0, 0);

        ASSERT_ANY_THROW(a/b);
}
