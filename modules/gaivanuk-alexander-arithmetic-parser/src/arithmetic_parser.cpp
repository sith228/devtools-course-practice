// Copyright 2017 Alexander Gaivanuk

#include "include/arithmetic_parser.h"

#include <math.h>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iterator>

/*
    ArithmeticParser is a recursive descent parser that
    uses the folowing formal grammar:

    EXPR  -> EXPR2{[+ | -]EXPR2}
    EXPR2 -> EXPR3{[* | /]EXPR3}
    EXPR3 -> EXPR4 | EXPR4^EXPR4
    EXPR4 -> x | NUM x | NUM(EXPR) | -F | FUNC(EXPR) | (EXPR)
    FUNC  -> cos | sin | tg | ctg | arcsin | arccos | arctg | ln | lg | abs
    NUM   -> I | R
    I     -> 0|1|2...|9|0I|1I|...|9I
    R     -> I.I
*/

using std::string;
using std::vector;
using std::stack;

vector<char> ArithmeticParser::delims = {
    '^', '+', '-', '*', '/', '(', ')'
};

vector<string> ArithmeticParser::funcnames = {
    "cos", "sin", "tg", "ctg", "arcsin", "arccos", "arctg", "ln", "lg", "abs"
};

ArithmeticParser::func_t ArithmeticParser::functions[] = {
    cos, sin, tan, [](double x) -> double { return 1.0 / tan(x); },
    asin, acos, atan, log, log10, fabs
};

bool ArithmeticParser::parse(const string &expression) {
    buffer = vector<char>();
    rpn = vector<Token>();
    buffer.reserve(80);
    rpn.reserve(50);

    string_ptr = expression.c_str();
    try {
        nextToken();
        EXPR();
        expectToken(T_END);
        return true;
    }
    catch (Token) {
        rpn.clear();
        return false;
    }
    catch (const char *) {
        rpn.clear();
        return false;
    }
}

double ArithmeticParser::evaluate(double x) const {
    stack<double> nums;
    int rpn_size = rpn.size();
    if (rpn_size == 0) return 0.0;

    for (int i = 0; i < rpn_size; i++) {
        const Token &token = rpn[i];
        token_t tt = token.type;

        if (tt == T_NUMBER) {
            nums.push(token.realValue);
        } else if (tt == T_X) {
            nums.push(x);
        } else {
            double left_operand, right_operand;

            right_operand = nums.top(); nums.pop();
            if (tt != T_NEGATE && tt != T_FUNC) {
                left_operand = nums.top(); nums.pop();
            }

            if (tt == T_PLUS)
                nums.push(left_operand + right_operand);
            else if (tt == T_MINUS)
                nums.push(left_operand - right_operand);
            else if (tt == T_MUL)
                nums.push(left_operand * right_operand);
            else if (tt == T_DIV)
                nums.push(left_operand / right_operand);
            else if (tt == T_POW)
                nums.push(pow(left_operand, right_operand));
            else if (tt == T_NEGATE)
                nums.push(-right_operand);
            else if (tt == T_FUNC)
                nums.push(functions[token.intValue](right_operand));
        }
    }

    return nums.top();
}

ArithmeticParser::Token ArithmeticParser::getToken() {
    token_state state = TS_INITIAL;
    char ch = 0;     // current char
    int number = 0;  // currently parsed number

    while (true) {
        ch = *string_ptr;
        switch (state) {
        case TS_INITIAL:
            if (isspace(ch)) {
                string_ptr++;
            } else if (tolower(ch) == 'x') {
                string_ptr++;
                return Token(T_X);
            } else if (isdigit(ch)) {
                number = ch - '0';
                string_ptr++;
                state = TS_NUMBER;
            } else if (isalpha(ch)) {
                state = TS_FUNCNAME;
            } else if (ch == 0) {
                return Token(T_END);
            } else {
                state = TS_DELIM;
            }
            break;
        case TS_NUMBER:
            while (isdigit(ch)) {
                number = number * 10 + ch - '0';
                ch = *++string_ptr;
            }

            if (ch == '.') {
                ch = *++string_ptr;
                if (!isdigit(ch)) throw string_ptr;

                buffer.clear();
                buffer.push_back('0');
                buffer.push_back('.');
                do {
                    buffer.push_back(ch);
                    ch = *++string_ptr;
                } while (isdigit(ch));

                double value = number + atof(buffer.data());
                return Token(T_NUMBER, value);
            } else {
                return Token(T_NUMBER, static_cast<double>(number));
            }
            break;
        case TS_FUNCNAME: {
            buffer.clear();
            while (isalpha(ch)) {
                buffer.push_back(ch);
                ch = *++string_ptr;
            }
            buffer.push_back('\0');
            const char *str = buffer.data();

            auto it = std::find(funcnames.begin(), funcnames.end(), str);
            if (it != funcnames.end()) {
                int index = std::distance(funcnames.begin(), it);
                return Token(T_FUNC, index);
            }

            throw str;
        }
        case TS_DELIM:
            auto it = std::find(delims.begin(), delims.end(), ch);
            if (it != delims.end()) {
                int index = std::distance(delims.begin(), it);
                string_ptr++;
                return Token((token_t)index);
            }
            throw string_ptr;
        }
    }
}

void ArithmeticParser::EXPR() {
    EXPR2();
    while (token.type == T_PLUS || token.type == T_MINUS) {
        token_t tt = token.type;
        nextToken();
        EXPR2();
        rpn.push_back(Token(tt));
    }
}

void ArithmeticParser::EXPR2() {
    EXPR3();
    while (token.type == T_MUL || token.type == T_DIV) {
        token_t tt = token.type;
        nextToken();
        EXPR3();
        rpn.push_back(Token(tt));
    }
}

void ArithmeticParser::EXPR3() {
    EXPR4();
    if (token.type == T_POW) {
        nextToken();
        EXPR4();
        rpn.push_back(Token(T_POW));
    }
}

void ArithmeticParser::EXPR4() {
    if (token.type == T_FUNC) {
        int functionIndex = token.intValue;
        nextToken();
        expectToken(T_LPAREN);
        nextToken();
        EXPR();
        expectToken(T_RPAREN);
        nextToken();
        rpn.push_back(Token(T_FUNC, functionIndex));
    } else if (token.type == T_X) {
        rpn.push_back(Token(T_X));
        nextToken();
    } else if (token.type == T_NUMBER) {
        rpn.push_back(Token(token));
        nextToken();
        if (token.type == T_X) {
            rpn.push_back(Token(T_X));
            rpn.push_back(Token(T_MUL));
            nextToken();
        } else if (token.type == T_LPAREN) {
            nextToken();
            EXPR();
            expectToken(T_RPAREN);
            nextToken();
            rpn.push_back(Token(T_MUL));
        }
    } else if (token.type == T_LPAREN) {
        nextToken();
        EXPR();
        expectToken(T_RPAREN);
        nextToken();
    } else if (token.type == T_MINUS) {
        nextToken();
        EXPR4();
        rpn.push_back(Token(T_NEGATE));
    } else {
        throw token;
    }
}
