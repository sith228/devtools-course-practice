// Copyright 2017 Grechukhin Nikita

#ifndef MODULES_LAB2_INTEGRATION_METHODS_INCLUDE_FUNCTION_PARSER_H_
#define MODULES_LAB2_INTEGRATION_METHODS_INCLUDE_FUNCTION_PARSER_H_

#include <vector>
#include <string>

struct Expression {
    explicit Expression(std::string token);
    Expression(std::string token, Expression a);
    Expression(std::string token, Expression a, Expression b);

    std::string token;
    std::vector<Expression> args;
};

class Parser {
 public:
    explicit Parser(const char* input) : input(input) {}
    Expression parse();

 private:
    std::string parse_token();
    Expression parse_simple_expression();
    Expression parse_binary_expression(int min_priority);

    const char* input;
};

double eval(Expression e);

#endif  // MODULES_LAB2_INTEGRATION_METHODS_INCLUDE_FUNCTION_PARSER_H_
