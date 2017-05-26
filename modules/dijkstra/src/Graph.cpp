// Copyright 2017 Kalinin Vladimir

#include "include/Graph.h"

edge::edge() : weight(0), key(0), next(0) {}

edge::edge(const int _weight, const int _key) : weight(_weight), key(_key), next(0) {}

void edge::setNext(edge* _next) { next = _next; }

int edge::getWeight() { return weight; }

int edge::getKey() { return key; }

edge* edge::getNext() { return next; }

graph::graph() : node(0), size(0) {}

graph::graph(int _size) : size(_size) {
  node = new edge*[size];
  for (int i = 0; i < size; i++)
    node[i] = 0;
}

void graph::addEdge(const int _weight, const int key1, const int key2) {
  if (isConnect(key1, key2))
    return;
  if (node[key1] == 0)
    node[key1] = new edge(_weight, key2);
  else
  {
    edge* tmp = node[key1];
    while (tmp->getNext())
      tmp = tmp->getNext();
    tmp->setNext(new edge(_weight, key2));
  }

  if (node[key2] == 0)
    node[key2] = new edge(_weight, key1);
  else
  {
    edge* tmp = node[key2];
    while (tmp->getNext())
      tmp = tmp->getNext();
    tmp->setNext(new edge(_weight, key1));
  }
}

bool graph::isConnect(const int key1, const int key2) {
  edge* tmp = node[key1];
  while (tmp) {
    if (tmp->getKey() == key2)
      return true;
    tmp = tmp->getNext();
  }
  return false;
}

int graph::getSize() {
  return size;
}

edge* graph::getNode(int n) {
  return node[n];
}
