// Copyright 2017 Grechukhin Nikita

#ifndef MODULES_NIKITA_GRECHUKHIN_LAB2_INTEGRATION_METHODS_INCLUDE_FUNCTION_PARSER_H_
#define MODULES_NIKITA_GRECHUKHIN_LAB2_INTEGRATION_METHODS_INCLUDE_FUNCTION_PARSER_H_

#include <vector>
#include <string>

struct Expression {
    Expression(std::string token);
    Expression(std::string token, Expression a);
    Expression(std::string token, Expression a, Expression b);

    std::string token; // Операция или число
    std::vector<Expression> args; // Выражения - аргументы операции
};

class Parser {
public:
    explicit Parser(const char* input) : input(input) {} // Конструктор, принимает строку с выражением
    Expression parse();

private:
    std::string parse_token(); // Парсит один токен
    Expression parse_simple_expression();
    Expression parse_binary_expression(int min_priority);

    const char* input; // Кусок строки, который еще не распарсили
};

double eval(Expression e);

#endif  // MODULES_NIKITA_GRECHUKHIN_LAB2_INTEGRATION_METHODS_INCLUDE_FUNCTION_PARSER_H_
