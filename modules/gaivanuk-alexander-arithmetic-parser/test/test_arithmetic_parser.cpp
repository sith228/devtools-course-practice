// Copyright 2017 Alexander Gaivanuk

#include <gtest/gtest.h>

#include <stdlib.h>
#include <math.h>
#include <string>

#include "include/arithmetic_parser.h"

using std::string;

TEST(ArithmeticParserTest, Can_parse_simple_expressions) {
    ArithmeticParser parser;

    string e1 = "1 + 2";
    string e2 = "x - 1";
    string e3 = "3.1 * 3";
    string e4 = "x / 2.0";
    string e5 = "x ^ 2.0";

    EXPECT_TRUE(parser.parse(e1));
    EXPECT_TRUE(parser.parse(e2));
    EXPECT_TRUE(parser.parse(e3));
    EXPECT_TRUE(parser.parse(e4));
}

TEST(ArithmeticParserTest, Can_parse_mixed_expressions) {
    ArithmeticParser parser;

    string e1 = "1 + (2 * x)";
    string e2 = "(1 - x) - (x + 21.3)";
    string e3 = "3.1/1 * 3^(1 + x)";

    EXPECT_TRUE(parser.parse(e1));
    EXPECT_TRUE(parser.parse(e2));
    EXPECT_TRUE(parser.parse(e3));
}

TEST(ArithmeticParserTest, Can_parse_expressions_with_omitted_mult) {
    ArithmeticParser parser;

    string e1 = "2x";
    string e2 = "23x + 11 / (3(2+3x))";
    string e3 = "3.1 - 3^2 * 3(1 + 2.0x)";

    EXPECT_TRUE(parser.parse(e1));
    EXPECT_TRUE(parser.parse(e2));
    EXPECT_TRUE(parser.parse(e3));
}

TEST(ArithmeticParserTest, Can_parse_expressions_with_unary_minus) {
    ArithmeticParser parser;

    string e1 = "-2x";
    string e2 = "23.1x + -11";
    string e3 = "-1 - (-2)";
    string e4 = "-(1 * -(-2x))";

    EXPECT_TRUE(parser.parse(e1));
    EXPECT_TRUE(parser.parse(e2));
    EXPECT_TRUE(parser.parse(e3));
    EXPECT_TRUE(parser.parse(e4));
}

TEST(ArithmeticParserTest, Can_parse_expressions_with_functions) {
    ArithmeticParser parser;

    string e1 = "(cos(x)^2 + sin(x)^2)";
    string e2 = "tg(1.0) / ctg(1/x)";
    string e3 = "arcsin(-arccos(x+2*arctg(2x)))";
    string e4 = "-ln(2(lg(-3x / 2)))";
    string e5 = "-abs(-x + 2)^2";

    EXPECT_TRUE(parser.parse(e1));
    EXPECT_TRUE(parser.parse(e2));
    EXPECT_TRUE(parser.parse(e3));
    EXPECT_TRUE(parser.parse(e4));
    EXPECT_TRUE(parser.parse(e5));
}

TEST(ArithmeticParserTest, Can_parse_expressions_with_whitespaces) {
    ArithmeticParser parser;

    string e = "1   \t + 2\f\r / x * cos (\t\n1.0/-x)";

    EXPECT_TRUE(parser.parse(e));
}

TEST(ArithmeticParserTest, Cant_parse_aborted_expressions) {
    ArithmeticParser parser;

    string e1 = "-2x +";
    string e2 = "x /";
    string e3 = "-1 - (-2";
    string e4 = "-1.";

    EXPECT_FALSE(parser.parse(e1));
    EXPECT_FALSE(parser.parse(e2));
    EXPECT_FALSE(parser.parse(e3));
    EXPECT_FALSE(parser.parse(e4));
}

TEST(ArithmeticParserTest, Cant_parse_wrong_parenthesis_order) {
    ArithmeticParser parser;

    string e1 = "(x)+(1/2)/((1+2)";
    string e2 = "x / 4 + (2))";

    EXPECT_FALSE(parser.parse(e1));
    EXPECT_FALSE(parser.parse(e2));
}

TEST(ArithmeticParserTest, Cant_parse_non_alphanum) {
    ArithmeticParser parser;

    string e1 = "^+1";
    string e2 = "$/x+1";

    EXPECT_NO_THROW(parser.parse(e1));
    EXPECT_NO_THROW(parser.parse(e2));
    EXPECT_FALSE(parser.parse(e1));
    EXPECT_FALSE(parser.parse(e2));
}

