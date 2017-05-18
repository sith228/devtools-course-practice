// Copyright 2017 Kazakov Andrew

#ifndef MODULES_REGEX_SEARCH_INCLUDE_REGEX_SEARCH_H_
#define MODULES_REGEX_SEARCH_INCLUDE_REGEX_SEARCH_H_

#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <vector>

typedef std::vector<int> RegexSearchResult;

// Basic regular expressions search.
// - Supported quanifications: *, ?, +, {n} (1<=n<=9)
// - Parentheses and quanitifications within another parenthesis are not allowed
// - \n, \r support
// - There can be empty regular expressions
// - Search is implemented according to DFA principle
class RegexSearch {
 public:
  static const int kNotFound = -1;
  static const int errorTooLongRegex = -1;
  static const int errorRegExpIncorrect = -2;
  static const int errorTooLongString = -3;

  explicit RegexSearch(const std::string = "");
  RegexSearch(const RegexSearch&);
  RegexSearch& operator=(const RegexSearch&);
  ~RegexSearch(void) {}

  void SetRegex(const std::string&);
  std::string GetRegex(void) const;

  // Returns kNotFound if there are no matches
  RegexSearchResult Find(const std::string&);

 private:
  // Token type. TOK_Q_CUSTOM is {n} quantifier
  enum TokenType {
    TOK_WORD,
    TOK_Q_ASTERISK,
    TOK_Q_QUESTION,
    TOK_Q_PLUS,
    TOK_Q_CUSTOM,
    TOK_PAR_OPEN,
    TOK_PAR_CLOSE,
    _ABSENT
  };

  struct Lexeme {
    std::string str;
    int min, max;
  };

  static const int kMaxStringLength = 5000;
  static const int kMaxRegexLength = 150;
  static const int kMaxTokenSize = 3;
  static const int kInfinityRepeats = -1;

  std::vector<Lexeme> regex_;
  std::string regex_str_;

  RegexSearchResult FindFirst(const std::string&, const size_t pos = 0);

  static void MakeStringLonger(std::string& out_str, const std::string& str);
  static void Parse(const std::string&, std::vector<Lexeme>&);
};

#endif
