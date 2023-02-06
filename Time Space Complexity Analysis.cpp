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

// Important Summarized Reference: https://www.bigocheatsheet.com/

/////Linear Search Time Complexity
// Best case: the key value presented at the first element, only comparison is needed. T=O(1)
// Worst case: element is not present in the array, with comparison and moving forward for every element using k time length. After ignoring constant k, T=O(n)
// Since we only consider the worst case, T=O(1) is abandoned. 

/////Selection Sort Time Complexity
//Working Logic: repeatedly selecting the smallest element from the unsorted portion of the list and moving it to the sorted portion. 
// T=kn+k(n-1)+k(n-2)+...+1=kn^2/2+kn/2=O(n^2), which is the same between the best and worst case.

/////Binary Search Time Complexity
// T=O(log n),using recursion, which is faster than linear search

/////Merge Sort Time Complexity
// T(N)=kN/2+kN/2+T(N/2)+T(N/2)+kN
  // KN/2:copy the first half elements to a new array
  // KN/2:copy the second half of elements to another new array
  // T(N/2):call the recursion 
  // kN:merge two sorted sub-arrays together with index i and j(comparison and arrange elements)
// T(N)=2T(N/2)+KN; T(N/2)=2(T/4)+KN/2; T(N/4)=2(T/8)+KN/4;...T(1)=k→T=knlogn, T=O(nlogn)
// Hence, merge sort is much faster than bubble sort/selection sort/insertion sort[T=O(n^2)].

/////Fibonacci Time Complexity
// T(n)=k+T(n-1)+T(n-2), which is tough to solve, and where k is basic constant work case time complexity
// We use `in-depth recursion` to solve the time complexity, the processes are listed below:
// n->n-1, n->n-2            //1 function call
/// n-1->n-2, n-1->n-3       //in this case, n-1 is the node, function call, each node is doing k amount of work, checking the basic case and calling the equation. 2 function call
/// n-2->n-3, n-2->n-4
//// n-2->n-3, n-2->n-4     //4 function call
//// n-3->n-4, n-3->n-5
//// n-3->n-4, n-3->n-5
//// n-4->n-5, n-4->n-6
// .........
// 1                       //finally evolute to the basic case
// PS: the length of evolution chain of left side=N, while, the length of evolution chain of right side=N/2
// Hence, T(N)=k* total number of node=k* total number of function call. 
// Namely, for the worst case, sum up 2^0+2^1+2^2+...+2^N=2^(N+1)-1
// T=k*(2*2^n)=O(2^N);(exponential), the running effect is horrible.


///////////////////////////////////
/////Space Complexity Analysis/////
// reference:https://www.simplilearn.com/tutorials/data-structure-tutorial/time-and-space-complexity#what_is_space_complexity
// Auxiliary Complexity: extra space or temporary space used by an algorithm.
// Space complexity: total space taken by the algorithm in terms of the `input size`.Or the `max` space required at any point of time during the executing program.Sometimes we need to consider `Recursion`.
// Space complexity includes input size and auxiliary.

/////Bubble Sort Space Complexity
// For auxiliary space, without considering input array, S=O(1),taking constant amount of space.

/////Binary Search Space Complexity
// For interactive case, we create midpoint,end, start, these few variables only,S=O(1)
// Recursive Case: element size taken consideration: N, N/2, N/4...,1. 
  // For each function, it requires k(constant amount) space.
  // At the final point,when recursion size comes to 1, the required amount of space up to the maximum.
  // Total number of function in call stack: logN
  // S=k*(logN)->S=O(logN)

/////Merge Sort Space Complexity
// divide array into two sub-array, then copy them, after recursion, merge them together
// N-> N/2 and N/2
/// N/2->N/4 and N/4
/// N/2->N/4 and N/4
//// N/4->N/8 and N/8
//// N/4->N/8 and N/8
//// N/4->N/8 and N/8
//// N/4->N/8 and N/8
// ......
// 1
// Call stack: N N/2 N/4 N/8....1, they are maximum number of function call in programming process, in total logN terms
// S=N+N/2+N/4...+k=O(N)

/////Fibonacci Space Complexity
// Recursion Call stack: max number of call function occur =N, space requires by each function is constant k
// S=k*N=O(N)

