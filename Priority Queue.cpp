#include <iostream>
#include <vector>
using namespace std;
//////////////////////
/////Introduction/////
// Reference: https://www.geeksforgeeks.org/priority-queue-in-cpp-stl/
// Intuition: extract or access elements in some specific orders, every element has an important priority factor, based on it we can sort the elements.
// it is an extension of normal queues which follow FIFO principle
// types: 
  // Min Priority Queue: the element gains the `least` priority comes first
  // Max Priority Queue: the element gains the `highest` priority comes first
// Functions we need: insert, getMin, getMax, removeMin, removeMax, getSize
// Ways to implement PQ: 
  // Array(unsorted  or sorted)
  // Linked list(unsorted or sorted)
  // Binary search tree
  // Unordered Map
  // Balanced BST, this method performs better than above in time complexity O(logN)
    // drawback: keeping balance and storing with multiple pointers are difficult and complicated


/////////////////////////////
/////Heaps--Introduction/////
// reference: https://www.programiz.com/dsa/heap-data-structure
// property:
  // 1. a complete binary tree(CBT)  (https://www.programiz.com/dsa/complete-binary-tree)
    // Characteristics: 
      // each node has maximum two children, all levels are completely filled except last one. Furthermore, it might be a full tree.
      // all the leaf elements must lean towards left(ie: nodes should be filled from left to right)
    // we can only `delete` the `last element` of the last level
  // 2. heap order property

///Without rebalance maintenance workload
// Minimum number of nodes: 2^0+2^1+2^2...+2^(h-2)+1= 2^(h-1)-1+1= 2^(h-1), where h: height
// Maximum number of nodes: 2^0+2^1+2^2...+2^(h-1)= 2^h -1
// In summary, 2^(h-1)≤n≤2^h -1
  // rewrite it we can get,  log_2 (n+1)≤h≤ log_2 n +1. In terms of time complexity, h=O(logN), without any maintaining workload.
///Store the heap easily
  // How to insert an element? 
    // Traditional method: 
      // Traversing all the levels, as soon as find out an empty position, we insert the value there.
      // While, this method T=O(N) that is not a good solution.
    // Optimization with array:
      // store the complete binary tree inside an array
      // we need to find the relationship between array index and tree parent-children connection 🌟
        // if an element index of array is i, then its `left child` will present at (2i+1) index of array, for the `right child`'s index is (2i+2).
        // given the child index, we want to find: parent index=(child index-1)/2
      // As for inserting an element T=O(1), with the help of formula, traversal and pointer are not needed.


//////////////////////////////////
/////Heaps--Insert and Delete/////
// heap order property
  // in Min heap: root<left & root<right
  // in Map heap: root>left & root>right
// insert 
  // Up-heapify: compare the inserted value with its parent node's, swap recursively to ensure it still a min/max heap 
  // T=O(h)=O(logN)
// delete 
  // Down-heapify: 
    // swap the original position of element we want to delete and the position we can delete(the last element)
    // swap the swapped node with children nodes recursively to ensure it still a min/max heap
  // T=O(h)=O(logN)
// getMin() in min heap & getMax() in max heap: T=O(1), return the root value
// removeMin() in min heap & removeMax() in max heap: T=O(logN)


////////////////////////
/////Implementation/////
// with min priority queue
class PriorityQueue{
  vector<int> pq;
  public:
    PriorityQueue(){

    }
    bool isEmpty(){
      return pq.size()==0; //check whether it is true
    }
    int getSize(){
      return pq.size();
    }
    int getMin(){
      if(isEmpty()){
        return 0; //default value returned if it is empty
      }
      return pq[0]; //return the root
    }
    void insert(int element){
      pq.push_back(element); //put it in the last position, it is a CBT, but cannot promise it obeys heap order property yet
      //apply the formula
      int ChildIndex=pd.size()-1;
      while(ChildIndex>0){ //child index begins from 1
        int ParentIndex=(ChildIndex-1)/2;
        //comparison and swap
        if(pq[ChildIndex]<pd[ParentIndex]){
          swap(pq[ChildIndex],pq[ParentIndex]);
          ChildIndex=ParentIndex; //update the child index
          }else{
            break;
          }
      }     
    }
    //🌟when ParentIndex==minIndex, stop criteria satisfied. We need to ensure child index does not out of range.
    int removeMin(){
      if(isEmpty()){
        return 0; 
      }
      int ans=pq[0]; //store the element
      //swap the first element and last element
      swap(pq[0],pq[pq.size()-1]);
      pq.pop_back(); //remove element from back, CBT satisfied
      //ensure the heap order priority satisfied
      int ParentIndex=0;
      while(true){
        //apply the formula
        int leftChildIndex=2*ParentIndex+1;
        int rightChildIndex=2*ParentIndex+2;
        //set the minimum index
        int minIndex=ParentIndex;
        //comparison
        if(leftChildIndex<pq.size() && pq[leftChildIndex]<pq[minIndex]){
          minIndex=leftChildIndex; //update the minimum index
        }
        if(rightChildIndex<pq.size() && pq[rightChildIndex]<pq[minIndex]){
          minIndex=rightChildIndex;
        }
        //swap
        if(minIndex==ParentIndex){
          break;
        }
        swap(pq[ParentIndex],pq[minIndex]);
        ParentIndex=minIndex;
      }
      return ans;
    }
};

int main(){
  PriorityQueue p;
  p.insert(14);
  p.insert(126);
  p.insert(55);
  p.insert(96);
  p.insert(32);
  p.insert(10);
  p.insert(5);
  cout<<p.getSize()<<endl;
  cout<<p.getMin()<<endl;
  while(!p.isEmpty()){
    cout<<p.removeMin()<<" ";
  }
  return 0;
}


