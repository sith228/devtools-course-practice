// Copyright 2017 Kiparenko Ilya

#include "include/symbolic_function.h"
#include <cctype>
#include <iostream>
#include <stack>
#include <string>
#include <utility>

using std::string;
using std::cout;
using std::endl;
using std::stod;
using std::to_string;

using std::stack;

string symbolic_function::print_tree(Node* root) {
  if (root != 0) {
    switch (root->type) {
      case NUMBER:
        return std::to_string(root->real_value);
        break;
      case SYMBOL:
        return symbols[root->index];
        break;
      case FUNCTION:
        if (nargs.at(root->op_type) == 2)
          return "(" +
                  print_tree(root->left) +
                  func_names.at(root->op_type) +
                  print_tree(root->right) +
                 ")";
        else
          return func_names.at(root->op_type) +
                "(" + print_tree(root->right) + ")";
        break;
    }
  } else {
    return "(0)";
  }
}

symbolic_function::symbolic_function(string s) {
  root = parse(s);
  root = to_postfix_form(root);
  root = postfix_to_AST(root);
}

symbolic_function::~symbolic_function() {
  del_tree(root);
}

symbolic_function::symbolic_function() {
}

symbolic_function& symbolic_function::operator=(const symbolic_function& sym) {
  root = copy_tree(sym.root);
  symbols = sym.symbols;
  return (*this);
}

string symbolic_function::to_string() {
  return print_tree(root);
}

symbolic_function symbolic_function::derivative(string variable) {
  symbolic_function sym(print_tree(derivative(root, variable)));
  return sym;
}

Node* symbolic_function::parse(string s) {
  Node* out = cr_Empty_node();
  Node* out_t = out;

  char buf[20];
  int buf_pos = 0;
  int token_type = -1;
  int token_state = -1;
  int i = 0;
  string delimiters("+-*/^()");

  while (i < s.size() || (i == s.size() && token_state == 0)) {
    char ch = s[i];
    if (isspace(ch)) {
      i++;
    } else {
      if (token_state == -1) {
        if (isalpha(ch)) {
          token_type = 2;
        } else {
          if (isdigit(ch) || ch == '.') {
            token_type = 1;
          } else {
            size_t index = delimiters.find(ch);
            if (index != string::npos) {
              out_t->left = cr_Op_node(functions.at(string(1, ch)));
              out_t = out_t->left;
              token_state = -1;
              i++;
              continue;
            } else {
              throw string("Unknown token");
            }
          }
        }
        buf[buf_pos++] = ch;
        token_state = 0;
        i++;
      } else {
        if (token_type == 1) {
          while (i < s.size() && isdigit(ch) || ch == '.') {
            buf[buf_pos++] = ch;
            i++;
            ch = s[i];
          }
          buf[buf_pos] = 0;
          out_t->left = cr_Number_node(stod(string(buf)));
          out_t = out_t->left;
          buf_pos = 0;
          token_state = -1;
        } else {
          while (i < s.size() && isalnum(ch)) {
            buf[buf_pos++] = ch;
            i++;
            ch = s[i];
          }
          buf[buf_pos] = 0;
          Node* new_node;
          string s_buf = string(buf);
          try {
            new_node = cr_Op_node(functions.at(s_buf));
          } catch (std::out_of_range& e) {
            new_node = cr_Symbol_node(symbols.size());
            symbols.push_back(s_buf);
          }
          out_t->left = new_node;
          out_t = out_t->left;
          buf_pos = 0;
          token_state = -1;
        }
      }
    }
  }

  out_t = out->left;
  delete out;
  return out_t;
}

