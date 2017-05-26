// Copyright 2017 Kalinin Vladimir
#include "include/dijkstra.h"
#include <limits.h>

int * dijkstra(int node_index, graph grf) {
  int* weight = new int[grf.getSize()];
  for (int i = 0; i < grf.getSize(); i++)
    weight[i] = INT_MAX;
  weight[node_index] = 0;

  int* mark = new int[grf.getSize()];
  for (int i = 0; i < grf.getSize(); i++)
    mark[i] = 0;

  bool allNodesMarked = false;

  while (!allNodesMarked) {
    int minWeightNode, minWeight = INT_MAX;
    for (int i = 0; i < grf.getSize(); i++)
      if (mark[i] == 0 && weight[i] < minWeight) {
        minWeight = weight[i];
        minWeightNode = i;
      }
    mark[minWeightNode] = 1;
    edge* tmp = grf.getNode(minWeightNode);
    while (tmp) {
      if (weight[tmp->getKey()] > weight[minWeightNode] + 
        tmp->getWeight() && mark[tmp->getKey()] == 0)
        weight[tmp->getKey()] = weight[minWeightNode] + tmp->getWeight();
      tmp = tmp->getNext();
    }

    allNodesMarked = true;
    for (int i = 0; i < grf.getSize(); i++)
      if (mark[i] == 0)
        allNodesMarked = false;
  }

  return weight;
}
