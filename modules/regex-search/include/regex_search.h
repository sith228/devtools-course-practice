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
    RegexSearch();
    RegexSearch(const std::string);
    RegexSearch(const RegexSearch&);
    RegexSearch& operator=(const RegexSearch&);

    void SetRegex(const std::string);
    std::string GetRegex(void) const;

    RegexSearchResult Find(std::string str);
    RegexSearchResult FindInFile(std::string filename);

protected:
    std::string regex_;
};
