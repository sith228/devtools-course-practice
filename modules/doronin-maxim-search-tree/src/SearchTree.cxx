// Copyright 2017 Doronin Maxim

#include "SearchTree.h"

SearchTree::SearchTree() : root(0) {};

SearchTree::~SearchTree() {
    recursiveDel(root);
}

Node* SearchTree::search(const double key) const {
    Node* currentNode = root;
    if (currentNode == 0)
        throw "search: Tree is empty!";

    while (currentNode != 0 && currentNode->key != key)
        if (key < currentNode->key)
            currentNode = currentNode->left;
        else
            currentNode = currentNode->right;

    return currentNode;
}

Node* SearchTree::findMin(const Node* const node = root) const {
    Node* currentNode = node;
    if (currentNode == 0)
        throw "searchMin: Tree is empty!";
    while (currentNode->left != 0)
        currentNode = currentNode->left;
    return currentNode;
}

Node* SearchTree::findMax(const Node* const node = root) const {
    Node* currentNode = node;
    if (currentNode == 0)
        throw "searchMax: Tree is empty!";
    while (currentNode->right != 0)
        currentNode = currentNode->right;
    return currentNode;
}

Node* SearchTree::findPrev(const double key) const {
    Node* currentNode = search(key);
    if (currentNode == 0)
        throw "findPrev: there is no element with such key!";
    return findPrev(currentNode);
}

Node* SearchTree::findNext(const double key) const {
    Node* currentNode = search(key);
    if (currentNode == 0)
        throw "findNext: there is no element with such key!";
    return findNext(currentNode);
}

Node* SearchTree::findPrev(const Node* const node) const {
    if (node == 0)
        throw "findPrev: Tree is empty!";
    if (node->left != 0)
        return findMax(node->left);

    Node* currentNode = node;
    while (currentNode->parent != 0
        && currentNode == currentNode->parent->left)
        currentNode = currentNode->parent;
    return currentNode;
}

Node* SearchTree::findNext(const Node* const node) const {
    if (node == 0)
        throw "findNext: Tree is empty!";
    if (node->right != 0)
        return findMin(node->right);

    Node* currentNode = node;
    while (currentNode->parent != 0
        && currentNode == currentNode->parent->right)
        currentNode = currentNode->parent;
    return currentNode;
}
