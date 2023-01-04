//////////////////////////////
/////Introduction to OOPS/////
// Object Oriented Programming: Classes and Objects. 
// A class is a template for objects, and an object is an instance of a class.
// individual objects inherit all the variables and functions from the class.
// Objects: attributes and methods composed of variables and functions belongs to class-->class member
// 1 class, create many copies and fill with the specific data come to objects.
// references: https://www.w3schools.com/cpp/cpp_oop.asp
#include <iostream>
#include "OOPBasicClass.cpp" //use the class file with "fileName"
using namespace std;


////////////////////////////////////////////////
/////Creating Objects and Access Attributes/////
int main(){
  /// create object statically
  Student s1;
  Student s2;
  Student s3;

  /// create object dynamically with pointer
  Student *s4= new Student;  
  Student *s5= new Student;

  /// Assign the value statically: objectName.attributeName=value;
  // s1.age=24;
  s1.rollNumber=100;
  // cout<<s1.age<<endl;
  cout<<s1.rollNumber<<endl;
  s1.display();  //since we do not have any argument, the blank is empty.
  s2.display();

  cout<<"S1 age: "<<s1.getAge()<<endl;
  cout<<"S2 age: "<<s2.getAge()<<endl;

  /// Assign the value to dynamically created object: (*objectName).attributeName=value;
  // (*s4).age=22;
  (*s4).rollNumber=17;
  /// Shortcut to assign value for dynamically created object: objectName-> attributeName=value;
  // s5->age= 18;
  s5->rollNumber= 49;

  (*s4).display();
  s5->display();

  cout<<"S4 age: "<<(*s4).getAge()<<endl;

  return 0;
}

/////Create object dynamically Concepts:
// new: allocates enough storage on the heap to hold the object and calls the constructor for that storage.
// dataType *objectName = new dataType;
// the new expression returns an address to memory in the heap.
// every use of new operator has associated call of delete to deallocating memory was allocated by new.
// https://cse.hkust.edu.hk/~dekai/library/ECKEL_Bruce/TICPP-2nd-ed-Vol-one/TICPP-2nd-ed-Vol-one-html/Chapter13.html

/////Isolation of Logic:
// a single file to contain the class only. Another file is to use the class.


/////////////////////////////
/////Getters and Setters/////
int main(){
  Student s1;
  Student *s2= new Student;
  //setter
  s1.setAge(20, 917);
  s2->setAge(30, 917);
  //getter
  s1.display();
  s2->display();

  return 0;
}
// the impact of making something private: data protection, set access rights throughout the code; code readability; encourage code reuse


//////////////////////
/////Constructors/////
// references:https://www.geeksforgeeks.org/constructors-c/
// Goal: to initialize the data members of new objects
// a special method that is automatically called when an object of a class is created.
// for every object,constructor will be called only once in the lifetime of object.
// does not have a return value and return type.
// By default, constructors do not have any argument, while copy and parameterized constructors have inputs.(3 types of constructors)
// it must be placed in the public accessibility place of the class
// Name of constructor is the same as the class name

///Syntax:
// 1. constructor within the class:
// <class-name> (list-of-parameters) { 
  // constructor definition;
  // }
// 2. constructor outside the class:
// <class-name>: :<class-name> (list-of-parameters){ 
  // constructor definition;
  // }

#include <iostream>
#include "OOPBasicClass.cpp"
using namespace std;

int main(){
  Student s6;      //constructor called
  s6.display();    //will print garbage value

  Student s7;
  s7.display();

  Student *s8=new Student;
  s8->display();

  cout<<"Parameterized Constructor Demo"<<endl;
  Student s9(10);
  s9.display();

  Student *s10=new Student(22);
  s10->display();

  return 0;
}
// return:
// Constructor Called
// 1654973160 32606
// Constructor Called
// -996735888 21913
// Constructor Called
// 0 0
// Parameterized Constructor Demo
// Constructor2 Called
// 0 10
// Constructor2 Called
// 0 22


//////////////////////////////////////
/////Constructor and This Keyword/////
/////Scope of variables:https://www.geeksforgeeks.org/scope-of-variables-in-c/
// local variable: defined within a function or block, and cannot be accessed or used outside that block
// global variable: declared at the top of the program outside all of the functions or blocks.

// Q1: What happen if there exist a local variable whose name is the same as global variable?
// A: The compiler will give precedence to the local variable.OR with the help of "this" keyword to differentiate the attribute and parameter. this->attributeName=parameterName; (mandatory)
// Q2: How to access a global variable when there is a local variable with same name?
// A: use scope resolution operator ::

