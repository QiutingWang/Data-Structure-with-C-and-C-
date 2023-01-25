#include <iostream>
#include <sys/time.h>
using namespace std;
// reference:https://www.simplilearn.com/tutorials/data-structure-tutorial/time-and-space-complexity
// How to evaluate the good/bad solutions? Sometimes the solutions to one question are more than one.--We want the optimal solution with less computing time and memory required.
// Time is a function of input size, but not refer to actual time of machine running on the specific algorithm.
  // Two ways to find the time complexity: experimental & theoretical method.

///////////////////////////////
/////Experimental Analysis/////
// Defintion: write the code for the algorithm, run it with different input size, note down the time taken, plot the graph to show the relationship between input length and time 
long getTimeInMicroSeconds(){ //use inbuilt function
	struct timeval currentTime;
	gettimeofday(&currentTime, NULL);
	return currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;
}

void mergeArrays(int x[],int y[],int a[],int s,int e){
       int mid = (s+e)/2;
       int i=s;
       int j = mid+1;
       int k = s;
       while(i<=mid && j<=e){
           if(x[i] < y[j]){
            a[k] = x[i];
            i++;
            k++;
           }else{
             a[k] = y[j];
             j++;
             k++;
           }
       }
       while(i<=mid){
        a[k] = x[i];
        k++;
        i++;
       }
       while(j<=e){
        a[k] = y[j];
        k++;
        j++;
       }
}
int *x = new int[10000000];
int *y = new int[10000000];

void mergeSort(int a[],int s,int e){
    if(s>=e){
        return;
    }
    int mid = (s+e)/2;
    for(int i=s;i<=mid;i++){
        x[i] = a[i];
    }
    for(int i=mid+1;i<=e;i++){
        y[i] = a[i];
    }
    mergeSort(x,s,mid);
    mergeSort(y,mid+1,e);
    mergeArrays(x,y,a,s,e);
}

void selectionSort(int a[],int n){
    for(int i=0;i<=n-2;i++){
        int smallest = i;
        for(int j=i+1;j<=n-1;j++){
            if(a[j]<a[smallest]){
                smallest = j;
            }
        }
        swap(a[i],a[smallest]);
    }
}

int main(){
  for(int n=10;n<=10000000; n *= 10){
    int *arr = new int[n];
    long startTime , endTime;
    for(int i=0;i<n;i++){
        arr[i] = n-i; //input the array
    }
    startTime = getTimeInMicroSeconds(); //return the current time
    ///mergeSort(arr,0,n-1);
    selectionSort(arr,n);
    endTime = getTimeInMicroSeconds();
    ///cout<<"Merge sort n = "<<n<<" time = "<<endTime-startTime<<endl;
    cout<<"Selection sort n = "<<n<<" time = "<<endTime-startTime<<endl;
    delete []arr;
  }
  return 0;
}
// return:
// Selection sort n = 10 time = 1
// Selection sort n = 100 time = 18
// Selection sort n = 1000 time = 1573
// Selection sort n = 10000 time = 306338
// Selection sort n = 100000 time = 30898953...

// Merge sort n = 10 time = 1
// Merge sort n = 100 time = 13
// Merge sort n = 1000 time = 139
// Merge sort n = 10000 time = 2015
// Merge sort n = 100000 time = 20923
// Merge sort n = 1000000 time = 520512
// Merge sort n = 10000000 time = 6366837

// As the return shows, merge sort is much faster than selection sort.


//////////////////////////////
/////Theoretical Analysis/////
// reference:https://www.freecodecamp.org/news/big-o-notation-why-it-matters-and-why-it-doesnt-1674cfa8a23c/
// https://zerotomastery.io/cheatsheets/big-o-cheat-sheet/
///The problems of Experimental Analysis: 
// if we have 10 ways to solve one problem, we need to code each of them... The workload is heavy and process is painful. Besides, it is difficult to figure out the function about input size.
// Time consuming(like the above case we try the selection sort)
///Defintion of Theoretical Analysis:
// Without coding, we can tell which solution is optimal.
/// Big O notation:O(), describes the upper bound of the complexity. We do not care about coefficient and focus on highest power.Drop none domaine term
// Constant: O(1)
// Linear time: O(n)
// Logarithmic time: O(n log n)
// Quadratic time: O(n^2)
// Exponential time: O(2^n)
// Factorial time: O(n!)

/// Other notation:
// Ω(),describes the lower bound of the complexity.
// Θ(), describes the exact bound of the complexity.
// o(), describes the upper bound excluding the exact bound.




