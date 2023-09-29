 /*
Name: Ruby Link
Student ID: 2392068
Email: rlink@chapman.edu
Class: CPSC_350-03
Assignment: Spanning the Gamut 
*/
 #include "Set.h"

 Set::Set(){
    vals = new DblList<int>(); //hold all of the values
 }
 Set::~Set(){
 }

int Set::addVal(int val){
    vals -> addBack(val);
    return val;
}

int Set::getVal(int pos){
    return vals ->get(pos);
}

int Set::removeVal(){
    int v = vals -> removeBack();
    return v;
}

//checks to see if a set contains a specified value
bool Set::contains(int val){
    int size = vals ->size();
    bool contains = false;
    for(int i = 0; i < size; ++i){
        if(val == vals -> get(i)){
            contains = true;
        }
    }
    return contains;
}
 
int Set::size(){
    return vals ->size();

}