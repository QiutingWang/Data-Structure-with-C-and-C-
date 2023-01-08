#include <iostream>
#include "OOPAdvanceClass.cpp"
using namespace std;

///////////////////////////////
/////Shallow and Deep Copy/////
// reference:https://www.geeksforgeeks.org/shallow-copy-and-deep-copy-in-c/
// Similarity:an object is created by copying the data of all variables of the original object;
/////Shallow Copy:
// both objects share the same memory location in heap section,then change made by one reflects change in another object;
/////Deep Copy:
// copy the entire area, both objects stored in different locations, then we should define the copy constructor and assign dynamic memory
int main(){
  char name[]="Clark";
  Student s1(20, name);
  s1.display();
  name[4]='e';
  Student s2(30,name); 
  s2.display();
  s1.display();
  return 0;
}
// return: S  D
// Clark 20  Clark 20
// Clare 30  Clare 30
// Clare 20  Clark 20


//////////////////////////////
/////Own Copy Constructor/////
// do deep copy: a user-defined copy constructor
// make sure the pointers of copied objects point to new memory locations.
// As soon as we create out own copy constructor, the inbuilt constructor does not effective anymore.
int main(){
  char name[]="Eva";
  Student s3(22, name);
  s3.display();

  Student s4(s3); //Copy constructor called, shallow copy
  s4.name[2]='e';   
  s3.display();
  s4.display();
  return 0;
}
//return: S❌      D✅
//     Eva 22     Eva 22
//     Eve 22     Eva 22
//     Eve 22     Eve 22

/////Pass by Reference:
//pass the reference of an argument in the calling function to the corresponding formal parameter of the called function.
//Changes to these variables in the function will affect the originals.
// No copy is made, so the address of local parameter is still the original argument stored in 
// with & symbol
// reference:https://www.cs.fsu.edu/~myers/c++/notes/references.html


/////////////////////////////
/////Initialization List/////
// reference:https://www.geeksforgeeks.org/when-do-we-use-initializer-list-in-c/
//  The list of members to be initialized is indicated with constructor as a comma-separated list followed by a colon. 
// Aim: initalized the const/normal/reference variables as the time of memory allocation.

/////Reference Variable: 
// one that refers to the address of another variable
// variable is declared preceded with & symbol, and can not be updated ,treated as internal pointer.
// a pointer can be declared as void, but reference cannot.
// pointer can have multiple levels of direction, while reference can only have single indirection.
int main(){
  Student1 s5(100,10);      //if we set Student1 s5; the two variables both contain garbage values
  s5.age1=10;  
  // s5.rollNumber=100; //over-writing the garbage value, but it is a constant, once we create a value, we can not change it.
  return 0;
}

//Another Example:
int main() {
  Point t1(10, 15);
  cout<<"x = "<<t1.getX()<<", ";
  cout<<"y = "<<t1.getY();
  return 0;
}
// return:
// x = 10, y = 15

/////Syntax:
// class MyClass {
//     dataType variable;
// public:
//     MyClass(dataType a):variable(a) {   // Assume that Type is an already
//                      // declared class and it has appropriate
//                      // constructors and operators
//     }
// };

