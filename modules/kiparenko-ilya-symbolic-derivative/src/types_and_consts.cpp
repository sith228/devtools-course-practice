//  Copyright 2017 Kiparenko Ilya

#include "include/types_and_consts.h"
#include <iostream>
using namespace std;

Node* CrSymbolNode(int index, Node* left, Node* right) {
  Node* t = new Node;
  cout << "create SYMBOL (" << t << ")\n";
  t->type = SYMBOL;
  t->index = index;
  t->left = left;
  t->right = right;
  return t;
}

Node* CrNumberNode(double real_value, Node* left, Node* right) {
  Node* t = new Node;
  cout << "create NUMBER (" << t << " : " << real_value << ")\n";
  t->type = NUMBER;
  t->real_value = real_value;
  t->left = left;
  t->right = right;
  return t;
}

Node* CrOpNode(Op op_type, Node* left, Node* right) {
  Node* t = new Node;
  cout << "create OP (" << t << " : " << func_names.at(op_type) <<  ")\n";
  t->type = FUNCTION;
  t->op_type = op_type;
  t->left = left;
  t->right = right;
  return t;
}

Node* CrEmptyNode(Node* left, Node* right) {
  Node* t = new Node;
  cout << "create EMPTY (" << t << ")\n";
  t->type = NUMBER;
  t->left = left;
  t->right = right;
  return t;
}

