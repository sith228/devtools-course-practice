// Copyright 2017 Doronin Maxim

#ifndef MODULES_SEARCH_TREE_INCLUDE_SEARCH_TREE_H_
#define MODULES_SEARCH_TREE_INCLUDE_SEARCH_TREE_H_

class Node {
 public:
     float key;
     Node* left;
     Node* right;
     Node* parent;
};

#endif MODULES_SEARCH_TREE_INCLUDE_SEARCH_TREE_H_
