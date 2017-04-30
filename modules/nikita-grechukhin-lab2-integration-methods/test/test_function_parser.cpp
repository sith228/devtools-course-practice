// Copyright 2017 Grechukhin Nikita

#include <gtest/gtest.h>
#include "include/function_parser.h"

TEST(EXPRESSION, can_create_number_expression) {
    std::string token = "1";

    Expression expression(token);

    EXPECT_EQ(token, expression.token);
}
