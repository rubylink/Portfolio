/*
Name: Ruby Link
Student ID: 2392068
Email: rlink@chapman.edu
Class: CPSC_350-03
Assignment: Spanning the Gamut 
*/
#ifndef MIN_HEAP_H
#define MIN_HEAP_H

template <typename T>
class MinHeap{
  public:
    MinHeap(int c);
    virtual ~MinHeap();
    void insert(T k);
    T getMin(); // gets root
    void deleteMin(); //deletes root
    bool isEmpty(){ return m_size==0;}
    int m_cap;
    int m_size;//how many things in heap
  private:
    T* m_Heap; //array
    
      //what's max size of heap
    void fixHeap(int startIdx);
    int getLeftIdx(int i);
    int getRightIdx(int i);
    int getParentIdx(int i);
};

template <typename T>
MinHeap<T>::MinHeap(int c){
  m_Heap = new T[c]; //initialize array
  m_size = 0;
  m_cap = c;
}

template <typename T>
MinHeap<T>::~MinHeap(){
  delete[] m_Heap;
}

template <typename T>
T MinHeap<T>::getMin(){
  //TODO: check for empty heap
  return m_Heap[0];
}

template <typename T>
int MinHeap<T>::getLeftIdx(int i){ //i is the parent
  return (2*i)+1;
}

template <typename T>
int MinHeap<T>::getRightIdx(int i){
  return (2*i)+2;
}

template <typename T>
int MinHeap<T>::getParentIdx(int i){
  return (i-1)/2; // integer division so we get an int back
}

template <typename T>
void MinHeap<T>::insert(T k){ // log(n)
  //TODO: make sure array isn't full
  m_Heap[m_size++] = k;
  int currIdx = m_size - 1;
  //make sure heap is still a valid heap
  while((currIdx!=0) && (m_Heap[currIdx] < m_Heap[getParentIdx(currIdx)])){
    T temp = m_Heap[currIdx];
    m_Heap[currIdx] = m_Heap[getParentIdx(currIdx)];
    m_Heap[getParentIdx(currIdx)] = temp;
    currIdx = getParentIdx(currIdx);

  }
}

template <typename T>
void MinHeap<T>::deleteMin(){
  //TODO: check for empty heap
  if(m_size==1){
    --m_size;
    //return;
  }else{
    m_Heap[0] = m_Heap[m_size-1];
    --m_size;
    fixHeap(0); //fix heap starting at root
  }
}

template <typename T>
void MinHeap<T>::fixHeap(int startIdx){ //log(n)
  int left = getLeftIdx(startIdx);
  int right = getRightIdx(startIdx);
  int smallest = startIdx; //isnt necessarily to the left in a heap
  if(left < m_size && m_Heap[left] < m_Heap[startIdx]){
    smallest = left; //in right, we have to compare this now
  }
  if(right < m_size && m_Heap[right] < m_Heap[smallest]){ // stand alone, they can both be true
    smallest = right; 
  }
  if(smallest != startIdx){//have to swap with child
    T temp = m_Heap[startIdx];
    m_Heap[startIdx] = m_Heap[smallest];
    m_Heap[smallest] = temp;
    fixHeap(smallest);
  }
}

#endif