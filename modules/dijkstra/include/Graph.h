// Copyright 2017 Kalinin Vladimir

#ifndef MODULES_DIJKSTRA_INCLUDE_GRAPH_H_
#define MODULES_DIJKSTRA_INCLUDE_GRAPH_H_

struct edge {
public:
  edge();
  edge(const int _weight, const int _key);
  void setNext(edge* _next);
  edge* getNext();
  int getWeight();
  int getKey();

private:
  int weight;
  int key;
  edge* next;
};

class graph {
public:
  graph();
  graph(int size);

  void addEdge(const int _weight, const int key1, const int key2);
  bool isConnect(const int key1, const int key2);
  int getSize();
  edge* getNode(int n);

private:
  int size;
  edge **node;
};

#endif  // MODULES_DIJKSTRA_INCLUDE_GRAPH_H_
