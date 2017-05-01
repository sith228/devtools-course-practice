// Copyright 2017 Grechukhin Nikita

#include "include/function_parser.h"
#include <cctype>
#include <cstring>
#include <string>
#include <cmath>
#include <stdexcept>
#include <cstdlib>
#include <iomanip>

int get_priority(const std::string& token) {
    if (token == "+") return 1;
    if (token == "-") return 1;
    if (token == "*") return 2;
    if (token == "/") return 2;
    if (token == "mod") return 2;
    if (token == "**") return 3;
    return 0;
}

Expression::Expression(std::string token) : token(token) {}

Expression::Expression(std::string token, Expression a) : token(token) {
    args.push_back(a);
}

Expression::Expression(std::string token, Expression a, Expression b) :
    token(token) {
    args.push_back(a);
    args.push_back(b);
}

std::string Parser::parse_token() {
    while (std::isspace(*input))
        ++input;

    if (std::isdigit(*input)) {
        std::string number;
        while (std::isdigit(*input) || *input == '.')
            number.push_back(*input++);
        return number;
    }

    static const std::string tokens[] =
    { "+", "-", "**", "*", "/", "mod", "abs", "sin", "cos", "(", ")" };


    for (auto &token : tokens) {
        if (std::strncmp(input, token.c_str(), token.size()) == 0) {
            input += token.size();
            return token;
        }
    }

    return "";
}

Expression Parser::parse_simple_expression() {
    auto token = parse_token();

    if (token.empty())
        throw std::runtime_error("Invalid input");

    if (std::isdigit(token[0]))
        return Expression(token);

    if (token == "(") {
        auto result = parse();
        if (parse_token() != ")") throw std::runtime_error("Expected ')'");
        return result;
    }

    auto arg = parse_simple_expression();
    return Expression(token, arg);
}

Expression Parser::parse_binary_expression(int min_priority) {
    auto left_expr = parse_simple_expression();

    for (;;) {
        auto op = parse_token();
        auto priority = get_priority(op);
        if (priority <= min_priority) {
            input -= op.size();
            return left_expr;
        }

        auto right_expr = parse_binary_expression(priority);
        left_expr = Expression(op, left_expr, right_expr);
    }
}

Expression Parser::parse() {
    return parse_binary_expression(0);
}

double eval(Expression e) {
    switch (e.args.size()) {
    case 2: {
                auto a = eval(e.args[0]);
                auto b = eval(e.args[1]);
                if (e.token == "+") return a + b;
                if (e.token == "-") return a - b;
                if (e.token == "*") return a * b;
                if (e.token == "/") return a / b;
                if (e.token == "**") return pow(a, b);
                if (e.token == "mod")
                    return static_cast<int>(a) % static_cast<int>(b);
                throw std::runtime_error("Unknown binary operator");
    }

    case 1: {
                auto a = eval(e.args[0]);
                if (e.token == "+") return +a;
                if (e.token == "-") return -a;
                if (e.token == "abs") return fabs(a);
                if (e.token == "sin") return sin(a);
                if (e.token == "cos") return cos(a);
                throw std::runtime_error("Unknown unary operator");
    }

    case 0:
        return strtod(e.token.c_str(), nullptr);
    }

    throw std::runtime_error("Unknown expression type");
}
