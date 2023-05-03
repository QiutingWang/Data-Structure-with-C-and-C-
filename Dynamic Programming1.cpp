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


/////////////////////////////////////////////
/////Minimum Steps to 1 Bottom Up Method/////
// the answer will be store in element at nth index in the array dp[n]
//dp[i]: the minimum steps needed to move from i to 1
int minSteps3(int n){
  //create and base case
  int *dp=new int[n+1];
  dp[0]=0;
  dp[1]=0;

  for(int i=2;i<=n; i++){
    int operation1=dp[i-1];
    int operation2=INT_MAX;
    int operation3=INT_MAX; 
    if(i%2==0){
      operation2=dp[i/2];
    }
    if(i%3==0){
      operation3=dp[i/3];
    }
    dp[i]=min(operation1,min(operation2,operation3))+1;
  }
  int ans = dp[n];
  delete []dp;
  return ans;
}

int main(){
  int n;
  cin>>n;
  cout<<minSteps3(n)<<endl;
  return 0;
}
// return 
// 7
// 3

// T=O(N), S=O(N)
///another writing syntax:
int minSteps3(int n){
  int *dp=new int[n+1];
  dp[0]=0;
  dp[1]=0;

  for(int i=2;i<=n; i++){
    dp[i]=dp[i-1]+1;
    if(i%2==0){
      dp[i]=min(dp[i],dp[i/2]+1); //compare the current minimum steps with dp[i/2]
    }
    if(i%3==0){
      dp[i]=min(dp[i],dp[i/3]+1);
    }
  }
  int ans = dp[n];
  delete []dp;
  return ans;
}


/////////////////////////
/////Climbing Stairs/////
// LeetCode No.70 https://leetcode.com/problems/climbing-stairs/
///// Recursive Approach
class Solution {
public:
    int countSteps(int n){
        if(n==0||n==1){
            return 1;
        }
        return countSteps(n-1)+countSteps(n-2);
    }
    int climbStairs(int n) {
        return countSteps(n);
    }
};


/////DP, only jump of 1 or jump of 2
class Solution {
public:
    int countSteps(int n){
        if(n==0||n==1){
            return 1;
        }
        return countSteps(n-1)+countSteps(n-2);
    }
    int climbStairs(int n) {
      //store in a newly created array
        int dp[n+1];
        dp[0]=1;
        dp[1]=1;
        for(int i=2; i<=n; i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};


/////DP Generalized, we can take jump of 1,2,...,or k steps at one time
class Solution {
public: 
    int countSteps(int n){
        if(n==0 || n==1){
            return 1;
        }
        return countSteps(n-1) + countSteps(n-2);
    }   
    int climbStairs(int n) {
        int k = 2;
        int dp[n+1];
        dp[0] = 1;
        for(int i=1;i<=n;i++){
            int ans = 0;
            for(int j=1; j<=k; j++){ //j means jump unit, which maximum unit is k.
                if(i-j>=0){
                  ans += dp[i-j];
                }
            }
            dp[i] = ans;
        }
        return dp[n]; 
    }
};
