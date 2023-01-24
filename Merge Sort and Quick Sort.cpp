#include <iostream>
using namespace std;
/////////////////////////////////
/////Merge Sort Introduction/////
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
