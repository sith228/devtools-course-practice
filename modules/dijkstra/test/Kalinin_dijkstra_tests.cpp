// Copyright 2017 Kalinin Vladimir
#include <gtest/gtest.h>

#include "include/dijkstra.h"
#include "src/dijkstra.cpp"
#include "include/Graph.h"
#include "src/Graph.cpp"

#include <iostream>
using namespace std;


TEST(Kalinin_dijkstra_tests, Can_Create_Edge) {
  // Arrange
  edge a1;
  edge a2(1, 2);
  // Act
  

  // Assert
  EXPECT_EQ(a2.getWeight(), 1);
  EXPECT_EQ(a2.getKey(), 2);
  EXPECT_EQ(a1.getWeight(), 0);
  EXPECT_EQ(a1.getKey(), 0);
}

TEST(Kalinin_dijkstra_tests, Can_Set_Next) {
  // Arrange
  edge a1;
  edge a2;
  // Act
  a1.setNext(&a2);

  // Assert
  EXPECT_EQ(a1.getNext(), &a2);
}

TEST(Kalinin_dijkstra_tests, Can_Create_Graph) {
  // Arrange
  

  // Act
  graph gr1;
  graph gr2(5);

  // Assert
  EXPECT_EQ(gr1.getSize(), 0);
  EXPECT_EQ(gr2.getSize(), 5);
}

TEST(Kalinin_dijkstra_tests, IsConnect_Works) {
  // Arrange
  graph gr(6);

  // Act
  gr.addEdge(9, 1, 3);

  // Assert
  EXPECT_EQ(gr.isConnect(1, 3), true);
  EXPECT_EQ(gr.isConnect(3, 1), true);
  EXPECT_EQ(gr.isConnect(1, 2), false);
}

TEST(Kalinin_dijkstra_tests, Can_Set_Edge_Weight) {
  // Arrange
  graph gr(6);

  // Act
  gr.addEdge(9, 1, 3);

  // Assert
  EXPECT_EQ(gr.getNode(1)->getWeight(), 9);
  EXPECT_EQ(gr.getNode(3)->getWeight(), 9);
}

TEST(Kalinin_dijkstra_tests, Diykstra_Result_Is_Correct) {
  // Arrange
  graph gr(6);
  gr.addEdge(7, 1, 2);
  gr.addEdge(10, 2, 3);
  gr.addEdge(9, 1, 3);
  gr.addEdge(15, 2, 4);
  gr.addEdge(11, 3, 4);
  gr.addEdge(14, 1, 0);
  gr.addEdge(2, 3, 0);
  gr.addEdge(9, 5, 0);
  gr.addEdge(6, 4, 5);
  int correct_answer[6] = { 11, 0, 7, 9, 20, 20 };

  // Act
  int* tmp = dijkstra(1, gr);

  //cout << tmp << endl;

  // Assert
  for (int i = 0; i < 6; i++)
    EXPECT_EQ(correct_answer[i], tmp[i]);
}
