#include <iostream>
#include <cmath>
#include <limits.h>
using namespace std;
//////////////////////////////////
/////Introduction & Fibonacci/////
// reference: https://www.geeksforgeeks.org/introduction-to-dynamic-programming-data-structures-and-algorithm-tutorials/
// Fibonacci number with recursion method:
int fib(int n){
  if(n==0||n==1){
    return n;
  }
  return fib(n-1)+fib(n-2);
}

int main(){
  int n;
  cin>>n;
  cout<<fib(n)<<endl;
  return 0;
}
//Problem: this method gets a slow computational speed with T=O(2^n)

// Using dynamic programming method:  
  // store the results of subproblems so that we do not have to re-compute them when needed later.
  // it reduces time complexities from exponential to polynomial.
  // the number of unique number calls will be n only
  // 🌟procedure:
    // create an array which initialized filling with 0, whose size=n. Namely, we have n+1 elements with value =0
    // as soon as we calculate the ith fibonacci number, we store the value at ith index in the array.
      // if at ith index of array has been already solved and filled, then we can simply reuse this stored value, recalculation is not needed.
int fib(int n){
  if(n==0||n==1){
    return n;
  }
  return fib(n-1)+fib(n-2);
}

int fib2(int n,int *arr){
  if(n==0||n==1){
    return n;
  }
  if(arr[n]!=0){ //we have already solved the answer
    return arr[n];
  }
  //if we haven't ever calculated the fib before
  int output=fib2(n-1,arr)+fib2(n-2,arr);
  arr[n]=output; //store the output for future use
  return output; //return the output
}
// for method2 we first calls back from the last element to the first element of the array, then fills the array with calculated values from left to right.
// T=O(2N)=O(N) for fib2

int fib3(int n){
  int *arr=new int(n+1);
  arr[0]=0;
  arr[1]=1;
  for(int i=2;i<=n;i++){
    arr[i]=arr[i-1]+arr[i-2];
  }
  int output=arr[n];
  delete []arr;
  return output;
}
// only traversal for single direction, T=O(N) in fib3

int main(){
  int n;
  cin>>n;
  cout<<fib(n)<<endl;
  //construct an array initialized filling with 0s.
  int *arr=new int[n+1];
  for(int i=0;i<=n;i++){
    arr[i]=0;
  }
  cout<<fib2(n,arr)<<endl;
  cout<<fib3(n)<<endl;
  return 0;

  delete []arr;
}
// return
// 35
// 9227465
// 9227465
// 9227465


////////////////////////////
/////Minimum Steps to 1/////
// 3 operations to find the minimum steps from n to 1
  // decrement by 1
  // divide by 2, if n%2=0
  // divide by 3, if n%3=0
// 🌟Procedures:
  // recursion, check whether it exists overlapping which contains solutions we need to calculate many times
  // memorization: top-down DP, array to store the calculation
  // Bottom-up DP->iterative


////////////////////////////////////////////////
/////Minimum Steps to 1: Brute Force Method/////
int minSteps(int n){
  //base case
  if(n<=1){
    return 0;
  }
  //recursive
  int operation1=minSteps(n-1);
  int operation2=INT_MAX,operation3=INT_MAX; //initialization for avoiding garbage values storage.
  if(n%2==0){
    operation2=minSteps(n/2);
  }
  if(n%3==0){
    operation3=minSteps(n/3);
  }
  //calculate the answer
  int ans=min(operation1,min(operation2,operation3))+1; 
  return ans;
}

int main(){
  int n;
  cin>>n;
  cout<<minSteps(n)<<endl;
  return 0;
}
// return 
// 7
// 3


//////////////////////////////////////////
/////Minimum Steps to 1: Memorization/////
int helper(int n, int *ans){
  if(n<=1){
    return 0;
  }
  if(ans[n]!=-1){ //if the output has been calculated before
    return ans[n];
  }
  //recursive
  int operation1=helper(n-1, ans);
  int operation2=INT_MAX,operation3=INT_MAX; //initialization for avoiding garbage values storage.
  if(n%2==0){
    operation2=helper(n/2, ans);
  }
  if(n%3==0){
    operation3=helper(n/3, ans);
  }
  //calculate the answer
  int output=min(operation1,min(operation2,operation3))+1; 
  //save answer for future use
  ans[n]=output;
  return output;
}

int minSteps2(int n){
  int *ans=new int[n+1];
  for(int i=0;i<=n;i++){
    ans[i]=-1; //initialized with invalid value
  }
  return helper(n, ans);
}

int main(){
  int n;
  cin>>n;
  cout<<minSteps2(n)<<endl;
  return 0;
}
// return
// 7
// 3




