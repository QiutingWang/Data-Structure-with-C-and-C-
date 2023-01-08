#include <iostream>
#include <cstring>
using namespace std;

/////Shallow Copy, Deep Copy, and Own Copy Constructor:
class Student{
    int age;
  public:
    char *name;

    Student(Student const &s){ //infinite loop is created, avoiding this, we use pass by reference add &.
      this->age=s.age;
      // this->name=s.name; ///shallow copy
      ///Deep copy
      this->name=new char[strlen(s.name)+1]; //create a new array
      strcpy(this->name, s.name);
    }

    Student(int age, char *name){
      this->age=age;
      // this->name=name;    ///shallow copy:copy only the address and 0th index
      ///Deep Copy: create a new array for deep copy with the same size:copy the entire copy
      this->name=new char[strlen(name)+1]; //plus one to copy the null char
      strcpy(this->name,name); //strcpy(destination, source); copy the content
    }
    void display(){
      cout<<name<<" "<<age<<endl;
    }
};


/////Initialization:
class Student1{
  public:
    int age1;
    int &x; //age 
    const int rollNumber; //let this variable cannot be changed, constant variable cannot contain garbage value. Hence, const dataType varName; is false syntax. 
    // Another inflexible syntax: We need to initialize the value. const dataType varName=value; But we can not change the value anymore.

    // Solution: constructor for each object having a value
    Student(int r, int a): rollNumber(r), age1(a), x(this->age1){}     
    //use initialization list to prevent containing garbage value as soon as the variable created. 
    // rollNumber(r) means: const int rollNumber=r; 
};

//Another Example:
class Point {
private:
    int x;
    int y;
public:
    Point(int i = 0, int j = 0):x(i), y(j) {}
    /*  The above use of Initializer list is optional as the
        constructor can also be written as:
        Point(int i = 0, int j = 0) {
            x = i;
            y = j;
        }
    */     
    int getX() const {
      return x;
      }
    int getY() const {
      return y;
      }
};


