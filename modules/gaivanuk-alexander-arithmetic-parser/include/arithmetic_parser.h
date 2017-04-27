// Copyright 2017 Alexander Gaivanuk

#ifndef MODULES_GAIVANUK_ALEXANDER_ARITHMETIC_PARSER_INCLUDE_ARITHMETIC_PARSER_H_
#define MODULES_GAIVANUK_ALEXANDER_ARITHMETIC_PARSER_INCLUDE_ARITHMETIC_PARSER_H_

#include <vector>
#include <string>

class ArithmeticParser {
 public:
    bool parse(const std::string &expression);
    bool evaluate(double x, double *result) const;
    bool evaluate(double *result) const { return evaluate(0.0, result); }

 private:
    typedef double(*Function)(double);

    static std::vector<char> delims_;
    static std::vector<std::string> funcnames_;
    static Function functions_[];

    enum TokenType {
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

    enum TokenState {
        TS_INITIAL,
        TS_NUMBER,
        TS_FUNCNAME,
        TS_DELIM
    };

    struct Token {
        TokenType type = (TokenType)0;

        union {
            int int_value;
            double real_value = 0.0;
        };

        Token() { }
        explicit Token(TokenType type)
            : type(type) { }
        Token(TokenType type, int value)
            : type(type), int_value(value) { }
        Token(TokenType type, double value)
            : type(type), real_value(value) { }
    };

    bool is_good = false;               // was expression parsed successfully
    Token token_;                       // current token
    std::vector<Token> rpn_;            // reverse polish notation
    const char *string_ptr_ = nullptr;  // pointer to string to parse
    std::vector<char> buffer_;          // temporary buffer used in getToken

    Token getToken();
    void nextToken() { token_ = getToken(); }
    void expectToken(TokenType token_type) {
        if (token_.type != token_type) throw token_;
    }

    void SUM_OPERATORS();
    void PRODUCT_OPERATORS();
    void POW_OPERATOR();
    void VALUE();
};

#endif  // MODULES_GAIVANUK_ALEXANDER_ARITHMETIC_PARSER_INCLUDE_ARITHMETIC_PARSER_H_
