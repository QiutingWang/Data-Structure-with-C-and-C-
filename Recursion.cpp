#include<bits/stdc++.h>
using namespace std;

///////////////////
/////Recursion/////
//Definition: when a function is call itself
// main()->A()->A()...
// We use it when the solution of a problem depends on the solution of a smaller problem with the same nature but a different input size
// Example: fact(N)=n*fact(N-1) to compute n!
int fact(int n){
  cout<<n<<endl;
  if (n==0) return 1; //to make a finite recursion without running out of memories.
  int smallAns=fact(n-1);
  return n*smallAns;
}

int main(){
  int n;
  cin>>n;
  int ans=fact(n);
  cout<<ans<<endl; 
  return 0;
}
// return:24 if we set input==4

//cout: standard output stream, predefined object of ostream class, with stream insertion operator (<<) to display the output on a console
// cin: standard input stream, with stream extraction operator >> to read the input from a console
// endl: standard end line,  used to insert a new line characters and flushes the stream.
// Call Stack: main()->fact(4)->fact(3)->...->fact(0) then once return the ans, the corresponding fact(n) function goes out of the memory. The goes out order is reverse:fact(0),fact(1)...,fact(4),main()


///////////////////////////
/////Recursion and pmi/////
// Principle of Mathematical Induction(PMI):used to prove facts
int fact(int n){
  ///first case:base case
  if (n==0){
    return 1;
  }
  int smallAns=fact(n-1); //second step:Assumption, recursive case(Induction Hypothesis)
  int ans=n*smallAns; //third step: Calculation to prove step 2 and step1
  return ans;
}
int main(){
  cout<<fact(4)<<endl;
  return 0;
}
// return:24

///////////////////////////
/////Fibonacci Numbers/////
// Sequence Fn: each number is the sum of the two preceding ones. 0 1 1 2 3 5 8 13 ... Assume the first two numbers 0 and 1 are fixed.
// https://en.wikipedia.org/wiki/Fibonacci_number
// This part, our goal is to find Fibonacci numbers
// Equation: F(n)=F(n-1)+F(n-2)
// If want to solve the bigger problem, we first come to the smaller problem

#include <iostream>  //A header: processing directive, want to use object from this library.<iosteam> library to handle input and output
using namespace std;  //std: standard, the cout is part of a collection of names called standard namespace

int fib(int n){
  ///Base Case:the first fixed numbers
  if (n==0){
    return 0;
  }
  if (n==1){
    return 1;
  }
  ///Recursive Case
  int smallerOutput1=fib(n-1);
  int smallerOutput2=fib(n-2);
  ///Calculation
  return smallerOutput1+smallerOutput2;
}
int main(){      //declare the function called main, all C++programs should contain this to be executable
  cout<< fib(6);
  return(0);
}
//return:8

///////////////
/////Power/////
// X^n = X*X^(n-1)
// pow(x,n) = pow(x, n-1)* x

int power(int x,int n){      //define the variable name with variable type declaration: int. It is a must for statically-typed language
  ///Base case: X^0=1
  if (n==0){
    return 1;
  }
  ///Recursive Case
  int smallOutput=power(x, n-1);
  ///Calculation
  return smallOutput*x;
}
int main(){
  cout<<power(5,3);
  return 0;
}
//return: 125
