// Copyright 2017 Kazakov Andrew

#include "include/regex_search.h"

//
// Constructors/operator=
//

RegexSearch::RegexSearch(const std::string regex) {
  SetRegex(regex);
}

RegexSearch::RegexSearch(const RegexSearch& regex) {
  regex_ = regex.regex_;
  regex_str_ = regex.regex_str_;
}

RegexSearch& RegexSearch::operator=(const RegexSearch& regex) {
  if (&regex != this) {
    regex_ = regex.regex_;
    regex_str_ = regex.regex_str_;
  }

  return *this;
}

//
// Set & get
//

void RegexSearch::SetRegex(const std::string& regex) {
  if (regex.length() > kMaxRegexLength)
    throw RegexSearch::errorTooLongRegex;

  std::vector<Lexeme> lexemes;

  try {
    RegexSearch::Parse(regex, lexemes);
  } catch (const int e) {
    throw RegexSearch::errorRegExpIncorrect;
  }

  regex_ = lexemes;
  regex_str_ = regex;
}

std::string RegexSearch::GetRegex() const {
  return regex_str_;
}

//
// Find
//

RegexSearchResult RegexSearch::Find(const std::string& str) {
  if (str.length() > kMaxStringLength)
    throw RegexSearch::errorTooLongString;

  RegexSearchResult res, temp(2);
  size_t pos = 0;

  // If regex is empty, the whole string matches
  if (regex_.size() == 0) {
    res.push_back(0);
    res.push_back(str.size());
    return res;
  }

  do {
    temp = FindFirst(str, pos);
    res.push_back(temp[0]);
    res.push_back(temp[1]);
    pos = temp[0] + temp[1];
  } while (temp[0] != RegexSearch::kNotFound);

  // At least there is one match, last 2 elements is useless
  if (res.size() > 2) {
    res.pop_back();
    res.pop_back();
  }

  return res;
}

//
// Private methods
//

RegexSearchResult RegexSearch::FindFirst(const std::string& str, const size_t pos) {
  RegexSearchResult res(2);

  Lexeme lexeme;
  std::string l_str, temp;

  // if true, we go to the next part of the regex
  bool curr_lexeme_ended = false;

  int match_start = RegexSearch::kNotFound, match_end = 0;

  for (size_t i = pos, j = 0; i < str.size() && j < regex_.size(); ++i) {
    lexeme = regex_[j];
    l_str = lexeme.str;

    // There are only 3 options: min=0 max=1, min=0 max=<infinity>, min=max=<const>
    if (lexeme.min == 0) {
      if (l_str.compare(str.substr(i, l_str.size())) == 0) {
        if (match_start == RegexSearch::kNotFound)
          match_start = i;
        match_end = (i += (l_str.size()));

        if (lexeme.max = RegexSearch::kInfinityRepeats)
          while (l_str.compare(str.substr(i, l_str.size())) == 0)
            match_end = (i += (l_str.size()));

        --i;
        curr_lexeme_ended = true;
      }
    } else {
      temp = "";
      for (int j = 0; j < lexeme.min; ++j)
        temp += l_str;

      if (temp.compare(str.substr(i, temp.size())) == 0) {
        if (match_start == RegexSearch::kNotFound)
          match_start = i;
        match_end = (i += (temp.size()));
        --i;
        curr_lexeme_ended = true;
      } else if (match_start != RegexSearch::kNotFound) {
        match_start = RegexSearch::kNotFound;
      }
    }

    if (curr_lexeme_ended) {
      curr_lexeme_ended = false;
      j++;
    }

  }  // for

  res[0] = match_start;
  res[1] = match_end - match_start;

  return res;
}

//
// Static methods
//

void RegexSearch::MakeStringLonger(std::string& out_str, const std::string& str) {
  out_str = str;
  for (int i = 0; i < (kMaxTokenSize - 1); ++i) {
    out_str.push_back(0);
  }
}

