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

//Time Complexity for selection sort: O(n^2)


///////////////////////////////
/////Bubble Sort Algorithm/////
// repeatedly swapping the adjacent elements if they are in the wrong order.
// Not suitable for large dataset, the time complexity is high
// do N-1 times bubble sort process, comparing neighbor elements, swapping and forming new arrays. N=number of elements in array
  //That because if we sort N numbers, we need N-1 numbers to be sorted, then the last element will also automatically be in the correct position
  // During the N-1 new arrays formation process, for nth formed array, the nth largest value is put into the correct position. The elements get sorted from left to right.
  //Component: unsorted sub-array+sorted sub-array sequence in N-1 new formed arrays, which have different inside order compared with selection sorting process.
void bubbleSort(int a[], int n){
  for(int count=1;count<=n-1;count++){
    for(int j=0;j<=n-2;j++){
      if(a[j]>a[j+1]){ //compared with adjacent elements
        swap(a[j],a[j+1]);
      }
    }
  }
}

int main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }

  bubbleSort(a,n);
  for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
  }
  return 0;
}
// return:
// 4
// 34 57 30 66
// 30 34 57 66

//Time Complexity for bubble sort:O(n^2). Number of steps for your program toke to execute.One of the algorithm evaluation metric, the less, the better.


/////////////////////////////////////////
/////Optimized Bubble Sort Algorithm/////
// If the array is unsorted, it will take n^2 steps. If the array is sorted, it will take n steps, with comparison but no swapping.
void bubbleSort(int a[], int n){
  for(int count=1;count<=n-1;count++){
    int flag=0;   //dummy variable flage to identify whether the swap process have been sorted or not.
    for(int j=0;j<=n-2;j++){
      if(a[j]>a[j+1]){ //compared with adjacent elements
        swap(a[j],a[j+1]);
        flag=1;
      }
    }
    if(flag==0){  //means the array is already sorted
      break; //come out of the loop
    }
  }
}

int main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }

  bubbleSort(a,n);
  for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
  }
  return 0;
}
//Time Complexity: O(n)
// return
// 5
// 1 2 3 4 5
// 1 2 3 4 5


//////////////////////////////////////////////////////
/////Inbuilt Sort: Standard Template Library(STL)/////
#include <algorithm> //sort function defined in this library
int main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  
  sort(a,a+n);

  for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
  }
  return 0;
}
// return
// 5
// 8 6 3 5 2
// 2 3 5 6 8 
///Master header files: #include<bits/stdc++.h> all the header files will included in C++ file.
