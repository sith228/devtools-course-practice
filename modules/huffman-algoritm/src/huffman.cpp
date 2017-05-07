// Copyright 2017 Bevzuk Semen

#include <include/huffman.h>
#include <vector>
#include <string>
#include <list>
#include <map>

Node::Node() {
    left = right = NULL;
}

Node::Node(char _symbol, int _count) {
    symbol = _symbol;
    count = _count;
    left = right = NULL;
}

Node::Node(Node* _left, Node* _right) {
    symbol = 0;
    left = _left;
    right = _right;
    count = _left->count + _right->count;
}

bool Node::operator == (Node const& _a) const {
    if (_a.count != this->count)
        return false;
    if (_a.symbol != this->symbol)
        return false;
    return true;
}

bool SortNode(const Node* _a, const Node* _b) {
    return _a->count < _b->count;
}

std::string Huffman::Encode(const std::string& _string,
                            std::map<char, std::vector<bool>>* _table) {
    CheckInputEncode(_string, *_table);

    input_string_ = _string;

    std::list<Node*> trees;
    CreateTree(&trees);

    Node *root = trees.front();
    std::vector<bool> code;
    CreateTable(root, &code, _table);

    std::string out = "";
    for (unsigned int i = 0; i < input_string_.length(); i++) {
        for (unsigned int j = 0; j < (*_table)[input_string_[i]].size(); j++) {
            out += '0' + (*_table)[input_string_[i]][j];
        }
    }

    return out;
}

std::string Huffman::Decode(const std::string& _s,
                            const std::map<char, std::vector<bool> > &_table) {
    CheckInputDecode(_s, _table);

    std::map<char, std::vector<bool> > temp_table = _table;
    std::map<std::vector<bool>, char> reverse_table;
    std::map<char, std::vector<bool> >::iterator itr_table;
    for (itr_table = temp_table.begin(); itr_table != temp_table.end();
         ++itr_table)
        reverse_table[itr_table->second] = itr_table->first;

    return DecodeReverseTable(_s, &reverse_table);
}

void Huffman::CheckInputEncode(const std::string& _string,
                               const std::map<char,
                               std::vector<bool>>& _table) {
    if (_string == "") {
        throw std::string("Empty line");
    }
}

void Huffman::CheckInputDecode(const std::string& _string, const std::map<char,
                               std::vector<bool>>& _table) {
    if (_string == "") {
        throw std::string("Empty line");
    }
    if (_table.empty()) {
        throw std::string("Empty table");
    }
}

void Huffman::CreateTree(std::list<Node*>* _trees) {
    std::map<char, int> symbols;
    for (unsigned int i = 0; i < input_string_.length(); i++)
        symbols[input_string_[i]]++;

    std::map<char, int>::iterator itr_map;
    for (itr_map = symbols.begin(); itr_map != symbols.end(); ++itr_map) {
        Node *p = new Node(itr_map->first, itr_map->second);
        _trees->push_back(p);
    }

    while (_trees->size() != 1) {
        _trees->sort(SortNode);

        Node *l = _trees->front();
        _trees->pop_front();
        Node *r = _trees->front();
        _trees->pop_front();

        Node *parent = new Node(l, r);
        _trees->push_back(parent);
    }
}

void Huffman::CreateTable(Node* _root, std::vector<bool>* _code,
                          std::map<char, std::vector<bool> >* _table) {
    if (_root->left) {
        _code->push_back(0);
        CreateTable(_root->left, _code, _table);
    }

    if (_root->right) {
        _code->push_back(1);
        CreateTable(_root->right, _code, _table);
    }

    if (_root->symbol)
        (*_table)[_root->symbol] = *_code;

    if (_code->size())
        _code->pop_back();
}

std::string Huffman::DecodeReverseTable(
    const std::string& _str,
    std::map<std::vector<bool>, char>* _table) {
    std::string out = "";
    std::vector<bool> code;
    int current_code;
    for (unsigned int i = 0; i < _str.length(); i++) {
        if (_str[i] == '0')
            current_code = 0;
        else
            current_code = 1;
        code.push_back(current_code);
        if ((*_table)[code]) {
            out += (*_table)[code];
            code.clear();
        }
    }
    return out;
}
