// Copyright 2017 Bevzuk Semen

#ifndef MODULES_HUFFMAN_ALGORITM_INCLUDE_HUFFMAN_H_
#define MODULES_HUFFMAN_ALGORITM_INCLUDE_HUFFMAN_H_

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>

class Node {
 public:
    int count;
    char symbol;
    Node *left;
    Node *right;

    Node();

    Node(char _symbol, int _count);

    Node(Node *_left, Node *_right);

    bool operator == (Node const & a) const;
};

bool SortNode(const Node *a, const Node *b);

class Huffman {
 public:
    std::string Encode(const std::string &_string,
                       std::map<char, std::vector<bool> >* _table);

    std::string Decode(const std::string &_string,
                       const std::map<char, std::vector<bool> >& _table);

 private:
    std::string input_string;

    void CheckInputEncode(const std::string &_string,
                          const std::map<char, std::vector<bool> >& _table);

    void CheckInputDecode(const std::string &_string,
                          const std::map<char, std::vector<bool> >& _table);

    void CreateTree(std::list<Node*>& trees);

    void CreateTable(Node *root, std::vector<bool>& code,
                     std::map<char, std::vector<bool> >& table);

    std::string Decode_reverse_table(const std::string &str,
                                     std::map<std::vector<bool>, char>& table);
};

#endif  // MODULES_HUFFMAN_ALGORITM_INCLUDE_HUFFMAN_H_
