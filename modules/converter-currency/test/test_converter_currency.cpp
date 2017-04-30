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

TEST_F(ConverterCurrenciesTest, can_convert_from_RUR_to_RUR) {

    float expected = 111.1f;
    EXPECT_EQ(expected, Converter->Convert(expected, RUR, RUR));
}

TEST_F(ConverterCurrenciesTest, can_convert_from_RUR_to_EUR) {
    float oldMoney = 111.1f;

    float expected = oldMoney * RURtoEUR;
    EXPECT_EQ(expected, Converter->Convert(oldMoney, RUR, EUR));
}

TEST_F(ConverterCurrenciesTest, can_convert_from_RUR_to_CNY) {
    float oldMoney = 111.1f;

    float expected = oldMoney * RURtoCNY;
    EXPECT_EQ(expected, Converter->Convert(oldMoney, RUR, CNY));
}

TEST_F(ConverterCurrenciesTest, can_convert_from_RUR_to_JPY) {
    float oldMoney = 111.1f;

    float expected = oldMoney * RURtoJPY;
    EXPECT_EQ(expected, Converter->Convert(oldMoney, RUR, JPY));
}

TEST_F(ConverterCurrenciesTest, can_convert_from_RUR_to_GBP) {
    float oldMoney = 111.1f;

    float expected = oldMoney * RURtoGBP;
    EXPECT_EQ(expected, Converter->Convert(oldMoney, RUR,GBP));
}

TEST_F(ConverterCurrenciesTest, can_convert_from_RUR_to_UAH) {
    float oldMoney = 111.1f;

    float expected = oldMoney * RURtoUAH;
    EXPECT_EQ(expected, Converter->Convert(oldMoney, RUR, UAH));
}

TEST_F(ConverterCurrenciesTest, can_convert_from_RUR_to_USD) {
    float oldMoney = 111.1f;

    float expected = oldMoney * RURtoUSD;
    EXPECT_EQ(expected, Converter->Convert(oldMoney, RUR, USD));
}

TEST_F(ConverterCurrenciesTest, can_convert_from_GBP_to_USD) {
    float oldMoney = 111.1f;

    float expected = oldMoney * RURtoUSD / RURtoGBP;
    EXPECT_EQ(expected, Converter->Convert(oldMoney, GBP, USD));
}

TEST_F(ConverterCurrenciesTest, can_convert_from_JPY_to_USD) {
    float oldMoney = 111.1f;

    float expected = oldMoney * RURtoUSD / RURtoJPY;
    EXPECT_EQ(expected, Converter->Convert(oldMoney, JPY, USD));
}

TEST_F(ConverterCurrenciesTest, can_convert_from_EUR_to_USD) {
    float oldMoney = 111.1f;

    float expected = oldMoney * RURtoUSD / RURtoEUR;
    EXPECT_EQ(expected, Converter->Convert(oldMoney, EUR, USD));
}

TEST_F(ConverterCurrenciesTest, can_convert_from_UAH_to_USD) {
    float oldMoney = 111.1f;

    float expected = oldMoney * RURtoUSD / RURtoUAH;
    EXPECT_EQ(expected, Converter->Convert(oldMoney, UAH, USD));
}

TEST_F(ConverterCurrenciesTest, can_convert_from_CNY_to_USD) {
    float oldMoney = 111.1f;

    float expected = oldMoney * RURtoUSD / RURtoCNY;
    EXPECT_EQ(expected, Converter->Convert(oldMoney, CNY, USD));
}

TEST_F(ConverterCurrenciesTest, there_are_no_problems_with_constructor) {

    EXPECT_NO_THROW(new converter_currency());
}
