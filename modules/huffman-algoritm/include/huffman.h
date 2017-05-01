// Copyright 2017 Bevzuk Semen

#include <iostream>
#include <vector>
#include <list>
#include <map>

using namespace std;

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
    string Encode(string &_string, map<char, vector<bool> >* _table);

    string Decode(string &_string, map<char, vector<bool> > &_table);

private:
    string input_string;

    void CheckInputEncode(string &_string, map<char, vector<bool> >* _table);

    void CheckInputDecode(string &_string, map<char, vector<bool> > &_table);

    void CreateTree(list<Node*> *trees);

    void CreateTable(Node *root, vector<bool> &code, map<char, vector<bool>> &table);

    string Decode_reverse_table(string &str, map<vector<bool>, char> &table);
};