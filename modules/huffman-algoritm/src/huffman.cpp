#include <include/huffman.h>

Node::Node() {
    left = right = NULL;
}

Node::Node(char _symbol, int _count) {
    symbol = _symbol;
    count = _count;
}

Node::Node(Node *_left, Node *_right) {
    symbol = 0;
    left = _left;
    right = _right;
    count = _left->count + _right->count;
}

bool SortNode(const Node *a, const Node *b) {
    return a->count < b->count;
}

string Huffman::Encode(string &_string, map<char, vector<bool>>* _table) {

    CheckInputEncode(_string, _table);

    input_string = _string;

    list<Node*> trees;
    CreateTree(&trees);

    Node *root = trees.front();
    vector<bool> code;
    CreateTable(root, code, *_table);

    string out = "";
    for (int i = 0; i < input_string.length(); i++) {
        for (int j = 0; j < (*_table)[input_string[i]].size(); j++) {
            out += '0' + (*_table)[input_string[i]][j];
        }
    }

    return out;
}

string Huffman::Decode(string &_s, map<char, vector<bool> > &_table) {
    CheckInputDecode(_s, _table);

    map<vector<bool>, char> reverse_table;
    map<char, vector<bool> >::iterator itr_table;
    for (itr_table = _table.begin(); itr_table != _table.end(); itr_table++)
        reverse_table[itr_table->second] = itr_table->first;

    return Decode_reverse_table(_s, reverse_table);
}

void Huffman::CheckInputEncode(string& _string, map<char, vector<bool>>* _table) {
    if (_string == "") {
        throw string("Empty line");
    }
    if (_table == nullptr) {
        throw string("Empty table");
    }
}

void Huffman::CheckInputDecode(string& _string, map<char, vector<bool>>& _table) {
    if (_string == "") {
        throw string("Empty line");
    }
    if (_table.empty()) {
        throw string("Empty table");
    }
}

void Huffman::CreateTree(list<Node*> *trees) {
    map<char, int> symbols;
    for (int i = 0; i < input_string.length(); i++)
        symbols[input_string[i]]++;

    map<char, int>::iterator itr_map;
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

void Huffman::CreateTable(Node *root, vector<bool> &code, map<char, vector<bool>> &table) {
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

string Huffman::Decode_reverse_table(string &str, map<vector<bool>, char> &table) {
    string out = "";
    vector<bool> code;
    int current_code;
    for (int i = 0; i < str.length(); i++) {
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