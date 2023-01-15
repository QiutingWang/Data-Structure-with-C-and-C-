#include<bits/stdc.h>
using namespace std;
/////////////////////////////////
/////Linear Search Algorithm/////
//How to search for a given key/value in array?
// Scan the array from left to right from index 0 to index n-1, until it finds the specific element in the array.
int linearSearch(int a[], int n, int key){
  for(int i=0;i<n;i++){
    if(a[i]==key){
      return i;
    }
  }
  return -1; //if the given key not present, then return the default invalid index.
}
int main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  cout<<"Enter key:"<<endl;
  int key;
  cin>>key; //the element we want to search

  int position=linearSearch(a,n,key);

  if(position==-1){
    cout<<"Key not found"<<endl;
  }else{
    cout<<"Key found at index"<<position<<endl;
  }
  return 0;
}
// return 
// 5
// 11 9 4 7 35
// Enter key:
// 35
// Key found at index4

///Time Complexity:O(n)

/////Problem with Linear Search:
// only required linear scan of an array, without considering the array sorted or not.
// Hence,the time complexity cannot be optimized.(Ideally, if the given array is sorted, we consider the time complexity to be O(logn))


/////////////////////////////////
/////Binary Search Algorithm/////
// Search in logn steps for sorted arrays.(Time Complexity)
// It can only be applied when the arrays are sorted.If the array is unsorted, binary search cannot apply, linear search is the only choice.
// Logic:repeatedly dividing the search interval in half. 
  // Sort the array in ascending order.
  // Set the start point and end point,then set the middle point
  // if the middle element is key, return the middle index.
  // if the key<middle,re-set the end index=middle index-1.(the key will be presented in the left side)
  // if the key>middle,re-set the start index=middle index +1()the key will be presented in the right side)
  // repeat,until the third step occurs
  // If the key not exists in array, the result will be start index>end index in repeated process, which is obviously wrong condition.
// Each time the search space is 1/2 of that of last time. N elements→N/2 elements→N/4 elements→...(N/2^k)elements, where k is the number of process repeated.
  // When (N/2^k)=1, the process stop repeating.In this case, k=log_2(N).(Time Complexity)
// Two Ways:Iterative & Recursive Methods
int binarySearch(int a[], int n, int key){
  int start=0, end=n-1;
  while(start<=end){
    int middle=/*(start+end)/2;*/ start+(start-end)/2; //with optimization
    //3 conditions
    if(a[middle]==key){
      return middle;
    }else if(a[middle]>key){
      end=middle-1;
    }else{
      start=middle+1;
    }
  }
  return -1; //when the given key is not present
}

int main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  cout<<"Enter key:"<<endl;
  int key;
  cin>>key; 
  sort(a,a+n);
  int position=binarySearch(a,n,key);
  if(position==-1){
    cout<<"Key not found"<<endl;
  }else{
    cout<<"Key found at index"<<position<<endl;
  }
  return 0;
}
// return:
// 7
// 15 56 72 6 108 44 96
// Enter key:
// 44
// Key found at index2

/////Optimization
// if both start and end values are extremely big, then the situation start+end>INT_MAX will happen.
  //Integer overflow(crossing the maximum value), wrap around will be taken place, it will cause running time error
    // Solution to avoid: (start+end)2→start+(end-start)/2; in the function
// Integer underflow(beyond the minimum value), the situation start+end<INT_MIN will happen.
