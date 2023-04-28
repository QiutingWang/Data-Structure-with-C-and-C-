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
      int ChildIndex=pq.size()-1;
      while(ChildIndex>0){ //child index begins from 1
        int ParentIndex=(ChildIndex-1)/2;
        //comparison and swap
        if(pq[ChildIndex]<pq[ParentIndex]){
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
// return
// 7
// 5
// 5 10 14 32 55 96 126
// Time complexity=O(NlogN)
// Space complexity=O(N)


///////////////////////////
/////Inplace Heap Sort/////
/////Optimization: to make space complexity becomes O(1)
// Solution: convert the input array into minimum heap
// component of min heap algorithm mentioned above: 1. build minimum heap;  2. call the remove min function N times
// Procedure:
  // Assumption: the first element is the part of heap, the remaining n-1 elements are unsorted array
  // once take next element of array into heap part, we need to ensure it obeys heap order property, comparison and consider whether we need swap operation
  // As a result, all of the elements are sorted expect the original head element whose current position at the last.
  // swap the first element(A) and last element(B), and assume A has been removed(but actually not). Use `size` to represent it
  // swap the remaining part of heap to make sure it obeys heap order property
  // iterate the last 2 steps with N times. Namely, as soon as the child index=0, stop criteria satisfied.
  // As consequences, the array is sorted in decreasing order. While, if we use max priority queue, the array is sorted in ascending order.
// T=O(NlogN), S=O(1)
void inplaceHeapSort(int *pq, int n){
  // build heap in input array
  for(int i=1; i<n; i++){ //assume the first element at index 0 is already in heap
    int ChildIndex=i;
      while(ChildIndex>0){ 
        int ParentIndex=(ChildIndex-1)/2;
        if(pq[ChildIndex]<pq[ParentIndex]){
          swap(pq[ChildIndex],pq[ParentIndex]);
          ChildIndex=ParentIndex; 
          }else{
            break;
          }
      }    
  }
  //call the remove min function for n times
  int size=n;
  while(size>0){
  swap(pq[0],pq[size-1]);
  size--; //assume the element is removed but actually not. We use size to represent that.
  // Down-heapify
  int ParentIndex=0;
      while(true){
        int leftChildIndex=2*ParentIndex+1;
        int rightChildIndex=2*ParentIndex+2;
        int minIndex=ParentIndex;

        if(leftChildIndex<size && pq[leftChildIndex]<pq[minIndex]){
          minIndex=leftChildIndex; 
        }
        if(rightChildIndex<size && pq[rightChildIndex]<pq[minIndex]){
          minIndex=rightChildIndex;
        }
        if(minIndex==ParentIndex){
          break;
        }
        swap(pq[ParentIndex],pq[minIndex]);
        ParentIndex=minIndex;
      }
  }
}

int main(){
  int pq[]={14, 126, 55, 96, 32, 10, 5};
  inplaceHeapSort(pq, 7);
  for(int i=0;i<7;i++){
    cout<<pq[i]<<" ";
  }
  return 0;
}
// return
// 126 96 55 32 14 10 5


////////////////////////////////
/////Inbuilt Priority Queue/////
// STL Format: priority_queue<value_type> variable_name
#include <queue>
int main(){
  priority_queue<int> pq;
  pq.push(14);
  pq.push(126);
  pq.push(55);
  pq.push(96);
  pq.push(32);
  pq.push(10);
  pq.push(5);
  cout<<"Size: "<<pq.size()<<endl;
  cout<<"Top: "<<pq.top()<<endl; //return the root element
  while(!pq.empty()){
    cout<<pq.top()<<endl;
    pq.pop(); //print the maximum element then delete it
  }
  return 0;
}
// return
// Size: 7
// Top: 126
// 126
// 96
// 55
// 32
// 14
// 10
// 5
// other STL functions: swap(), emplace(), value_type


////////////////////////
/////K Sorted Array/////
// Rule: the maximum distance one element can move left or right for being sorted is up to `K-1` unit
// inputs we need to give: array and k
// Sorting:
  // Method1: blindly and simply use inbuilt sort() function. T=O(NlogN)
  // Method2: use Maximum priority queue
    // Process: the container contains k elements at most composing a Priority Queue, we pick up the maximum one as the sorted part with newly arranged index literately. 
void KSortedArray(int *input, int n, int k){
  priority_queue<int> pq;
  for(int i=0;i<k;i++){
    pq.push(input[i]); //insert the first k elements
  }
  int start=0; //set a pointer
  for(int i=k;i<n;i++){
    input[start]=pq.top(); //get the maximum element
    pq.pop(); //remove it
    start++; //move ahead
    pq.push(input[i]); //insert the ith element into the priority queue
  }
  while(!pq.empty()){
    input[start]=pq.top();
    pq.pop();
    start++;
  }
}

int main(){
  int input[]={14, 126, 55, 96, 32, 10, 5};
  int k=3;
  KSortedArray(input, 7, k);
  for(int i=0;i<7;i++){
    cout<<input[i]<<" ";
  }
  return 0;
}
// return
// 126 96 55 32 14 10 5
// T=O(Nlogk), if the k is very small, T≈O(N), S=O(k)≈O(1)


////////////////////////////
/////K Smallest Element/////
// procedure: 
  // push the first k elements to set up a priority queue
  // comparison: 
    // if the next element < the largest element in priority queue-->swap
    // if the next element > the largest element in priority queue-->do nothing
  // iteration the comparison step 
  // reverse the final results of the k-element priority queue is what we want
void KSmallest(int *a, int n, int k){
  priority_queue<int> pq;
  //push the first k elements
  for(int i=0;i<k;i++){
    pq.push(a[i]);
  }
  //comparison
  for(int i=k;i<n;i++){
    if(a[i]<pq.top()){
      pq.pop();
      pq.push(a[i]);
    }
  }
  //get answer
  while(!pq.empty()){
    cout<<pq.top()<<" ";
    pq.pop();
  }
}

int main(){
  int a[]={14, 126, 55, 96, 32, 10, 5};
  KSmallest(a,7,3);
  return 0;
}
// return
// 14 10 5
// T≈O(N), S=O(k)≈O(1)
