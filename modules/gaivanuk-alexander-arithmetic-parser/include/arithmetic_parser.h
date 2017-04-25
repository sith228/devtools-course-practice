// Copyright 2017 Alexander Gaivanuk

#ifndef MODULES_GAIVANUK_ALEXANDER_ARITHMETIC_PARSER_INCLUDE_ARITHMETIC_PARSER_H_
#define MODULES_GAIVANUK_ALEXANDER_ARITHMETIC_PARSER_INCLUDE_ARITHMETIC_PARSER_H_

#include <vector>
#include <string>

class ArithmeticParser {
 public:
    bool parse(const std::string &expression);
    double evaluate(double x = 0.0) const;
 private:
    typedef double(*func_t)(double);

    static char delims[];
    static const char *funcnames[];
    static func_t functions[];

    enum token_t {
        T_POW,
        T_PLUS,
        T_MINUS,
        T_MUL,
        T_DIV,
        T_LPAREN,
        T_RPAREN,
        T_NEGATE,
        T_X,
        T_FUNC,
        T_NUMBER,
        T_END
    };

    enum token_state {
        TS_INITIAL,
        TS_NUMBER,
        TS_FUNCNAME,
        TS_DELIM
    };

    struct Token {
        token_t type;

        union {
            int intValue;
            double realValue;
        };

        Token(token_t type, int value)
            : type(type), intValue(value) { }
        Token(token_t type, double value)
            : type(type), realValue(value) { }
        explicit Token(token_t type = token_t(0))
            : type(type) { }
    };

    const char *data;
    Token token;
    std::vector<char> buf;
    std::vector<Token> rpn;

    Token getToken();
    void nextToken() { token = getToken(); }
    void expectToken(token_t tt) {
        if (token.type != tt) throw token;
    }

    void EXPR();
    void EXPR2();
    void EXPR3();
    void EXPR4();
};

#endif  // MODULES_GAIVANUK_ALEXANDER_ARITHMETIC_PARSER_INCLUDE_ARITHMETIC_PARSER_H_
