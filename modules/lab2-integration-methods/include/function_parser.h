// Copyright 2017 Grechukhin Nikita

#ifndef MODULES_LAB2_INTEGRATION_METHODS_INCLUDE_FUNCTION_PARSER_H_
#define MODULES_LAB2_INTEGRATION_METHODS_INCLUDE_FUNCTION_PARSER_H_

#include <vector>
#include <string>

struct Expression {
    explicit Expression(const std::string &token);
    Expression(const std::string &token, const Expression &a);
    Expression(const std::string &token, const Expression &a, const Expression &b);

    std::string token;
    std::vector<Expression> args;
    double eval();
};

class Parser {
 public:
     Expression parse(const char *input);

 private:
     Expression parse2();
     std::string parse_token();
     Expression parse_simple_expression();
     Expression parse_binary_expression(int min_priority);

     const char* input;
};

#endif  // MODULES_LAB2_INTEGRATION_METHODS_INCLUDE_FUNCTION_PARSER_H_
