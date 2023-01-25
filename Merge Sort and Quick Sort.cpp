#include <iostream>
using namespace std;
////////////////////
/////Merge Sort/////
/// reference: https://www.geeksforgeeks.org/merge-sort/
/// Procedure: Divide an array into sub-arrays→sort each sub-arrays→merge the sorted sub-arrays together
  // Division: continuously divide the array into two-equal halves,until it can not be cut any more. Namely, when length of sub-array==0 or 1.
  // Merge: set i is the index of one sub-array and j is for another, compares the values of elements from two sub-arrays by traversing i and j from left to right
/// Time complexity: O(n logn), stable, fast, and easy
/// We can choose to create and copy new sub-arrays or not after the division. If we choose not to create new sub-arrays, we just simply treat them as independent arrays.
void mergeArrays(int x[],int y[],int a[],int start,int end){
  // find the midpoint
  int mid=(start+end)/2;
  //initialization
  int i=start;
  int j=mid+1;
  int n=start; //the index of original array
  //Comparison, Copy, and Moving
  while(i<=mid && j<=end){
    if(x[i]<y[j]){
      a[n]=x[i];
      i++;
      n++;
    }else{
      a[n]=y[j];
      j++;
      n++;
    }
  }
  // Copy the rest elements
  while(i<=mid){
    a[n]=x[i];
    i++;
    n++;
  }
  while(j<=end){
    a[n]=y[j];
    j++;
    n++;
  }
}

void mergeSort(int a[],int start,int end){
  // base case
  if(start>=end){ //means length=0 or 1
    return; 
  }
  // find the mid point 
  int mid=(start+end)/2;
  //the left half:create the new array and copy the elements from original one
  int x[100];
  for(int i=0;i<=mid;i++){ 
    x[i]=a[i];
  }
  // the right half
  int y[100];
  for(int i=mid+1;i<=end;i++){
    y[i]=a[i]; //the rest empty left part will be filled with garbage values
    // y[i-(mid+1)]=a[i]; //another way to copy beginning at the first index, without garbage values
  }
  //call the recursion
  mergeSort(x,start,mid);
  mergeSort(y,mid+1,end);
  mergeArrays(x,y,a,start,end);
}

int main(){
  int a[]={5,3,2,7,9,10,45,92};
  mergeSort(a,0,7);
  for(int i=0;i<8;i++){
    cout<<a[i]<<endl;
  }
  return 0;
}
// return:
// 2
// 3
// 5
// 7
// 9
// 10
// 45
// 92


////////////////////
/////Quick Sort/////
// reference:https://www.geeksforgeeks.org/quick-sort/
// pick an element as pivot and partitions the original array around the picked pivot
// Different position selection of pivot: first element, last element, midpoint, random element
  // Usually, we choose the last element as pivot.
// partition: put x(pivot element) to a correct position in a sorted array, put elements<x before x without sorting, put elements>x after x without sorting, then repeatedly apply quick sort procedures to sub-arrays until all elements are sorted.
int partition(int a[],int start,int end){
  int i=start;
  int pivot=a[end];
  for(int j=start;j<=end-1;j++){ //traversing from left to right except the pivot element
    if(a[j]<pivot){
      swap(a[i],a[j]);
      i++;
    }
  }
  swap(a[i],a[end]); //put pivot in the correct position
  return i; //this is the partition index p we need later
}

void quickSort(int a[],int start,int end){
  if(start>=end){
    return;
  }
  int p=partition(a,start,end); //the partition function will return the pivot index p
  quickSort(a,start,p-1); //call the quickSort for unsorted two partitions
  quickSort(a,p+1,end);
}

int main(){
  int a[]={2,4,9,14,45,6};
  quickSort(a,0,5); //call the function
  for(int i=0;i<6;i++){ //print
    cout<<a[i]<<" ";
  }
  return 0;
}
// return:
// 2 4 6 9 14 45
