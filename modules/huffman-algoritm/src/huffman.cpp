#include "include/huffman.h"

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
    count = left->count + right->count;
}

bool SortNode(const Node *a, const Node *b) {
    return (a->count < b->count);
}