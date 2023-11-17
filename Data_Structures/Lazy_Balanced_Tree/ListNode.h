/*
Name: Ruby Link
Student ID: 2392068
Email: rlink@chapman.edu
Class: CPSC_350-03
Assignment: Spanning the Gamut 
*/
#ifndef LIST_NODE_H
#define LIST_NODE_H
#include <cstdlib>

template<typename T>
class ListNode{
    public:
    ListNode(T data);
    virtual ~ListNode();
    T m_data;
    ListNode<T>* m_next; //recursive data structure b/c it points to instances of itself
    ListNode<T>* m_prev;
};

template<typename T>
ListNode<T>::ListNode(T data){
    m_data = data;
    m_next = NULL;
    m_prev = NULL;
}

template<typename T>
ListNode<T>::~ListNode(){
    m_next = NULL;
    m_prev = NULL;
}

#endif