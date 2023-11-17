/*
Name: Ruby Link
Student ID: 2392068
Email: rlink@chapman.edu
Class: CPSC_350-03
Assignment: Spanning the Gamut 
*/
#include "WGraph.h"
#include <iostream>
#include <string>

WGraph::WGraph(){
  m_size = 0;
  m_adj = NULL;
  m_conn = NULL;
  edgeHeap = new MinHeap<Edge>(0); //keeps track of the edges in order from least to greatest - priority queue
}

WGraph::WGraph(unsigned int sz){
  m_size = sz;
  edgeHeap = new MinHeap<Edge>(m_size + 1);
  
  m_adj = new double*[sz];
  m_conn = new double*[sz];
  for(int i = 0; i < m_size; ++i){
    m_adj[i] = new double[sz];
    m_conn[i] = new double[sz];
  }
  //start with edges
  for(int i = 0; i < m_size; ++i){
    for(int j = 0; j < m_size; ++j){
      m_adj[i][j] = std::numeric_limits<double>::max(); //essentially infinity
      m_conn[i][j] = std::numeric_limits<double>::max();
    }
  }
}

WGraph::~WGraph(){
  //release memory
}

int WGraph::size(){
  return m_size;
}

void WGraph::addEdge(VertexID i, VertexID j, double w){
  if(i < m_size && j < m_size){
    m_adj[i][j] = w;
    m_adj[j][i] = w;
  }
  Edge nd = Edge(i, j, w);
  edgeHeap -> insert(nd);
  calcFW();
}

void WGraph::removeEdge(VertexID i, VertexID j){
  if(i < m_size && j < m_size){
    m_adj[i][j] = std::numeric_limits<double>::max();
    m_adj[j][i] = std::numeric_limits<double>::max();
  }
  calcFW();
}

bool WGraph::areAdjacent(VertexID i, VertexID j){
  return (m_adj[i][j] < std::numeric_limits<double>::max());
}


void WGraph::calcFW(){ //runtime complexity O(v^3)
  for(int i = 0; i < m_size; ++i){
    for(int j = 0; j < m_size; ++j){
      m_conn[i][j] = m_adj[i][j]; //start with conn == adj matrix
    }
  }
  for(int im = 0; im < m_size; ++ im){ //intermediate points --> transitive closure
    for(int source = 0; source < m_size; ++source){ //source = starting point
      for(int sink = 0; sink < m_size; ++sink){ //sink = ending point
        if(source == sink){
          continue;
        }else if(m_conn[source][im] != std::numeric_limits<double>::max() &&
          m_conn[im][sink] != std::numeric_limits<double>::max() &&
          m_conn[source][sink] > m_conn[source][im] + m_conn[im][sink]){
           m_conn[source][sink] = m_conn[source][im] + m_conn[im][sink];
        }
      }
    }
  }
}

double WGraph::cheapestCost(VertexID i, VertexID j){
  return m_conn[i][j]; //constant
}

void WGraph::printAdj(){
  std::cout << "ADJ MATRIX";
  for(int i = 0; i < m_size; ++i){
    std::cout << std::endl;
    for(int j = 0; j < m_size; ++j){
      if(m_adj[i][j] > 100){
        std::cout << "0";
      }
      else{
        std::cout << m_adj[i][j];
      }
      std::cout << " ";
    }
  }
}

//used to see if two sets are equal to each other 
bool WGraph::setEquals(Set s1, Set s2){
  bool same = true;
  if(s1.size() != s2.size()){ //if the size is different, not the same
    same = false;
  }
  else{
    for(int i = 0; i < s1.size(); ++i){
      if(s1.getVal(i) != s2.getVal(i)){ // if the components aren't the same
        same = false;
      }
    }
  }
  return same;
}


//combines two sets together by moving the contents on set2 to set1
void WGraph::setMerge(Set s1, Set s2){
  int val; 
  for(int i = 0; i < s2.size(); ++i){
    val = s2.removeVal();
    if(!s1.contains(val)){
      s1.addVal(val);
    }
  }
}

//computes the MST and makes a new MST graph
void WGraph::computeMST(int nodes){
int edgeCount = 0;
WGraph minGraph(m_size);
int v1, v2;
int weightCount = 0;
DblList<Set>* setList = new DblList<Set>();
//starts out as each vertex is its own set
for(int i = 0; i < m_size; ++i){
  Set s = Set();
  s.addVal(i);
  std::cout << i << std::endl;
  setList -> addBack(s);
}

//temps
Edge currEdge = Edge();
Set currSet = Set();
Set set1 = Set();
Set set2 = Set();

while(edgeCount < nodes - 1){
  //get the minimum value
  currEdge = edgeHeap -> getMin();
  //get the vertexs from the edge
  v1 = currEdge.getv1();
  v2 = currEdge.getv2();
  //find the set containing vertex 1
  for(int i = 0; i < setList ->size(); ++i){
    currSet = setList -> get(i);
    for(int j = 0; j <currSet.size(); ++j){
      if(currSet.contains(v1)){
        set1 = currSet;
      }
    }
  }
  //finding the set containing vertex 2
  for(int i = 0; i < setList ->size(); ++i){
    currSet = setList -> get(i);
    for(int j = 0; j <currSet.size(); ++j){
      if(currSet.contains(v2)){
        set2 = currSet;
      }
    }
  }
  //if the two sets aren't equal, merge them and add a new edge to minGraph
  if(!setEquals(set1,set2)){
    int edgeWeight = currEdge.getEdge();
    weightCount += edgeWeight;
    edgeHeap -> deleteMin();
    setMerge(set1, set2);
    minGraph.addEdge(v1,v2, edgeWeight);
    edgeCount++;
    }
  else{
        edgeHeap -> deleteMin(); //pop from minHeap
    }
    
  }

  std::cout <<std::endl;
  std::cout <<std::endl;
  std::cout <<std::endl;
  
  std::cout << "/////////////////// Results ////////////////////" << std::endl;
  std::cout << "MST: " << weightCount << std::endl;
  
  minGraph.printAdj();
}

