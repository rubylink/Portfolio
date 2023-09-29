/*
Name: Ruby Link
Student ID: 2392068
Email: rlink@chapman.edu
Class: CPSC_350-03
Assignment: Lazy Balanced Trees
*/
#ifndef LazyBST_H
#define LazyBST_H

#include <iostream>       
#include <algorithm>    

#include "TreeNode.h"
#include "DblList.h"

template <typename T>
class LazyBST{
    public:
        LazyBST();
        virtual ~LazyBST();
        bool contains(T d); // recursive version that uses recContainsHelper
        T& get(T d);
        void printInOrder();
        T* sortInOrder(); // least to greatest 
        void printTreePostOrder(); // left tree then right tree then root 
        void insert(T d);
        int size(); 
        T maxVal(); // right most child
        T minVal(); // left most child 
        T median(); // will only work if tree is balanced 
        void remove (T d);
        void rebalance(T* arr, int begin, int end);
        T* m_sortedArr;
        void clearList();
        int clearTree();
        bool isBalanced();
        int m_size;
        
    private: 
        TreeNode<T>* m_root;
        T& getHelper(TreeNode<T>* node, T d);
        int m_idx;
        bool recContainsHelper(TreeNode<T>* n, T d); 
        void printIOHelper(TreeNode<T>* n);
        T* sortIOHelper(TreeNode<T>* n);
        void printTreePostOrderHelper(TreeNode<T>* subTreeRoot);
        void insertHelper(TreeNode<T>*& subTreeRoot, T& d);
        T getMaxHelper(TreeNode<T>* n);
        T getMinHelper(TreeNode<T>* n);
        void findTarget(T key, TreeNode<T>*& target, TreeNode<T>*& parent);
        TreeNode<T>* getSuccessor (TreeNode<T>* rightChild);
        int calcLeftDepth(TreeNode<T>* root);
        int calcRightDepth(TreeNode<T>* root);
        //void rebalance(T* arr, int begin, int end);
        //void rebalanceHelper(T* arr);
        void clearTreeHelper(TreeNode<T>* root);  
};

   template <typename T>
        LazyBST<T>::LazyBST(){
        m_root = NULL;
        m_size = 0;
        m_idx = 0;
        //m_rightDepth = 0;
        //m_leftDepth = 0;
        //m_tempList = new DblList<T>();
    }

    template <typename T>
    LazyBST<T>::~LazyBST(){
        // TO DO: free up all memory 
    }

    // RECURSIVE CONTAINS
    template <typename T>
    bool LazyBST<T>::contains(T d){
        return recContainsHelper(m_root, d);
    }

    // RECURSIVE CONTAINS HELPER
    template <typename T>
    bool LazyBST<T>::recContainsHelper(TreeNode<T>* n, T d){
        if (n == NULL){ // if it is null then d is not in tree 
            return false;
        } 
        if (n -> m_data == d) { // if it is not null, is it here? 
            return true;
        }
        if (d > n -> m_data){ // it's not null but it's also not here, check if it is > or <
            return recContainsHelper(n -> m_right, d);
        } else {
            return recContainsHelper(n -> m_left, d);
        }
    }

    template <typename T>
    void LazyBST<T>::printInOrder(){
        printIOHelper(m_root);
    }

    template <typename T>
    void LazyBST<T>::printIOHelper(TreeNode<T>* n){
        if (n != NULL){ // is the node null? 
            printIOHelper(n -> m_left); // if not then print left of the current
            //std::cout << n -> m_data << std::endl; // always print the current node 
            printIOHelper(n -> m_right); // then print the right of the current 
        } 
    }
