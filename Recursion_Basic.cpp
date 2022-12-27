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


///////////////////////
/////Print Numbers/////
// print(n): print numbers from 1 to n
// print(n)=print(n-1)+n
#include <iostream>
using namespace std;

void print(int n){  //special type void indicates: the function does not return a value.
  ///Base Case
  if(n==0){
    return; //do not print anything, cuz we begin from 1
  }
  ///Recursive Case
  print(n-1); //this will print 1,2,...,n-1
  ///Calculation
  cout<<n<<endl;
  return;
}
int main(){
  print(5);
  return 0;
}
// return:
// 1
// 2
// 3
// 4
// 5

// The results show the order is an ascending. What about a descending order?
void print2(int n){ 
  ///Base Case
  if(n==0){
    return; //mandatory
  }
  
  cout<<n<<endl;
  print2(n-1); //print from n-1,n-2,...,1
  return;
}
int main(){
  print2(5);
  return 0;
}
// return:
// 5
// 4
// 3
// 2
// 1

/////Additional Defintion--Void Pointer: void*
  //If the pointer type is void, it is universal and can point to any variable that's not declared with the const or volatile keyword.Can point to a free function,or to a static member function, but not to a non-static member function. A void pointer has no associated data type with it. 
  // Disadvantages: the data pointed to by them cannot be directly dereferenced. Hence,any address in a void pointer needs to be transformed into other pointer type that points to a concrete data type before being dereferenced.
/////Part of Pointer Definition:
// https://cplusplus.com/doc/tutorial/pointers/
// Each variable lives at a particular address in C++, the first address is 0.
// &: the address of operator. &x: the address of x variable, and must to be a number.
// int *p: * specifies p is a pointer to an int, meaning that we can assign to p the address of int.
// *: pointer dereferencing operator, to access memory via a pointer.
// The * operator is the inverse of & operator.


//////////////////////
/////Count Digits/////
// Function: count(n)=count(n/10)+1 ,n is nature number
int count(int n){
  ///Base case
  if(n==0){
    return 0;
  }
  ///Recursive Case
  int smallAns=count(n/10);
  ///Calculation
  return smallAns+1;
}
int main(){
  cout<<count(1865)<<endl;
  return 0;
}
//return: 4;


///////////////////////
/////Sum of Digits/////
//Add all digits of value n eg:n=12345 ⇒15
//Function: sum(n)=sum(n/10)+ last_digit
int sum(int n){
  ///Base case
  if (n==0){
    return 0;
  }
  ///Recursive Case
  int smallAns=sum(n/10);
  ///Calculation:find out the last digit first
  int last_digit = n%10; //%: modulus
  return smallAns+last_digit;
}
int main(){
  cout<<sum(123456789)<<endl;
  return 0;
}
//return:45


////////////////////////
/////Multiplication/////
//m*n if we only use + or -
//m*n=m+m+...+m for n times
//Function: m*n=m*(n-1) + m
#include <iostream>;
using namespace std;

int multiply(int m,int n){
  ///Base Case
  if (n==0){
    return 0;
  }
  ///Recursive Case
  int smallAns=multiply(m,n-1);
  ///Calculation
  return m+smallAns;
}
int main(){
  cout<<multiply(3,5);
  return 0;
}
//return:15


//////////////////////
/////Count Zeros/////
//Count how many zeros in the presented number, if n≥0;
//Function:countZeros(n)=countZeros(n/10),then check if (lastDigit=0)->smallAns+1; else ->smallAns.
int countZeros(int n){
  ///Base Case
  if (n==0){
  return 0;
  }
  ///Recursive Case
  int smallAns=countZeros(n/10);
  ///Calculation
  int lastDigit= n%10;
  if (lastDigit==0){
    return smallAns+1;
  } else{
    return smallAns;
  }
}
int main(){
  cout<<countZeros(20000917); 
  return 0;
}
//return: 4

/////Additional Concepts: long type in C++
// the long is a larger data type than int.(int:32bits, long:64bits) stored as numbers ranging in value from -2,147,483,648 to 2,147,483,647.  
// Use & to declare the long type


///////////////////////
/////Geometric Sum/////
// Example: given k=3, then we need to calculate 1+ 1/2 + 1/(2^2) + 1/(2^3).
// References: https://www.mathsisfun.com/algebra/sequences-sums-geometric.html
// In a Geometric Sequence each term is found by multiplying the previous term by a constant.
// In general, the sequence is {a, ar, ar^2, ar^3, ...,ar^k }. r: common ratio, a: the first term
// Function: GeoSum(k)= GeoSum(k-1) + power(r,k)
int power(int x,int n){     
  ///Base case: X^0=1
  if (n==0){
    return 1;
  }
  ///Recursive Case
  int smallOutput=power(x, n-1);
  ///Calculation
  return smallOutput*x;
}

double geoSum(int k){
  ///Base Case
  if (k==0){
    return 1;
  }
  ///Recursive Case
  double smallAns=geoSum(k-1);
  ///Calculation
  return smallAns + 1.0/power(2,k); //use the function we defined at first
}
int main(){
  cout<<geoSum(5);
  return 0;
}
//return: 1.96875

/////Additional Concepts: double type in C++
// a versatile data type that can represent any numerical value in the compiler, including decimal values. It can contain numbers till 15 digits.
// can be treated as one kind of float data type
