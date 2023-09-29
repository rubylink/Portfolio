/*
Name: Ruby Link
Student ID: 2392068
Email: rlink@chapman.edu
Class: CPSC_350-03
Assignment: The Waiting Game
*/

#ifndef ListQueue_H
#define ListQueue_H
#include <iostream>
#include "DblList.h"

template<typename T>
class ListQueue{
    public:
        ListQueue();
        virtual ~ListQueue();
        void add(T data); //add to the back
        T remove(); //remove from the front
        T peek();
        bool isEmpty();
        int size();

    private:
        DblList<T>* m_list;

};

template<typename T>
ListQueue<T>::ListQueue(){
    m_list = new DblList<T>();
}

template<typename T>
ListQueue<T>::~ListQueue(){
    delete m_list;
}

template<typename T>
bool ListQueue<T>::isEmpty(){
    return (m_list->size() == 0);
}

template<typename T>
int ListQueue<T>::size(){
    return m_list->size();;
}

template<typename T>
void ListQueue<T>::add(T data){
    m_list->addBack(data);
}

template<typename T>
T ListQueue<T>::remove(){
    return m_list->removeFront();
}

template<typename T>
T ListQueue<T>::peek(){
    return m_list-> get(0);
}

#endif