// Copyright 2017 Doronin Maxim

#ifndef MODULES_SEARCH_TREE_INCLUDE_SEARCH_TREE_H_
#define MODULES_SEARCH_TREE_INCLUDE_SEARCH_TREE_H_

class Node {
 public:
     double key;
     Node* left;
     Node* right;
     Node* parent;
};

class SearchTree {
 public:
     SearchTree();
     ~SearchTree();

     double findMin() const;
     double findMax() const;
     double findPrev(const double key) const;
     double findNext(const double key) const;
     bool search(const double key) const;

     void insert(const float key);
     void erase(const float key);

     bool isEmpty() const;
     bool size() const;

 protected:
     Node* root;
     void recursiveDeletion(Node* node);
     int recursiveSize(const Node* const node) const;
};

#endif MODULES_SEARCH_TREE_INCLUDE_SEARCH_TREE_H_