//same as print in order, but sorts things into an array
    template <typename T>
    T* LazyBST<T>::sortInOrder(){
        m_sortedArr = new T[m_size];
        m_idx = 0;
        return sortIOHelper(m_root);
    }

    template <typename T>
    T* LazyBST<T>::sortIOHelper(TreeNode<T>* n){
        if (n != NULL){ // is the node null? 
            sortIOHelper(n -> m_left); // if not then print left of the current
            m_sortedArr[m_idx++] = n -> m_data;
            //std::cout << n -> m_data << std::endl; // always print the current node 
            sortIOHelper(n -> m_right); // then print the right of the current 
        } 
        return m_sortedArr;
    }


    template <typename T>
    void LazyBST<T>::printTreePostOrder(){
        printTreePostOrderHelper(m_root);
    }

    template <typename T>
    void LazyBST<T>::printTreePostOrderHelper(TreeNode<T>* subTreeRoot){
        if(subTreeRoot != NULL){
            printTreePostOrderHelper(subTreeRoot->m_left);
            printTreePostOrderHelper(subTreeRoot->m_right);
            //std::cout << subTreeRoot->m_data << std::endl;
        }
    }

    
    // INSERT RECURSIVETY 
    template <typename T>
    void LazyBST<T>::insert(T d){
        //cout << "Hey?" << endl;
        if(m_size < 3){
            cout << "we good" << endl;
            insertHelper(m_root, d);
            ++m_size;
        }
        else if(!isBalanced()){
            cout << "Sort" << endl;
            sortInOrder();
            int ogSize = m_size;
            cout << "Clear" << endl;
            clearTree();
            cout << "Rebalancing!: " << endl;
            rebalance(m_sortedArr, 0, ogSize-1);
            insertHelper(m_root, d);
        }

        else{
            cout << "we good" << endl;
            insertHelper(m_root, d);
            ++m_size;
        }
        
    }
    // INSERT HELPER SO WE DO NOT HAVE TO PASS IN ROOT 
    // pass in by reference so that you don't have to manually mess with pointers (r & l children)
    template <typename T>
    void LazyBST<T>::insertHelper(TreeNode<T>*& subTreeRoot, T& d){
        if(subTreeRoot == NULL){
            subTreeRoot =  new TreeNode<T>(d); // insert here  & stop recursive call 

        } else if(d > subTreeRoot->m_data){
            insertHelper(subTreeRoot->m_right, d);

        } else{ // Less than or = to so we will have repeats in this tree. 
								// Some say duplicates are not allowed in trees but you can alternatively 
								// choose whether to put them to left or right as long as you're consistent
            insertHelper(subTreeRoot->m_left, d);
        }
    }

    // HELPER METHODS 

    // GET SIZE 
    template <typename T>
    int LazyBST<T>::size(){
       return m_size;
    }

    
    // GET MAX 
    template <typename T>
    T LazyBST<T>::maxVal(){
       return getMaxHelper(m_root);
    }

    template <typename T>
    T LazyBST<T>::getMaxHelper(TreeNode<T>* n){
       if(n -> m_right == NULL){
        return n -> m_data;
       } else {
            return getMaxHelper(n -> m_right);
       }
       
    }

    // GET MIN 
    template <typename T>
    T LazyBST<T>::minVal(){
       return getMinHelper(m_root);
    }

    template <typename T>
    T LazyBST<T>::getMinHelper(TreeNode<T>* n){
       if(n -> m_left == NULL){
            return n -> m_data;
       } else {
            return getMinHelper(n -> m_left);
       }
       
    }

    // GET MEDIAN - ONTY WORKS IF TREE IS BALANCED! 
    template <typename T>
    T LazyBST<T>::median(){
        //check if empty we assume it is a non-empty tree
        return m_root->m_data;
    }

    template <typename T>
    void LazyBST<T>::findTarget(T key, TreeNode<T>*& target, TreeNode<T>*& parent){
        while (target /*-> m_data*/ != NULL && target -> m_data != key){
            parent = target; 
            if (key < target -> m_data){
                target = target -> m_left;
            } else {
                target = target -> m_right;
            }
        }
    }

    template <typename T>
    TreeNode<T>* LazyBST<T>::getSuccessor(TreeNode<T>* rightChild){
        while (rightChild -> m_left != NULL){
            rightChild = rightChild -> m_left; //if there are no more children on the left, this is the successor
        }
        return rightChild; 
    }

    template <typename T>
    void LazyBST<T>::remove(T d){
        // check if tree is empty 
        // we assume the tree is non-empty 
        TreeNode<T>* target = NULL; 
        TreeNode<T>* parent = NULL; 
        target = m_root;

        // find the target 
        findTarget(d, target, parent); // no need save under any variables, target and parent are redefined bc we passed them in by reference  
        
        // target value was not found - it does not exist in our tree
        if (target == NULL){
            return;
        }

        // SCENARIO 1: TARGET IS A LEAF (INCLUDING ROOT)
        if (target -> m_left == NULL && target -> m_right == NULL){
            if (target == m_root){
                m_root = NULL;
            } else { // if it's a leaf but not the root 
                // check if target is its parent's left or right child 
                if (target == parent -> m_left){ // if target is a left child
                    parent -> m_left = NULL;
                } else { // target is a right child 
                    parent -> m_right = NULL;
                }
            }
            delete target;
			-- m_size;
        } 

        // SCENARIO 3: TARGET HAS TWO CHILDREN 
        else if (target -> m_left != NULL && target -> m_right != NULL){  // both children pointers are not null
            TreeNode<T>* suc = getSuccessor(target -> m_right);
            T value = suc -> m_data;
            remove(value); // goes in the BST remove method and removes the node w/ d = value
            target -> m_data = value;
        } 

        // SCENARIO 2: TARGET HAS 1 CHILD 
        else { 
            TreeNode<T>* child;
            // check whether target has a left or right child 
            if (target -> m_left != NULL){ // target has a left child 
                child = target -> m_left;
            } else{                        // target has a right child 
                child = target -> m_right;
            }

            if (target == m_root){
                m_root = child;
            } else {
                if (target == parent -> m_left){ // our target is a left child 
                    parent -> m_left = child; // make the parent's left child the target's child 
                } else {                       // our target is a right child 
                    parent -> m_right = child; // make the parent's right child the target's child 
                }
            }
						target -> m_left = NULL;
						target -> m_right = NULL;

            delete target;
			-- m_size;
        }
        
    }


    template <typename T>       
    int LazyBST<T>::calcRightDepth(TreeNode<T>* rightRoot){
        if (rightRoot == NULL) {
            return 0;
        }
        int leftHeight = calcRightDepth(rightRoot->m_left);
        int rightHeight = calcRightDepth(rightRoot->m_right);
        return 1 + max(leftHeight, rightHeight);
}


    template <typename T>
    int LazyBST<T>::calcLeftDepth(TreeNode<T>* leftRoot){
        if (leftRoot == NULL) {
            return 0;
        }
        int leftHeight = calcLeftDepth(leftRoot->m_left);
        int rightHeight = calcLeftDepth(leftRoot->m_right);
        return 1 + max(leftHeight, rightHeight);
    }

    template <typename T>
    bool LazyBST<T>::isBalanced(){
        //ADD IF ITS NULL!!!
        cout << "Left and right depth??" << endl;
        int rightDepth = calcRightDepth(m_root->m_right);
        int leftDepth = calcLeftDepth(m_root -> m_left);
        //std::cout << "left depth: " << rightDepth << std::endl;
        //std::cout<< "right depth: " << leftDepth<< std::endl;
        if(rightDepth == 0 || leftDepth == 0){
            return true;
        }
        else if(rightDepth >= 1.5 * leftDepth ||leftDepth >= 1.5 * rightDepth){
            return false;
        }
        else{
            return true;
        }
    }

    template <typename T>
    void LazyBST<T>::rebalance(T* arr, int begin, int end){
        //cout << "begin " << begin << endl;
        //cout << "end " << end << endl;
        if (begin <= end){
            //cout << "HEYY REBALCNINGGGG" << endl;
            int median = (begin + end) / 2;
            T data = arr[median];
            //std::cout << "median: " << data << std::endl;
            TreeNode<T>* node = new TreeNode<T>(arr[median]);
            insertHelper(m_root, data);
            ++m_size;
            rebalance(arr, begin, median-1);
            rebalance(arr, median + 1, end);
        }
    }

