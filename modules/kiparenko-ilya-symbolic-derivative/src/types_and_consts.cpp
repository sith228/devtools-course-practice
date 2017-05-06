//  Copyright 2017 Kiparenko Ilya

#include "include/types_and_consts.h"

using namespace Types;

Node* Types::cr_Symbol_node(int index, Node* left, Node* right) {
  Node* t = new Node();
  t->type = SYMBOL;
  t->index = index;
  t->left = left;
  t->right = right;
  return t;
}

Node* Types::cr_Number_node(double real_value, Node* left, Node* right) {
  Node* t = new Node();
  t->type = NUMBER;
  t->real_value = real_value;
  t->left = left;
  t->right = right;
  return t;
}

Node* Types::cr_Op_node(Op op_type, Node* left, Node* right) {
  Node* t = new Node();
  t->type = FUNCTION;
  t->op_type = op_type;
  t->left = left;
  t->right = right;
  return t;
}

Node* Types::cr_Empty_node(Node* left, Node* right) {
  Node* t = new Node();
  t->type = EMPTY;
  t->left = left;
  t->right = right;
  return t;
}