/////This:
// references:https://www.geeksforgeeks.org/this-pointer-in-c/
// a kind of pointer variable, stays in non-static member function calls and treated as a local variable within the function.Not available in static function.
// hold the address and memory of current object.
// every function in the class has access to this keyword
// Syntax: *this;     delete this;       this->attributeName1=value; 
int main(){
  Student s12(10,100);
  cout<<"Address of s12: "<<&s12<<endl;     //&: get the address

  Student s13(20,200);
  cout<<"Address of s13: "<<&s12<<endl; 
  
  return 0;
}
// return:
// this 0x7ffe3f236420
// Constructor3 Called
// Address of s12: 0x7ffe3f236420
// this 0x7ffcdbcad7b0
// Constructor3 Called
// Address of s13: 0x7ffcdbcad7a8

// add a constrain: We want attribute age does not have any garbage value. 
// Write a parameter constructor to specify age, then the default constructor is no longer available. Because there is no matching character.
// Student (int a){
//   age=a;
// }


//////////////////////////
/////Copy Constructor/////
// As soon as we create a Class, then we have several functions for free:
// Default constructor
// Copy constructor; Reference:https://www.geeksforgeeks.org/copy-constructor-in-cpp/
// Copy assignment operator
// Destructor

/////Definitions:
// Syntax: ClassName new_objName(old_objName);  ClassName new_objName(*old_objName) || ClassName new_objName=new ClassName(*old_objName); || ClassName new_objName=new ClassName(old_objName); 
// initializes an object using another object of the same class,which has been created previously is known as a copy constructor. 
// Copy constructor takes a reference to an object of the same class as an argument.
// only called once, it will be called at the time of object creation.
// types: 1.Default copy constructor; 2. User defined copy constructor
int main(){
  /// Creating Objects Statically
  Student s14(20,150);        //create a parameterized constructor--user defined
  cout<<"s14: ";
  s14.display();

  Student s15(s14);   //copy constructor
  cout<<"s15: ";
  s15.display();

  /// Creating Objects Dynamically, 2 kinds of written methods
  Student *s16=new Student(23,170);
  cout<<"s16: ";
  s16->display();

  Student s17(*s16);
  Student *s18=new Student(*s16); //create a copy of dynamically created object
  Student *s19=new Student(s14);  //create a copy of statically created object
  // whether use * mark or not depends on the property of object being copied, that is dynamically or statically created.

  return 0;
}
// return:
// this 0x7ffedeb14a28
// Constructor3 Called
// s14: 20 150
// s15: 20 150


///////////////////////////////////////////////
/////Copy Assignment Operator & Destructor/////
/////Copy Assignment Operator
// Syntax: new_objName=old_objName;
// This operator is called when an already initialized object is assigned a new value from another existing object. 
// It does not create a separate memory block or new memory space just as copy constructor does.
// both of objects have already been created in the memories, and we want to copy the values.
// Copy assignment operator and Copy constructor do the same work, but exceed under the different precondition.
int main(){
  Student s20(30, 55);
  Student s21(40, 99);
  Student *s22=new Student(50,120);

  //copy assignment operator
  s21=s20; 
  *s22=s20;
  s21=*s22;

  return 0;
}

/////Destructor
// references:https://www.geeksforgeeks.org/destructors-c/
///Definitions:
// deallocates the memory of object,releases memory space occupied by the objects, statically created objects are destroyed.
// has the same name as the class name
// no return type
// no any input argument
// Q:The above three properties are the same as default constructor, so how to differentiate from it?
// A: use tilde symbol ~
// the quantity of destructor is only 1, while the quantity of constructor can be many
// It is automatically called when object goes out of scope. 

///Syntax:
// 1. defining the destructor within the class
// ~ ClassName(){

// }
// 2. defining the destructor outside the class
// ClassName :: ~ ClassName(){

// }

// return:
// this 0x7fff332e0e18
// Constructor3 Called
// this 0x7fff332e0e20
// Constructor3 Called
// this 0x560587aac2c0
// Constructor3 Called
// Destructor Called
// Destructor Called  

//Q: Why only get twice destructor announcement? A: because s20,s21 are objects, while s22 is not object,it is only a pointer variable(*s22 is object created dynamically)
//Q:So how to delete dynamically created object? A: use  delete dy_objName; in main without written * mark.
int main(){
  Student s20(30, 55);
  Student s21(40, 99);
  Student *s22=new Student(50,120);

  //copy assignment operator
  s21=s20; 
  *s22=s20;
  s21=*s22;

  delete s22; 
  return 0;
}
// return:
// this 0x7fff5480a538
// Constructor3 Called
// this 0x7fff5480a540
// Constructor3 Called
// this 0x55fa702732c0
// Constructor3 Called
// Destructor Called
// Destructor Called
// Destructor Called


///////////////////////////////
/////Play with Constructor/////
int main(){
  Student s23; //default constructor will be called
  Student s24(44); //constructor2 will be called
  Student s25(50, 169); //constructor3 will be called
  Student s26(s25); //copy constructor will be called
  s23=s24; //no constructor will be called, but copy assignment operator will be called
  Student s27=s23; //copy constructor will be called
  return 0;
}