Node* symbolic_function::to_postfix_form(Node* root) {
  Node* out = cr_Empty_node();
  Node* out_t = out;
  stack<Node*> st;
  Node* t = root;
  while (t != 0) {
    if (t->type == FUNCTION) {
      switch (t->op_type) {
        case L_BRACE:
          st.push(t);
          break;
        case R_BRACE: {
          Node* top = st.top();
          st.pop();
          while (!st.empty() && top->op_type != L_BRACE) {
            out_t->left = top;
            out_t = out_t->left;

            top = st.top();
            st.pop();
          }
          if (top->op_type != L_BRACE)
            throw string("wrong braces");
          break;
        }
        default: {
          int prec = precendence.at(t->op_type);
          while (!st.empty() && precendence.at(st.top()->op_type) >= prec) {
            out_t->left = st.top();
            st.pop();
            out_t = out_t->left;
          }
          st.push(t);
          break;
        }
      }
    } else {  // Symbol or Number
      out_t->left = t;
      out_t = out_t->left;
    }

    t = t->left;
  }

  while (!st.empty()) {
    out_t->left = st.top();
    st.pop();
    out_t = out_t->left;
  }
  out_t->left = 0;
  out_t = out->left;
  delete out;
  return out_t;
}

Node* my_pop(stack<Node*>* st) {
  if (st->empty()) {
    throw std::out_of_range("stack underlow");
  } else {
    Node* t = st->top(); st->pop();
    return t;
  }
}

Node* symbolic_function::postfix_to_AST(Node* root) {
  stack<Node*> st;
  Node* out;
  Node* t = root;
  while (t != 0) {
    if (t->type == FUNCTION) {
      Node* new_token = t;
      t = t->left;
      new_token->right = my_pop(&st);
      if (nargs.at(new_token->op_type) > 1)
        new_token->left = my_pop(&st);
      else
        new_token->left = 0;
      st.push(new_token);

    } else {
      Node* new_token = t;
      t = t->left;
      new_token->left = 0;
      st.push(new_token);
    }
  }
  out = my_pop(&st);
  if (!st.empty())
    throw string("syntax error");
  return out;
}

void symbolic_function::del_tree(Node* root) {
  stack<Node*> st;
  st.push(root);
  while (!st.empty()) {
    root = st.top(); st.pop();
    if (root->left != 0)
      st.push(root->left);
    if (root->right != 0)
      st.push(root->right);
    delete root;
  }
}

Node* symbolic_function::copy_tree(Node* root) {
  if (root != 0) {
    Node* out = new Node();
    *out = *root;
    out->left  = copy_tree(root->left);
    out->right = copy_tree(root->right);
    return out;
  } else {
    return 0;
  }
}


