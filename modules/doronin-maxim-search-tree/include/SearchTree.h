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

     Node* search(const double key) const;
     Node* findMin() const;
     Node* findMax() const;
     Node* findMin(const Node* const node) const;
     Node* findMax(const Node* const node) const;
     Node* findPrev(const double key) const;
     Node* findNext(const double key) const;
     Node* findPrev(const Node* const node) const;
     Node* findNext(const Node* const node) const;

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
