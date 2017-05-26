// Copyright 2017 Kalinin Vladimir

#ifndef MODULES_DIJKSTRA_INCLUDE_GRAPH_H_
#define MODULES_DIJKSTRA_INCLUDE_GRAPH_H_

struct edge {
 public:
  edge();
  edge(const int _weight, const int _key);
  void SetNext(edge* _next);
  edge* GetNext();
  int GetWeight();
  int GetKey();

 private:
  int weight_;
  int key_;
  edge* next_;
};

class graph {
 public:
  graph();
  explicit graph(int size);

  void AddEdge(const int _weight, const int key1, const int key2);
  bool IsConnect(const int key1, const int key2);
  int GetSize();
  edge* GetNode(int n);

  int * Dijkstra(int node_index);

 private:
  int size_;
  edge **node_;
};

#endif  // MODULES_DIJKSTRA_INCLUDE_GRAPH_H_
