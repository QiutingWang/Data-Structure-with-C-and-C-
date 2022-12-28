/////////////////////////////
/////Arrays Introduction/////
// https://cplusplus.com/doc/tutorial/arrays/
// can be individually referenced by adding an index to a unique identifier, starting from 0.
// Typical declaration for an array: type name [elements];
// We must give a size to the array.

///Initialization 
#include<iostream>
using namespace std;

int main(){
  int a[10]; //we will get 10 boxes in the contiguous manner,each of size= 4 bits, each box contain one integer
  a[0]=2;
  a[4]=5;
  cout<<a[0]<<" "<<a[4]<<endl;
  return 0; 
}
//return:2 5
///explicitly initialized to specific values when it is declared by using {}
//The number of values between braces {} shall not be greater than the number of elements in the array.
//If we defined less,the remaining elements are set to their default values, normally is 0.
int main(){
  int a[4]={1,2,3,4}; //Initialization
  cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<endl; //Printing Values
  return 0;
}
//1 2 3 4

/////Using For Loop Method to print
int main(){
  int a[4]={1,2,3,4}; //Initialization
  for (int i=0;i<4;i++){ //use for loop to print the element in the array
    cout<<a[i]<<" ";
  }
  return 0;
}
// Return:1 2 3 4
// If we change n=10,a[10]={1,2,3,4}, then return will be 1 2 3 4 0 0 0 0 0 0 .

/////Garbage Value:
int main(){
  int a[10];
  for (int i=0;i<10;i++){
    cout<<a[i]<<" ";
  }
  return 0;
}
// return:-975731992 32555 1813295776 21903 0 0 1813295328 21903 -1456338944 32767 

// Another Example with garbage value:
int main(){
  int a[10];
  for (int i=0;i<10;i++){
    a[i]=i*i;
    cout<<a[i]<<" ";
  }
  return 0;
}
// return:0 1 4 9 16 25 36 49 64 81 

/////sizeof 
int main(){
  int b;
  cout<<sizeof(b)<<endl;
}

//return: 4 bits
int main(){
  int d[10]={1,2,3};
  cout<<sizeof(d)<<endl;
} 
//return:40 bits

///Concept: For Loop
// for (statement1, statement2, statement3){
  ///code block to be executed;
// }
// Statement1: executed once before the execution of block;(init)
// Statement2: defines the condition for executing the code block.(condition)
// Statement3:  executed (every time) after the code block has been executed.(increment)


///////////////////////////////
/////Sum of Array Elements/////
int main(){
  cout<<'Enter the number of elements'<<endl;
  int n;
  cin>>n;

  int a[n];
  ///input
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  ///print every element before the summation:
  for (int i=0; i<n; i++){
    cout<<a[i]<<" ";
  }
  cout<<endl;
  
  /// Calculation:
  int sum=0;
  for (int i=0; i<n; i++){
    sum += a[i]; //+=:  adds the value of the right operand to a variable and assigns the result to the variable.
  }
  cout<<sum<<endl;
  return 0;
}
//return:
// 3
// 1 2 3(input with keyboard)
// 1 2 3(print the elements)
// 6(calculation result)

/////Concept: cin
// a standard input stream with >> extraction operator.
// A stream is an entity where a program can either insert or extract characters to/from. 
// extracts from cin a value to be stored in it, the program will wait for the user to enter some sequence from the keyboard.


//////////////////////////////////
/////Largest Element in Array/////
#include <climits>
int main(){
  int n;
  cin>>n;                //input the size of array
  int a[n];
  for (int i=0; i<n; i++){
    cin>>a[i];           //input the array
  }

  int largest=INT_MIN;   //INT_MIN: -∞
  int smallest =INT_MAX; //INT_MAX: +∞
  for (int i=0; i<n; i++){
    if (a[i] > largest){ //compare the current value with the largest value
      largest = a[i];
    }
    if (a[i]<smallest){
      smallest=a[i];
    }
  }
  cout<<largest<<endl;
  cout<<smallest<<endl;
  return 0;
}
//return: 
// 3
// 6 9 7
// 9
// 6
/////Find the smallest value? change if(a[i]<smallest), and int smallest=INT_MAX in the settings


//////////////////////////
/////Swap Two Numbers/////
// Task: Given 2 numbers in a and b, swap them.
// Process: copy the value in a to temp, copy the value of b to a, copy the value in temp to b;
int main(){
  int a,b;
  cin>>a>>b;

  cout<<"before swapping"<<endl;   // '' and " " are different is usage in C++
  cout<<"a = "<<a<<endl;
  cout<<"b = "<<b<<endl;

  int temp= a;
  a=b;
  b=temp;

  cout<<"after swapping"<<endl;
  cout<<"a = "<<a<<endl;
  cout<<"b = "<<b<<endl;

  return 0;
}
// return:
// 1
// 2
// before swapping
// a = 1
// b = 2
// after swapping
// a = 2
// b = 1

/////Another method use ^: XOR--Bitwise exclusive OR
int main(){
  int a,b;
  cin>>a>>b;

  cout<<"before swapping"<<endl;   // '' and " " are different is usage in C++
  cout<<"a = "<<a<<endl;
  cout<<"b = "<<b<<endl;

  a = a^b;
  b = a^b;
  a = a^b;

  cout<<"after swapping"<<endl;
  cout<<"a = "<<a<<endl;
  cout<<"b = "<<b<<endl;

  return 0;
}
// return:
// 8
// 9
// before swapping
// a = 8
// b = 9
// after swapping
// a = 9
// b = 8

/////Another method use swap(a,b), the most simplest way
int main(){
  int a,b;
  cin>>a>>b;

  cout<<"before swapping"<<endl;   // '' and " " are different is usage in C++
  cout<<"a = "<<a<<endl;
  cout<<"b = "<<b<<endl;

  swap(a,b);

  cout<<"after swapping"<<endl;
  cout<<"a = "<<a<<endl;
  cout<<"b = "<<b<<endl;

  return 0;
}
// return:
// 5
// 6
// before swapping
// a = 5
// b = 6
// after swapping
// a = 6
// b = 5