TEST(ArithmeticParserTest, Can_eval_expressions_without_x) {
    ArithmeticParser parser;

    string e1 = "2*(2+2)";
    string e2 = "3 / 1 + 5^3";
    string e3 = "3.43 * (1+2) + 5/3";

    double e1_exp = 8;
    double e2_exp = 128;
    double e3_exp = 3.43 * (1 + 2) + 5.0 / 3.0;

    parser.parse(e1);
    double a1 = parser.evaluate();
    parser.parse(e2);
    double a2 = parser.evaluate();
    parser.parse(e3);
    double a3 = parser.evaluate();

    EXPECT_DOUBLE_EQ(a1, e1_exp);
    EXPECT_DOUBLE_EQ(a2, e2_exp);
    EXPECT_DOUBLE_EQ(a3, e3_exp);
}

TEST(ArithmeticParserTest, Can_eval_expressions_with_x) {
    ArithmeticParser parser;

    string e1 = "x / (1 + 3.0x)";
    string e2 = "1 + x*2 / x^3";
    string e3 = "3.3 * (x - 1) / 2x / 2";

    auto e1_fn = [](double x) { return x / (1 + 3.0*x); };
    auto e2_fn = [](double x) { return 1 + x * 2 / (x*x*x); };
    auto e3_fn = [](double x) { return 3.3 * (x - 1) / (2*x) / 2; };

    double x = 0.234;

    parser.parse(e1);
    double a1 = parser.evaluate(x);
    parser.parse(e2);
    double a2 = parser.evaluate(x);
    parser.parse(e3);
    double a3 = parser.evaluate(x);

    EXPECT_DOUBLE_EQ(a1, e1_fn(x));
    EXPECT_DOUBLE_EQ(a2, e2_fn(x));
    EXPECT_DOUBLE_EQ(a3, e3_fn(x));
}

TEST(ArithmeticParserTest, Can_eval_expressions_with_functions) {
    ArithmeticParser parser;
    string e1 = "cos(x)^2 + sin(x)^2";
    string e2 = "tg(x) * ctg(x) + x / 2";
    string e3 = "sin(x) + arcsin(0.2)";
    string e4 = "arccos(0.2) * sin(x/3)";
    string e5 = "arctg(0.01) - tg(x+3)+1";
    string e6 = "lg(x*ln(2.72))";
    string e7 = "-abs(x)/x";

    auto e1_exp = 1.0;
    auto e2_fn = [](double x) { return 1 + x / 2; };
    auto e3_fn = [](double x) { return sin(x) + asin(0.2); };
    auto e4_fn = [](double x) { return acos(0.2) * sin(x / 3); };
    auto e5_fn = [](double x) { return atan(0.01) - tan(x + 3) + 1; };
    auto e6_fn = [](double x) { return log(x*log(2.72)) / log(10); };
    auto e7_fn = [](double x) { return -fabs(x) / x; };

    double x = 435.343;

    parser.parse(e1);
    double a1 = parser.evaluate(x);
    parser.parse(e2);
    double a2 = parser.evaluate(x);
    parser.parse(e3);
    double a3 = parser.evaluate(x);
    parser.parse(e4);
    double a4 = parser.evaluate(x);
    parser.parse(e5);
    double a5 = parser.evaluate(x);
    parser.parse(e6);
    double a6 = parser.evaluate(x);
    parser.parse(e7);
    double a7 = parser.evaluate(x);

    EXPECT_DOUBLE_EQ(a1, e1_exp);
    EXPECT_DOUBLE_EQ(a2, e2_fn(x));
    EXPECT_DOUBLE_EQ(a3, e3_fn(x));
    EXPECT_DOUBLE_EQ(a4, e4_fn(x));
    EXPECT_DOUBLE_EQ(a5, e5_fn(x));
    EXPECT_DOUBLE_EQ(a6, e6_fn(x));
    EXPECT_DOUBLE_EQ(a7, e7_fn(x));
}

TEST(ArithmeticParserTest, Evaluate_returns_zero_on_error) {
    ArithmeticParser parser;

    parser.parse("(");

    EXPECT_EQ(parser.evaluate(0.424), 0.0);
}
