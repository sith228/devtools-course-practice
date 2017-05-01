// Copyright 2017 Bevzuk Semen

#include <include/huffman.h>
#include <map>

Node::Node() {
    left = right = NULL;
}

Node::Node(char _symbol, int _count) {
    symbol = _symbol;
    count = _count;
    left = right = NULL;
}

Node::Node(Node *_left, Node *_right) {
    symbol = 0;
    left = _left;
    right = _right;
    count = _left->count + _right->count;
}

bool Node::operator == (Node const& a) const {
    if (a.count != this->count)
        return false;
    if (a.symbol != this->symbol)
        return false;
    if (a.left != this->left)
        return false;
    if (a.right != this->right)
        return false;
    return true;
}

bool SortNode(const Node *a, const Node *b) {
    return a->count < b->count;
}

std::string Huffman::Encode(const std::string &_string, std::map<char, std::vector<bool>>* _table) {

    CheckInputEncode(_string, _table);

    input_string = _string;

    std::list<Node*> trees;
    CreateTree(&trees);

    Node *root = trees.front();
    std::vector<bool> code;
    CreateTable(root, code, *_table);

    std::string out = "";
    for (unsigned int i = 0; i < input_string.length(); i++) {
        for (unsigned int j = 0; j < (*_table)[input_string[i]].size(); j++) {
            out += '0' + (*_table)[input_string[i]][j];
        }
    }

    return out;
}

std::string Huffman::Decode(const std::string &_s, const std::map<char, std::vector<bool> > &_table) {
    CheckInputDecode(_s, _table);

    std::map<char, std::vector<bool> > temp_table = _table;
    std::map<std::vector<bool>, char> reverse_table;
    std::map<char, std::vector<bool> >::iterator itr_table;
    for (itr_table = temp_table.begin(); itr_table != temp_table.end(); itr_table++)
        reverse_table[itr_table->second] = itr_table->first;

    return Decode_reverse_table(_s, reverse_table);
}

void Huffman::CheckInputEncode(const std::string& _string, const std::map<char, std::vector<bool>>* _table) {
    if (_string == "") {
        throw std::string("Empty line");
    }
    if (_table == nullptr) {
        throw std::string("Empty table");
    }
}

void Huffman::CheckInputDecode(const std::string& _string, const std::map<char, std::vector<bool>>& _table) {
    if (_string == "") {
        throw std::string("Empty line");
    }
    if (_table.empty()) {
        throw std::string("Empty table");
    }
}

void Huffman::CreateTree(std::list<Node*> *trees) {
    std::map<char, int> symbols;
    for (unsigned int i = 0; i < input_string.length(); i++)
        symbols[input_string[i]]++;

    std::map<char, int>::iterator itr_map;
    for (itr_map = symbols.begin(); itr_map != symbols.end(); itr_map++) {
        Node *p = new Node(itr_map->first, itr_map->second); // first - char, second - count
        trees->push_back(p);
    }

    while (trees->size() != 1) {
        trees->sort(SortNode);

        Node *l = trees->front();
        trees->pop_front();
        Node *r = trees->front();
        trees->pop_front();

        Node *parent = new Node(l, r);
        trees->push_back(parent);
    }
}

void Huffman::CreateTable(Node *root, std::vector<bool> &code, std::map<char, std::vector<bool>> &table) {
    if (root->left) {
        code.push_back(0); // left - 0
        CreateTable(root->left, code, table);
    }

    if (root->right) {
        code.push_back(1); // right - 1
        CreateTable(root->right, code, table);
    }

    if (root->symbol)
        table[root->symbol] = code;

    if (code.size())
        code.pop_back();
}

std::string Huffman::Decode_reverse_table(const std::string &str, std::map<std::vector<bool>, char> &table) {
    std::string out = "";
    std::vector<bool> code;
    int current_code;
    for (unsigned int i = 0; i < str.length(); i++) {
        if (str[i] == '0')
            current_code = 0;
        else
            current_code = 1;
        code.push_back(current_code);
        if (table[code]) {
            out += table[code];
            code.clear();
        }
    }

    return out;
}