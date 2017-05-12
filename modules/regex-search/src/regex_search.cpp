// Copyright 2017 Kazakov Andrew

#include "include/regex_search.h"

RegexSearch::RegexSearch(const std::string regex) {
    regex_ = std::regex(regex);
}

RegexSearch::RegexSearch(const RegexSearch& regex) {
    regex_ = regex.regex_;
}

RegexSearch& RegexSearch::operator=(const RegexSearch& regex) {
    regex_ = regex.regex_;

    return *this;
}

void RegexSearch::SetRegex(const std::string regex) {
    regex_ = regex;
}

std::regex RegexSearch::GetRegex() const {
    return regex_;
}

RegexSearchResult RegexSearch::Find(std::string str) {
    std::smatch matches;
    RegexSearchResult res;

    while (std::regex_search(str, matches, regex_)) {
        res.push_back(matches.length());
        res.push_back(matches.position());
        str = matches.suffix().str();
    }

    return res;
}

RegexSearchResult RegexSearch::FindInFile(std::string filename) {
    std::smatch matches;
    RegexSearchResult res;
    std::string str;
    std::ifstream file;

    file.open(filename);
    std::getline(file, str);
    file.close();

    while (std::regex_search(str, matches, regex_)) {
        res.push_back(matches.length());
        res.push_back(matches.position());
        str = matches.suffix().str();
    }

    return res;
}
