/////////////////////////////////////
/////Selection Sorting Algorithm/////
// references: https://www.geeksforgeeks.org/selection-sort/
///Sorting:
// Kinds of Sorting: Selection,Bubble, Insertion, Bucket, Radix, Quick, Merge, Heap, Iterative, Counting sort...
// Defintion of Sorting: re-arrange elements according to using a comparison operator on the elements. Generally means sort in ascending order by default.
// Effect: to make the searching process faster

/// Selection Sorting:
// Definition: by repeatedly finding the smallest element from the unsorted part and putting it at the beginning. 
// Compared with the first element of unsorted elements and the remaining part's minimum, if min of remaining<first unsorted element,swap the position. Then continue the process...
// Stopping: After N (size of array) iteration we will get sorted array.
// Hence,there are two arrays emerge: sorted sub-array & unsorted sub-array
#include <iostream>
using namespace std;

void selectionSort(int a[], int n){
  for(int i=0;i<=n-2;i++){
    int smallest=i; //realized by swapping the index
    for(int j=i+1; j<=n-1; j++){ //n-1 is the last position
      if(a[j]<a[smallest]){
        smallest=j;
      }
    }
    if(a[i]>a[smallest]){
      swap(a[i],a[smallest]); 
    }
  }
}

int main(){
  //Input
  int n;
  cin>>n;
  int a[n];
  for(int i=0; i<n; i++){
    cin>>a[i];
  }
  //call the function
  selectionSort(a, n);
  //print  
  for(int i=0;i<n;i++){  
    cout<<a[i]<<" ";
  }

  return 0;
}
// return:
// 5
// 8 4 3 7 9
// 3 4 7 8 9