// Copyright 2017 Kalinin Vladimir

#include "include/Graph.h"
#include <limits.h>

edge::edge() : weight_(0), key_(0), next_(0) {}

edge::edge(const int _weight, const int _key) :
  weight_(_weight), key_(_key), next_(0) {}

void edge::SetNext(edge* _next) { next_ = _next; }

int edge::GetWeight() { return weight_; }

int edge::GetKey() { return key_; }

edge* edge::GetNext() { return next_; }

graph::graph() : size_(0), node_(0) {}

graph::graph(int _size) : size_(_size) {
  node_ = new edge*[size_];
  for (int i = 0; i < size_; i++)
    node_[i] = 0;
}

void graph::AddEdge(const int _weight, const int key1, const int key2) {
  if (IsConnect(key1, key2))
    return;
  if (node_[key1] == 0) {
    node_[key1] = new edge(_weight, key2);
  } else {
    edge* tmp = node_[key1];
    while (tmp->GetNext())
      tmp = tmp->GetNext();
    tmp->SetNext(new edge(_weight, key2));
  }

  if (node_[key2] == 0) {
    node_[key2] = new edge(_weight, key1);
  } else {
    edge* tmp = node_[key2];
    while (tmp->GetNext())
      tmp = tmp->GetNext();
    tmp->SetNext(new edge(_weight, key1));
  }
}

bool graph::IsConnect(const int key1, const int key2) {
  edge* tmp = node_[key1];
  while (tmp) {
    if (tmp->GetKey() == key2)
      return true;
    tmp = tmp->GetNext();
  }
  return false;
}

int graph::GetSize() {
  return size_;
}

edge* graph::GetNode(int n) {
  return node_[n];
}

int* graph::Dijkstra(int node_index) {
  int* weight = new int[size_];
  for (int i = 0; i < size_; i++)
    weight[i] = INT_MAX;
  weight[node_index] = 0;

  int* mark = new int[size_];
  for (int i = 0; i < size_; i++)
    mark[i] = 0;

  bool allNodesMarked = false;

  while (!allNodesMarked) {
    int minWeightNode, minWeight = INT_MAX;
    for (int i = 0; i < size_; i++)
      if (mark[i] == 0 && weight[i] < minWeight) {
        minWeight = weight[i];
        minWeightNode = i;
      }
    mark[minWeightNode] = 1;
    edge* tmp = node_[minWeightNode];
    while (tmp) {
      if (weight[tmp->GetKey()] > weight[minWeightNode] +
        tmp->GetWeight() && mark[tmp->GetKey()] == 0)
        weight[tmp->GetKey()] = weight[minWeightNode] + tmp->GetWeight();
      tmp = tmp->GetNext();
    }

    allNodesMarked = true;
    for (int i = 0; i < size_; i++)
      if (mark[i] == 0)
        allNodesMarked = false;
  }
  delete[] mark;

  return weight;
}