void RegexSearch::Parse(const std::string& regex, std::vector<Lexeme>& lexemes) {
  char char_next, temp;
  size_t offset = 0;  // how many chars to ignore after the iteration
  bool par_open = false;

  // For quantifiers
  TokenType curr_tok = TokenType::_ABSENT, prev_tok = TokenType::_ABSENT;
  int q_min_repeats, q_max_repeats;

  // Regex substrings
  std::string literals_block;  // сurrent continuous sequence of literals
  size_t lb_size = 0;  // literals_block current size

  // For looking ahead
  std::string regex_long;
  MakeStringLonger(regex_long, regex);

  for (auto i = 0; i < regex.size(); offset = 0, ++i) {
    char_next = regex_long[i + 1];
    prev_tok = curr_tok;

    switch (regex[i]) {
      case '\\':
        if (char_next == 0) continue;
        curr_tok = TokenType::TOK_WORD;
        offset = 1;

        temp = char_next;
        switch (char_next) {
          case 'n': temp = '\n'; break;
          case 'r': temp = '\r'; break;
        }

        literals_block += temp;

        break;

      case '{':
        if (par_open || lb_size == 0 || char_next == 0)
          throw 1;
        curr_tok = TokenType::TOK_Q_CUSTOM;
        offset = 2;

        if (char_next >= '1' && char_next <= '9') {
          if (regex_long[i + 2] != '}') throw 1;
          q_min_repeats = char_next - '0';

          if (prev_tok == TokenType::TOK_PAR_CLOSE) {
            lexemes.push_back({ literals_block, 1, 1 });
          } else if (prev_tok == TokenType::TOK_WORD) {
            if (lb_size > 1)
              lexemes.push_back({ literals_block.substr(0, lb_size - 1), 1, 1 });
            lexemes.push_back({ literals_block.substr(lb_size - 1), q_min_repeats, q_min_repeats});
          }

          literals_block = "";
        } else if (char_next == '}') {
          offset = 1;
        } else {
          throw 1;
        }

        break;

      case '(':
        if (par_open) throw 1;
        par_open = true;
        curr_tok = TokenType::TOK_PAR_OPEN;

        if (lb_size > 0) {
          lexemes.push_back({ literals_block, 1, 1 });
          literals_block = "";
        }

        break;

      case ')':
        if (!par_open) throw 1;
        par_open = false;
        curr_tok = TokenType::TOK_PAR_CLOSE;

        break;

      case '*':
        if (par_open || lb_size == 0) throw 1;
        curr_tok = TokenType::TOK_Q_ASTERISK;

        q_min_repeats = 0;
        q_max_repeats = kInfinityRepeats;

        break;

      case '+':
        if (par_open || lb_size == 0) throw 1;
        curr_tok = TokenType::TOK_Q_PLUS;

        if (prev_tok == TokenType::TOK_PAR_CLOSE) {
          lexemes.push_back({ literals_block, 1, 1 });
          lexemes.push_back({ literals_block, 0, kInfinityRepeats });
        } else if (prev_tok == TokenType::TOK_WORD) {
          if (lb_size > 1)
            lexemes.push_back({ literals_block.substr(0, lb_size - 1), 1, 1 });
          lexemes.push_back({ literals_block.substr(lb_size - 1), 1, 1 });
          lexemes.push_back({ literals_block.substr(lb_size - 1), 0, kInfinityRepeats });
        }
        literals_block = "";

        break;

      case '?':
        if (par_open || lb_size == 0) throw 1;
        curr_tok = TokenType::TOK_Q_QUESTION;

        q_min_repeats = 0;
        q_max_repeats = 1;

        break;

      default:
        curr_tok = TokenType::TOK_WORD;

        literals_block += regex[i];
        break;
    }

    // Processing quantifiers
    if (curr_tok == TokenType::TOK_Q_ASTERISK || curr_tok == TokenType::TOK_Q_QUESTION) {
      if (lb_size == 0)
        throw 1;
      if (prev_tok == TokenType::TOK_PAR_CLOSE) {
        lexemes.push_back({ literals_block, 1, 1 });
      } else if (prev_tok == TokenType::TOK_WORD) {
        if (lb_size > 1)
          lexemes.push_back({ literals_block.substr(0, lb_size - 1), 1, 1 });
        lexemes.push_back({ literals_block.substr(lb_size - 1), q_min_repeats, q_max_repeats });
      }
      literals_block = "";
    }

    i += offset;
    lb_size = literals_block.size();
  }

  if (lb_size > 0) {
    lexemes.push_back({ literals_block, 1, 1 });
  }
}