Node* symbolic_function::derivative(Node* root, string variable) {
  switch (root->type) {
    case NUMBER:
      return 0;
      break;
    case SYMBOL:
      if (symbols[root->index] == variable)
        return cr_Number_node(1.0);
      else
        return 0;
      break;
    case FUNCTION: {
      Node* r_der = derivative(root->right, variable);
      Node* l_der = (root->left == 0) ? 0 : derivative(root->left, variable);
      int flag = (l_der != 0)*2 + (r_der != 0);
      switch (root->op_type) {
        case SUB:
        case ADD: {  // a +- b
          switch (flag) {
            case 0:  // a' = b' = 0
              return 0;
              break;
            case 1:  // a' = 0
              if (root->op_type == SUB)
                return cr_Op_node(MUL,
                         cr_Number_node(-1.0),
                         r_der);                // -b'
              else
                return r_der;
              break;
            case 2:  // b' = 0
              return l_der;
              break;
            case 3:  // a' != 0 && b' != 0
              return cr_Op_node(root->op_type, l_der, r_der);
              break;
        }
      }
      case DIV:
      case POW:
      case MUL: {
        if (flag > 0) {
          Node* temp_l = copy_tree(root->left);
          Node* temp_r = copy_tree(root->right);
          switch (root->op_type) {
            case DIV:  // a/b
              switch (flag) {
                case 3:  // a' != 0 && b' != 0
                  return
                    cr_Op_node(DIV,
                      cr_Op_node(POW,
                        temp_r,
                        cr_Number_node(2.0))  // b^2
                      ,  // ),
                      cr_Op_node(SUB,
                        cr_Op_node(MUL, l_der, temp_r),
                        cr_Op_node(MUL, temp_l, r_der)));    // a'*b - a*b'
                      // )
                    // );
                  break;
                case 2:  // b' = 0
                  // del_tree(temp_l)
                  return cr_Op_node(DIV,
                           l_der,
                           temp_r);  // a'/b
                         // );
                  break;
                case 1:  // a' = 0
                  return
                    cr_Op_node(DIV,
                      cr_Op_node(POW,
                        temp_r,
                        cr_Number_node(2.0))     // b^2
                      ,  // )
                      cr_Op_node(MUL,
                        cr_Number_node(-1.0),
                        cr_Op_node(MUL, temp_l, r_der)));    // - a*b'
                      // )
                    // );
                  break;
              }
              break;
            case MUL:  // a*b
              switch (flag) {
                case 3:  // a' != 0 && b' != 0
                  return
                    cr_Op_node(ADD,
                      cr_Op_node(MUL, l_der, temp_r),  // a'* b
                      cr_Op_node(MUL, temp_l, r_der));  // a * b'
                    // );
                case 2:  // b' = 0
                  // del_tree(temp_l)
                  return
                    cr_Op_node(MUL, l_der, temp_r);   // a'* b
                case 1:  // a' = 0
                  // del_tree(temp_r)
                  return
                    cr_Op_node(MUL, temp_l, r_der);    // a * b'
              }
              break;
            case POW:  // a^b = exp(b*log(a))
              switch (flag) {
                case 3:  // a' != 0 && b' != 0
                  return
                    cr_Op_node(MUL,
                      copy_tree(root),
                      cr_Op_node(ADD,
                        cr_Op_node(MUL,
                          r_der,
                          cr_Op_node(LOG, 0, temp_l))     // b' * log(a)
                        ,  // ),
                        cr_Op_node(MUL,
                          temp_r,
                          cr_Op_node(DIV, l_der, temp_l))));  // b * a'/a
                        // )
                      // )
                    // );  // a^b * (b' * log(a) + b * a' / a)
                case 2:  // b' = 0
                  return
                    cr_Op_node(MUL,
                      temp_r,
                      cr_Op_node(MUL,
                        cr_Op_node(POW,
                          temp_l,
                          cr_Op_node(SUB,
                            temp_r,
                            cr_Number_node(1.0)))    // b - 1
                          //)
                        ,  // ),
                        l_der));
                      // )
                    // );  // b * a^(b-1) * a'
                case 1:  // a' = 0
                  // del_tree(temp_r);
                  return
                    cr_Op_node(MUL,
                      copy_tree(root),
                      cr_Op_node(MUL,
                        r_der,
                        cr_Op_node(LOG, 0, temp_l)));  // b' * log(a)
                      // )
                    // );  // a^b * b' * log(a)
              }
              break;
          }
        } else {
          return 0;
        }
      }
      case COS:
      case SIN:
      case LOG:  // f(a)
        if (flag) {
          Node* temp_r = copy_tree(root->right);
          Node* new_root = cr_Op_node(MUL, 0, r_der);  // ??? * a'
          switch (root->op_type) {
            case COS:  // cos(a)
              new_root->left =
                cr_Op_node(MUL,
                  cr_Number_node(-1.0),
                  cr_Op_node(SIN, 0, temp_r));  // -sin(a)
                // );
              break;
            case SIN:  // sin(a)
              new_root->left =
                cr_Op_node(COS, 0, temp_r);  // cos(a)
              break;
            case LOG:  // log(a)
              new_root->left =
                cr_Op_node(DIV,
                  cr_Number_node(1.0),
                  temp_r);                 // 1/a
                // );
              break;
          }
          // f'(a) * a';
          return new_root;
        }
      }
    }
  }
}
