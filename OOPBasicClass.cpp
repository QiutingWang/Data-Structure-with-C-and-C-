#include <iostream>
using namespace std;

class Student{
    int age;                       //be default, it is private accessibility

  public:
    ///default constructor
    Student(){                    // do the same work as the internal constructor was doing.
      cout<<"Constructor Called" <<endl;
    }

    ///parameterized constructor
    Student(int r){
      cout<<"Constructor2 Called"<<endl;
      this->rollNumber=rollNumber;  //if there exist two different scope variables sharing the same name,then use this is mandatory.
    }
    Student(int a, int r){
      cout<<"this "<<this<<endl;     //get the address
      cout<<"Constructor3 Called"<<endl;
      this->age=a; //using this->attributeName=value; is optional
      rollNumber=r;
    }

    int rollNumber;
    void display(){                //Getter: use a function, we can access the attribute outside the class for the private
      cout<<age<<" "<<rollNumber<<endl;
    }
    int getAge(){           
      return age;
    }
    void setAge(int a, int password){           //Setter: set values to the private attribute use function in class and we can add some constrain use if function
      if (password != 917){
        return;
      }
      if (a<0){
        return;
      }
      age=a;
    }

    //destructor
    ~ Student(){
      cout<<"Destructor Called"<<endl;
    }
};

/////Syntax of Creating a Class: a user defined data type
// class className{
//  AccessSpecifiers:          //https://www.w3schools.com/cpp/cpp_access_specifiers.asp
//   type attributeName1;
//   type attributeName2;
//   ...
// }

/////Access Specifiers:who can use the attribute of class
// public: members are accessible from outside the class[anywhere]
// private: members cannot be accessed (or viewed) from outside the class[inside] Default setting,if there is no declaration.
// protected: members cannot be accessed from outside the class, however, they can be accessed in inherited classes. Related to "Inheritance" concept
