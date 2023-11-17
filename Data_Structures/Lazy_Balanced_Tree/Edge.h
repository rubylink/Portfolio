/*
Name: Ruby Link
Student ID: 2392068
Email: rlink@chapman.edu
Class: CPSC_350-03
Assignment: Spanning the Gamut 
*/
#ifndef EDGE_H
#define EDGE_H
#include <cstdlib>

//edge class represent the connection between two verticies and an edge
class Edge{
    public:
        Edge();
        Edge(int v1, int v2, int weight);
        ~Edge();
        int m_vertex1;
        int m_vertex2; 
        int m_edge;
        int getv1();
        int getv2();
        int getEdge();
        void print();
        bool operator==(const Edge& n) const;
        bool operator!=(const Edge& n) const;
        bool operator<(const Edge& n) const;
        bool operator>(const Edge& n) const;
};

#endif