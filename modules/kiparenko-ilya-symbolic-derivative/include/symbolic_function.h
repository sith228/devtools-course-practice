#ifndef SYMBOLIC_FUNCTION_H
#define SYMBOLIC_FUNCTION_H

#include <string>
#include <vector>
#include <unordered_map>

#include "types_and_consts.h"

using namespace std;

using namespace Types;


class symbolic_function {
public:
  symbolic_function(string s);
  string to_string();
  symbolic_function();
  symbolic_function& derivative(string variable);
  symbolic_function& operator=(symbolic_function& sym);
  ~symbolic_function();

private:
  Node* root;
  vector<string> symbols;



  Node* parse(string s);
  Node* to_postfix_form(Node* root);
  Node* postfix_to_AST(Node* root);
  Node* evaluate(Node* root);
  Node* derivative(Node* root, string);
  void print_list(Node* root);
  void print_node(Node* root);
  void del_tree(Node* root);
  Node* copy_tree(Node* root);
  string print_tree(Node* root);
};

#endif // SYMBOLIC_FUNCTION_H
