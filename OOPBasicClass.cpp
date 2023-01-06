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


class Fraction{
  private:
    int numerator;
    int denominator;

  public:
    ///create a parameterized constructor, force the users to give value of these two attributes
    Fraction(int numerator, int denominator){
      this->numerator = numerator;
      this->denominator = denominator; //the attribute names are the same as the parameter names,use this->
    }
    void print(){
      cout<<this->numerator<<"/"<<this->denominator<<endl; //optional to use this
    }
    void add(Fraction const &f2){       //reference variable avoids copy and const keyword
      int lcm= this->denominator * f2.denominator; //optional to use this. f1 is stored in this
      int x=lcm/this->denominator;
      int y=lcm/f2.denominator;
      int num=x*this->numerator + y*f2.numerator;
      //store the result in f1, f1=f1+f2
      this->numerator=num;
      this->denominator=lcm; 

      simplify(); //call the function,this stored f1
    }
    /// Simplify, inbuilt function GCD= __gcd(a,b);
    // int c=__gcd(a,b);
    void simplify(){
      int gcd=1;
      int j= min(this->numerator, this->denominator);
      for (int i=1; i<=j; i++){
        if (numerator%i==0 && denominator%i==0){
          gcd=i;
        }
      }
      this->numerator = this->numerator/gcd;
      this->denominator= this->denominator/gcd;
    }
    void multiply(Fraction const &f2){
      numerator=numerator * f2.numerator;
      denominator=denominator * f2.denominator;

      simplify();
    }
};