/*
    template <typename T>
    void LazyBST<T>::rebalanceHelper(T* arr){
        int sizey = 0;
        for(T d: arr){
            cout << "data: " << d << endl;
            sizey++;
        }
        //int sizeArr = sizeof(arr)/ sizeof(T);
        int sizeArr = sizey;
        cout << "sizeArr: " << sizeArr << endl;
        int medianIdx = sizeArr/2;
        cout << "median index : " << medianIdx << endl;
        T* leftArr = new T[medianIdx];
        T* rightArr = new T[medianIdx];
        while(){
            insert(arr[medianIdx]);
            for(int i = 0; i < medianIdx; ++i){
                leftArr[i] = arr[i];
            }
            int counter = 0;
            for(int i = medianIdx; i < sizeArr; ++i){
                rightArr[counter++] = arr[i];
            }
            hi = 0;
            rebalanceHelper(leftArr);
            rebalanceHelper(rightArr);

        }  
    }
*/
    template <typename T>
    int LazyBST<T>::clearTree(){
        clearTreeHelper(m_root);
        return m_size;
    }

    template <typename T>
    void LazyBST<T>::clearTreeHelper(TreeNode<T>* root){
        while(root != NULL){
            clearTreeHelper(root -> m_left);
            clearTreeHelper(root -> m_right);
            root = NULL;
            --m_size;
        }
    }

    template <typename T>
    T& LazyBST<T>::get(T d){
        return getHelper(m_root, d);
    }

    template <typename T>
    T& LazyBST<T>::getHelper(TreeNode<T>* node, T d){
        if (node == NULL){ // if it is null then d is not in tree 
            cout << "not found" << endl;
            TreeNode<T>* data = new TreeNode<T>(d);
            return data -> m_data;
        } 
        if (node -> m_data == d) { // if it is not null, is it here? 
            return node -> m_data;
        }
        if (d > node -> m_data){ // it's not null but it's also not here, check if it is > or <
            return getHelper(node -> m_right, d);
        } else {
            return getHelper(node -> m_left, d);
        }
    }



    #endif