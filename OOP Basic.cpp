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
