/*
Name: Ruby Link
Student ID: 2392068
Email: rlink@chapman.edu
Class: CPSC_350-03
Assignment: Spanning the Gamut 
*/
#include "Edge.h"
#include <iostream>
#include <string>


Edge::Edge(){
  m_vertex1 = 0;
  m_vertex2 = 0; 
  m_edge = 0;

}
Edge::Edge(int v1, int v2, int weight){
  m_vertex1 = v1;
  m_vertex2 = v2; 
  m_edge = weight;
}

Edge::~Edge(){
}

void Edge::print(){
    std::cout << "v1= " << m_vertex1 << std::endl;
    std::cout << "v2= " << m_vertex2 << std::endl;
    std::cout << "weight= " << m_edge << std::endl;
}

int Edge::getv1(){
    return m_vertex1;
}

int Edge::getv2(){
    return m_vertex2;
}

int Edge::getEdge(){
    return m_edge;
}

//OVERLOADED OPERATORS - used source as stated in README
bool Edge::operator==(const Edge& n) const {
        return m_edge == n.m_edge;
    }

bool Edge::operator!=(const Edge& n) const {
        return m_edge != n.m_edge;
    }
bool Edge::operator<(const Edge& n) const {
        return m_edge < n.m_edge;
    }

bool Edge::operator>(const Edge& n) const {
        return m_edge > n.m_edge;
    }