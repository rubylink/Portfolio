/*
Name: Ruby Link
Student ID: 2392068
Email: rlink@chapman.edu
Class: CPSC_350-03
Assignment: Lazy Balanced Trees
*/

#ifndef DBL_LIST_H
#define DBL_LIST_H

#include "ListNode.h"

template <typename T>
class DblList{
    public:
        DblList();
        virtual ~DblList();
        int size();

        bool isEmpty();
        void addFront(T data);
        void addBack(T data);
        void add(int pos, T data);

        T get(int pos); //return element without deleting it from linked list
        int find(T data);
        T removeFront();
        T removeBack();
        T remove(int pos); 

    private:
        ListNode<T>* m_front;
        ListNode<T>* m_back;
        int m_size;
};

template<typename T>
DblList<T>::DblList(){
    m_front = NULL;
    m_back = NULL;
    m_size = 0;
}

template<typename T>
DblList<T>::~DblList(){
    //todo - free memory - loop through and delete
    m_front = NULL;
    m_back = NULL;
    m_size = 0;
}

template<typename T>
int DblList<T>::size(){
    return m_size;
}

template<typename T>
bool DblList<T>::isEmpty(){
    return (m_size == 0);
}

template<typename T>
void DblList<T>::addFront(T data){
    ListNode<T>* newNode = new ListNode<T>(data);
    if(!isEmpty()){
        newNode->m_next = m_front; //setting the new nodes next pointer = to current front
        m_front->m_prev = newNode; //have current fronts prev point to = new node 
    }else{
        m_back = newNode; //if full bring to back
    }
    m_front = newNode; //assign new front
    ++m_size;
}

template<typename T>
void DblList<T>::addBack(T data){
    ListNode<T>* newNode = new ListNode<T>(data);
    if(!isEmpty()){
        newNode->m_prev = m_back; // new nodes previous pointer point to current back
        m_back->m_next = newNode; // the current back next pointer is equal to the new node
    }else{
        m_front = newNode; //if full, bring to front
    }
    m_back = newNode; //assign new back
    ++m_size;
}

template<typename T>
void DblList<T>::add(int pos, T data){
    if(isEmpty()){
        addFront(data);
    }else if(pos == 0){
        addFront(data);
    }else if(pos >= m_size){
        addBack(data);
    }else{
        ListNode<T>* current = m_front; //create temporary pointer that points to the front (will keep track of where we visit)
        int cPos = 0; //index of current position
        while(cPos != pos){
            current = current->m_next; //how we follow the chain
            ++cPos;
        }
        ListNode<T>* newNode = new ListNode<T>(data); //create the new node
        current->m_prev->m_next = newNode; //dealing with previous pointer to new as next
        newNode->m_prev = current->m_prev; //dealing with new pointer to previous and previous
        current->m_prev = newNode; //dealing with current previous pointer to new previous
        newNode->m_next = current; //dealing with new pointer to current as next
        ++m_size;
    }
}

template<typename T>
T DblList<T>::removeFront(){
    //make sure not empty
    T data = m_front->m_data; //keeps track of the data because we will return it at the end after we delete the node
    if(m_size == 1){
        delete m_front;
        m_front = NULL;
        m_back = NULL;
    }else{
        ListNode<T>* currFront = m_front; // temp pointer
        m_front = m_front->m_next; // new front is old fronts next
        m_front->m_prev = NULL; // set fronts previous = to null 
        delete currFront;
    }
    --m_size;
    return data;
}

template<typename T>
T DblList<T>::removeBack(){
    //make sure not empty
     T data = m_back->m_data;
     if(m_size == 1){
        delete m_back;
        m_front = NULL;
        m_back = NULL;
     }else{
        ListNode<T>* currBack = m_back; // keeps track of old back
        m_back = m_back->m_prev;
        m_back->m_next = NULL;
        delete currBack;
     }
     --m_size;
     return data;
}

template<typename T>
T DblList<T>::remove(int pos){
    //make sure not empty
    T data;
    if(pos == 0){
        data = removeFront();
    }else if(pos >= m_size -1){
        data = removeBack();   
    }else{
        ListNode<T>* current = m_front;
        int cPos = 0;
        while(cPos != pos){ //finds the node we want to delete
            current = current->m_next; // node we want to remove is = to current
            ++cPos;
        }
        data = current->m_data;
        current->m_prev->m_next = current->m_next; // currents prevs node's next pointer will now point ot the node one ahead or current
        current->m_next->m_prev = current->m_prev; // currens next pointers's previous should point to currents previous
        delete current;
        --m_size;
    }
    return data;
}

template<typename T>
T DblList<T>::get(int pos){ // return without deleting
    //is pos in range, etc.
    ListNode<T>* current = m_front;
    int cPos = 0;
    while(cPos != pos){
        current = current->m_next;
        ++cPos;
    }
    return current->m_data;
}
template<typename T>
int DblList<T>::find(T data){
    ListNode<T>* current = m_front;
    int position = 0;
    while(current ->m_data != data && position <= m_size){
        current = current -> m_next;
        ++position;
    }
    if(current == NULL){
        return -1;
    }
    else{
        return position; 
    }
}


#endif