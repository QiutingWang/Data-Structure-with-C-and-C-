#include<iostream>
using namespace std;
//////////////////////////////////
/////Check if Array is Sorted/////
// There are 2 ways of breaking our array: from left to right & from right to left
// in recursive method, if we initialize the function return type is boolean, for the base case, we need to discuss situations for true and false.

/////From left to right
bool isSorted(int a[], int n){
  //Base case
  if(n==0 || n==1){
    return true;
  }
  //Comparison
  if(a[0]>a[1]){
    return false;
  } 
  //Recursive
  bool isSmallerSorted=isSorted(a+1, n-1); //call the function
  //Calculation Procedure
  if(isSmallerSorted){ 
    return true;
  }else{
    return false;
  }
  //Another way:
  /*return isSmallerSorted;*/
  //OR
  /*return isSorted(a+1, n-1);*/
}

///Another check logic:
bool isSorted2(int a[], int n){
  //Base Case
  if(n==0 || n==1){
    return true;
  }
  bool isSmallerSorted=isSorted(a+1, n-1);
  if(!isSmallerSorted){
    return false;
  }
  if(a[0]>a[1]){
    return false;
  }else{
    return true;
  }
}

/////From right to left sequence
bool isSorted3(int a[],int n){
  if(n==0||n==1){
    return true;
  }
  if(a[n-2]>a[n-1]){
    return false;
  }
  return isSorted3(a,n-1); //treat the last element as starting points, then if another n-1elements are sorted,then the whole array is sorted
}

int main(){
  // int a[]={1,2,3,4,5};
  int a[]={1,2,3,5,4};
  if(isSorted/*isSorted2*//*isSorted3*/(a,5)){ //call and print 
    cout<<"Sorted"<<endl;
  }else{
    cout<<"Not Sorted"<<endl;
  }
  return 0;
}
// return:
// Sorted
// Not Sorted


//////////////////////
/////Sum of Array/////
// Other methods can use loop, accumulation
///Case1: Divide array from left to right
int sumOfArray(int a[], int n){
  // Base Case
  if(n==0){
    return 0;
  }
  // Recursion, Call the rest of the array
  return a[0]+sumOfArray(a+1, n-1); //repeatedly divide array into two sub-array: a and a+1,until break the final a+1 sub-array with size=0
  // a+1 referring to the pointer to the element just after a[0].
}

///Another writing format for Case1 without passing area, we use index to express the two sub-arrays
// A useful trick and easy to understand
int sumOfArray3(int a[], int n, int i){
  if(i==n){
    return 0;
  }
  return a[i]+sumOfArray3(a, n, i+1); //repeatedly pass the value of i in different position of the array changing from right to left
}

///Case2: Divide array from right to left
int sumOfArray2(int a[],int n){
  if(n==0){
    return 0;
  }
  return a[n-1]+sumOfArray2(a,n-1);
}

int main(){
  int a[]={1,2,3,4,5};
  cout<<sumOfArray/*sumOfArray2*//*sumOfArray3*/(a,5/*,0*/)<<endl;
  return 0;
}
// return:
// 15
/// Procedure: 0+5+4+3+2+1(Case1)
/// Procedure: 0+1+2+3+4+5(Case2)


/////////////////////////////////////
/////Check if element is present/////
///Case1: traversing the array from right to left
// Method1: first check,then calling
bool isPresent(int a[],int n,int x){ //x: the value we want to find out
   if(n==0){
    return false;
   }
   if(a[0]==x){
    return true;
   }
   return isPresent(a+1,n-1,x); //for the recursive case, we only need to consider the rest of array
  //  check whether the first element of the remaining array ==x.
}

// Method2: first calling,then check the first element.
bool isPresent2(int a[],int n,int x){ 
   if(n==0){
    return false;
   }
   bool remainingArray=isPresent2(a+1,n-1,x); 
   if(remainingArray){  //if remainingArray is true, the return true
    return true;
   }
   if(a[0]==x){
    return true;
   }else{
    return false;
   }
}

// Method3: index i approach
bool isPresent4(int a[],int n, int x,int i){
  if(i==n){ //if the i is the last index out of bound or it is empty
  return false;
  }
  if(a[i]=x){
    return true;
  }
  return isPresent4(a,n,x,i+1); //if it is not found, use i+1: moving i ahead to next position, similar to for-loop i++
}

///Case2: traversing the array from left to right
bool isPresent3(int a[],int n,int x){ 
   if(n==0){
    return false;
   }
   if(a[n-1]==x){ //check the last element 
    return true;
   }
   return isPresent3(a,n-1,x); 
}

int main(){
  int a[]={1,2,3,4,5};
  if(isPresent/*isPresent2*//*isPresent3*//*isPresent4*/(a,5,2)){
    cout<<"Found"<<endl;
  }else{
    cout<<"Not Found"<<endl;
  }
  return 0;
}
// return:
// Found