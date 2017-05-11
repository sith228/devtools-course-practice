// Copyright 2017 Kazakov Andrew

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>

typedef std::vector<unsigned int> RegexSearchResult;

class RegexSearch {
public:
    RegexSearch(const std::string);
    RegexSearch(const RegexSearch&);
    RegexSearch& operator=(const RegexSearch&);
    ~RegexSearch(void);

    void SetRegex(const std::string);
    std::regex GetRegex(void) const;

    RegexSearchResult Find(std::string str);
    RegexSearchResult FindInFile(std::string filename);

protected:
    std::regex regex_;
};
