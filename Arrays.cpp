/////////////////////////////
/////Arrays Introduction/////
// https://cplusplus.com/doc/tutorial/arrays/
// can be individually referenced by adding an index to a unique identifier, starting from 0.
// Typical declaration for an array: type name [elements];

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
//If we defined less,the remaining elements are set to their default values 
int main(){
  int a[4]={1,2,3,4}; //Initialization
  cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<endl; //Printing Values
  return 0;
}
//1 2 3 4

