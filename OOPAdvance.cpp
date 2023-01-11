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


///////////////////////////
/////Constant Function/////
//Feature: Those functions that are denied permission to change the values of the data member.
//Syntax:
// <return_type> <function_name>() const{
         //function body
// } For function definition within the class declaration.
//For function declaration within a class. <return_type> <function_name>() const; 
int main(){
  Fraction f1(10,5);
  Fraction f2(15,4);
  ///Create a constant object f3, cannot change the property
  Fraction const f3;   //default constructor not called, garbage value will be set, the complier prevent calling any normal function through const object, but constant function is allowed.
  cout<<f3.getNumerator()<<" "<<f3.getDenominator();
  /// Try to change the value of numerator
  f3.setNumerator(10);  //get error in the line
  return 0;
}


///////////////////////
/////Static Member/////
/// Syntax: static dataType attributeName;
/// Features: 
// declared with static keyword
// Only one copy of that member is created for the entire class, not changing with objects.
// only be initalized outside the class
///Initialization and Assign the value of static attribute
// dataType className :: staticAttributeName=value;      where :: is scope resolution operator
///Update the static attribute: take the help of constructor
int main(){
  Student s1;
  /*
  cout<<s1.rollNumber<<" "<<s1.age<<endl; //default constructor called, containing garbage value.
  //The complier allows us to change the static attribute value with any object.
  s1.totalStudents=20;  //inappropriate in logic to write s1.totalStudents, because static member belongs to class.
  Student s2;
  cout<<s2.totalStudents<<endl; 
  */
  Student s2,s3,s4,s5;

  cout<<Student::totalStudents<<endl;
  return 0;
}
// return:
// 0 0
// 20
// 20

// return: (update)
// 5

/// Create static function
/// syntax:
// static dataType functionName(arguments){
//   function body
// }
///Feature: 
// object doesn't allow to call the function. objectName.staticFunctionName() is wrong!
// the static function belongs to class
// Static function can only access the static data members and can call only static functions.
// Static function cannot use 'this' keyword, because we do not call static function through objects.
///Call the function, syntax:
// class::staticFunctionName();


//////////////////////////////
/////Operator Overloading/////
// reference:https://www.geeksforgeeks.org/operator-overloading-c/
// does not change the attribute of current object
///Defintion:
// We can extend the functionality of the existing operators(eg:work for user-defined classes)
// Example: f3=f1+f2 is wrong, because operator doesn't become effective to function operation. However, int c=a+b; is correct
// our aim is to make f3=f1+f2 work.
// create a new fraction f3, then it will return the new fraction if f1 and f2 both remain unchanged.
// Change the functionName to 'operatorsymbol', such as change add to operator+.
///Example: add function and operator+
int main(){
  Fraction f1(10,2);
  Fraction f2(15,4);
  //Fraction f3=f1.add(f2); //with add function
  Faction f4=f1+f2; //with operator+ syntax
  
  f1.print();
  f2.print();
  // f3.print();
  f4.print();

  return 0;
}
//return: f1,f2 remain unchanged
// 10/2
// 15/4
// 35/4

///Example: multiply function and operator*
int main(){
  Fraction f1(10,2);
  Fraction f2(15,4);
  Fraction f3=f1*f2;
  f1.print();
  f2.print();
  f3.print();
  return 0;
}
// return:
// 10/2
// 15/4
// 75/4

///Example: Equal and Not Equal Operator
int main(){
  Fraction f1(10,2);
  Fraction f2(15,4);
  if (f1==f2){
    cout<<"Equal"<<endl;
  }else{
    cout<<"Not Equal"<<endl;
  }
  return 0;
}
// return:
// Not Equal

///Example: ++ operator:pre-increment&post-increment(Unary Operator)
// Pre-increment: Syntax: ++ObjectName;
// do not need to past any argument, unary operator calculates the value and store it in 'this'.
int main(){
  Fraction f1(10,2);
  Fraction f2(15,4);

  f1.print();
  Fraction f3=++f1;
  // ++f1;
  f1.print();
  f3.print();

  return 0;
}
// return:
// 10/2
// 6/1
// 6/1

///With nested operators
int main(){
  Fraction f1(10,2);
  Fraction f2(15,4);
  f1.print();

  Fraction f3=++(++f1);  //inside the bracket +=f1 store the value in f1 address, while outside ++ store the value in f3 in a new address.
  // But we want the temporary memory that stores f3 never to be created. And function only making effects on the memory of f1.
  // Solution: use Return by Reference, then new copy would not be created as return.
    // https://www.geeksforgeeks.org/return-by-reference-in-c-with-examples/
    // Syntax: dataType& functionName(arguments){functionBody};
  f1.print();
  f3.print();

  return 0;
}
// return:   after use return by reference
// 10/2        10/2
// 6/1         7/1
// 7/1         7/1

///Example: Post-Increment Operator
// nesting is not allowed for post-increment operator
//Syntax: objectName++; the return comes to this, and do not create any argument
// The differences between Pre- and Post-Increment Operator will come when we assign the values:
  // For post-increment operator, first use then increment; While pre-, first do the increment then use;
int main(){
  Fraction f1(10,2);
  Fraction f2(15,4);
  Fraction f3=f1++;
  f1.print();
  f3.print();
  return 0;
}
// return:
// 6/1
// 5/1

///Example: += operator
// eg: i+=j → i=i+j     If in function, F1=F1+F2; return a fraction by reference without system copy. Similar to add function we created before.

//Nesting is allowed in this case
int main(){
  int i=5;
  int j=3;
  (i+=j)+=j;
  cout<<i<<" "<<j<<endl;
  return 0;
}
// return:
// 11 3

int main(){
  Fraction f1(10,3);
  Fraction f2(5,2);
  f1+=f2;
  f1.print();
  f2.print();
  return 0;
}
// return:
// 35/6
// 5/2


/////////////////////////////
/////Dynamic Array Class/////
int main(){
  DynamicArray d1; //default constructor called
  d1.add(10);
  d1.add(20);
  d1.add(30);
  d1.add(40);
  d1.add(50);
  d1.add(60);

  cout<<d1.getElement(2)<<endl;

  d1.print();
  cout<<d1.getCapacity()<<endl;

  DynamicArray d2(d1); //copy constructor called (shallow copy)
  DynamicArray d3; //default constructor called
  d3=d1;    //copy assignment operator called. In this case, it also creates a shallow copy.
            // do the operator overloading, hence d1,d2,and d3 are independent with each other
  d1.add(100,0);
  d1.print(); 
  d2.print();
  d3,print();

  DynamicArray d4(100); //parameterized constructor called
  cout<<d4.getCapacity()<<endl;

  return 0;
}
// return: S                     D                  operator overloading
//                                                  30                //test getElement function
// 10 20 30 40 50 60      10 20 30 40 50 60         10 20 30 40 50 60
// 10                     10                        10
// 100 20 30 40 50 60     100 20 30 40 50 60        100 20 30 40 50 60
// 100 20 30 40 50 60     10 20 30 40 50 60         10 20 30 40 50 60 
// 100 20 30 40 50 60     100 20 30 40 50 60        10 20 30 40 50 60 
//                                                  100

