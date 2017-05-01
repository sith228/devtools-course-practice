#include <iostream>

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
};

bool SortNode(const Node *a, const Node *b);