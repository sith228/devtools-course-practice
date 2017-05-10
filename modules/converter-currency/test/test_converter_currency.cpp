// Copyright 2017 Dmitrichev Nikita

#include <gtest/gtest.h>

#include "include/ConverterCurrency.h"

TEST(ConverterCurrenciesTest, can_not_convert_if_money_size_less_then_zero) {
    EXPECT_ANY_THROW(ConverterCurrency::Convert(-1, RUR, EUR));
}

TEST(ConverterCurrenciesTest, can_convert_if_money_size_equal_to_zero) {
    EXPECT_NO_THROW(ConverterCurrency::Convert(0, RUR, EUR));
}

TEST(ConverterCurrenciesTest, if_zero_money_size_was_converted_its_zero) {
    double expected = 0.0;
    EXPECT_EQ(expected, ConverterCurrency::Convert(0, RUR, EUR));
}

TEST(ConverterCurrenciesTest, can_convert_if_target_equal_to_old) {
    double exp = 111.1;
    EXPECT_NEAR(exp, ConverterCurrency::Convert(exp, EUR, EUR), 0.01);
}

TEST(ConverterCurrenciesTest, converter_works_right) {
    double expected = 2647.32;  // 100 usd to uah
    EXPECT_NEAR(expected, ConverterCurrency::Convert(100.0, USD, UAH), 0.5);
}
