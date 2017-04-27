// Copyright 2017 Doronin Maxim

#include "include/SearchTree.h"

SearchTree::SearchTree() : root(0) {}

SearchTree::~SearchTree() {
    recursiveDeletion(&root);
}

const Node* SearchTree::search(const double key) const {
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

const Node* SearchTree::findMin() const {
    return findMin(root);
}

const Node* SearchTree::findMax() const {
    return findMax(root);
}

const Node* SearchTree::findMin(const Node* const node) const {
    const Node* currentNode = node;
    if (currentNode == 0)
        throw "searchMin: Tree is empty!";
    while (currentNode->left != 0)
        currentNode = currentNode->left;
    return currentNode;
}

const Node* SearchTree::findMax(const Node* const node) const {
    const Node* currentNode = node;
    if (currentNode == 0)
        throw "searchMax: Tree is empty!";
    while (currentNode->right != 0)
        currentNode = currentNode->right;
    return currentNode;
}

const Node* SearchTree::findPrev(const double key) const {
    const Node* currentNode = search(key);
    if (currentNode == 0)
        throw "findPrev: there is no element with such key!";
    return findPrev(currentNode);
}

const Node* SearchTree::findNext(const double key) const {
    const Node* currentNode = search(key);
    if (currentNode == 0)
        throw "findNext: there is no element with such key!";
    return findNext(currentNode);
}

const Node* SearchTree::findPrev(const Node* const node) const {
    if (node->left != 0)
        return findMax(node->left);

    const Node* currentNode = node;
    const Node* currentParent = node->parent;
    while (currentParent != 0 && currentNode == currentParent->left) {
        currentNode = currentParent;
        currentParent = currentParent->parent;
    }
    return currentParent;
}

const Node* SearchTree::findNext(const Node* const node) const {
    if (node->right != 0)
        return findMin(node->right);

    const Node* currentNode = node;
    const Node* currentParent = node->parent;
    while (currentParent != 0 && currentNode == currentParent->right) {
        currentNode = currentParent;
        currentParent = currentParent->parent;
    }
    return currentParent;
}

void SearchTree::insert(const double key) {
    Node* node = new Node;
    node->key = key;
    node->left = 0;
    node->right = 0;
    node->parent = 0;

    if (root == 0) {
        root = node;
        return;
    }
    if (search(key) != 0)
        throw "insert: Already have such key!";

    Node* currentNode = root;
    Node* tmpParentNode;
    while (currentNode != 0) {
        tmpParentNode = currentNode;
        if (currentNode->key < node->key)
            currentNode = currentNode->right;
        else
            currentNode = currentNode->left;
    }

    node->parent = tmpParentNode;
    if (tmpParentNode->key <= node->key)
        tmpParentNode->right = node;
    else
        tmpParentNode->left = node;
}

void SearchTree::erase(const double key) {
    Node* dyingNode = const_cast<Node*>(search(key));
    if (dyingNode == 0)
        throw "erase: no such element in the tree";

    Node* parent = dyingNode->parent;
    if (dyingNode->left == 0 && dyingNode->right == 0) {
        if (parent->left == dyingNode)
            parent->left = 0;
        if (parent->right == dyingNode)
            parent->right = 0;
        delete dyingNode;
        return;
    } else if (dyingNode->left == 0 || dyingNode->right == 0) {
        if (dyingNode->left == 0) {
            if (parent->left == dyingNode)
                parent->left = dyingNode->right;
            else
                parent->right = dyingNode->right;
            dyingNode->right->parent = parent;
        } else {
            if (parent->left == dyingNode)
                parent->left = dyingNode->left;
            else
                parent->right = dyingNode->left;
            dyingNode->left->parent = parent;
        }
        delete dyingNode;
        return;
    } else {
        Node* child = const_cast<Node*>(findNext(dyingNode));
        double newKey = child->key;
        erase(child->key);
        dyingNode->key = newKey;
    }
}

void SearchTree::clear() {
    recursiveDeletion(&root);
}

bool SearchTree::isEmpty() const {
    if (root != 0)
        return 0;
    else
        return 1;
}

const int SearchTree::size() const {
    return recursiveSize(root);
}

void SearchTree::recursiveDeletion(Node** const node) {
    if (*node == 0)
        return;
    recursiveDeletion(&((*node)->left));
    recursiveDeletion(&((*node)->left));
    delete *node;
    *node = 0;
}

const int SearchTree::recursiveSize(const Node* const node) const {
    if (node == 0)
        return 0;
    int size;
    size = recursiveSize(node->left) + recursiveSize(node->right);
    return size + 1;
}
