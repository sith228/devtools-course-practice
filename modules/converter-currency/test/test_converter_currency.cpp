// Copyright 2017 Dmitrichev Nikita

#include <gtest/gtest.h>
#include "include/ConverterCurrency.h"

using Currency::CNY;
using Currency::RUR;
using Currency::USD;
using Currency::GBP;
using Currency::UAH;
using Currency::EUR;
using Currency::JPY;
using Currency::RURtoCNY;
using Currency::RURtoEUR;
using Currency::RURtoGBP;
using Currency::RURtoJPY;
using Currency::RURtoUAH;
using Currency::RURtoUSD;

TEST(ConverterCurrenciesTest, can_not_convert_if_money_size_less_then_zero) {
    EXPECT_ANY_THROW(ConverterCurrency::Convert(-1, RUR, EUR));
}

TEST(ConverterCurrenciesTest, can_convert_if_money_size_equal_to_zero) {
    EXPECT_NO_THROW(ConverterCurrency::Convert(0, RUR, EUR));
}

TEST(ConverterCurrenciesTest, if_zero_money_size_was_converted_its_zero) {
    float expected = 0.0f;
    EXPECT_EQ(expected, ConverterCurrency::Convert(0, RUR, EUR));
}

TEST(ConverterCurrenciesTest, can_convert_if_target_equal_to_old) {
    float expected = 111.1f;
    EXPECT_EQ(expected, ConverterCurrency::Convert(expected, EUR, EUR));
}

TEST(ConverterCurrenciesTest, can_convert_from_RUR_to_RUR) {
    float expected = 111.1f;
    EXPECT_EQ(expected, ConverterCurrency::Convert(expected, RUR, RUR));
}

TEST(ConverterCurrenciesTest, can_convert_from_RUR_to_EUR) {
    float oldMoney = 111.1f;

    float expected = oldMoney * RURtoEUR;
    EXPECT_EQ(expected, ConverterCurrency::Convert(oldMoney, RUR, EUR));
}

TEST(ConverterCurrenciesTest, can_convert_from_RUR_to_CNY) {
    float oldMoney = 111.1f;

    float expected = oldMoney * RURtoCNY;
    EXPECT_EQ(expected, ConverterCurrency::Convert(oldMoney, RUR, CNY));
}

TEST(ConverterCurrenciesTest, can_convert_from_RUR_to_JPY) {
    float oldMoney = 111.1f;

    float expected = oldMoney * RURtoJPY;
    EXPECT_EQ(expected, ConverterCurrency::Convert(oldMoney, RUR, JPY));
}

TEST(ConverterCurrenciesTest, can_convert_from_RUR_to_GBP) {
    float oldMoney = 111.1f;

    float expected = oldMoney * RURtoGBP;
    EXPECT_EQ(expected, ConverterCurrency::Convert(oldMoney, RUR, GBP));
}

TEST(ConverterCurrenciesTest, can_convert_from_USD_to_RUR) {
    float oldMoney = 111.1f;

    float expected = oldMoney / RURtoUSD;
    EXPECT_EQ(expected, ConverterCurrency::Convert(oldMoney, USD, RUR));
}

TEST(ConverterCurrenciesTest, can_convert_from_RUR_to_UAH) {
    float oldMoney = 111.1f;

    float expected = oldMoney * RURtoUAH;
    EXPECT_EQ(expected, ConverterCurrency::Convert(oldMoney, RUR, UAH));
}

TEST(ConverterCurrenciesTest, can_convert_from_RUR_to_USD) {
    float oldMoney = 111.1f;

    float expected = oldMoney * RURtoUSD;
    EXPECT_EQ(expected, ConverterCurrency::Convert(oldMoney, RUR, USD));
}

TEST(ConverterCurrenciesTest, can_convert_from_GBP_to_USD) {
    float oldMoney = 111.1f;

    float expected = oldMoney * RURtoUSD / RURtoGBP;
    EXPECT_EQ(expected, ConverterCurrency::Convert(oldMoney, GBP, USD));
}

TEST(ConverterCurrenciesTest, can_convert_from_JPY_to_USD) {
    float oldMoney = 111.1f;

    float expected = oldMoney * RURtoUSD / RURtoJPY;
    EXPECT_EQ(expected, ConverterCurrency::Convert(oldMoney, JPY, USD));
}

TEST(ConverterCurrenciesTest, can_convert_from_EUR_to_USD) {
    float oldMoney = 111.1f;

    float expected = oldMoney * RURtoUSD / RURtoEUR;
    EXPECT_EQ(expected, ConverterCurrency::Convert(oldMoney, EUR, USD));
}

TEST(ConverterCurrenciesTest, can_convert_from_UAH_to_USD) {
    float oldMoney = 111.1f;

    float expected = oldMoney * RURtoUSD / RURtoUAH;
    EXPECT_EQ(expected, ConverterCurrency::Convert(oldMoney, UAH, USD));
}

TEST(ConverterCurrenciesTest, can_convert_from_CNY_to_USD) {
    float oldMoney = 111.1f;

    float expected = oldMoney * RURtoUSD / RURtoCNY;
    EXPECT_EQ(expected, ConverterCurrency::Convert(oldMoney, CNY, USD));
}

