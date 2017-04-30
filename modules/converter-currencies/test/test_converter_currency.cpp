// Copyright 2017 Dmitrichev Nikita

#include <gtest/gtest.h>

#include "include/converter_currency.h"
     
class ConverterCurrenciesTest : public ::testing::Test {
protected:
    virtual void SetUp() {
        Converter = new converter_currency();
    }
    converter_currency* Converter;
};

TEST_F(ConverterCurrenciesTest, can_not_convert_if_money_size_less_then_zero) {

    EXPECT_ANY_THROW(Converter->Convert(-1, RUR, EUR));
}

TEST_F(ConverterCurrenciesTest, can_convert_if_money_size_equal_to_zero) {

    EXPECT_NO_THROW(Converter->Convert(0, RUR, EUR));
}

TEST_F(ConverterCurrenciesTest, if_zero_money_size_was_converted_its_zero) {

    float expected = 0.0f;
    EXPECT_EQ(expected, Converter->Convert(0, RUR, EUR));
}

TEST_F(ConverterCurrenciesTest, can_convert_if_target_equal_to_old) {

    float expected = 111.1f;
    EXPECT_EQ(expected, Converter->Convert(expected, EUR, EUR));
}

TEST_F(ConverterCurrenciesTest, can_convert_from_old_to_new) {
    float oldmoney = 111.1f;

    float expected = oldmoney / RURtoEUR * RURtoJPY;
    EXPECT_EQ(expected, Converter->Convert(oldmoney, EUR, JPY));
}

TEST_F(ConverterCurrenciesTest, there_are_no_problems_with_constructor) {

    EXPECT_NO_THROW(new converter_currency());
}