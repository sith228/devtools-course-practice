// Copyright 2017 Doronin Maxim

#ifndef MODULES_DORONIN_MAXIM_SEARCH_TREE_INCLUDE_SEARCHTREE_H_
#define MODULES_DORONIN_MAXIM_SEARCH_TREE_INCLUDE_SEARCHTREE_H_


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

     const Node* search(const double key) const;
     const Node* findMin() const;
     const Node* findMax() const;
     const Node* findMin(const Node* const node) const;
     const Node* findMax(const Node* const node) const;
     const Node* findPrev(const double key) const;
     const Node* findNext(const double key) const;

     void insert(const double key);
     void erase(const double key);
     void clear();

     bool isEmpty() const;
     const int size() const;

 protected:
     Node* root;

     const Node* findPrev(const Node* const node) const;
     const Node* findNext(const Node* const node) const;

     void recursiveDeletion(Node*& node);  // for destructor
     const int recursiveSize(const Node* const node) const;
};

#endif  // MODULES_DORONIN_MAXIM_SEARCH_TREE_INCLUDE_SEARCHTREE_H_
