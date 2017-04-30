// Copyright 2017 Dmitrichev Nikita

#include <gtest/gtest.h>

#include "include/converter_currencies.h"

TEST(ConverterCurrenciesTest, can_not_create_convert_with_negativ_first_arg) {
     // No actions

     EXPECT_ANY_THROW(new converter_currencies(-100, RUR));
}

TEST(ConverterCurrenciesTest, can_create_converter_with_positive_first_arg) {
    // No actions

    EXPECT_NO_THROW(new converter_currencies(100, RUR));
}

TEST(ConverterCurrenciesTest, can_not_set_convert_with_negative_first_arg) {
    converter_currencies conv_curr(0.0f, RUR);

    EXPECT_ANY_THROW(conv_curr.SetCurrentMoney(-100, RUR));
}

TEST(ConverterCurrenciesTest, can_set_converter_with_positive_first_arg) {
    converter_currencies conv_curr(0.0f, RUR);

    EXPECT_NO_THROW(conv_curr.SetCurrentMoney(100, RUR));
}

TEST(ConverterCurrenciesTest, got_currency_name_is_right) {
    converter_currencies conv_curr(111.0f, RUR);

    Currency expected = RUR;
    EXPECT_EQ(expected, conv_curr.GetCurrentCurrency());
}

TEST(ConverterCurrenciesTest, got_currency_size_is_right) {
    converter_currencies conv_curr(111.0f, RUR);

    float expected = 111.0f;
    EXPECT_EQ(expected, conv_curr.GetCurrentSize());
}

TEST(ConverterCurrenciesTest, setter_changes_currency_name) {
    converter_currencies conv_curr(0.0f, RUR);

    conv_curr.SetCurrentMoney(111.0f, UAH);

    Currency expected = UAH;
    EXPECT_EQ(expected, conv_curr.GetCurrentCurrency());
}

TEST(ConverterCurrenciesTest, setter_changes_currency_size) {
    converter_currencies conv_curr(0.0f, RUR);

    conv_curr.SetCurrentMoney(111.0f, UAH);

    float expected = 111.0f;
    EXPECT_EQ(expected, conv_curr.GetCurrentSize());
}

TEST(ConverterCurrenciesTest, convert_zero_changes_name_do_not_changes_size) {
    converter_currencies conv_curr(0.0f, RUR);
    float oldsize = conv_curr.GetCurrentSize();
    Currency oldname = conv_curr.GetCurrentCurrency();

    conv_curr.Convert(UAH);

    bool expected = conv_curr.GetCurrentCurrency() != oldname &&
         conv_curr.GetCurrentSize() == oldsize;
    EXPECT_TRUE(expected);
}

TEST(ConverterCurrenciesTest, conver_of_no_zero_changes_name_and_size) {
    converter_currencies conv_curr(111.50f, RUR);
    float oldsize = conv_curr.GetCurrentSize();
    Currency oldname = conv_curr.GetCurrentCurrency();

    conv_curr.Convert(UAH);

    bool expected = conv_curr.GetCurrentCurrency() != oldname &&
         conv_curr.GetCurrentSize() != oldsize;
    EXPECT_TRUE(expected);
}

TEST(ConverterCurrenciesTest, convert_works_right_if_was_unviersal_ruble) {
    converter_currencies conv_curr(100.50f, RUR);

    conv_curr.Convert(UAH);

    float expected = 100.50f*RURtoUAH;
    EXPECT_EQ(expected, conv_curr.GetCurrentSize());
}

TEST(ConverterCurrenciesTest, convert_works_right_if_was_not_unviersal_ruble) {
    converter_currencies conv_curr(100.50f, EUR);

    conv_curr.Convert(UAH);

    float expected = 100.50f / RURtoEUR * RURtoUAH;
    EXPECT_EQ(expected, conv_curr.GetCurrentSize());
}

TEST(ConverterCurrenciesTest, convert_works_right_if_RURtoRUR) {
    converter_currencies conv_curr(100.50f, RUR);

    conv_curr.Convert(RUR);

    float expected = 100.50f;
    EXPECT_EQ(expected, conv_curr.GetCurrentSize());
}

TEST(ConverterCurrenciesTest, convert_works_right_if_SomethingtoItself) {
    converter_currencies conv_curr(100.50f, UAH);

    conv_curr.Convert(UAH);

    float expected = 100.50f;
    EXPECT_EQ(expected, conv_curr.GetCurrentSize());
}

TEST(ConverterCurrenciesTest, convert_works_right_if_RURtoSomething) {
    converter_currencies conv_curr(100.50f, RUR);

    conv_curr.Convert(UAH);

    float expected = 100.50f * RURtoUAH;
    EXPECT_EQ(expected, conv_curr.GetCurrentSize());
}

TEST(ConverterCurrenciesTest, convert_works_right_if_SomethingtoSomething) {
    converter_currencies conv_curr(100.50f, EUR);

    conv_curr.Convert(UAH);

    float expected = 100.50f / RURtoEUR * RURtoUAH;
    EXPECT_EQ(expected, conv_curr.GetCurrentSize());
}
