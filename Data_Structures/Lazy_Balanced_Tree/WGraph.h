
/*
Name: Ruby Link
Student ID: 2392068
Email: rlink@chapman.edu
Class: CPSC_350-03
Assignment: Spanning the Gamut 
*/
#ifndef WGraph_H
#define WGraph_H
#include "DblList.h"
#include "ListNode.h"
#include "MinHeap.h"
#include "Edge.h"
#include "Set.h"
#include <cstdlib>
#include <deque>
#include <set>
#include <stack>
#include <iostream>
#include <limits>

//a weighted, undirected WGraph implemented with adjacency matrix
//fixed size

typedef unsigned int VertexID;

class WGraph{
public: 
  WGraph();
  WGraph(unsigned int sz);
  ~WGraph();
  MinHeap<Edge>* edgeHeap;
  //DblList<Set>* setList;
  bool setEquals(Set s1, Set s2);
  void setMerge(Set s1, Set s2);
  void addEdge(VertexID i, VertexID j, double w);
  void removeEdge(VertexID i, VertexID j);
  bool areAdjacent(VertexID i, VertexID j);
  double cheapestCost(VertexID i, VertexID j);
  void calcFW();
  double** m_adj;
  void printAdj();
  int mstCost();
  void computeMST(int nodes);
  int size();

private:
  double** m_conn; //more general, is there a path between a start and a finish and what's the cost (all parts summed)
  unsigned int m_size; //Edges in WGraph (fixed)
  //DblList<T> vertices;


};

#endif